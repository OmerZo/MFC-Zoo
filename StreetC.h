#pragma once
#include "Animal.h"
// StreetC command target

class StreetC : public Animal
{
public:
	StreetC(CString name, CString color, CString age);
	virtual ~StreetC();

	virtual CString getColor();
};


