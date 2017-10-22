#include "network.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTOR
Network::Network()
: network_(0), clock_(0.0)
{}
		
//GETTER AND SETTER FOR clock_		
double Network::getClock() const {
  return clock_;
}
  
void Network::setClock(double clock) {
  clock_ = clock;
}

//ADD A NEURON IN THE NETWORK
void Network::addNeuron()
{
    network_.push_back(new Neuron(network_.size(), 1.5));
} 
			
//SIMULATION LOOP neuron1_ AND neuron2_ IN TAKING THE CONNECTION BETWEEN THEM  (AND THE DELAY) INTO ACCOUNT
void Network::simulationLoop(double tstart, double tstop, double Iext) {
	clock_ = tstart;
	
	for(auto& neuron: network_) {
		neuron->setTime(tstart);
	}
	
	int size(network_.size());
	int a;

	while(clock_ < tstop) {
		for(int i(0); i < size; ++i) {
			network_[i]->simulationLoop(Iext);
			if(network_[i]->isSpiking()) {
				a = floor((clock_ + network_[i]->getDelay())/network_[i]->getH());
				if(i == (size - 1)) {
					network_[0]->setBuffer(a % 16, network_[i]->getJ());
				} else {
					network_[i+1]->setBuffer(a % 16, network_[i]->getJ());
				}
			}
		}
		clock_ += network_[0]->getN()*network_[0]->getH();	
	}
}

//DESTROY ALL THE NEURONS OF THE NETWORK
void Network::destructionNeurons()
{
	for(auto& neuron: network_) {
        if(neuron != nullptr) {
            delete neuron;
            neuron = nullptr;
        }
    }
    //network_.erase(remove(network_.begin(), network_.end(), nullptr), network_.end());
}				
				
//DESTRUCTOR	
Network::~Network() {
	destructionNeurons();
}
