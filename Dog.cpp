// Dog.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "Dog.h"


// Dog

Dog::Dog(CString name, CString color, CString age)
	:Animal(name, color, _T("woof-woof"), _T("4"), age, _T("Dog"))
{
}

Dog::~Dog()
{
}

CString Dog::getColor() { return color; }

// Dog member functions
