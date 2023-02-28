#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <array>

// forward declarations
class Camera;

class CameraManager
{
public:
	CameraManager();
	CameraManager(const CameraManager& cm);
	CameraManager& operator=(const CameraManager& cm);
	virtual ~CameraManager();

	void SetCurrentCamera(Camera* pCam);
	Camera* GetCurrentCamera();

private:
	Camera* pDefaultCamera;
	Camera* pCurrentCamera;
};

#endif