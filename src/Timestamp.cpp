
#include "Timestamp.h"

Timestamp& Timestamp::operator+=(const Timestamp& other)
{
	this->Initialize(this->m_nTicks + other.m_nTicks);
	return *this;
}

Timestamp& Timestamp::operator-=(const Timestamp& other)
{
	this->Initialize(this->m_nTicks - other.m_nTicks);
	return *this;
}

Timestamp::Timestamp() : m_nSec(0),
						 m_nMilliSec(0),
						 m_nMicroSec(0),
						 m_nTicks(0),	
						 m_nTotalSec(0),
						 m_nTotaMilliSec(0),
						 m_nTotaMicroSec(0)
{	
	if (s_nFreq.LowPart == 0 && s_nFreq.HighPart == 0)
	{
		QueryPerformanceFrequency(&s_nFreq);
	}
}


Timestamp::Timestamp(LONGLONG nMicroSeconds)
{
	if (s_nFreq.LowPart == 0 && s_nFreq.HighPart == 0)
	{
		QueryPerformanceFrequency(&s_nFreq);
	}

	this->Initialize(nMicroSeconds);
}

Timestamp::Timestamp(long nSec,long nMilliSec,long nMicroSec) : m_nSec(nSec),
															    m_nMilliSec(nMilliSec),
																m_nMicroSec(nMicroSec)
{	
	if (s_nFreq.LowPart == 0 && s_nFreq.HighPart == 0)
	{
		QueryPerformanceFrequency(&s_nFreq);
	}

	double nSeconds = ((double)m_nSec + ((double)m_nMilliSec / 1000) + (double)((double)m_nMicroSec / 1000000));
	m_nTicks =  (LONGLONG)((double)nSeconds * (double)s_nFreq.QuadPart);
	Initialize(m_nTicks);
}

void Timestamp::Initialize(LONGLONG ticks)
{
	this->m_nTicks = ticks;
	
    this->m_nSec =  (long)((ticks * 1000000.0 /  s_nFreq.QuadPart) / 1000000.0);
    this->m_nMilliSec = (long)(((double)ticks * (1000000.0 /  s_nFreq.QuadPart)) / 1000) % 1000;
    this->m_nMicroSec = (long)(((double)ticks * (1000000.0 /  s_nFreq.QuadPart))) % 1000;

	this->m_nTotalSec = m_nSec;
    this->m_nTotaMilliSec = (long)(((double)ticks * (1000000.0 /  s_nFreq.QuadPart)) / 1000);
    this->m_nTotaMicroSec = (long)(((double)ticks * (1000000.0 /  s_nFreq.QuadPart)));
}

std::wstring Timestamp::ToString() const
{
	wchar_t szTime[256];
	swprintf_s(szTime, 256, L"%0.2d:%0.2d:%0.2d", m_nTotalSec / 60 / 60, // hours
												  m_nTotalSec / 60 % 60 , // minutes
												  m_nTotalSec % 60); // seconds

	return std::wstring(szTime);
}

long GetTotalMicroseconds()
{	
//	return (long)(((double)this->m_nTicks * (1000000.0 /  s_nFreq.QuadPart)));
	return 0;  
}

Timestamp Timestamp::Now()
{
	Timestamp timestamp;
	LARGE_INTEGER now; 

	QueryPerformanceCounter(&now);
	ConvertLongLongToTimestamp(now.QuadPart,&timestamp);

	return timestamp;
}

void Timestamp::ConvertLargeIntegerToTimestamp(LARGE_INTEGER lTimestamp,Timestamp *pTimestamp)
{
	ConvertLongLongToTimestamp(lTimestamp.QuadPart,pTimestamp);
}

void Timestamp::ConvertLongLongToTimestamp(LONGLONG lTimestamp,Timestamp *pTimestamp)
{
	*pTimestamp = Timestamp(lTimestamp);
}

bool Timestamp::operator == (const Timestamp &other)const
{
	return ( this->m_nSec == other.m_nSec &&
			 this->m_nMilliSec == other.m_nMilliSec &&
			 this->m_nMilliSec == other.m_nMilliSec);
}	

