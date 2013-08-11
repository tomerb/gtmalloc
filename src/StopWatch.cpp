
#include "StopWatch.h"

LARGE_INTEGER Timestamp::s_nFreq = { 0 };

StopWatch::StopWatch() : m_bStopped(false)
{
	m_Elapsed.m_nSec = 0;
	m_Elapsed.m_nMilliSec = 0;
	m_Elapsed.m_nMicroSec = 0;
}

StopWatch::~StopWatch()
{
}
	
void StopWatch::Start()
{
	m_bStopped = false;
	QueryPerformanceCounter(&m_nStart);
	m_nLastLap = m_nStart;
}

void StopWatch::Stop()
{
	m_bStopped = true;
	CalculateDuration();
}

void StopWatch::AddLap(const std::wstring& lapName, const Timestamp& elapsed)
{
	_Lap lap;

	lap.m_LapName = lapName;
	lap.m_Elapsed = elapsed;

	m_Laps.push_back(lap);
}

void StopWatch::Lap(const std::wstring& lapName)
{
	if (m_bStopped == true)
	{
		
	}

	LARGE_INTEGER snap;
	Timestamp	elapsed;
	BOOL bRet = QueryPerformanceCounter(&snap);
	LONGLONG nTimeDiff = snap.QuadPart - m_nLastLap.QuadPart;
	Timestamp::ConvertLongLongToTimestamp(nTimeDiff, &elapsed);

	m_nLastLap = snap;

	if (lapName.empty())
	{
//		AddLap(core::StringUtils::Format(L"Lap #%d", m_Laps.size()), elapsed);
	}
	else
	{
		AddLap(lapName, elapsed);
	}
}

Timestamp StopWatch::GetElapsed()
{
	if ( m_bStopped == false )
	{
		CalculateDuration();
	}

 	return m_Elapsed;
}

void StopWatch::CalculateDuration()
{
	BOOL bRet = QueryPerformanceCounter(&m_nStop);
	m_nTimeDiff = m_nStop.QuadPart - m_nStart.QuadPart;
	Timestamp::ConvertLongLongToTimestamp(m_nTimeDiff, &m_Elapsed);
}

//////////////////////////////////////////////////////////

AutoStopWatch::AutoStopWatch(const std::wstring& name, const Timestamp& threshold = Timestamp(10 * 60, 0, 0))
{
	m_StopWatch.Start();
	m_Name = name;
	m_Threshold = threshold;
}

AutoStopWatch::~AutoStopWatch()
{
	m_StopWatch.Stop();

	if (m_StopWatch.GetElapsed().m_nTicks > m_Threshold.m_nTicks)
	{
	//	LOG4CPLUS_TRACE_FMT(logger, L"Stopwatch  '%s' duration : %s", m_Name.c_str(), m_StopWatch.GetElapsed().ToString());
	}
}
