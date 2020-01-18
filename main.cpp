#include <iostream>
#include <utility>
#include <string>
#include <ctime>
#include "../include/Cube.hpp"
#include "../include/Generation.hpp"

#define W 0
#define Y 1
#define B 2
#define G 3
#define P 4
#define O 5

using namespace std;

void GA(Cube *);

int main(){
    srand(time(NULL));
  
    //cube state
    vector<Matrix * > sides;

    //FRONT->WHITE
    Matrix * front = new Matrix(3,3);
    front->setValue(0, 0, W);
    front->setValue(0, 1, W);
    front->setValue(0, 2, W);
    front->setValue(1, 0, W);
    front->setValue(1, 1, W);
    front->setValue(1, 2, W);
    front->setValue(2, 0, W);
    front->setValue(2, 1, W);
    front->setValue(2, 2, W);
    sides.push_back(front);

    //BACK->YELLOW
    Matrix * back = new Matrix(3,3);
    back->setValue(0, 0, Y);
    back->setValue(0, 1, Y);
    back->setValue(0, 2, Y);
    back->setValue(1, 0, Y);
    back->setValue(1, 1, Y);
    back->setValue(1, 2, Y);
    back->setValue(2, 0, Y);
    back->setValue(2, 1, Y);
    back->setValue(2, 2, Y);
    sides.push_back(back);

    //LEFT->BLUE
    Matrix * left = new Matrix(3,3);
    left->setValue(0, 0, B);
    left->setValue(0, 1, B);
    left->setValue(0, 2, B);
    left->setValue(1, 0, B);
    left->setValue(1, 1, B);
    left->setValue(1, 2, B);
    left->setValue(2, 0, B);
    left->setValue(2, 1, B);
    left->setValue(2, 2, B);
    sides.push_back(left);
    
    
    //RIGHT->GREEN
    Matrix * right = new Matrix(3,3);
    right->setValue(0, 0, G);
    right->setValue(0, 1, G);
    right->setValue(0, 2, G);
    right->setValue(1, 0, G);
    right->setValue(1, 1, G);
    right->setValue(1, 2, G);
    right->setValue(2, 0, G);
    right->setValue(2, 1, G);
    right->setValue(2, 2, G);
    sides.push_back(right);
    
    //UP->PINK
    Matrix * up = new Matrix(3,3);
    up->setValue(0, 0, P);
    up->setValue(0, 1, P);
    up->setValue(0, 2, P);
    up->setValue(1, 0, P);
    up->setValue(1, 1, P);
    up->setValue(1, 2, P);
    up->setValue(2, 0, P);
    up->setValue(2, 1, P);
    up->setValue(2, 2, P);
    sides.push_back(up);
    
    //DOWN->ORANNGE
    Matrix * down = new Matrix(3,3);
    down->setValue(0, 0, O);
    down->setValue(0, 1, O);
    down->setValue(0, 2, O);
    down->setValue(1, 0, O);
    down->setValue(1, 1, O);
    down->setValue(1, 2, O);
    down->setValue(2, 0, O);
    down->setValue(2, 1, O);
    down->setValue(2, 2, O);
    sides.push_back(down);
    


    Cube * cube = new Cube(sides);

    for(int i = 0; i < 2; i++){
        cube->rotate(3, 1);
        cube->rotate(4, 1);
    }
    cube->printHorizontally();
    //DNA * dna = new DNA(1);
    //cout<<"DNA: ";
    //dna->print();
    //cout<<endl;
    //DNA::evaluateFitness(dna, cube);
    //cout<<"Fitness: "<<(int)dna->getFitness()<<endl;


    GA(cube); 
     
    return 0;
}

void GA(Cube * cube){
    int generation = 0;
    int hf = 0;
    Generation * nextGen;
    Generation * currentGen = new Generation(100, 50);
    Generation::evaluateFitness(currentGen, cube);
    Generation::sort(currentGen);
    hf = (int)currentGen->getDNAs().at(0)->getFitness();
    cout << "Generation: " << generation++ << " \t\tHF: " << hf <<endl;
    while(hf != 0){
        nextGen = new Generation();
        //Generation::generateRandom(currentGen, nextGen, 0.1);
        //Generation::selectTopFit(currentGen, nextGen, 0.1);
        Generation::selectAllKind(currentGen, nextGen, 0.1);
        Generation::crossover(currentGen, nextGen, 0, 0.8);
        Generation::mutate(currentGen, nextGen, 0, 0.1);
        Generation::evaluateFitness(nextGen, cube);
        Generation::sort(nextGen);
        hf = (int) nextGen->getDNAs().at(0)->getFitness();
        cout << "Generation: " << generation++ << " \t\tHF: " << hf <<endl;
        delete currentGen;
        currentGen = nextGen;
        //currentGen->print();
    }

    cout<<endl<<"Solution: ";
    nextGen->getDNAs().at(0)->print();
    cout<<endl<<"Split: "<<(int)nextGen->getDNAs().at(0)->getSplit()<<endl;
    
}
