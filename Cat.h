#pragma once
#include "Animal.h"

// Cat command target

class Cat : public Animal
{
public:
	Cat(CString name, CString color, CString age, CString type);
	virtual ~Cat();

	virtual CString getColor() = 0;

};


