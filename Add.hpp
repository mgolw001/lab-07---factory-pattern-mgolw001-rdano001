#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

class Add : public Base {
    private:
              Base* leftOP;
              Base* rightOP;
	
    public:
        Add(Base* lop ,Base* rop){
		leftOP = lop;
		rightOP = rop;
	}

	~Add(){
		delete leftOP;
		delete rightOP;
	}

        double evaluate(){return leftOP->evaluate() + rightOP->evaluate();}

        std::string stringify(){
		std::string s = "( " + leftOP->stringify() + " + " + rightOP->stringify() + " )";
		return s;
	}
};

#endif 
