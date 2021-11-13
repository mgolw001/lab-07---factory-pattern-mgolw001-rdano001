#ifndef __OP_HPP__
#define __OP_HPP__
#include <stdlib.h>
#include <time.h>
#include <string>
#include "base.hpp"

class Op : public Base {
    public:
        Op(double value): Base() {
        val = value;
        }

        double evaluate(){return val;}
        std::string stringify(){
        return std::to_string(val);
        }
    private:
        double val;
};

#endif
