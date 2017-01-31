#include "Nota.h"



CNota::CNota(int ziua,int ora)
{
	mZiua = ziua;
	mOra = ora;
}

CNota::CNota(CNota& nota)
{
	mZiua = nota.mZiua;
	mOra = nota.mOra;
}

CNota::CNota()
{
	mZiua = 0;
	mOra = 0;
}


CNota::~CNota()
{
	//cout << "Destructor Nota" << endl;
}
