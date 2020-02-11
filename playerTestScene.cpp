#include "stdafx.h"
#include "playerTestScene.h"


playerTestScene::playerTestScene()
{
}


playerTestScene::~playerTestScene()
{
}


HRESULT playerTestScene::init()
{
	_player = new player;
	_player->init();

	return S_OK;
}

void playerTestScene::release()
{
	

}

void playerTestScene::update()
{

	_player->update();

}

void playerTestScene::render()
{
	

	_player->render();
	CAMERAMANAGER->getWorldImage()->render(getMemDC(), 0, 0, CAMERAMANAGER->get_CameraX(), CAMERAMANAGER->get_CameraY(), WINSIZEX, WINSIZEY);
}
