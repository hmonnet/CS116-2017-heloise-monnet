#include "network.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <cmath>
using namespace std;

///CONSTRUCTOR
Network::Network()
: connexions_(12500, vector<int>(1250, 0)), clock_(0.0), nbSpikes_(0)
{
	for(int i(0); i < 10000; ++i) {
		excitatoryNeurons_.push_back(new Neuron(i, 0.1));
	}
	for(int i(0); i < 2500; ++i) {
		inhibitoryNeurons_.push_back(new Neuron(i+10000, -0.5));
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
		for(int excTarget(0); excTarget < 1000; ++excTarget) {
			uniform_int_distribution<> excDis (0, 9999);
			connexions_[neuron][excTarget] = excDis(gen);
		}
		
		for(int inhTarget(1000); inhTarget < 1250; ++inhTarget) {
			uniform_int_distribution<> inhDis (10000, 12499);
			connexions_[neuron][inhTarget] = inhDis(gen);
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


	while(clock_ < tstop) {
		int a(floor((clock_ + 1.5)/0.1));
		
		for(int neuron(0); neuron < 10000; ++neuron) {
			excitatoryNeurons_[neuron]->simulationLoop(1);
			
			if(excitatoryNeurons_[neuron]->isSpiking()) {
				nbSpikes_ += 1;
				for(int target(0); target < 1000; ++target) {
					int targetId(connexions_[neuron][target]);
					excitatoryNeurons_[targetId]->setBuffer(a % 16, 0.1);
				}
				for(int target(1000); target < 1250; ++target) {
					int targetId(connexions_[neuron][target]);
					inhibitoryNeurons_[targetId-10000]->setBuffer(a % 16, 0.1);
				}
			}
		}

		for(int neuron(10000); neuron < 12500; ++neuron) {
			inhibitoryNeurons_[neuron-10000]->simulationLoop(1);
			
			if(inhibitoryNeurons_[neuron-10000]->isSpiking()) {
				nbSpikes_ += 1;
				for(int target(0); target < 1000; ++target) {
					int targetId(connexions_[neuron][target]);
					excitatoryNeurons_[targetId]->setBuffer(a % 16, -0.5);
				}
				for(int target(1000); target < 1250; ++target) {
					int targetId(connexions_[neuron][target]);
					inhibitoryNeurons_[targetId-10000]->setBuffer(a % 16, -0.5);
				}
			}
		 }
		
		if(nbSpikes_ > 0) {
			storeNbSpikes();
			nbSpikes_ = 0;
		}
		
		clock_ += 0.1;
	}
}

///STORE THE NUMBER OF SPIKES AT EACH TIME T
void Network::storeNbSpikes() {
	ofstream sortie;
	sortie.open("nbSpikes.txt", ios::out|ios::app);
	if(sortie.fail()) {
		cerr << "Error. Impossible to write in fichier.txt." << endl;
	} else {
		sortie << clock_ << "	" << nbSpikes_ << endl;
	}
	sortie.close();
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
