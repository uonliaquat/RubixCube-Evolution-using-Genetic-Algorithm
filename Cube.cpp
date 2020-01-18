#include "../include/Cube.hpp"

Cube::Cube(int size){
    this->size = size; 
    for(int i = 0; i < 6; i++){
       Matrix * side = new Matrix(size, size, i);
        this->sides.push_back(side);
    }
}

Cube::Cube(vector<Matrix *> sides){
    if(sides.size() != 6){
        cerr << "There must be only 6 sides of RubixCube!" << endl;
        assert(false);
    }
    for(int i = 0; i < 6; i++){
        if(!sides.at(i)->isSquare()){
            cerr << "RubixCube must be in square shape!" << endl;
            assert(false);
        }
    }
    for(int i = 0; i < 5; i++){
        if(sides.at(i)->getSize() != sides.at(i + 1)->getSize()){
            cerr << "Size of all 6 sides must be equal!" << endl;
            assert(false);
        }
    }

    this->size = sides.at(0)->getRows();

    for(int i = 0; i < 6; i++){
        Matrix * side = new Matrix(sides.at(i)->getData());
        this->sides.push_back(side);
    }
}
Cube::~Cube(){
    for(int i = 0; i < 6; i++){
        delete this->sides.at(i);
    }
}

vector<int8_t> Cube::getEdge(int8_t side, int8_t no){
    vector<int8_t> edge;
    switch(no){
        case 0:
            edge.push_back(this->getSides().at(side)->getData().at(0).at(1));
            break;
        case 1:
            edge.push_back(this->getSides().at(side)->getData().at(1).at(2));
            break;
        case 2:
            edge.push_back(this->getSides().at(side)->getData().at(2).at(1));
            break;
        case 3:
            edge.push_back(this->getSides().at(side)->getData().at(1).at(0));
            break;
    }
    switch(side){
        case FRONT:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(TOP)->getData().at(2).at(1));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(RIGHT)->getData().at(1).at(0));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(DOWN)->getData().at(0).at(1));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(LEFT)->getData().at(1).at(2));
                    break;
            }
            break;
        case BACK:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(TOP)->getData().at(0).at(1));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(LEFT)->getData().at(1).at(0));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(DOWN)->getData().at(2).at(1));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(RIGHT)->getData().at(1).at(2));
                    break;
            }
            break;
        case LEFT:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(TOP)->getData().at(1).at(0));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(FRONT)->getData().at(1).at(0));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(DOWN)->getData().at(1).at(0));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(BACK)->getData().at(1).at(2));
                    break;
            }
            break;
        case RIGHT:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(TOP)->getData().at(1).at(2));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(BACK)->getData().at(1).at(0));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(DOWN)->getData().at(1).at(2));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(FRONT)->getData().at(1).at(2));
                    break;
            }
            break;
        case TOP:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(BACK)->getData().at(0).at(1));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(RIGHT)->getData().at(0).at(1));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(FRONT)->getData().at(0).at(1));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(LEFT)->getData().at(0).at(1));
                    break;
            }
            break;
        case DOWN:
            switch(no){
                case 0:
                    edge.push_back(this->getSides().at(FRONT)->getData().at(2).at(1));
                    break;
                case 1:
                    edge.push_back(this->getSides().at(RIGHT)->getData().at(2).at(1));
                    break;
                case 2:
                    edge.push_back(this->getSides().at(BACK)->getData().at(2).at(1));
                    break;
                case 3:
                    edge.push_back(this->getSides().at(LEFT)->getData().at(2).at(1));
                    break;
            }
            break; 
    }
    return edge;
}

