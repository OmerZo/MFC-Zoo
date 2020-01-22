// Fish.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "Fish.h"


// Fish

Fish::Fish(CString name, CString color, CString age)
	:Animal(name, color, _T("blu-blu"), _T("0"), age)
{
}

Fish::~Fish()
{
}

CString Fish::getColor() {return color;}


