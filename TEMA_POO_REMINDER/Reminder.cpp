#include "Reminder.h"

void CReminder::Load(char* filename)
{
	ifstream f;

	f.open(filename);

	if (f.is_open() == false)
		throw new CExceptie(ER_OPEN_FILE, "Couldn't open the specified file");

	char buffer[1024];
	char *p;

	if (mRecord.size() != 0)
	{
		for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
			delete *it;
		mRecord.clear();
	}

	while (f.getline(buffer, sizeof(buffer)))
	{
		int zi, ora;
		double durata;
		p = strtok(buffer, " \n");

		if (strcmp(p, "Apel") == 0)
		{
			p = strtok(NULL, " \n");
			zi = atoi(p);
			p = strtok(NULL, " \n");
			ora = atoi(p);
			p = strtok(NULL, " \n");
			CApel *ptr=new CApel(zi, ora, p);
			mRecord.push_back(ptr);
		}
		else
		{
			p = strtok(NULL, " \n");
			zi = atoi(p);
			p = strtok(NULL, " \n");
			ora = atoi(p);
			p = strtok(NULL, " \n");
			durata = atof(p);
			f.getline(buffer, sizeof(buffer));
			CSedinta* ptr = new CSedinta(zi, ora, durata, buffer);
			mRecord.push_back(ptr);

		}

		
	}

	f.close();

}

void CReminder::Save(char* filename)
{
	ofstream f;

	f.open(filename);


	for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
	{
		(*it)->printToFile(f);
	}

	f.close();
}

void CReminder::run(int ziua, int ora)
{
	for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
	{
		if (ziua == (*it)->GetZiua() && (*it)->GetOra() >= ora && (*it)->GetOra() <= ora + 2)
			(*it)->display();
	}
}

bool CReminder::checkRecord(CNota* obj)
{
	for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
	{

		if (!((**it)==(*obj)))
			return false;
	}

	return true;
}


CNota* CReminder::operator[](int index)
{
	int counter = 0;
	if (index< 0 || (unsigned int)index > mRecord.size())
		throw new CExceptie(ER_INVALID_INDEX, "Invalid index!");

	for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++, counter++)
	if (counter == index)
		return *it;

	return NULL;
}

CReminder* CReminder::operator+(const CReminder& obj)
{
	CReminder *ptr = new CReminder;

	list<CNota*> lista1 = this->mRecord;
	list<CNota*> lista2 = obj.mRecord;


	for (list<CNota*>::iterator it = lista1.begin(); it != lista1.end(); it++)
	{
		CNota *aux = (*it)->copy();

		ptr->mRecord.push_back(aux);

	}
	
	for (list<CNota*>::iterator i = lista2.begin(); i != lista2.end(); i++)
	{

		if (true == checkRecord(*i))
		{
			CNota* aux = (*i)->copy();

			ptr->mRecord.push_back(aux);
		}
		else throw new CExceptie(ER_OPERATOR_PLUS, "eroare operator plus");
		
	}

	return ptr;
}



void CReminder::addSedinta(int ziua, int oraStart, double durata, char* subiect)
{
	
	if (ziua<1 || ziua> 365 || oraStart<0 || oraStart>23)
		throw new CExceptie(ER_MEETING_FORMAT, "Incorrect input data!");

	CNota* nota = new CSedinta(ziua, oraStart, durata, subiect);

	if (false == checkRecord(nota))
	{
		throw new CExceptie(ER_MEETING_OVERWRITE, "Overwrite meeting!");
	}

	mRecord.push_back(nota);
}

void CReminder::addApel(int ziua, int ora, char* numar)
{
	if (ziua<1 || ziua> 365 || ora<0 || ora>23|| strlen(numar)>10)
		throw new CExceptie(ER_CALL_FORMAT, "Incorrect input data!");

	CNota* nota = new CApel(ziua, ora, numar);

	if (false == checkRecord(nota))
	{
		throw new CExceptie(ER_CALL_OVERWRITE, "Overwrite call!");

	}
	
	mRecord.push_back(nota);

}

void CReminder::display(int ziua, int ora)
{
	if (ziua == 1&& ora == 0)
	{
		for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
		{
			(*it)->display();
			cout << endl;
		}
	}
	else
	{
		for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
		{
			if ((*it)->GetZiua() >= ziua && (*it)->GetOra() >= ora)
			{
				(*it)->display();
				cout << endl;
			}
		}
	}
}

CReminder::CReminder()
{

}


CReminder::~CReminder()
{
	if (mRecord.size()!=0)
	{
		for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
		{
			delete *it;
		}
		mRecord.clear();
	}

}
