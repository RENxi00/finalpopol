#include "stdafx.h"
#include "cameraManager.h"

cameraManager::cameraManager()
{
	_cameraSizeX = WINSIZEX;
	_cameraSizeY = WINSIZEY;

	//플레이어 위치
	_cameraX = 100;
	_cameraY = 100;

	_worldImage = new image;
	_worldImage = IMAGEMANAGER->addImage("worldMap", 2080, 2080);
	_worldDC = _worldImage->getMemDC();

	_cameraWorldSizeX = 2080;
	_cameraWorldSizeY = 2080;


	_cameraRect = RectMake(_cameraX, _cameraY, WINSIZEX, WINSIZEY);
}

cameraManager::~cameraManager()
{
}

HRESULT cameraManager::init()
{
	return S_OK;
}

void cameraManager::release()
{
}

void cameraManager::update()
{
}

void cameraManager::render()
{
}

void cameraManager::set_CameraXY(int x, int y)
{
	_cameraX = x - _cameraSizeX / 2.0f;
	_cameraY = y - _cameraSizeY / 2.0f;
	Camera_Correction();
}


void cameraManager::Camera_Correction()
{
	if (_cameraX < 0) _cameraX = 0;
	if (_cameraY < 0) _cameraY = 0;
	if (_cameraX + _cameraSizeX > _cameraWorldSizeX)
	{
		_cameraX = _cameraWorldSizeX - _cameraSizeX;
	}
	if (_cameraY + _cameraSizeY > _cameraWorldSizeY)
	{
		_cameraY = _cameraWorldSizeY - _cameraSizeY;
	}
}

void cameraManager::Camera_Move()
{
}
