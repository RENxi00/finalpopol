#pragma once
#include "gameNode.h"
#include "tileNode.h"


// ȭ�� ũ�⸸ ����Ʈ �ǰ� (Ŭ����)
// �ֵ� ���� �Ҽ� �ִ� �̳ѹ� ��������
// ��ư�� ���ؼ� ĳ���� ���� ���� �Ҽ� �ֵ���.. 

// ������ ���̵� �Ҷ�� �� ���� �̸� �ҷ��;� �ҵ� 


// �̳� �ʿ��Ѱ� , �̵�����, �̵��Ұ�, 
// �ι�° �̳ѹ� = Ÿ�Ͽ� ��ϵ� ������Ʈ Ÿ��-> �ƹ��͵� ������ ���������� �ٴ����� ���Ǿ��� ������ �̷��� 
// -> �̰Ŵ� gamenode�� ������� ���� ������ �ݹ� 

// ������ ��ü�� ��Ʈ ������ ������ 
// �ܼ� Ÿ���� �ƴ� ������Ʈ���� 

// tap�����ɷ� rect�� �̹��� ���� �ִ� �����ϰ� 

// 


class mapTool : public gameNode
{
	POINT center; 


public:
	mapTool();
	~mapTool();
};
