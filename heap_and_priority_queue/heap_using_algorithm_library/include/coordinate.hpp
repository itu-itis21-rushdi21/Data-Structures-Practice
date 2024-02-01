#pragma once
#include<iostream>
#include<math.h>
using namespace std;

class Cordinate {
    private:
        int xCor;
        int yCor;
    public:
        Cordinate(int x, int y): xCor(x), yCor(y) {};
        void print() {cout << "(" << xCor << "," << yCor << ")" << " "; };
        int get_xCor() {
            return this->xCor;
        }
        int get_yCor() {
            return this->yCor;
        }
        double length() {return sqrt(pow(xCor, 2) + pow(yCor, 2) );}

};

class CordinateComparator {
    public:
        // the operator key word here is KEY no optional   
        bool operator() (Cordinate& c1, Cordinate& c2) {
            // since they are passed by reference and the function uses & in the parameters so no need to dereference c1 and c2 (no need to for ex c1->get_xCor()) 
            if(c1.get_xCor() == c2.get_xCor() && c1.get_yCor() == c2.get_yCor())
                return true;
            return false;
        }
};

class CordinateComparator2 {
    public:
        // the operator key word here is KEY no optional   
        bool operator() (Cordinate& c1, Cordinate& c2) {
            // if true means keep the order if false means swap the elements (the order they are intered)
            // ex c1 = 4 c2 = 6 --> (4 > 6) --> false --> swap aka order from largest to smallest
            // make sense for this sign to order largest to smallest cause 7 > 5 > 3 > 1 etc :)
            if(c1.get_xCor() > c2.get_xCor())
                return true; // order correct
            return false;   // order wrong swap
        }
        // if we exchange the true and the false values we will get opposite order and then true will mean swap while false no swap but it is anti logic
        // cause ture in if must corrospond to return true  
};

class CordinateComparator3 {
    public:
        // the operator key word here is KEY no optional   
        bool operator() (Cordinate& c1, Cordinate& c2) {
            // if true means keep the order if false means swap the elements (the order they are intered)
            // ex c1 = 6 c2 = 4 --> (6 < 4) --> false --> swap aka order from smallest to largest
            if(c1.get_xCor() < c2.get_xCor())
                return true;
            return false;
        }
        // if we exchange the true and the false values we will get opposite order and then true will mean swap while false no swap    
};