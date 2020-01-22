#pragma once
#include "Animal.h"
// SiamiC command target

class SiamiC : public Animal
{
public:
	SiamiC(CString name, CString color, CString age);
	virtual ~SiamiC();

	virtual CString getColor();
};


