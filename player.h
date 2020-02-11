#pragma once
#include "gameNode.h"
#define PLAYER_SPEED 3

// 상태 패턴을 이용
// 플레이어는 찍어 낼거 아니니까 프렌드 클래스 써서 해도 될거같음 
// 타일 따라 가세욤 
// 아이템에 따라 변하는 상태도 있다. 
// 만들어야 하는 상태 
// 아이들, 이동, 대화?, 낚시, 채집, 

// 만들어야 하는 씬 
// 맵툴씬 / 마을 씬 / 집/ 상점/ 관청?(촌장집 
// 인벤토리 , 도감(옵저버) , 
// 

// 이거 상태 패턴 작동하게 만든다음에 무브나 그런곳 init 잘 실행 되는지 확인 합시다. 
// https://boycoding.tistory.com/116?category=959177 가구 이 패턴 이용해서 짜낼 수 있을거같ㅌ은데요



//전방선언
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
	unordered_map<string, StateBase*> _stateList; // unordered_map <- 해더 정의가 필요함 , 아래 링크 보고 공부 요망.
	//https://cookiehcl.tistory.com/23
	//https://hsp1116.tistory.com/35

	// 주민들 호감도는 어디있어야 할까 
	// 메세지 풀이 잇어야 하는디 . . . 

	// ㅣ벌 가구도 해야 하네 ㅋㅌㅋㅋ ㅋ ㅋ ㅋ ㅋ 
	// 게임 데이터클래스에 다 저장해 둔 다음에 게임데이터만 저장 하게 하는것도 괜찮을거같은데?  
	// 로딩 할때 게임 데이터만 불러 오면 되는거 아님?

	// 맵툴 -> 상호 작용 안되는 애들은 (절벽이나 폭포 같은 애들) 은 그냥 찍고 바다 같은 애들은 객체로 뺴셍ㅁ( 물고기 잡고 그런거)

	// 저장할 것들 , 가구 상태 , 맵 상태, 

	int _playerX, _playerY;		// 중점이든 뭐든 암튼 그거
	POINT _playerIndex;			// 인덱스 (좌표)
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

	// 상태를 변경하는데 쓰일 함수 
	void ChangeState(string str);
};


class StateBase
{
public:
	StateBase(player* me) :me(me) {}   // 이게 머지 왜이렇게 쓴건지 모르겠음 찾아 보기 
	~StateBase() {}

	virtual void Enter() = 0;	// 초기화
	virtual void Excute() = 0;   // 업데이트 
	virtual void Exit() {}  // 끝날때 할거 
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
