#include "../include/Generation.hpp"

Generation::Generation(){

}

Generation::Generation(int size, int dnaSize){
    for(int i = 0; i < size; i++){
        DNA * dna = new DNA(dnaSize);
        this->dna.push_back(dna);
    }
}

void Generation::addDNA(DNA * dna){
    this->dna.push_back(dna);
}

void Generation::sort(Generation * g){
    for(int i = 0; i < g->getSize() - 1; i++){
        for(int j = i + 1; j < g->getSize(); j++){
            if(g->getDNAs().at(i)->getFitness() >
                g->getDNAs().at(j)->getFitness()){
                DNA * temp = g->getDNAs().at(i);
                g->setDNA(i, g->getDNAs().at(j));
                g->setDNA(j, temp);
            }
        }
    }
}

void Generation::evaluateFitness(Generation * g, Cube * cube){
    for(int i = 0; i < g->getSize(); i++){
        DNA::evaluateFitness(g->getDNAs().at(i), cube);
    }
}

DNA * Generation::select(Generation * g){
    int index = Gene::generateRandomNo(0, g->getSize() - 1);
    return(DNA::copy(g->getDNAs().at(index)));
}

void Generation::crossover(Generation * old_g, Generation * new_g, int type, double rate){
    for(int i = 0; i < old_g->getSize() * rate; i++){
        DNA * dna1 = select(old_g);
        DNA * dna2 = select(old_g);
        DNA * newDNA = DNA::crossover(dna1, dna2, type);
        new_g->addDNA(newDNA);
    }
        
}

void Generation::mutate(Generation * old_g, Generation * new_g, int type, double rate){
    for(int i = 0; i < old_g->getSize() * rate; i++){
        DNA * dna = select(old_g);
        DNA::mutate(dna, type);
        new_g->addDNA(dna);
    }
}

void Generation::selectTopFit(Generation * old_g, Generation * new_g, double rate){
    sort(old_g);
    for(int i = 0; i < old_g->getSize() * rate; i++){
        DNA * dna = DNA::copy(old_g->getDNAs().at(i));
        new_g->addDNA(dna);
    }
}

void Generation::selectAllKind(Generation * old_g, Generation * new_g, double rate){
    sort(old_g);
    vector<int> point;
    point.push_back(-1);
    for(int i = 1; i < old_g->getSize() - 1; i++){
        if(old_g->getDNAs().at(i)->getFitness() != old_g->getDNAs().at(i - 1)->getFitness()){
            point.push_back(i - 1);
        }
    }
    point.push_back(old_g->getSize() - 1);
    for(int i = 0; i < point.size() - 1; i++){
        int rand = Gene::generateRandomNo(point.at(i) + 1, point.at(i + 1));
        new_g->addDNA(DNA::copy(old_g->getDNAs().at(rand)));
    }
    for(int i = point.size(); i < old_g->getSize() * rate; i++){
        new_g->addDNA(new DNA(old_g->getDNAs().at(0)->getSize()));
    }
}

void Generation::generateRandom(Generation * old_g, Generation * new_g, double rate){
    for(int i = 0; i < old_g->getSize() * rate; i++){
        old_g->addDNA(new DNA(old_g->getDNAs().at(0)->getSize()));
    }
}

void Generation::print(){
    cout<<endl;
    for(int i = 0; i < this->dna.size(); i++){
        cout<<"DNA: "<< i <<endl;
        this->dna.at(i)->print();
        cout<<"Fitness: "<<(int)this->dna.at(i)->getFitness()<<endl;
    }
}
