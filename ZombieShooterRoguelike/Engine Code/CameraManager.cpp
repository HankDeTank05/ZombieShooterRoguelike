#include "CameraManager.h"

#include "Camera.h"

void CameraManager::SetCurrentCamera(Camera* pCam)
{
	pCurrentCamera = pCam;
}

void CameraManager::SetP1Camera(Camera* pCam)
{
	pP1Camera = pCam;
}

void CameraManager::SetP2Camera(Camera* pCam)
{
	pP2Camera = pCam;
}

void CameraManager::SetP3Camera(Camera* pCam)
{
	pP3Camera = pCam;
}

void CameraManager::SetP4Camera(Camera* pCam)
{
	pP4Camera = pCam;
}

Camera* CameraManager::GetCurrentCamera()
{
	return pCurrentCamera;
}

Camera* CameraManager::GetP1Camera()
{
	return pP1Camera;
}

Camera* CameraManager::GetP2Camera()
{
	return pP2Camera;
}

Camera* CameraManager::GetP3Camera()
{
	return pP3Camera;
}

Camera* CameraManager::GetP4Camera()
{
	return pP4Camera;
}

void CameraManager::SetCameraMode(Mode mode)
{
	cameraMode = mode;
}
