#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

class Div : public Base {

    private:
              Base* leftOP;
              Base* rightOP;
    public:
        Div(Base*,Base*){
		leftOP = lop;
		rightOP = rop;
	} 

	~Div(){
		delete leftOP;
		delete rightOP;
	} 

        double evaluate(){return leftOP->evaluate()/rightOP->evaluate();} 

        std::string stringify(){
		std::string s = "( " + leftOP->stringify() + " / " + rightOP->stringify() + " )";
		return s;
	} 
};

#endif 
