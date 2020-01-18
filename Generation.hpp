#ifndef _GENERATION_HPP_
#define _GENERATION_HPP_

#include <iostream>
#include <vector>
#include "../include/DNA.hpp"
#define SP              0
#define RANDOM_RESET    0

using namespace std;

class Generation{
    private:
        vector<DNA *> dna;

    public:
        Generation();
        Generation(int, int);
        static void evaluateFitness(Generation *, Cube *);
        void print();
        static void sort(Generation *);
        static DNA * select(Generation *);
        static void crossover(Generation *, Generation *, int, double);
        static void mutate(Generation *, Generation *, int, double);
        static void selectTopFit(Generation *, Generation *, double);
        static void selectAllKind(Generation *, Generation *, double);
        static void generateRandom(Generation *, Generation *, double);
        int getSize(){ return dna.size(); }
        void setDNA(int index, DNA * dna){ this->dna.at(index) = dna; }
        vector<DNA *> getDNAs(){ return dna; };
        void addDNA(DNA *);



};

#endif
