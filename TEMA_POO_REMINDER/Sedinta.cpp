#include "Sedinta.h"


void CSedinta::display()
{
	double minutes, hours;
	double fractpart, intpart;

	fractpart = modf(mDurata, &intpart);

	minutes = fractpart * 60;
	hours = intpart;

	cout << "Sedinta\n" << "Ziua: " << mZiua << "\t" << "Ora de inceput: " << mOra
		<< "\t" << "Durata: " << hours << " ore si " << minutes << " minut(e)" << endl;
	cout << "Subiect: " << mSubiect << endl;

}

void CSedinta::printToFile(ofstream &f)
{
	
	char string[100];
	sprintf(string, "Sedinta %d %d %f\n%s\n", mZiua,mOra,mDurata,mSubiect);
	f << string;

}
bool CSedinta::operator==(const CNota & obj) const
{
	return obj==*this;
}

bool CSedinta::operator==(const CApel& obj) const
{
	return true;
}
bool CSedinta::operator==(const CSedinta &obj)const
{
	if (this == &obj)
		return false;
	else
	{
		if (this->mZiua == obj.mZiua)
		{
			if (!((obj.mOra<this->mOra && obj.mOra + obj.mDurata <= this->mOra)
				|| (obj.mOra >= this->mOra + this->mDurata && obj.mOra + obj.mDurata >(this->mOra + this->mDurata))))
				return false;
		}
	}
	return true;
}


CNota* CSedinta::copy()
{
	return new CSedinta(*this);
}

CSedinta::CSedinta() :CNota()
{
	mDurata = 0;
	mSubiect = NULL;
}

CSedinta::CSedinta(int ziua, int ora, double durata, char* subiect)
: CNota(ziua, ora)
{
	mDurata = durata;
	mSubiect = new char[strlen(subiect) + 1];
	strcpy(mSubiect, subiect);
}

CSedinta::CSedinta(CSedinta& s)
: CNota(s)
{
	mDurata = s.mDurata;
	
	mSubiect = new char[strlen(s.mSubiect) + 1];
	strcpy(mSubiect, s.mSubiect);
}

CSedinta::~CSedinta()
{
	if (mSubiect != NULL)
	{
		delete[] mSubiect;
		mSubiect = NULL;
	}

//	cout << "Destructor Sedinta" << endl;
}
