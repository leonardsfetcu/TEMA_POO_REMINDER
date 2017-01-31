#pragma once
#include "Nota.h"
class CSedinta :
	public CNota
{
	double							mDurata;
	char*							mSubiect;
public:
	void							display();
	bool							operator==(const CApel& obj)const;
	bool							operator==(const CSedinta& obj)const;
	bool							operator==(const CNota & obj) const;
	CNota*							copy();
	void							printToFile(ofstream &f);
	double							GetDurata() const { return mDurata; }
	char*							GetSubiect() const { return mSubiect; }
	void							freePtr();

	CSedinta(int ziua, int ora, double durata, char* subiect);
	CSedinta(CSedinta& s);
	CSedinta();
	~CSedinta();
};

