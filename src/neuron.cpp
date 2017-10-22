#include "neuron.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//CONSTRUCTORs
Neuron::Neuron() 
: id_(0), delay_(0), potential_(0.0), nbSpikes_(0), isRefractory_(0), time_(0.0), Iext_(0.0), buffer_(16, 0)
{}

Neuron::Neuron(int id, double delay)
: id_(id), delay_(delay), potential_(0.0), nbSpikes_(0), isRefractory_(0), time_(0.0), Iext_(0.0), buffer_(16, 0)
{}

//GETTERS
double Neuron::getPotential() const {
  return potential_;
}
int Neuron::getNbSpikes() const {
  return nbSpikes_;
}
double Neuron::getTime() const {
  return time_;
}
double Neuron::getDelay() const {
	return delay_;
}
double Neuron::getN() const {
	return n_;
}
double Neuron::getH() const {
	return h_;
}
double Neuron::getJ() const {
	return J_;
}

//SETTERS
void Neuron::setPotential(double potential) {
  potential_ = potential;
}
void Neuron::setNbSpikes(int nbSpikes) {
  nbSpikes_ = nbSpikes;
}
void Neuron::setTime(double time) {
  time_ = time;
}
void Neuron::setBuffer(int position, double J) {
	buffer_[position] += J;
}

//UPDATE OF THE NEURON STATE AT TIME t+T
void Neuron::updatePotential(double Iext) {
    double R(tau_ / C_);
    int a((time_/h_));
    potential_ = exp(-h_/tau_)*potential_ + Iext*R*(1-exp(-h_/tau_)) + buffer_[a % 16];
    buffer_[a % 16] = 0.0;
}
  
//RETURN TRUE IF THE NEURON IS SPIKING
bool Neuron::isSpiking() {
	if(potential_ > Vth_) {
		return true;
	} else {
		return false;
	}
}

//SIMULATION LOOP OF THE NEURON
void Neuron::simulationLoop(double Iext) {
	Iext_ = Iext;
	if(isRefractory_ > 0) {
	  --isRefractory_;
	  potential_ = Vreset_;
	} else {            
	  updatePotential(Iext);
	  cout << "Time: " << time_ << "  Potential neuron " << id_ << " : " << potential_ << endl;
	  if(isSpiking()) {
		nbSpikes_ += 1;
		storeSpike();
		isRefractory_ = (tauref_ / (n_*h_));
	  }
	}
	time_ += n_*h_;
}

//STORAGE OF SPIKE TIMES IN A FILE
void Neuron::storeSpike() {
	ofstream sortie;
	sortie.open("data.txt", ios::out|ios::app);
	if(sortie.fail()) {
		cout << "Error. Impossible to write in fichier.txt." << endl;
	} else {
		sortie << "Time: " << time_ << "  Potential neuron " << id_ << " : " << potential_ << endl;
		cout << "A spike occured, the neuron " << id_ << " enters in a refractory period (potential: 0)." << endl;
	}
	sortie.close();
}
  
//DESTRUCTOR
Neuron::~Neuron() {
}
