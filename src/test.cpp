#include <iostream>
#include "neuron.hpp"
#include "gtest/gtest.h"

TEST(OneNeuron, PositiveCurrent) {
	Neuron neuron;
	neuron.setIext(1.0);
	
	neuron.simulationLoop(1);
	EXPECT_NEAR(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getPotential(), 1e-3);
	//with a Iext of 1.00, membrane potential after one simulation loop 
	
	neuron.simulationLoop(1000);
	EXPECT_NEAR(20.0, neuron.getPotential(), 2e-1);
	//with an Iext of 1.00, membrane potential expected to be near 20.0 after 1000 simulation loops
	
	neuron.setIext(0.0);
	neuron.simulationLoop(1000);
	EXPECT_NEAR(0.0, neuron.getPotential(), 2e-1);
	//with an Iext of 0, membrane potential expected to be near 0.0 after 1000 simulation loops
	
} //TEST IF THE MEMBRANE POTENTIAL IS COMPUTED CORRECTLY WITH A POSITIVE CURRENT

TEST(OneNeuron, NegativeCurrent) {
	Neuron neuron;
	neuron.setIext(-1.0);
	
	neuron.simulationLoop(1);
	EXPECT_NEAR(-20.0*(1.0-std::exp(-0.1/20.0)), neuron.getPotential(), 1e-3);
	//with a Iext of -1.00, membrane potential after one simulation loop 
	
	neuron.simulationLoop(1000);
	EXPECT_NEAR(-20.0, neuron.getPotential(), 2e-1);
	//with an Iext of -1.00, membrane potential expected to be near -20.0 after 1000 simulation loops
	
} //TEST IF THE MEMBRANE POTENTIAL IS COMPUTED CORRECTLY WITH A NEGATIVE CURRENT


TEST(OneNeuron, SpikeTimes) {
	Neuron neuron;
	neuron.setIext(1.01);
	
	neuron.simulationLoop(923);
	EXPECT_EQ(0, neuron.getNbSpikes());
	neuron.simulationLoop(1);
	EXPECT_EQ(1, neuron.getNbSpikes());
	//with a Iext of 1.01 => first spike expected at time 92.4
	
	neuron.simulationLoop(943);
	EXPECT_EQ(1, neuron.getNbSpikes());
	neuron.simulationLoop(1);
	EXPECT_EQ(2, neuron.getNbSpikes());
	//with a Iext of 1.01 => second spike expected at time 186.8

} //TEST IF THE SPIKE ARRIVES AT THE RIGHT TIME

TEST(TwoNeurons, NoPSSpike) {
	Neuron neuron1(1, 0.1), neuron2(2, 0.1);
	int delay(15);
	neuron1.setIext(1.01);
	
	for(int i(0); i < (924+delay); ++i) {	
		neuron1.simulationLoop(1);
		if(neuron1.isSpiking()) {
			neuron2.setBuffer((i+delay) % 16, 0.1);
			EXPECT_EQ(0.0, neuron2.getPotential());
		}
		neuron2.simulationLoop(1);
	}
	
	EXPECT_NEAR(0.1, neuron2.getPotential(), 1e-2);	
} //TEST IF THE SECOND NEURON (IEXT = 0) RECEIVES  A J WITH THE CORRECT DELAY WHEN THE FIRST NEURON SPIKE

TEST(TwoNeurons, WithPSSpike) {
	Neuron neuron1(1, 0.1), neuron2(2, 0.1);
	int delay(15);
	neuron1.setIext(1.01);
	neuron2.setIext(1.00);
	
	for(int i(0); i < (1868+delay); ++i) {	
		neuron1.simulationLoop(1);
		if(neuron1.isSpiking()) {
			neuron2.setBuffer((i+delay) % 16, 0.1);
			EXPECT_EQ(0, neuron2.getNbSpikes());
		}
		neuron2.simulationLoop(1);
	}
	
	EXPECT_EQ(1, neuron2.getNbSpikes());	
} //TEST IF THE SECOND NEURON (IEXT = 1.00) SPIKES THANKS TO THE J RECEIVED FROM THE SPIKE OF THE FIRST NEURON


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
