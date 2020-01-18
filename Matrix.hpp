#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

#define CLOCK_WISE          1
#define ANTI_CLOCK_WISE     -1
#define DOUBLE_CLOCK_WISE   0

class Matrix{
    private:
        int rows, cols;
        vector<vector<int>> data;
    public:
        Matrix(int rows, int cols);
        Matrix(int rows, int cols, int value);
        Matrix(vector<vector<int>> data);
        void transpose(int clockWise);

        int getRows(){ return rows; }
        int getCols(){ return cols; }
        vector<vector<int>> getData(){ return data; }
        int getSize() { return (this->rows * this->cols); }
        bool isSquare();

        void setValue(int row, int col, int value){ this->data.at(row).at(col) = value; }
        int getValue(int row, int col){ return data.at(row).at(col); }
        void print();
        void print(int noOfRows);

        static Matrix * copy(Matrix * matrix);
        static void swap(Matrix * a, int index_a, bool row_a, Matrix * b, int index_b, bool row_b, bool reverse);
};

#endif
