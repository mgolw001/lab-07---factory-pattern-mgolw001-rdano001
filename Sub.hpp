#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>

class Sub : public Base {

    private:
              Base* leftOP;
              Base* rightOP;

    public:
        Sub(Base*,Base*){
		leftOP = lop;
		rightOP = rop;
	}
	
	~Sub(){
		delete leftOP;
		delete rightOP;
	}
	
        double evaluate(){return leftOP->evaluate() - rightOP->evaluate();}

        std::string stringify(){
		std::string s = "( " + leftOP->stringify() + " - " + rightOP->stringify()+" )"; 
		return s;
	}
};

#endif  
