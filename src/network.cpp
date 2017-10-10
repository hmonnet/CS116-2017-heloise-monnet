#include "network_class.hpp"
#include "neuron_class.hpp"
#include <iostream>
using namespace std;

//CONSTRUCTOR
Network::Network() {
}
		
//GETTER AND SETTER FOR clock_		
double Network::getClock() const {
  return clock_;
}
  
void Network::setClock(double clock) {
  clock_ = clock;
}
			
//UPDATE neuron1_ AND neuron2_
void Network::simulationLoop(double tstart, double tstop, double Iext) {
	clock_ = tstart;
	while(clock_ < tstop) {
		neuron1_.updatePotential(Iext);
		if(neuron1_.isSpiking()) {
			
		}
		neuron2_.updatePotential(Iext);
		if(neuron2_.isSpiking()) {
			
		}
		clock_ += neuron1_.getN()*neuron1_.getH();
	}
}		
				
//DESTRUCTOR	
Network::~Network() {
}
