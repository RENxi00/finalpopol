#pragma once
#include "gameNode.h"
#include "tileNode.h"


// 화면 크기만 프린트 되게 (클립핑)
// 애들 구별 할수 있는 이넘문 넣으세욤
// 버튼을 통해서 캐릭터 마다 저장 할수 있도록.. 

// 집마다 씬이동 할라면 맵 파일 이름 불러와야 할듯 


// 이넘 필요한거 , 이동가능, 이동불가, 
// 두번째 이넘문 = 타일에 등록된 오브젝트 타입-> 아무것도 없는지 아이템인지 바닥인지 엔피씬지 집인지 이런거 
// -> 이거는 gamenode에 등록할지 말지 고민좀 햅바 

// 집같은 객체는 렉트 여러개 차지함 
// 단순 타일이 아닌 오브젝트들을 

// tap같은걸로 rect랑 이미지 껏다 켯다 가능하게 

// 


class mapTool : public gameNode
{
	POINT center; 


public:
	mapTool();
	~mapTool();
};

