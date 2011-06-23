#pragma once
#include "Clock.h"
//should be in project settings
#define USE_RDTSC
#ifdef USE_RDTSC
#include <windows.h>
#endif
//other platform specific includes
#ifdef USE_RDTSC
class ClockRDTSC:public Clock{
public:
	ClockRDTSC():m_start(0),m_period(0){
		__int64 freq=0;
		::QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		m_period=1/(float)freq;
		::QueryPerformanceCounter((LARGE_INTEGER*)&m_start);
	}
	virtual ~ClockRDTSC(){}
	virtual float getTime()const{
		__int64 count=0;
		::QueryPerformanceCounter((LARGE_INTEGER*)&count);
		return m_period*(float)(count-m_start);
	}
private:
	__int64 m_start;
	float m_period;
};
Clock *Clock::create(){
	return new ClockRDTSC;
}
#endif
//other platform specific clocks