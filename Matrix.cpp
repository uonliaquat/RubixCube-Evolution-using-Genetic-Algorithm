#include "../include/Matrix.hpp"

Matrix::Matrix(int rows, int cols){
    this->rows = rows;
    this->cols = cols;

    for(int i = 0; i < rows; i++){
        vector<int> row;
        for(int j = 0; j < cols; j++){
            row.push_back(0);
        }
        this->data.push_back(row);
    }
}

Matrix::Matrix(int rows, int cols, int value){
    this->rows = rows;
    this->cols = cols;

    for(int i  = 0; i < rows; i++){
        vector<int> row;
        for(int j = 0; j < cols; j++){
            row.push_back(value);
        }
        this->data.push_back(row);
    }
}

Matrix::Matrix(vector<vector<int>> data){
    for(int i = 0; i < data.size() - 1; i++){
        if(data.at(i).size() != data.at(i + 1).size()){
            cerr << "No of Cols must be equal for all rows!" << endl;
            assert(false);
        }
    }

    this->rows = data.size();
    this->cols = data.at(0).size();

    for(int i = 0; i < this->rows; i++){
        vector<int> row;
        for(int j = 0; j < this->cols; j++){
            row.push_back(data.at(i).at(j));
        }
        this->data.push_back(row);
    }
}

void Matrix::transpose(int rotation){
    Matrix * temp = copy(this);
    if(rotation == CLOCK_WISE){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                this->data.at(i).at(j) = 
                    temp->getData().at(temp->getRows() - j - 1).at(i);
            }
        }
    }
    else if(rotation == ANTI_CLOCK_WISE){
        for(int i = 0; i < this->rows; i++){
            for(int j = 0; j < this->cols; j++){
                this->data.at(i).at(j) =
                    temp->getData().at(j).at(temp->getCols() - i - 1);
            }
        } 
    }
    else if(rotation == DOUBLE_CLOCK_WISE){
        Matrix::transpose(CLOCK_WISE);
        Matrix::transpose(CLOCK_WISE);
    }
    delete temp;
}

void Matrix::print(){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            cout << this->data.at(i).at(j) << " ";
        }
        cout<<endl;
    }
}

void Matrix::print(int rowNo){
    for(int j = 0; j < this->cols; j++){
         cout << this->data.at(rowNo).at(j) << " ";
    }
}

bool Matrix::isSquare(){
    if(this->rows == this->cols){
        return true;
    }
    return false;
}

Matrix * Matrix::copy(Matrix * matrix){
    Matrix * newMatrix = new Matrix(matrix->getRows(), matrix->getCols());
    for(int i = 0; i < newMatrix->getRows(); i++){
        for(int j = 0; j < newMatrix->getCols(); j++){
            newMatrix->setValue(i, j, matrix->getValue(i, j));
        }
    }
    return newMatrix;
}

void Matrix::swap(Matrix * a, int index_a, bool row_a, Matrix * b, int index_b, bool row_b, bool reverse){

    int temp;
    if(row_a && row_b){
        if(a->getCols() != b->getCols()){
            cerr << "Cols of both Matrices must be equal!" << endl;
            assert(false);
        }
       for(int i = 0; i < b->getCols(); i++){
            temp = b->getValue(index_b, i);
            if(reverse){
                b->setValue(index_b, i, a->getValue(index_a, a->getCols() - i - 1));
                a->setValue(index_a, a->getCols() - i - 1, temp);
            }
            else{
                b->setValue(index_b, i, a->getValue(index_a, i));
                a->setValue(index_a, i, temp);
            }
       }
    }
    else if(row_a && !row_b){
        if(a->getCols() != b->getRows()){
            cerr << "Cols of Matrix A must be equal to Rows of Matrix b!" << endl;
            assert(false);
        }
        for(int i = 0; i < b->getRows(); i++){
            temp = b->getValue(i, index_b);
            if(reverse){
                b->setValue(i, index_b, a->getValue(index_a, a->getCols() - i - 1));
                a->setValue(index_a, a->getCols() - i - 1, temp);
            }
            else{
                b->setValue(i, index_b, a->getValue(index_a, i));
                a->setValue(index_a, i, temp);
            }
        }
    }
    else if(!row_a && row_b){
        if(a->getRows() != b->getCols()){
            cerr << "Rows of Matrix A must be euqal to Cols of Matrix b!" << endl;
            assert(false);
        }
        for(int i = 0; i < b->getCols(); i++){
            temp = b->getValue(index_b, i);
            if(reverse){
                b->setValue(index_b, i, a->getValue(a->getRows() - i - 1, index_a));
                a->setValue(a->getRows() - i - 1, index_a, temp);
            }
            else{
                b->setValue(index_b, i, a->getValue(i, index_a));
                a->setValue(i, index_a, temp);
            }
        }
    }
    else if(!row_a && !row_b){
        if(a->getRows() != b->getCols()){
            cerr << "Rows of both Matrices must be equal!" << endl;
            assert(false);
        }
        for(int i = 0; i < b->getRows(); i++){
            temp = b->getValue(i, index_b);
            if(reverse){
                b->setValue(i, index_b, a->getValue(a->getRows() - i - 1, index_a));
                a->setValue(a->getRows() - i - 1, index_a, temp);
            }
            else{
                b->setValue(i, index_b, a->getValue(i, index_a));
                a->setValue(i, index_a, temp);
            }
        }
    }
}

