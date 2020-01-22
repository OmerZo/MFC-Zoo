// Animal.cpp : implementation file
//

#include "pch.h"
#include "zooTestOne.h"
#include "Animal.h"


// Animal

Animal::Animal(CString name, CString color, CString sound, CString numOfLegs, CString age)
{
	this->name = name;
	this->color = color;
	this->sound = sound;
	this->numOfLegs = numOfLegs;
	this->age = age;
}

Animal::~Animal()
{
}

CString Animal::getName() { return this->name; }
//CString Animal::getColor() { return this->name; }
CString Animal::getSound() { return this->sound; }
CString Animal::getNumOfLegs() { return this->numOfLegs; }
CString Animal::getAge() { return this->age; }

