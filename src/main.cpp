#include "network.hpp"
#include "neuron.hpp"
#include <iostream>

using namespace std;

int main() {
//DECLARATION OF THE VARIABLES
  Network network;
  
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
  cin >> Iext;
  while(cin.fail()) {
	cout << "Error, you have to enter a double." << endl;
	cin.clear();
	cin.ignore(256,'\n');
	cout << "Iext = " << flush;
	cin >> Iext;
  }
  
//SIMULATION FROM tstart TO tstop
  network.simulationLoop(tstart, tstop, Iext);
  
  return 0;
}
