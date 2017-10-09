#include "neuron_class.hpp"
#include <iostream>
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
  
//DESTRUCTOR
Neuron::~Neuron() {
}
