#ifndef __FACTORY_HPP__
#define __FACTORY_HPP_

#include "Base.hpp"
#include "Op.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include <iostream>
using namespace std;

class Factory
{
	public:
		Base* parse(char** input, int length){
			if(length>0){
				Base* prev = nullptr;
				Base* next = nullptr;
				Base* parsed;
				for(int i =0; i<length; i++){
					
					if(input[i]=="+"){
						if(i==0||i==length-1){//the first and last character cannot be an operator
							return nullptr;
						}
						parsed = new Add(prev,next);		
						next = parsed;
					}
					else if(input[i]=="-"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						parsed = new Sub(prev,next);
						next = parsed;	
					}
					else if(input[i]=="*"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						parsed = new Mult(prev,next);
						next = parsed;
					}
					else if(input[i]=="/"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						parsed = new Div(prev,next);
						next = parsed;
					}
					else if(input[i]=="**"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						parsed = new Pow(prev,next);
						next = parsed;
					}
				}	
			}
			return nullptr;
		}
};
#endif //__FACTORY_HPP__
