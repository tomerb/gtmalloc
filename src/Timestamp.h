
#pragma once

#include <string>
#include <windows.h>

class Timestamp
{
	public:

		static Timestamp Empty;

		Timestamp();
		Timestamp(LONGLONG nMicroSeconds);
		Timestamp(long nSec,long nMilliSec,long nMicroSec);

		bool operator== (const Timestamp &other)const;

		Timestamp &operator+=(const Timestamp& other);
		Timestamp &operator-=(const Timestamp& other);

		std::wstring ToString() const;

		static Timestamp Now();

		static void ConvertLongLongToTimestamp(LONGLONG lTimestamp,Timestamp *pTimestamp);
		static void ConvertLargeIntegerToTimestamp(LARGE_INTEGER lTimestamp,Timestamp *pTimestamp);

		void Initialize(LONGLONG ticks);

		long					m_nSec;
		long					m_nMilliSec;
		long					m_nMicroSec;

		long					m_nTotalSec;
		long					m_nTotaMilliSec;
		long					m_nTotaMicroSec;
		
		LONGLONG				m_nTicks;
		static LARGE_INTEGER	s_nFreq;
};

