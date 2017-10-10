#ifndef NETWORK_HPP
#define NETWORK_HPP

class Neuron; //pre-declaration

class Network {
	private:
		Neuron neuron1_;
		Neuron neuron2_;
		double clock_;
		
	public:
//CONSTRUCTOR
		Network();
		
//GETTER AND SETTER FOR clock_
		double getClock() const;
		void setClock(double clock);
				
//SIMULATION LOOP FOR neuron1_ AND neuron2_
		void simulationLoop(double tstart, double tstop, double Iext);
		
//DESTRUCTOR	
		~Network();
	
};

#endif
