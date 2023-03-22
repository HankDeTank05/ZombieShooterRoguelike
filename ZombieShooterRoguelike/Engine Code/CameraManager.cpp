#include "CameraManager.h"

#include "Camera.h"

CameraManager::CameraManager()
	: pDefaultCamera(new Camera()),
	pCurrentCamera(pDefaultCamera)
{
	// do nothing
}

CameraManager::CameraManager(const CameraManager& cm)
	: pDefaultCamera(new Camera(*cm.pDefaultCamera)),
	pCurrentCamera(cm.pCurrentCamera)
{
	// do nothing
}

CameraManager& CameraManager::operator=(const CameraManager& cm)
{
	pDefaultCamera = new Camera(*cm.pDefaultCamera);
	pCurrentCamera = cm.pCurrentCamera;

	return *this;
}

CameraManager::~CameraManager()
{
	delete pDefaultCamera;
}

void CameraManager::SetCurrentCamera(Camera* pCam)
{
	pCurrentCamera = pCam;
}

Camera* CameraManager::GetCurrentCamera()
{
	return pCurrentCamera;
}
