#pragma once
#include "gameNode.h"

class gamePlayScene : public gameNode
{
public:
	// 실제 플레이 씬 

	gamePlayScene();
	~gamePlayScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

