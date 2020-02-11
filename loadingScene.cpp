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
	_background = IMAGEMANAGER->addImage("�ε����", "���׿��극����ε�.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	_loadingBar = new progressBar;
	_loadingBar->init(0, WINSIZEY - 50, WINSIZEX, 50);
	_loadingBar->setGauge(0, 0);

	CreateThread(
		NULL,			//�������� ���ȼӼ�(�ڽ������찡 ������) �ڵ�� �ڽ����� �θ����� �ľ�
		NULL,			//�������� ����ũ��(NULL�� �θ� ���ξ������ ����ũ��� �����ϴ�)
		threadFunction,	//������ ����� �Լ� ��
		this,			//�������� �Ű�����(this���ϸ� �� Ŭ����)
		NULL,			//�������� Ư��(NULL�� �θ� �ٷ� �����Ѵ�)
		0				//�������� ���� �� �������� ID�� �Ѱ��ش� ������ NULL�� ��.
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
		SCENEMANAGER->changeScene("�ΰ��Ӿ�");
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
		IMAGEMANAGER->addImage("�ΰ���", "����ȭ��.bmp", WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
		Sleep(1);

		loadHealper->_currentCount++;
	}
	return 0;
}
