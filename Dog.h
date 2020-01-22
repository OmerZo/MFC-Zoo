#pragma once
#include "Animal.h"
// Dog command target

class Dog : public Animal
{
public:
	Dog(CString name, CString color, CString age);
	virtual ~Dog();

	virtual CString getColor();

private:
	//CString color;
};


