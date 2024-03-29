#pragma once


class Animal : public CObject
{
public:
	Animal(CString name, CString color, CString sound, CString numOfLegs, CString age, CString type);
	virtual ~Animal();

	virtual CString getName();
	virtual CString getColor() = 0;
	virtual CString getSound();
	virtual CString getNumOfLegs();
	virtual CString getAge();
	virtual CString getType();

	void Serialize(CArchive& archive);

protected:
	CString name;
	CString color;
	CString sound;
	CString numOfLegs;
	CString age;
	CString type;
};


