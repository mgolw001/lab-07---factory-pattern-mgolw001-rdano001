#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "Base.hpp"
#include "Op.hpp"
#include <string>

class Div : public Base {

    private:
              Base* leftOP;
              Base* rightOP;
    public:
        Div(Base* lop ,Base* rop){
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
