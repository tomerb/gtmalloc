#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__

#include "windows.h"
#include "common.h"
#include "AverageCalculator.h"
#include "Timestamp.h"
#include <string>
#include <set>

struct _Lap
{
	std::wstring	m_LapName;
	Timestamp		m_Elapsed;
};

class CORE_EXT_API StopWatch
{
	public:

		StopWatch();
		virtual ~StopWatch();
	
		void Start();
		void Lap(const std::wstring& lapName = L"");
		void Stop();

		// TODO:
		// void Pause();
		// void Resume();

		Timestamp GetElapsed();

		std::list<_Lap> GetLaps() { return m_Laps; }

	private:
		
		void AddLap(const std::wstring& lapName, const Timestamp& elapsed);

		void CalculateDuration();
		LARGE_INTEGER			m_nStart;
		LARGE_INTEGER			m_nLastLap;
		LARGE_INTEGER			m_nStop;
		LARGE_INTEGER			m_nFreq;
		LONGLONG				m_nTimeDiff;
		Timestamp				m_Elapsed;
		bool					m_bStopped;

		std::list<_Lap>			m_Laps;
};	

class CORE_EXT_API AutoStopWatch
{
	public:

		AutoStopWatch(const std::wstring& name, const Timestamp& threshold);

		virtual ~AutoStopWatch();

	private:

		StopWatch	m_StopWatch;
		std::wstring	m_Name;
		Timestamp		m_Threshold;
};

#endif //__STOPWATCH_H__