vector<int8_t> Cube::getCorner(int8_t side, int8_t no){
    vector<int8_t> corner;
    switch(no){
        case 0:
            corner.push_back(this->getSides().at(side)->getData().at(0).at(0));
            break;
        case 1:
            corner.push_back(this->getSides().at(side)->getData().at(0).at(2));
            break;
        case 2:
            corner.push_back(this->getSides().at(side)->getData().at(2).at(2));
            break;
        case 3:
            corner.push_back(this->getSides().at(side)->getData().at(2).at(0));
            break;
    }
    switch(side){
        case FRONT:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(LEFT)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(TOP)->getData().at(2).at(0));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(TOP)->getData().at(2).at(2));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(0).at(2));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(LEFT)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(0).at(0));
                    break;
            }
            break;
        case BACK:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(TOP)->getData().at(0).at(2));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(LEFT)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(TOP)->getData().at(0).at(0));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(LEFT)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(2).at(0));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(2).at(2));
                    break;
            }
            break;
        case LEFT:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(BACK)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(TOP)->getData().at(0).at(0));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(TOP)->getData().at(2).at(0));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(0).at(0));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(BACK)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(2).at(0));
                    break;
            }
            break;
        case RIGHT:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(TOP)->getData().at(2).at(2));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(BACK)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(TOP)->getData().at(0).at(2));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(BACK)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(2).at(2));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(DOWN)->getData().at(0).at(2));
                    break;
            }
            break;
        case TOP:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(BACK)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(LEFT)->getData().at(0).at(0));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(BACK)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(0).at(2));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(0).at(2));
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(0).at(0));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(0).at(0));
                    corner.push_back(this->getSides().at(LEFT)->getData().at(0).at(2));
                    break;
            }
            break;
        case DOWN:
            switch(no){
                case 0:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(LEFT)->getData().at(2).at(2));
                    break;
                case 1:
                    corner.push_back(this->getSides().at(FRONT)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(2).at(0));
                    break;
                case 2:
                    corner.push_back(this->getSides().at(BACK)->getData().at(2).at(0));
                    corner.push_back(this->getSides().at(RIGHT)->getData().at(2).at(2));
                    break;
                case 3:
                    corner.push_back(this->getSides().at(BACK)->getData().at(2).at(2));
                    corner.push_back(this->getSides().at(LEFT)->getData().at(2).at(0));
                    break;
            }
            break;

    }
    return corner;
}

vector<int8_t> Cube::getCenter(int8_t side, bool isEdge, int8_t no){
    vector<int8_t> center;
    center.push_back(this->getSides().at(side)->getData().at(1).at(1));
    if(isEdge){
        switch(side){
            case FRONT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                }
                break;
            case BACK:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                }
                break;
            case LEFT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        break;
                }
                break;
            case RIGHT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        break;
                }
                break;
            case TOP:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                }
                break;
            case DOWN:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                }
                break;
        }
    }
    else{
         switch(side){
            case FRONT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                }
                break;
            case BACK:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                }
                break;
            case LEFT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                }
                break;
            case RIGHT:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(TOP)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(DOWN)->getData().at(1).at(1));
                        break;
                }
                break;
            case TOP:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                }
                break;
            case DOWN:
                switch(no){
                    case 0:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                    case 1:
                        center.push_back(this->getSides().at(FRONT)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 2:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(RIGHT)->getData().at(1).at(1));
                        break;
                    case 3:
                        center.push_back(this->getSides().at(BACK)->getData().at(1).at(1));
                        center.push_back(this->getSides().at(LEFT)->getData().at(1).at(1));
                        break;
                }
                break;
        }

    }
    return center;
}



void Cube::printVertically(){
    for(int i = 0; i < 6; i++){
        cout << getSideName(i) << endl; 
        this->sides.at(i)->print();
        cout << endl;
    }
    cout<<endl<<endl;
}

