#pragma once
#include "singletonBase.h"
#include "timer.h"
#include <time.h>

class timeManager : public singletonBase <timeManager>
{
private:
	timer* _timer;


	time_t curr_time;
	struct tm *curr_tm;


public:
	timeManager();
	~timeManager();

	HRESULT init();
	void release();
	void update(float lockFPS = 0.0f);
	void render(HDC hdc);

	//Delta타임
	inline float getElapsedTime() const { return _timer->getElapsedTime(); }

	//World타임
	inline float getWorldTime() const { return _timer->getWorldTime(); }

	// 실제 날자 (년)
	inline int getYear() const { return curr_tm->tm_year; }
	// 실제 날자 (월) ( 0 ~ 11 ) 
	inline int getMonth() const { return curr_tm->tm_mon; }
	// 실제 날자 (일) 
	inline int getDay() const { return curr_tm->tm_mday; }
	// 실제 요일 ( 0~6 , 일요일: 0 )
	inline int getWday() const { return curr_tm->tm_wday; }
	// 실제 시간(시)
	inline int getHour() const { return curr_tm->tm_hour;}
	// 실제 시간(분)
	inline int getMinute() const { return curr_tm->tm_min;}

};

