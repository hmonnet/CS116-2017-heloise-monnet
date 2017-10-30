#!/bin/bash

rm spikes.txt
rm nbSpikes.txt

cmake ..
make
./neuron

python graph.py
