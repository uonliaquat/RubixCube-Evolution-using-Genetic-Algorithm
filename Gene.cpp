#include "../include/Gene.hpp"

Gene::Gene(){
    side = generateRandomNo(0,5);
    rotation = generateRandomNo(-1,1);
}

Gene::Gene(int8_t side, int8_t rotation){
    this->side = side;
    this->rotation = rotation;
}

Gene * Gene::copy(Gene * gene){
    Gene * newGene = new Gene(gene->getSide(), gene->getRotation());
    return newGene;
}

int Gene::generateRandomNo(int min, int max){
    random_device                   rand_dev;
    mt19937                         generator(rand_dev());
    uniform_int_distribution<int>   distr(min, max);
    return distr(generator);
}

void Gene::print(){
    cout << Cube::getSideName(this->side)
         << Cube::getRotationSign(this->rotation);
}


