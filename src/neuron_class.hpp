#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron {
	private:
		double potential_;
		int nbSpikes_;
		double time_;
		
	public:
//CONSTRUCTOR
		Neuron(double potential, int nbSpikes, double time);
		
//GETTERS AND SETTERS
		double getPotential() const;
		int getNbSpikes() const;
		double getTime() const;
		
		void setPotential(double potential);
		void setNbSpikes(int nbSpikes);
		void setTime(double time);
		
//UPDATE OF THE NEURON STATE AT TIME t+T
		void updatePotential(double h, double C, double tau, double Iext);
		
//DESTRUCTOR
		~Neuron();
};

#endif
