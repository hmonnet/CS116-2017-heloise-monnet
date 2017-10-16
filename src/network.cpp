#include "network.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTOR
Network::Network()
: neuron1_(1, 1.5), neuron2_(2, 1.5), clock_(0.0)
{}
		
//GETTER AND SETTER FOR clock_		
double Network::getClock() const {
  return clock_;
}
  
void Network::setClock(double clock) {
  clock_ = clock;
}
			
//SIMULATION LOOP neuron1_ AND neuron2_ IN TAKING THE CONNECTION BETWEEN THEM  (AND THE DELAY) INTO ACCOUNT
void Network::simulationLoop(double tstart, double tstop, double Iext) {
	clock_ = tstart;
	neuron1_.setTime(tstart);
	neuron2_.setTime(tstart);
	
	int a;
	int b;
		
	while(clock_ < tstop) {
		neuron1_.simulationLoop(Iext);
		if(neuron1_.isSpiking()) {
			a = floor((clock_ + neuron1_.getDelay())/neuron1_.getH());
			neuron2_.setBuffer(a % 16, neuron1_.getJ());
		}
		neuron2_.simulationLoop(0.0);
		if(neuron2_.isSpiking()) {	
			b = floor((clock_ + neuron2_.getDelay())/neuron1_.getH());
			neuron1_.setBuffer(b % 16, neuron2_.getJ());
		}
		clock_ += neuron1_.getN()*neuron1_.getH();		
	}	
}
				
//DESTRUCTOR	
Network::~Network() {
}
