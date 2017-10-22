#include <iostream>
#include "neuron.hpp"
#include "gtest/gtest.h"

TEST(NeuronTest, MembranePotential) {
	Neuron neuron;
	
	neuron.updatePotential(1.0);
	
	EXPECT_NEAR(20.0*(1.0-std::exp(-0.1/20.0)), neuron.getPotential(), std::pow(10, -6));
} //TEST IF THE MEMBRANE POTENTIAL IS COMPUTED CORRECTLY

TEST(NeuronTest, Spike) {
	Neuron neuron;
	
	neuron.setTime(100);
	
	while(neuron.getTime() < 200) {
		neuron.simulationLoop(1.01);
		if(neuron.isSpiking()) {
			EXPECT_NEAR(192.4, neuron.getTime(), std::pow(10, -6));
		}
	}
} //TEST IF THE SPIKE ARRIVES AT THE RIGHT TIME


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
