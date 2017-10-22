#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"
#include <vector>

class Neuron; //pre-declaration

class Network {
	private:
		std::vector <Neuron*> network_;
		double clock_;
		
	public:
//CONSTRUCTOR
		Network();
		
//GETTER AND SETTER FOR clock_
		double getClock() const;
		void setClock(double clock);
		
//ADD A NEURON IN THE NETWORK
		void addNeuron();
				
//SIMULATION LOOP FOR neuron1_ AND neuron2_ IN TAKING THE CONNECTION BETWEEN THEM (AND THE DELAY) INTO ACCOUNT
		void simulationLoop(double tstart, double tstop, double Iext);

//DESTROY ALL THE NEURONS OF THE NETWORK
		void destructionNeurons();
		
//DESTRUCTOR	
		~Network();
	
};

#endif
