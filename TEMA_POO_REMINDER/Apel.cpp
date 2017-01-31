#include "Apel.h"

void CApel::printToFile(ofstream &f)
{

	char string[100];

	sprintf(string, "Apel %d %d %s\n", mZiua,mOra,mNrTel);
	f << string;

}
void CApel::display()
{
	cout << "Apel\n"<< "Telefon: " << mNrTel <<"\tZiua: "<<mZiua<< "\tOra: " << mOra << endl;
}

bool CApel::operator==(const CNota &obj) const
{
	
	return obj == *this;
}

bool CApel::operator==(const CApel& obj) const
{
	if (this == &obj)
		return false;
	else
	{
		if (this->mZiua == obj.GetZiua() && this->mOra == obj.GetOra() && strcmp(this->mNrTel,obj.mNrTel)==0)
			return false; //obiectele comparate nu pot fi in aceeasi lista
	}
	return true;
}
bool CApel::operator==(const CSedinta &obj) const
{
	return true; // obiectele comparate pot fi introduse in lista, nu se influenteaza reciproc
}


CNota* CApel::copy()
{
	return new CApel(*this);
}

CApel::CApel() : CNota()
{

}

CApel::CApel(int ziua, int ora, char* nrTel) : CNota(ziua,ora)
{

	strcpy(mNrTel, nrTel);

}


CApel::CApel(CApel& a)
:CNota(a)
{
	strcpy(mNrTel, a.mNrTel);
}

CApel::~CApel()
{
//	cout << "Destructor Apel" << endl;
}
