#pragma once
#include "singletonBase.h"

class cameraManager : public singletonBase<cameraManager>
{
private:
	RECT  _cameraRect;							// ������ RECT   
	float _cameraWorldSizeX, _cameraWorldSizeY; // ī�޶� ���
	float _cameraSizeX, _cameraSizeY;			// ī�޶� ũ�� 
	float _cameraX, _cameraY;					// ī�޶� ��ǥ 
		
	HDC _worldDC;
	image* _worldImage;

public:
	cameraManager();
	~cameraManager();

	HRESULT init();
	void release();
	void update();
	void render();

	// ī�޶��� ��ǥ 
	void set_CameraXY(int x, int y);

	float get_CameraX() { return _cameraX; }
	float get_CameraY() { return _cameraY; }

	//ī�޶� �� ������ ������ ���ϰ� 
	void Camera_Correction();
	void Camera_Move();
	// ���� DC
	HDC getWorldDC() { return _worldDC; }
	image* getWorldImage() { return _worldImage; }

};