# Freedericksz
This program simulates liquid crystals in an electric field, outputting the average diffraction coefficient they generate.

# Setup
The main program requires the Boost library, and will require SDL2 for visualization. If visualization is not required, You can remove the VISOR_ENABLE definition from main.cpp and -lSDL2 from the makefile. An automated framework for running multiple instances of this program multicore is provided in the form of the shell scripts. you only need to run doall.sh although init.py and run.sh contain variables you may wish to change. After runnning doall.sh, plot.dat will contain data points to visualize, showing the freedericksz transition occur 
