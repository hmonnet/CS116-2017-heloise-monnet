#include "neuron_class.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTOR
  Neuron::Neuron(double potential = 0.0, int nbSpikes = 0, int isRefractory = 0, double time = 0.0, double Iext = 0.0)
  : potential_(potential), nbSpikes_(nbSpikes), isRefractory_(isRefractory), time_(time), Iext_(Iext)
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
double Neuron::getN() const {
	return n_;
}
double Neuron::getH() const {
	return h_;
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
void Neuron::updatePotential(double Iext) {
    double R(tau_ / C_);
    potential_ = exp(-h_/tau_)*potential_ + Iext*R*(1-exp(-h_/tau_)) + J_;
}
  
//RETURN TRUE IF THE NEURON IS SPIKING
		bool Neuron::isSpiking() {
			if(potential_ > Vth_) {
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
		sortie << "Time: " << time_ << "  Potential: " << potential_ << endl;
		cout << "A spike occured, the neuron enters in a refractory period (potential: 0)." << endl;
	}
	sortie.close();
}

//SIMULATION LOOP OF THE NEURON
void Neuron::simulationLoop(double tstart, double tstop, double Iext) {
	time_ = tstart;
	while(time_ < tstop) {
		Iext_ = Iext;
		if(isRefractory_ > 0) {
		  --isRefractory_;
		  potential_ = Vreset_;
		} else {            
		  updatePotential(Iext);
		  cout << "Time: " << time_ << "  Potential: " << potential_ << endl;
		  if(isSpiking()) {
			nbSpikes_ += 1;
			storeSpike();
			isRefractory_ = (tauref_ / (n_*h_));
		  }
		}
		time_ += n_*h_;
	}
}
  
//DESTRUCTOR
Neuron::~Neuron() {
}
