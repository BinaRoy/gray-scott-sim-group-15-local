# Gray-Scott Reaction-Diffusion Simulation

## Project Overview
This project simulates the Gray-Scott reaction-diffusion system, a model that describes the interaction of two chemical substances. It's implemented in C++ and uses CMake for building. The project also includes a suite of unit tests.

## Prerequisites
- C++ Compiler (e.g., GCC, Clang)
- CMake (version 3.10 or higher)
- Make

## Building the Application
1. **Clone the Repository**: First, clone the repository to your local machine.

git clone gray-scott-sim-group-15
cd gray-scott-sim-group-15

2. **Create a Build Directory**: This is where all build-related files will be stored.

mkdir build && cd build

3. **Generate Build System**: Run CMake to create the build system.

cmake ..

4. **Compile the Application**: Use Make to compile the source code.

make

5. After these steps, you should find the executable in the `build` directory.

## Running the Simulation
To run the simulation, execute the compiled binary from the build directory:
./GrayScottSimulation

## Running Tests
The project includes a set of unit tests to verify the functionality:

1. After building the application, the test binary will also be compiled in the `build` directory.

2. Run the tests by executing:

./GrayScottSimulationTests

3. The output will show the results of each test.
