// Cat.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "Cat.h"


// Cat

Cat::Cat(CString name, CString color, CString age)
	:Animal(name, color, _T("miow-miow"), _T("4"), age)
{
}

Cat::~Cat()
{
}



// Cat member functions
