#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include <array>

// forward declarations
class Camera;

class CameraManager
{
public:
	CameraManager();
	CameraManager(const CameraManager& rCamMgr);
	CameraManager& operator=(const CameraManager& rCamMgr);
	virtual ~CameraManager();

	enum class Mode
	{
		Menu,
		OnePlayer,
		TwoPlayer,
		ThreePlayer,
		FourPlayer,
	};

	void SetCurrentCamera(Camera* pCam);
	void SetP1Camera(Camera* pCam);
	void SetP2Camera(Camera* pCam);
	void SetP3Camera(Camera* pCam);
	void SetP4Camera(Camera* pCam);
	Camera* GetCurrentCamera();
	Camera* GetP1Camera();
	Camera* GetP2Camera();
	Camera* GetP3Camera();
	Camera* GetP4Camera();

	void SetCameraMode(Mode mode);

private:
	void SetOnePlayerMode();
	void SetTwoPlayerMode();
	void SetThreePlayerMode();
	void SetFourPlayerMode();

private:
	Mode cameraMode;
	Camera* pDefaultCamera;
	Camera* pCurrentCamera;
	Camera* pP1Camera;
	Camera* pP2Camera;
	Camera* pP3Camera;
	Camera* pP4Camera;
};

#endif