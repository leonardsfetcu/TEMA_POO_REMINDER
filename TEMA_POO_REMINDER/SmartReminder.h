#pragma once
#include "Reminder.h"
class CSmartReminder :
	public CReminder
{
	int							mIntervalStart;
	int							mIntervalEnd;

public:
	using CReminder::addSedinta;

	void						addSedinta(float durata,char* subiect,int ziInceput,int ziFinal);
	void						setWorkInterval(int oraStart, int oraEnd) { mIntervalStart = oraStart; mIntervalEnd = oraEnd; }
	CSmartReminder();
	~CSmartReminder();
};

