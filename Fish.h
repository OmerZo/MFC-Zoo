#pragma once

// Fish command target

#include "Animal.h"

class Fish : public Animal
{
public:
	Fish(CString name, CString color, CString age);
	virtual ~Fish();

};


