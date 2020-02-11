#pragma once
#include "gameNode.h"
#define PLAYER_SPEED 3

// ���� ������ �̿�
// �÷��̾�� ��� ���� �ƴϴϱ� ������ Ŭ���� �Ἥ �ص� �ɰŰ��� 
// Ÿ�� ���� ������ 
// �����ۿ� ���� ���ϴ� ���µ� �ִ�. 
// ������ �ϴ� ���� 
// ���̵�, �̵�, ��ȭ?, ����, ä��, 

// ������ �ϴ� �� 
// ������ / ���� �� / ��/ ����/ ��û?(������ 
// �κ��丮 , ����(������) , 
// 

// �̰� ���� ���� �۵��ϰ� ��������� ���곪 �׷��� init �� ���� �Ǵ��� Ȯ�� �սô�. 
// https://boycoding.tistory.com/116?category=959177 ���� �� ���� �̿��ؼ� ¥�� �� �����Ű���������



//���漱��
class StateBase;
class PlayerMove;
class PlayerIdle;


class player : public gameNode
{
private:

	friend class StateBase;
	friend class PlayerMove;
	friend class PlayerIdle;

	StateBase* _currentState;
	unordered_map<string, StateBase*> _stateList; // unordered_map <- �ش� ���ǰ� �ʿ��� , �Ʒ� ��ũ ���� ���� ���.
	//https://cookiehcl.tistory.com/23
	//https://hsp1116.tistory.com/35

	// �ֹε� ȣ������ ����־�� �ұ� 
	// �޼��� Ǯ�� �վ�� �ϴµ� . . . 

	// �ӹ� ������ �ؾ� �ϳ� �������� �� �� �� �� 
	// ���� ������Ŭ������ �� ������ �� ������ ���ӵ����͸� ���� �ϰ� �ϴ°͵� �������Ű�����?  
	// �ε� �Ҷ� ���� �����͸� �ҷ� ���� �Ǵ°� �ƴ�?

	// ���� -> ��ȣ �ۿ� �ȵǴ� �ֵ��� (�����̳� ���� ���� �ֵ�) �� �׳� ��� �ٴ� ���� �ֵ��� ��ü�� ���Ĥ�( ����� ��� �׷���)

	// ������ �͵� , ���� ���� , �� ����, 

	int _playerX, _playerY;		// �����̵� ���� ��ư �װ�
	POINT _playerIndex;			// �ε��� (��ǥ)
	image* _playerImage;
	int _frameX, _frameY;
	int _count;
	RECT _playerRc;

public:
	player();
	~player();

	//HRESULT init(float x, float y, int width, int height);
	HRESULT init();
	void release();
	void update();
	void render();

	// ���¸� �����ϴµ� ���� �Լ� 
	void ChangeState(string str);
};


class StateBase
{
public:
	StateBase(player* me) :me(me) {}   // �̰� ���� ���̷��� ������ �𸣰��� ã�� ���� 
	~StateBase() {}

	virtual void Enter() = 0;	// �ʱ�ȭ
	virtual void Excute() = 0;   // ������Ʈ 
	virtual void Exit() {}  // ������ �Ұ� 
protected:
	player* me;
};

class PlayerIdle : public StateBase
{
public:
	PlayerIdle(player* me) :StateBase(me) {}
	~PlayerIdle() {}
	virtual void Enter();
	virtual void Excute();
	virtual void Exit();
};

class PlayerMove : public StateBase
{
public:
	PlayerMove(player* me) :StateBase(me) {}
	~PlayerMove() {}
	virtual void Enter();
	virtual void Excute();
	virtual void Exit();
};
