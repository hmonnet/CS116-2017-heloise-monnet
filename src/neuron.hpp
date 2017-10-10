#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron {
	private:
		int id_;
		double potential_;
		int nbSpikes_;
		int isRefractory_;
		double time_;
		double Iext_;
	
//NEURON PARAMETERS		
		const double n_=1.0;
		const double h_=0.1;
		const double C_=1.0;
		const double tau_=20.0;
		const double tauref_=2.0;
		const double Vreset_=0.0;
		const double Vth_=20.0;
		const double J_=0.1; //VALEUR??
		
	public:
//CONSTRUCTOR
		Neuron(int id);
		
//GETTERS AND SETTERS
		double getPotential() const;
		int getNbSpikes() const;
		double getTime() const;
		double getN() const;
		double getH() const;
		double getJ() const;
		
		void setPotential(double potential);
		void setNbSpikes(int nbSpikes);
		void setTime(double time);
		
//UPDATE OF THE NEURON STATE AT TIME t+T
		void updatePotential(double Iext);
		
//RETURN TRUE IF THE NEURON IS SPIKING
		bool isSpiking();
		
//SIMULATION LOOP OF THE NEURON
		 void simulationLoop(double clock, double Iext);
		
//STORAGE OF SPIKE TIMES IN A FILE
		void storeSpike();
				
//DESTRUCTOR
		~Neuron();
		
};

#endif
