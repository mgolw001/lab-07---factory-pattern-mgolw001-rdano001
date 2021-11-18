#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "Base.hpp"
#include "Op.hpp"
#include <string>

class Sub : public Base {

    private:
              Base* leftOP;
              Base* rightOP;

    public:
        Sub(Base*lop , Base*rop){
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
