#ifndef _CUBE_HPP_
#define _CUBE_HPP_

#define FRONT               0
#define BACK                1
#define LEFT                2
#define RIGHT               3
#define TOP                 4
#define DOWN                5

#define CLOCK_WISE          1
#define ANTI_CLOCK_WISE     -1
#define DOUBLE_CLOCK_WISE   0

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../include/Matrix.hpp"
using namespace std;

class Cube{
    private:
        int size;
        vector<Matrix *> sides;
    public:        
        Cube(int size);
        Cube(vector<Matrix *> sides);
        ~Cube();
        static Cube * copy(Cube * cube);
        void rotate(int8_t side, int8_t rotation);
        void scramble();
        void printVertically();
        void printHorizontally();
        int getSize(){ return size; }
        vector<Matrix *> getSides(){ return sides; }
        Matrix * getFront() { return sides.at(0); }
        Matrix * getBack(){ return sides.at(1); }
        Matrix * getLeft() { return sides.at(2); }
        Matrix * getRight() { return sides.at(3); }
        Matrix * getTop(){ return sides.at(4); }
        Matrix * getDown(){ return sides.at(5); }
        vector<int8_t> getEdge(int8_t side, int8_t no);
        vector<int8_t> getCorner(int8_t side, int8_t no);
        vector<int8_t> getCenter(int8_t side, bool isEdge, int8_t no);

        static string getSideName(int8_t);
        static string getRotationSign(int8_t);

        


};

#endif
