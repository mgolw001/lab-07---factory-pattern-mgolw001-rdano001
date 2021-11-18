#ifndef __POW_HPP__
#define __POW_HPP__

#include "Base.hpp"
#include "math.h"
#include "Op.hpp"
#include <string>

class Pow : public Base {
	
    private:
        Base*  leftOP;
        Base*  rightOP;

    public:
        Pow(Base* lop , Base* rop){
		leftOP = lop;
		rightOP = rop;
	}

	~Pow(){
		delete leftOP;	
		delete rightOP;
	}

        double evaluate(){pow(leftOP->evaluate(),rightOP->evaluate());} 

        std::string stringify(){
		std::string s = "( " + leftOP->stringify() + "**" + rightOP->stringify() + " )";
   		return s;
	}
};

#endif 
