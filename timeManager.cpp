#include "stdafx.h"
#include "timeManager.h"


timeManager::timeManager()
	: _timer(NULL)
{
}


timeManager::~timeManager()
{
}

HRESULT timeManager::init()
{
	_timer = new timer;
	_timer->init();

	return S_OK;
}

void timeManager::release()
{
	if (_timer != NULL) SAFE_DELETE(_timer);
}

void timeManager::update(float lockFPS)
{
	if (_timer != NULL)
	{
		_timer->tick(lockFPS);
	}

	// time 함수는 1970년 1월 1일 이후 몇초가 지났는지를 계산한다. NULL을 인자로 사용
	curr_time = time(NULL);

	// 지역 시간을 기준으로 변환 및 출력 편의를 위하여 tm 구조체에 저장한다.(포맷팅)
	curr_tm = localtime(&curr_time);

	
}

void timeManager::render(HDC hdc)
{
	char str[256];
	string frameRate;

	//FPS / WorldTime / ElapsedTime
	SetTextColor(hdc, RGB(255, 255, 255));
	SetBkMode(hdc, TRANSPARENT);

#ifdef _DEBUG
	{
		sprintf_s(str, "framePerSec(FPS) : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));

		sprintf_s(str, "worldTime : %f", _timer->getWorldTime());
		TextOut(hdc, 0, 20, str, strlen(str));

		sprintf_s(str, "elapsedTime : %f", _timer->getElapsedTime());
		TextOut(hdc, 0, 40, str, strlen(str));
	}
#else
	{
		sprintf_s(str, "framePerSec(FPS) : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif
	

}
