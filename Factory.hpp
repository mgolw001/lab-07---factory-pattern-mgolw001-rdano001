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
#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Factory
{
	public:
		
		vector<string> DereferenceInput(char** input, int length){ // turn input to string
			vector<string> s;
			for ( unsigned int i = 0; i < length; i++){
				char* c = input[i];
				s.push_back(c);
			}
		   return s;
		}

		Base* parse(char** input, int length){
			vector<string> ex = DereferenceInput(input, length); 
			Base* parsed = nullptr;
			if(length>0){
				//Base* prev = nullptr;
				//Base* next = nullptr;
				double temp1;
				double temp2;

				for(int i =0; i<length; i++){
					
					if(ex[i]=="+"){
						if(i==0||i==length-1){//the first and last character cannot be an operator
							return nullptr;
						} 
						if (parsed == nullptr){
						temp1 = stod(ex[i-1]);
						temp2 = stod(ex[i+1]);
						Base* op1 = new Op(temp1);
						Base* op2 = new Op(temp2);
						delete parsed;
						parsed = new Add(op1,op2);		
						}
						else {
						temp1 = parsed->evaluate();
						temp2 = stod(ex[i+1]);
						Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Add(op1,op2);
						}
					}
					else if(ex[i]=="-"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						if (parsed == nullptr){
                                                temp1 = stod(ex[i-1]);
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Sub(op1,op2);
                                                }
                                                else {
                                                temp1 = parsed->evaluate();
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Sub(op1,op2);
                                                }	
					}
					else if(ex[i]=="*"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						if (parsed == nullptr){
                                                temp1 = stod(ex[i-1]);
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Mult(op1,op2);
                                                }
                                                else {
                                                temp1 = parsed->evaluate();
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Mult(op1,op2);
                                                }
					}
					else if(ex[i]=="/"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						if (parsed == nullptr){
                                                temp1 = stod(ex[i-1]);
                                                temp2 = stod(ex[i+1]);
						if(temp2==0){
							return nullptr;
						}
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Div(op1,op2);
                                                }
                                                else {
                                                temp1 = parsed->evaluate();
                                                temp2 = stod(ex[i+1]);
						if(temp2==0){
                                                        return nullptr;
                                                }
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Div(op1,op2);
                                                }
					}
					else if(ex[i]=="**"){
						if(i==0||i==length-1){
                                                        return nullptr;
                                                }
						if (parsed == nullptr){
                                                temp1 = stod(ex[i-1]);
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Pow(op1,op2);
                                                }
                                                else {
                                                temp1 = parsed->evaluate();
                                                temp2 = stod(ex[i+1]);
                                                Base* op1 = new Op(temp1);
                                                Base* op2 = new Op(temp2);
						delete parsed;
                                                parsed = new Pow(op1,op2);
                                                }
					}
					
					 
				}	
			}
			return parsed;
		}
};
#endif //__FACTORY_HPP__
