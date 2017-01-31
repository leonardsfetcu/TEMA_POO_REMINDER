#pragma once
#include "Nota.h"


class CApel :
	public CNota
{
	char							mNrTel[10];
	
public:

	


	void							display();
	bool							operator==(const CApel& obj) const;
	bool							operator==(const CSedinta &obj) const;
	bool							operator==(const CNota &obj) const;
	CNota*							copy();
	void							printToFile(ofstream &f);
	const char*						GetNrTel() const { return mNrTel; }
	CApel(CApel& a);
	CApel();
	CApel(int ziua,int ora,char* nrTel);
	~CApel();
};