#include "stdafx.h"
#include "player.h"





player::player()
{

}


player::~player()
{
	// 치킨은 가장 완벽한 음식이다.
	// 치킨이 최고인것에 의문을 품는가?
	// 치킨을 선택하는것은 인생 최대의 성공이다.
}

HRESULT player::init()
{
	IMAGEMANAGER->addFrameImage("PlayerWalk", "./Resources/Player/PlayerWalk.bmp", 600, 400, 6, 4, true, RGB(255,0,255));
	_playerX = _playerY = 100;
	_frameX = _frameY = _count = 0;
	
	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_count++;

	if (_count > 8)
	{
		_frameX += 1;
		if (_frameX > 5)
		{
			_frameX = 0;
		}
		_count = 0;
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_frameY = 0;
		_playerX -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_frameY = 1;
		_playerX += PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_frameY = 2;
		_playerY -= PLAYER_SPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_frameY = 3;
		_playerY += PLAYER_SPEED;
	}

	CAMERAMANAGER->set_CameraXY(_playerX,_playerY); // 카메라 세팅
}

void player::render()
{

	IMAGEMANAGER->findImage("PlayerWalk")->frameRender(CAMERAMANAGER->getWorldDC(),_playerX,_playerY, _frameX, _frameY);
	//IMAGEMANAGER->findImage("playerRun")->frameRender(getMemDC(), _playerX, _playerY, _frameX, _frameY);

}

void player::ChangeState(string str)
{
}

void PlayerIdle::Enter()
{
}

void PlayerIdle::Excute()
{
}

void PlayerIdle::Exit()
{
}

void PlayerMove::Enter()
{
}

void PlayerMove::Excute()
{
}

void PlayerMove::Exit()
{
}
