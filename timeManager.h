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

	//DeltaŸ��
	inline float getElapsedTime() const { return _timer->getElapsedTime(); }

	//WorldŸ��
	inline float getWorldTime() const { return _timer->getWorldTime(); }

	// ���� ���� (��)
	inline int getYear() const { return curr_tm->tm_year; }
	// ���� ���� (��) ( 0 ~ 11 ) 
	inline int getMonth() const { return curr_tm->tm_mon; }
	// ���� ���� (��) 
	inline int getDay() const { return curr_tm->tm_mday; }
	// ���� ���� ( 0~6 , �Ͽ���: 0 )
	inline int getWday() const { return curr_tm->tm_wday; }
	// ���� �ð�(��)
	inline int getHour() const { return curr_tm->tm_hour;}
	// ���� �ð�(��)
	inline int getMinute() const { return curr_tm->tm_min;}

};

