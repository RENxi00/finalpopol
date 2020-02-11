#pragma once
#include "gameNode.h"

class gameStartScene : public gameNode
{
public:
	// 화면 뜨면서 맵툴로 갈지 새로 시작할지 이어서 할지 끝낼지 선택 가능.
	gameStartScene();
	~gameStartScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

