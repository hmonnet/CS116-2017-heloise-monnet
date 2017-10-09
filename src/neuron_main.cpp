#include "neuron_class.cpp"
#include <iostream>
using namespace std;

int main() {
//DECLARATION OF THE VARIABLES
  Neuron neuron;
  struct neuronParams {
    double h;
    double C;
    double tau;
    double tauref;
    double Vreset;
    double Vth;
  }
  neuronParams = {0.1, 1.0, 20.0, 2.0, 0.0, 20.0};
  
  double tstart;
  double tstop;
  double Iext;
  
  int n(1);
  int isRefractory(0);

//INITIALISATION OF tstart, tstop AND Iext  
  cout << "Enter a time interval [tstart,tstop)." << endl;
  cout << "tstart = " << flush;
  cin >> tstart;
  while(cin.fail()) {
    cout << "Error, you have to enter a double." << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "tstart = " << flush;
    cin >> tstart;
  }
  
  cout << "tstop = " << flush;
  cin >> tstop;
  while(cin.fail()) {
    cout << "Error, you have to enter a double." << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "tstop = " << flush;
    cin >> tstop;
  }
  
  cout << "Enter the external current." << endl;
  cout << "Iext = " << flush;
  cin >> Iext; //ou 0 si on n'est pas dans le while?
  while(cin.fail()) {
    cout << "Error, you have to enter a double." << endl;
    cin.clear();
    cin.ignore(256,'\n');
    cout << "Iext = " << flush;
    cin >> Iext;
  }
  
//SIMULATION FROM tstart TO tstop  
  neuron.setTime(tstart);
  
  while(neuron.getTime() < tstop) {
    if(isRefractory > 0) {
      --isRefractory;
      neuron.setPotential(neuronParams.Vreset);
    } else {            
      neuron.updatePotential(neuronParams.h, neuronParams.C, neuronParams.tau, Iext);
      cout << "Time: " << neuron.getTime() << "  Potential: " << neuron.getPotential() << endl;
      if(neuron.getPotential() > neuronParams.Vth) {
        neuron.setNbSpikes(neuron.getNbSpikes() + 1);
		neuron.storeSpike();
        isRefractory = (neuronParams.tauref / (n*neuronParams.h));
      }
    }
    neuron.setTime(neuron.getTime() + n*neuronParams.h); //bon endroit?
  }
  return 0;
}
