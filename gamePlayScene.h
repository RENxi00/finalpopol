#pragma once
#include "gameNode.h"

class gamePlayScene : public gameNode
{
public:
	// ���� �÷��� �� 

	gamePlayScene();
	~gamePlayScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

