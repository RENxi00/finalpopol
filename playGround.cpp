#include "stdafx.h"
#include "playGround.h"
#include "playerTestScene.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}


HRESULT playGround::init()
{
	gameNode::init(true);
	//_player = new player;
	//_player->init();
	//SCENEMANAGER->addScene("ÀÎ°ÔÀÓ¾À", new inGameScene);
	//SCENEMANAGER->addScene("·Îµù¾À", new loadingScene);
	SCENEMANAGER->addScene("Å×½ºÆ®¿ë¾À", new playerTestScene);
	SCENEMANAGER->changeScene("Å×½ºÆ®¿ë¾À");
	//SCENEMANAGER->changeScene("·Îµù¾À");



	return S_OK;
}


void playGround::release()
{
	gameNode::release();


}


void playGround::update()
{
	gameNode::update();
	//_player->update();
	SCENEMANAGER->update();

}



void playGround::render()
{
	PatBlt(CAMERAMANAGER->getWorldDC(), CAMERAMANAGER->get_CameraX(), CAMERAMANAGER->get_CameraY(), WINSIZEX, WINSIZEY, WHITENESS);
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===========================================================
	
	SCENEMANAGER->render();

	//_player->render();
	//CAMERAMANAGER->getWorldImage()->render(getMemDC(), 0, 0, CAMERAMANAGER->get_CameraX(), CAMERAMANAGER->get_CameraY(), WINSIZEX, WINSIZEY);





	//===========================================================
	_backBuffer->render(getHDC(), 0, 0);
}
