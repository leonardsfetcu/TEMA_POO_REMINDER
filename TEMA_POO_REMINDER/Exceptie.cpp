#include "Exceptie.h"


void CExceptie::printErrMessage()
{
	cout << "Error code " << mCode << ": " << mMessage << endl;
}

CExceptie::CExceptie()
{
	mMessage = NULL;
}


CExceptie::CExceptie (int code,char* message)
{
	mMessage = new char[strlen(message) + 1];
	strcpy(mMessage, message);
	mCode = code;
}


CExceptie::~CExceptie()
{
	if (mMessage != NULL)
	{
		delete[] mMessage;
		mMessage = NULL;
	}
}
