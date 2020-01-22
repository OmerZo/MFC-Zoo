// StreetC.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "StreetC.h"


// StreetC

StreetC::StreetC(CString name, CString color, CString age)
	:Animal(name, color, _T("miow-miow"), _T("4"), age)
{
}

StreetC::~StreetC()
{
}

CString StreetC::getColor() { return color; }


// StreetC member functions
