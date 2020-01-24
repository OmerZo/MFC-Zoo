// SiamiC.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "SiamiC.h"


// SiamiC

SiamiC::SiamiC(CString name, CString color, CString age)
	:Animal(name, color, _T("miow-miow"), _T("4"), age, _T("Siami Cat"))
{
}

SiamiC::~SiamiC()
{
}

CString SiamiC::getColor() { return color; }


// SiamiC member functions
