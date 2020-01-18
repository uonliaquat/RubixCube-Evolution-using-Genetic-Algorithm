#include "../include/DNA.hpp"

DNA::DNA(int size){
    for(int i = 0; i < size; i++){
        Gene * gene;
        if(i > 0){
            do{
                gene = new Gene();
            }while(this->genes.at(i - 1)->getSide() == gene->getSide());
            this->genes.push_back(gene);
        }
        else{
            gene = new Gene();
            this->genes.push_back(gene);
        }
    }
}

DNA::DNA(vector<Gene *> genes){
    for(int i = 0; i< genes.size(); i++){
        this->genes.push_back(Gene::copy(genes.at(i)));
    }
}

DNA::~DNA(){
    for(int i = 0; i < this->genes.size(); i++){
        delete this->genes.at(i);
    }
}

void DNA::print(){
    for(int i = 0; i < this->genes.size(); i++){
        this->genes.at(i)->print();
        cout<<" ";
    }
}

DNA * DNA::crossover(DNA * dna1, DNA * dna2, int type){
    DNA * offspring;
    switch(type){
        case SP:{
            int point = Gene::generateRandomNo(1, dna1->getSize() - 1);
            while(dna1->getGenes().at(point - 1)->getSide() == dna2->getGenes().at(point)->getSide()){
                point = Gene::generateRandomNo(1, dna1->getSize() - 1);
            }
            DNA * leftGenes = copy(dna1, 0, point);
            DNA * rightGenes = copy(dna2, point, dna2->getSize());
            offspring = combine(leftGenes, rightGenes);
            break;
        }
        
    }
    return offspring;
}

void DNA::mutate(DNA * dna, int type){
    switch(type){
        case RANDOM_RESET:{
            for(int i = 0; i < dna->getSize(); i++){
                int8_t rnd = Gene::generateRandomNo(0, 1);
                if(rnd == 1){
                    if(i > 0){
                        Gene * gene;
                        do{
                            gene = new Gene();
                        }while(dna->getGenes().at(i - 1)->getSide() == gene->getSide());
                        dna->setGene(i, gene);
                    }
                    else{
                        dna->setGene(i, new Gene());
                    }
                }
            }
        }
    }
}

void DNA::evaluateFitness(DNA * dna, Cube * cube){
    Cube * tempCube = Cube::copy(cube);
    int8_t fitness = 0;
    for(int i = 0; i < dna->getSize(); i++){
        tempCube->rotate(dna->getGenes().at(i)->getSide(), dna->getGenes().at(i)->getRotation());
        fitness = 0;
        /*for(int j = 0; j < 4; j++){
             //edges
            for(int k = 0; k < 4; k++){
                vector<int8_t> center = tempCube->getCenter(j, true, k); 
                vector<int8_t> edge = tempCube->getEdge(j, k);
                if(edge.at(0) == center.at(1) && edge.at(1) == center.at(0)){
                    fitness++;
                }
                else if((edge.at(0) == center.at(0) && edge.at(1) != center.at(1))
                || (edge.at(0) != center.at(0) && edge.at(1) == center.at(1))){
                    fitness = fitness + 2;
                }
                else if((edge.at(0) != center.at(1) && edge.at(1) != center.at(0))
                    &&  (edge.at(0) != center.at(0) && edge.at(1) != center.at(1))){
                    fitness = fitness+ 3;
                }  
                if(j > 1){
                    k++;
                }   
            }
            //corners
            if(j < 2){
                for(int k = 0; k < 4; k++){
                    vector<int8_t> center = tempCube->getCenter(j, false, k);
                    vector<int8_t> corner = tempCube->getCorner(j, k);
                    if((corner.at(0) == center.at(1) && corner.at(1) == center.at(2) && corner.at(2) == center.at(0))
                    || (corner.at(0) == center.at(2) && corner.at(2) == center.at(1) && corner.at(1) == center.at(0))){
                        fitness++;
                    }
                    else if((corner.at(0) == center.at(0) && corner.at(1) == center.at(1) && corner.at(2) != center.at(2)) 
                        || (corner.at(0) == center.at(0) && corner.at(1) != center.at(1) && corner.at(2) == center.at(2)) 
                        || (corner.at(0) != center.at(0) && corner.at(1) == center.at(1) && corner.at(2) == center.at(2))){
                        fitness = fitness + 2;
                    }
                    else if((corner.at(0) == center.at(0) && corner.at(1) != center.at(1) && corner.at(2) != center.at(2))
                        || (corner.at(1) == center.at(1) && corner.at(0) != center.at(0) && corner.at(2) != center.at(2)) 
                        || (corner.at(2) == center.at(2) && corner.at(0) != center.at(0) && corner.at(1) != center.at(1))) {
                        fitness = fitness + 3;
                    }
                    else if((corner.at(0) != center.at(0) && corner.at(1) != center.at(1)) && corner.at(2) != center.at(2)){
                        fitness = fitness + 4;

                    }  
                }

            }
        }*/

        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    if(tempCube->getSides().at(j)->getData().at(k).at(l) != 
                            tempCube->getSides().at(j)->getData().at(1).at(1)){
                        fitness++;
                    }
                }
            }
        }
        if(fitness == 0){
            dna->setFitness(fitness);
            dna->setSplit(i);
            return;
        }
    }
    dna->setFitness(fitness);

}

DNA * DNA::copy(DNA * dna){
    DNA * newDna = new DNA(dna->getGenes());
    newDna->setFitness(dna->getFitness());
    newDna->setSplit(dna->getSplit());
    return newDna;
}

DNA * DNA::copy(DNA * dna, int start, int end){
    vector<Gene *> genes;
    for(int i = start; i < end; i++){
        if(dna->getSize() > i){
            genes.push_back(dna->getGenes().at(i));
        }
    }
    DNA * newDna = new DNA(genes);
    return newDna;
}

DNA * DNA::combine(DNA * dna1, DNA * dna2){
    vector<Gene *> genes;
    for(int i = 0; i < dna1->getSize(); i++){
        genes.push_back(dna1->getGenes().at(i));
    }
    for(int i = 0; i < dna2->getSize(); i++){
        genes.push_back(dna2->getGenes().at(i));
    }
    DNA * dna = new DNA(genes);
    return dna;
}
