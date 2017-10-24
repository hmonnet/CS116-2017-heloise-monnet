#include "neuron.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <random>
using namespace std;

///CONSTRUCTORS
Neuron::Neuron() 
: id_(0), J_(0.1), potential_(0.0), nbSpikes_(0), isRefractory_(0), time_(0.0), Iext_(0.0), buffer_(16, 0)
{}

Neuron::Neuron(int id, double J) 
: id_(id), J_(J), potential_(0.0), nbSpikes_(0), isRefractory_(0), time_(0.0), Iext_(0.0), buffer_(16, 0)
{}

///GETTERS
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

///SETTERS
void Neuron::setId(int id) {
	id_ = id;
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
void Neuron::setIext(double Iext) {
  Iext_ = Iext;
}
void Neuron::setJ(double J) {
	J_ = J;
}
void Neuron::setBuffer(int position, double J) {
	buffer_[position] += J;
}

///UPDATE OF THE NEURON STATE AT TIME t+T
void Neuron::updatePotential() {
    double R(tau_ / C_);
    int a((time_/h_));
    
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<> dis(0.2); ///v_thr*J*h*C_E=0.02*0.1*0.1*1000=0.2
    
    potential_ = exp(-h_/tau_)*potential_ + Iext_*R*(1-exp(-h_/tau_)) + buffer_[a % 16] + dis(gen);
    buffer_[a % 16] = 0.0;
}
  
///RETURN TRUE IF THE NEURON IS SPIKING
bool Neuron::isSpiking() {
	if(potential_ > Vth_) {
		return true;
	} else {
		return false;
	}
}

///SIMULATION LOOP OF THE NEURON
void Neuron::simulationLoop(int nbSimulationLoops) {
	for(int i(0); i < nbSimulationLoops; ++i) {
		if(isRefractory_ > 0) {
		  --isRefractory_;
		  potential_ = Vreset_;
		} else {            
		  updatePotential();
		  if(isSpiking()) {
			nbSpikes_ += 1;
			storeSpike();
			isRefractory_ = (tauref_ / (n_*h_));
		  }
		}
		time_ += n_*h_;
	}
}

///STORAGE OF SPIKE TIMES IN A FILE
void Neuron::storeSpike() {
	ofstream sortie;
	sortie.open("data.txt", ios::out|ios::app);
	if(sortie.fail()) {
		cout << "Error. Impossible to write in fichier.txt." << endl;
	} else {
		sortie << "Time: " << time_ << "  Potential neuron " << id_ << " : " << potential_ << endl;
		cout << "A spike occured at time " << time_ << ", the neuron " << id_ << " enters in a refractory period (potential: 0)." << endl;
	}
	sortie.close();
}
  
///DESTRUCTOR
Neuron::~Neuron() {
}
