#include <iostream>
#include "neuron.hpp"
#include "gtest/gtest.hpp"

TEST(NeuronTest, MembranePotential) {
	Neuron neuron;
	neuron.set_i_ext(1.0);
	
	neuron.update(1);
	EXPECT_EQ(20.0*(1.0-std::exp(-0.1/20.0)), neuron.get_v_m());
} //EXAMPLE OF TEST


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS(); 
}
