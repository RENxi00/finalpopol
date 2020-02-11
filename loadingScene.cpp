#include "stdafx.h"
#include "loadingScene.h"
#include "progressBar.h"

loadingScene::loadingScene()
	: _background(nullptr), _loadingBar(nullptr),
	_currentCount(0)
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	_background = IMAGEMANAGER->addImage("로딩배경", "리그오브레전드로딩.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);

	CreateThread(
		NULL,			//스레드의 보안속성(자식윈도우가 있을때) 핸들로 자식인지 부모인지 파악
		NULL,			//스레드의 스택크기(NULL로 두면 메인쓰레드와 스택크기는 동일하다)
		threadFunction,	//스레드 사용할 함수 명
		this,			//스레드의 매개변수(this로하면 본 클래스)
		NULL,			//스레드의 특성(NULL로 두면 바로 실행한다)
		0				//스레드의 생성 후 스레드의 ID를 넘겨준다 보통은 NULL로 둠.
	);

	return S_OK;
}

void loadingScene::release()
{
	SAFE_DELETE(_loadingBar);
}

void loadingScene::update()
{
	_loadingBar->update();
	_loadingBar->setGauge(_currentCount, LOADINGMAX);

	if (_currentCount == LOADINGMAX)
	{
		SCENEMANAGER->changeScene("인게임씬");
	}

}

void loadingScene::render()
{
	_background->render(getMemDC(), 0, 0);
	_loadingBar->render();
}

DWORD CALLBACK threadFunction(LPVOID lpParameter)
{
	loadingScene* loadHealper = (loadingScene*)lpParameter;

	while (loadHealper->_currentCount != LOADINGMAX)
	{
		IMAGEMANAGER->addImage("인게임", "시작화면.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
		Sleep(1);

		loadHealper->_currentCount++;
	}
	return 0;
}
