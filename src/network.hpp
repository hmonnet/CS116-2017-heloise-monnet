#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"

class Neuron; //pre-declaration

class Network {
	private:
		Neuron neuron1_;
		Neuron neuron2_;
		double clock_;
		
	public:
//CONSTRUCTOR
		Network();
		
//GETTER AND SETTER FOR clock_
		double getClock() const;
		void setClock(double clock);
				
//SIMULATION LOOP FOR neuron1_ AND neuron2_ IN TAKING THE CONNECTION BETWEEN THEM (AND THE DELAY) INTO ACCOUNT
		void simulationLoop(double tstart, double tstop, double Iext);
		
//STORAGE OF SPIKE TIMES OF neuron1_ AND neuron2_ IN A FILE
		void storeSpike();		
		
//DESTRUCTOR	
		~Network();
	
};

#endif
