#include "network.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTOR
Network::Network()
: neuron1_(1, 2), neuron2_(2, 3), clock_(0.0)
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
	
	int a(round(clock_/neuron2_.getH()));
	int b(round(clock_/neuron2_.getH()));
	
	while(clock_ < tstop) {
		neuron1_.simulationLoop(clock_, Iext);
		if(neuron1_.isSpiking()) {
			neuron2_.setBuffer((a + neuron1_.getDelay()) % 4);
		}
		neuron2_.simulationLoop(clock_, Iext);
		if(neuron2_.isSpiking()) {
			neuron1_.setBuffer((b + neuron2_.getDelay()) % 4);
		}
		clock_ += neuron1_.getN()*neuron1_.getH();		
	}	
}
				
//DESTRUCTOR	
Network::~Network() {
}
