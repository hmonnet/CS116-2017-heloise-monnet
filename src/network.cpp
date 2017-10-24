#include "network.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <cmath>
using namespace std;

///CONSTRUCTOR
Network::Network()
: connexions_(12500, vector<int>(12500, 0)), clock_(0.0)
{
	for(int i(0); i < 10000; ++i) {
		excitatoryNeurons_.push_back(new Neuron(i, 0.5));
	}
	for(int i(0); i < 2500; ++i) {
		inhibitoryNeurons_.push_back(new Neuron(i+10000, 0.1));
	}
}
		
///GETTER AND SETTER FOR clock_		
double Network::getClock() const {
  return clock_;
}
  
void Network::setClock(double clock) {
  clock_ = clock;
}

///DISTRIBUTION OF THE CONNECTIONS BETWEEN ALL THE EXCITATORY AND INHIBITORY NEURONS
void Network::connexions() {
	random_device rd;
	std::mt19937 gen(rd());
	
	for(int neuron(0); neuron < 12500; ++neuron) {
		int nbExcitatorySources(1000);
		while(nbExcitatorySources > 0) {
			uniform_int_distribution<> excDis (0, 9999);
			if(connexions_[neuron][excDis(gen)] == 0) {
				connexions_[neuron][excDis(gen)] = 1;
				connexions_[excDis(gen)][neuron] = 1;
			}
			--nbExcitatorySources;
		}
			
		int nbInhibitorySources(250);
		while(nbInhibitorySources > 0) {
			uniform_int_distribution<> inhDis (1000, 12499);
			if(connexions_[neuron][inhDis(gen)] == 0) {
				connexions_[neuron][inhDis(gen)] = 1;
				connexions_[inhDis(gen)][neuron] = 1;
			}
			--nbInhibitorySources;
		}
	}
}

			
///SIMULATION LOOP FOR ALL THE EXCITATORY AND INHIBITORY NEURONS IN TAKING THE CONNECTION BETWEEN THEM AND THE DELAY INTO ACCOUNT
void Network::simulationLoop(double tstart, double tstop) {
	clock_ = tstart;
	
	for(auto neuron: excitatoryNeurons_) {
		neuron->setTime(tstart);
	}
	for(auto neuron: inhibitoryNeurons_) {
		neuron->setTime(tstart);
	}
	
	connexions();
	
	int a(0);

	while(clock_ < tstop) {
		for(int neuron(0); neuron < 10000; ++neuron) {
			excitatoryNeurons_[neuron]->simulationLoop(1);
			
			if(excitatoryNeurons_[neuron]->isSpiking()) {
				a = floor((clock_ + excitatoryNeurons_[neuron]->getDelay())/excitatoryNeurons_[neuron]->getH());
				
				for(int target(0); target < 12500; ++target) {
					if (connexions_[neuron][target] == 1) {
						if(target < 10000) {
							excitatoryNeurons_[target]->setBuffer(a % 16, excitatoryNeurons_[neuron]->getJ());
						} else {
							inhibitoryNeurons_[target-10000]->setBuffer(a % 16, excitatoryNeurons_[neuron]->getJ());
						}
					}
				}
			}
		 }
		
		 for(int neuron(0); neuron < 2500; ++neuron) {
			inhibitoryNeurons_[neuron]->simulationLoop(1);
			
			if(inhibitoryNeurons_[neuron]->isSpiking()) {
				a = floor((clock_ + inhibitoryNeurons_[neuron]->getDelay())/inhibitoryNeurons_[neuron]->getH());
				
				for(int target(0); target < 12500; ++target) {
					if (connexions_[neuron+10000][target] == 1) {
						if(target < 10000) {
							excitatoryNeurons_[target]->setBuffer(a % 16, inhibitoryNeurons_[neuron]->getJ());
						} else {
							inhibitoryNeurons_[target-10000]->setBuffer(a % 16, inhibitoryNeurons_[neuron]->getJ());
						}
					}
				}
			}
		 }
		
		clock_ += excitatoryNeurons_[0]->getN()*excitatoryNeurons_[0]->getH();	
	}
}

///DESTROY ALL THE NEURONS OF THE NETWORK
void Network::destructionNeurons()
{
	for(auto& neuron: excitatoryNeurons_) {
        if(neuron != nullptr) {
            delete neuron;
            neuron = nullptr;
        }
    }
    for(auto& neuron: inhibitoryNeurons_) {
        if(neuron != nullptr) {
            delete neuron;
            neuron = nullptr;
        }
    }
}				
				
///DESTRUCTOR	
Network::~Network() {
	destructionNeurons();
}
