#pragma once
#include "gameNode.h"

class gameStartScene : public gameNode
{
public:
	// ȭ�� �߸鼭 ������ ���� ���� �������� �̾ ���� ������ ���� ����.
	gameStartScene();
	~gameStartScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

