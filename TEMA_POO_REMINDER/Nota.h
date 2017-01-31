#pragma once
#include<iostream>
#include<math.h>
#include<fstream>
#include"Exceptie.h"
using namespace std;

class CApel;
class CSedinta;


class CNota
{
protected:
	int								mZiua; //ziua de inceput ( 1 <-> 365 )
	int								mOra; //ora de inceput ( 0 <-> 23 )
	
public:

	virtual void					display() = 0;
	virtual bool					operator==(const CApel& obj) const = 0;
	virtual bool					operator==(const CSedinta &obj) const = 0;
	virtual bool					operator==(const CNota &obj) const = 0;
	virtual void					printToFile(ofstream &f)=0;
	virtual CNota*					copy() = 0;
	int								GetZiua() const { return mZiua; }
	int								GetOra() const { return mOra; }
	CNota(int ziua, int ora);
	CNota(CNota& nota);
	CNota();
	virtual ~CNota();
};

