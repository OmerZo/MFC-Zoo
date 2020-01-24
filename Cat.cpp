// Cat.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "Cat.h"


// Cat

Cat::Cat(CString name, CString color, CString age, CString type)
	:Animal(name, color, _T("miow-miow"), _T("4"), age, type)
{
}

Cat::~Cat()
{
}



// Cat member functions
