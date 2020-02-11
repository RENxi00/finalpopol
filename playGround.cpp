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
	//SCENEMANAGER->addScene("�ΰ��Ӿ�", new inGameScene);
	//SCENEMANAGER->addScene("�ε���", new loadingScene);
	SCENEMANAGER->addScene("�׽�Ʈ���", new playerTestScene);
	SCENEMANAGER->changeScene("�׽�Ʈ���");
	//SCENEMANAGER->changeScene("�ε���");



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
