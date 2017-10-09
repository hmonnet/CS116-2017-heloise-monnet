#ifndef NETWORK_HPP
#define NETWORK_HPP
#include <vector>

class Neuron; // prédéclaration

class Network {
	private:
		Neuron neuron1_;
		Neuron neuron2_;
		double clock_;
		
	public:
//CONSTRUCTOR
		Network() {
		}
		
//UPDATE neuron1_ AND neuron2_
		void update(double h, double C, double tau, double Iext);
		
//STORE THE SPIKES OF EACH NEURON OF neurons_
		void store();
		
		
//DESTRUCTOR	
		~Network() {
		}
	
};

#endif
