#include "SmartReminder.h"




void CSmartReminder::addSedinta(float durata, char* subiect, int ziInceput, int ziFinal)
{
	for (int idx_zi = ziInceput; idx_zi <= ziFinal; idx_zi++)
	{
		for (int idx_ora = mIntervalStart; idx_ora <= mIntervalEnd-durata; idx_ora++)
		{
			CNota* ptr = new CSedinta(idx_zi, idx_ora, durata, subiect);

			if (true == checkRecord(ptr))
			{
				mRecord.push_back(ptr);
				cout << "Sedinta a fost planificata in ziua " << idx_zi << " de la ora "
					<< idx_ora << " : 00 la ora " << idx_ora + durata << " :00" << endl;
				return;
			}
			delete ptr;
		}
	}

	throw new CExceptie(ER_CANNOT_FIND_INTERVAL, "interval not found");
}



CSmartReminder::CSmartReminder() 
{
}


CSmartReminder::~CSmartReminder()
{
	if (mRecord.size() != 0)
	{
		for (list<CNota*>::iterator it = mRecord.begin(); it != mRecord.end(); it++)
		{
			delete *it;
		}
		mRecord.clear();
	}
}
