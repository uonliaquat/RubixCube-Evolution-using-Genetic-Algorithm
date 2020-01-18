#ifndef _DNA_HPP_
#define _DNA_HPP_

#include <iostream>
#include "../include/Gene.hpp"

#define SP              0
#define RANDOM_RESET    0

#define FRONT           0
#define BACK            1
#define LEFT            2
#define RIGHT           3
#define TOP             4
#define DOWN            5

using namespace std;

class DNA{
    private:
        vector<Gene *> genes;
        int8_t fitness, split;

    public:
        DNA(int);
        DNA(vector<Gene *>);
        ~DNA();


        void print();
        int getSize(){ return genes.size(); }
        vector<Gene *> getGenes(){ return genes; }
        void setGene(int index, Gene * gene){ this->genes.at(index) = gene; }
        int8_t getFitness(){ return fitness; };
        void setFitness(int8_t fitness){ this->fitness = fitness; }
        int8_t getSplit(){ return split; }
        void setSplit(int8_t split){ this->split = split; }
         

        static DNA * crossover(DNA *, DNA *, int);
        static void mutate(DNA *, int);
        static void evaluateFitness(DNA * dna, Cube * cube);
        static DNA * copy(DNA *);
        static DNA * copy(DNA *, int, int);
        static DNA * combine(DNA *, DNA*);

};

#endif
