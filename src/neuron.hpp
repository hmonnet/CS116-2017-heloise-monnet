#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>

class Neuron {
	private:
		int id_;
		double delay_;
		double potential_;
		int nbSpikes_;
		int isRefractory_;
		double time_;
		double Iext_;
		std::vector<double> buffer_;
	
//NEURON PARAMETERS		
		const double n_=1.0;
		const double h_=0.1;
		const double C_=1.0;
		const double tau_=20.0;
		const double tauref_=2.0;
		const double Vreset_=0.0;
		const double Vth_=20.0;
		const double J_=0.1;
		
	public:
//CONSTRUCTORS
		Neuron();
		Neuron(int id, double delay);
		
//GETTERS
		double getPotential() const;
		int getNbSpikes() const;
		double getTime() const;
		double getDelay() const;
		double getN() const;
		double getH() const;
		double getJ() const;

//SETTERS		
		void setPotential(double potential);
		void setNbSpikes(int nbSpikes);
		void setTime(double time);
		void setBuffer(int position, double J);
		
//UPDATE OF THE NEURON STATE AT TIME t+T
		void updatePotential(double Iext);
		
//RETURN TRUE IF THE NEURON IS SPIKING
		bool isSpiking();
		
//SIMULATION LOOP OF THE NEURON
		 void simulationLoop(double Iext);
		
//STORAGE OF SPIKE TIMES IN A FILE
		void storeSpike();
				
//DESTRUCTOR
		~Neuron();
		
};

#endif
