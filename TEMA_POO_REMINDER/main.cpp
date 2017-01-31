#include<iostream>
#include"SmartReminder.h"


using namespace std;



void main()
{
	
	CReminder *R1, *R2, *R3;
//	CSmartReminder *SM;

	try {

		R1 = new CReminder;
		R2 = new CReminder;


		R1->addApel(2, 7, "0732776657");
		R1->addSedinta(2, 10, 2.1, "Sedinta numarul 1");
		R1->addSedinta(1, 13, 1.5, "Sedinta numarul 2");
		R1->addApel(3, 16, "112");
		R1->addSedinta(2, 13, 2, "Sedinta numarul 3");
		R1->addApel(1, 10, "123434");


		R1->display();
		R2->addApel(2, 7, "0732776657");
		R2->addSedinta(2, 10, 2.1, "Sedinta numarul 1");
		R2->addSedinta(1, 13, 1.5, "Sedinta numarul 2");
		R2->addApel(3, 16, "112");
		R2->addSedinta(2, 13, 2, "Sedinta numarul 3");
		R2->addApel(1, 10, "123434");
		R2->display();


		delete R1;
	
	}
	catch (CExceptie* e)
	{
		e->printErrMessage();
		delete e;
	}
	


	

}