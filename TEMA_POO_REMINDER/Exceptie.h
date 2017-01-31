#pragma once
#include<iostream>
#include"ErrorCodes.h"

using namespace std;



class CExceptie
{
	char*								mMessage;
	int									mCode;

public:
	void								printErrMessage();
	CExceptie();
	CExceptie(int,char*);
	~CExceptie();
	
};

