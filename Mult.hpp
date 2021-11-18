#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "Base.hpp"
#include "Op.hpp"
#include <string>

class Mult : public Base {

    private:
              Base* leftOP;
              Base* rightOP;
    public:
        Mult(Base* lop , Base* rop){
		leftOP = lop;
		rightOP = rop;
	}
	~Mult(){
		delete leftOP;
		delete rightOP;
	}

        double evaluate(){return leftOP->evaluate() * rightOP->evaluate();}
      
	std::string stringify(){
		std::string s = "( " + leftOP->stringify() + " * " + rightOP->stringify()+" )"; 
		return s;
	}	
};

#endif  
