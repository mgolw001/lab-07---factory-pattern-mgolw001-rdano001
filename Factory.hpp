#ifndef __FACTORY_HPP__
#define __FACTORY_HPP_

#include "Base.hpp"

class Factory
{
	public:
		Base* parse(char** input, int length);
};
#endif //__FACTORY_HPP__
