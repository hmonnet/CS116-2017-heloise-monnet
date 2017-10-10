#include "network.hpp"
#include <iostream>
#include <fstream>
using namespace std;

//CONSTRUCTOR
Network::Network()
: neuron1_(1), neuron2_(2), clock_(0.0)
{}
		
//GETTER AND SETTER FOR clock_		
double Network::getClock() const {
  return clock_;
}
  
void Network::setClock(double clock) {
  clock_ = clock;
}
			
//SIMULATION LOOP neuron1_ AND neuron2_ IN TAKING THE CONNECTION BETWEEN THEM INTO ACCOUNT
void Network::simulationLoop(double tstart, double tstop, double Iext) {
	clock_ = tstart;
	while(clock_ < tstop) {
		neuron1_.simulationLoop(clock_, Iext);
		if(neuron1_.isSpiking()) {
			neuron2_.setPotential(neuron2_.getPotential() + neuron1_.getJ());
		}
		neuron2_.simulationLoop(clock_, Iext);
		if(neuron2_.isSpiking()) {
			neuron1_.setPotential(neuron1_.getPotential() + neuron2_.getJ());
		}
		clock_ += neuron1_.getN()*neuron1_.getH();		
	}	
}
				
//DESTRUCTOR	
Network::~Network() {
}
