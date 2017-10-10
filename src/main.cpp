#include "neuron_class.cpp"
#include <iostream>
using namespace std;

int main() {
//DECLARATION OF THE VARIABLES
  Neuron neuron;
  
  double tstart;
  double tstop;
  double Iext;

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
  neuron.simulationLoop(tstart, tstop, Iext);
  
  return 0;
}