void Cube::printHorizontally(){
    for(int i = 0; i < 6; i++){
        cout<<getSideName(i)<<" \t\t";
    }
    cout<<endl;
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < 6; j++){
            this->sides.at(j)->print(i);
            cout<<" \t\t";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void Cube::scramble(){
    int noOfMoves = rand() % 50 + 20;
    for(int i = 0; i < noOfMoves; i++){
        uint8_t side = rand() % 6;
        bool clockWise = rand() % 2;
        rotate(side, clockWise);
    }
}

Cube * Cube::copy(Cube * cube){
    Cube * newCube = new Cube(cube->getSides());
    return newCube;
}

void Cube::rotate(int8_t side, int8_t rotation){
    this->sides.at(side)->transpose(rotation);
    switch(side){
        case FRONT:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 2, true, this->sides.at(RIGHT), 0, false, false);
                Matrix::swap(this->sides.at(LEFT), 2, false, this->sides.at(TOP), 2, true, true);
                Matrix::swap(this->sides.at(DOWN), 0, true, this->sides.at(LEFT), 2, false, false);
            }
            else if(rotation == ANTI_CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 2, true, this->sides.at(LEFT), 2, false, true);
                Matrix::swap(this->sides.at(RIGHT), 0, false, this->sides.at(TOP), 2, true, false);
                Matrix::swap(this->sides.at(DOWN), 0, true, this->sides.at(RIGHT), 0, false, true);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(FRONT, CLOCK_WISE);
                Cube::rotate(FRONT, CLOCK_WISE);
            }
            break;
        case BACK:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 0, true, this->sides.at(LEFT), 0, false, true);
                Matrix::swap(this->sides.at(RIGHT), 2, false, this->sides.at(TOP), 0, true, false);
                Matrix::swap(this->sides.at(DOWN), 2, true, this->sides.at(RIGHT), 2, false, true);
            }
            else if(rotation == ANTI_CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 0, true, this->sides.at(RIGHT), 2, false, false);
                Matrix::swap(this->sides.at(LEFT), 0, false, this->sides.at(TOP), 0, true, true);
                Matrix::swap(this->sides.at(DOWN), 2, true, this->sides.at(LEFT), 0, false, false);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(BACK, CLOCK_WISE);
                Cube::rotate(BACK, CLOCK_WISE);
            }
            break;
        case LEFT:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 0, false, this->sides.at(FRONT), 0, false, false);
                Matrix::swap(this->sides.at(BACK), 2, false, this->sides.at(TOP), 0, false, true);
                Matrix::swap(this->sides.at(DOWN), 0, false, this->sides.at(BACK), 2, false, true);
            }
            else if(rotation == ANTI_CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 0, false, this->sides.at(BACK), 2, false, true);
                Matrix::swap(this->sides.at(FRONT), 0, false, this->sides.at(TOP), 0, false, false);
                Matrix::swap(this->sides.at(DOWN), 0, false, this->sides.at(FRONT), 0, false, false);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(LEFT, CLOCK_WISE);
                Cube::rotate(LEFT, CLOCK_WISE);
            }
            break;
        case RIGHT:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 2, false, this->sides.at(BACK), 0, false, true);
                Matrix::swap(this->sides.at(FRONT), 2, false, this->sides.at(TOP), 2, false, false);
                Matrix::swap(this->sides.at(DOWN), 2, false, this->sides.at(FRONT), 2, false, false);
            }
            else if(rotation == ANTI_CLOCK_WISE){
                Matrix::swap(this->sides.at(TOP), 2, false, this->sides.at(FRONT), 2, false, false);
                Matrix::swap(this->sides.at(BACK), 0, false, this->sides.at(TOP), 2, false, true);
                Matrix::swap(this->sides.at(DOWN), 2, false, this->sides.at(BACK), 0, false, true);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(RIGHT, CLOCK_WISE);
                Cube::rotate(RIGHT, CLOCK_WISE);
            }
            break;
        case TOP:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(FRONT), 0, true, this->sides.at(LEFT), 0, true, false);
                Matrix::swap(this->sides.at(RIGHT), 0, true, this->sides.at(FRONT), 0, true, false);
                Matrix::swap(this->sides.at(BACK), 0, true, this->sides.at(RIGHT), 0, true, false);
            }
            else if(rotation == ANTI_CLOCK_WISE){ 
                Matrix::swap(this->sides.at(FRONT), 0, true, this->sides.at(RIGHT), 0, true, false);
                Matrix::swap(this->sides.at(LEFT), 0, true, this->sides.at(FRONT), 0, true, false);
                Matrix::swap(this->sides.at(BACK), 0, true, this->sides.at(LEFT), 0, true, false);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(TOP, CLOCK_WISE);
                Cube::rotate(TOP, CLOCK_WISE);
            }
            break;
        case DOWN:
            if(rotation == CLOCK_WISE){
                Matrix::swap(this->sides.at(FRONT), 2, true, this->sides.at(RIGHT), 2, true, false);
                Matrix::swap(this->sides.at(LEFT), 2, true, this->sides.at(FRONT), 2, true, false);
                Matrix::swap(this->sides.at(BACK), 2, true, this->sides.at(LEFT), 2, true, false);
            }
            else if(rotation == ANTI_CLOCK_WISE){
                Matrix::swap(this->sides.at(FRONT), 2, true, this->sides.at(LEFT), 2, true, false);
                Matrix::swap(this->sides.at(RIGHT), 2, true, this->sides.at(FRONT), 2, true, false);
                Matrix::swap(this->sides.at(BACK), 2, true, this->sides.at(RIGHT), 2, true, false);
            }
            else if(rotation == DOUBLE_CLOCK_WISE){
                Cube::rotate(DOWN, CLOCK_WISE);
                Cube::rotate(DOWN, CLOCK_WISE);
            }
            break;
    }           
}

string Cube::getSideName(int8_t sideNo){
    switch(sideNo){
        case FRONT:     return "F";
        case BACK:      return "B";
        case LEFT:      return "L";
        case RIGHT:     return "R";
        case TOP:       return "T";
        case DOWN:      return "D";
    }
    return NULL;
}

string Cube::getRotationSign(int8_t rotation){
    switch(rotation){
        case CLOCK_WISE:        return "";
        case ANTI_CLOCK_WISE:   return "'";
        case DOUBLE_CLOCK_WISE: return "2";
    }
    return "";
}

