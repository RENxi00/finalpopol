#pragma once
#include "gameNode.h"
#include "player.h"


class playerTestScene : public gameNode
{
	player* _player;

public:
	playerTestScene();
	~playerTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

