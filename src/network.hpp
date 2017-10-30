#ifndef NETWORK_HPP
#define NETWORK_HPP
#include "neuron.hpp"
#include <vector>

class Neuron; ///pre-declaration

class Network {
	private:
		std::vector <Neuron*> excitatoryNeurons_;
		std::vector <Neuron*> inhibitoryNeurons_;
		std::vector<std::vector<int>> connexions_;
		double clock_;
		int nbSpikes_;
		
	public:
///CONSTRUCTOR
		Network();
		
///GETTER AND SETTER FOR clock_
		double getClock() const;
		void setClock(double clock);
		
///DISTRIBUTION OF THE CONNECTIONS BETWEEN ALL THE EXCITATORY AND INHIBITORY NEURONS
		void connexions();
				
///SIMULATION LOOP FOR ALL THE EXCITATORY AND INHIBITORY NEURONS IN TAKING THE CONNECTION BETWEEN THEM AND THE DELAY INTO ACCOUNT
		void simulationLoop(double tstart, double tstop);
		
///STORE THE NUMBER OF SPIKES AT EACH TIME T
		void storeNbSpikes();

///DESTROY ALL THE NEURONS OF THE NETWORK
		void destructionNeurons();
		
///DESTRUCTOR	
		~Network();
	
};

#endif
