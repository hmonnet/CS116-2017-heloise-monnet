#include "network_class.hpp"
#include "neuron_class.hpp"
#include <iostream>
using namespace std;

//CONSTRUCTOR
		Network::Network();
		
//ADD A NEURON TO neurons_		
		void Network::addNeuron() {
			neurons_.push_back(new Neuron);
		} 
		
//UPDATE ALL THE NEURONS OF neurons_
		void Network::update(double h, double C, double tau, double Iext) {
			int size = neurons_.size();

			for(int i(0); i < size; ++i) {
				neurons_[i]->updatePotential(h, C, tau, Iext);
			}
		}
		
//STORE THE SPIKES OF EACH NEURON OF neurons_
		void store() {
			
		}		
				
//DESTRUCTOR	
		Network::~Network();
