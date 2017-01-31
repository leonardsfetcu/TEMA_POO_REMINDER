#pragma once
#include<iostream>
#include<list>
#include<fstream>
#include"Nota.h"
#include"Apel.h"
#include"Sedinta.h"
#include"Exceptie.h"


using namespace std;


class CReminder
{
protected:
	list<CNota*>						mRecord;
	bool								checkRecord(CNota* obj);

public:
	void								Save(char* filename);
	void								Load(char* filename);
	void								run(int ziua, int ora);
	void								addSedinta(int ziua,int oraStart,double durata,char* subiect);
	void								addApel(int ziua,int ora,char* numar);
	void								display(int ziua=1,int ora=0);
	CNota*								operator[](int index);
	CReminder*							operator+(const CReminder& obj);
	CReminder();
	~CReminder();
};

