#include "neuron_class.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTOR
  Neuron::Neuron(double potential = 0.0, int nbSpikes = 0, double time = 0.0)
  : potential_(potential), nbSpikes_(nbSpikes), time_(time)
  {}

//GETTERS AND SETTERS
double Neuron::getPotential() const {
  return potential_;
}
int Neuron::getNbSpikes() const {
  return nbSpikes_;
}
double Neuron::getTime() const {
  return time_;
}
  
void Neuron::setPotential(double potential) {
  potential_ = potential;
}
void Neuron::setNbSpikes(int nbSpikes) {
  nbSpikes_ = nbSpikes;
}
void Neuron::setTime(double time) {
  time_ = time;
}

//UPDATE OF THE NEURON STATE AT TIME t+T
void Neuron::updatePotential(double h, double C, double tau, double Iext) {
    double R(tau / C);
    potential_ = exp(-h/tau)*potential_ + Iext*R*(1-exp(-h/tau));
}
  
//RETURN TRUE IF THE NEURON IS SPIKING
		bool Neuron::isSpiking(double Vth) {
			if(potential_ > Vth) {
				return true;
			} else {
				return false;
			}
		}
  
//STORAGE OF SPIKE TIMES IN A FILE
void Neuron::storeSpike() {
	ofstream sortie;
	sortie.open("data.txt", ios::out|ios::app);
	if(sortie.fail()) {
		cout << "Error. Impossible to write in fichier.txt." << endl;
	} else {
		sortie << "Time: " << Neuron::getTime() << "  Potential: " << Neuron::getPotential() << endl;
		cout << "A spike occured, the neuron enters in a refractory period (potential: 0)." << endl;
	}
	sortie.close();
}
  
//DESTRUCTOR
Neuron::~Neuron() {
}
