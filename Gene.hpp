#ifndef _GENE_HPP_

#include <iostream>
#include <random>
#include <iterator>
#include "../include/Cube.hpp"

#define FRONT                   0
#define BACK                    1
#define LEFT                    2
#define RIGHT                   3
#define TOP                     4
#define DOWN                    5

#define ANTI_CLOCK_WISE         -1
#define DOUBLE_CLOCK_WISE       0
#define CLOCK_WISE              1

using namespace std;

class Gene{

    private:
        int8_t side, rotation;

    public:
        Gene();
        Gene(int8_t side, int8_t rotation);

        int8_t getSide(){ return side; }
        int8_t getRotation(){ return rotation; }
        void print();

        static Gene * copy(Gene *);
        static int generateRandomNo(int, int);
    
};

#endif
