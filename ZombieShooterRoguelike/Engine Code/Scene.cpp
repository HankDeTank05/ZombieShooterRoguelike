#include "Scene.h"

#include "RegistrationBroker.h"
#include "UpdatableManager.h"
#include "DrawableManager.h"
#include "CameraManager.h"

Scene::Scene()
	: pRegBroker(new RegistrationBroker()),
	pUpMgr(new UpdatableManager()),
	pDrawMgr(new DrawableManager()),
	pCamMgr(new CameraManager())
{
	// do nothing
}

Scene::Scene(const Scene& s)
	: pRegBroker(new RegistrationBroker(*s.pRegBroker)),
	pUpMgr(new UpdatableManager(*s.pUpMgr)),
	pDrawMgr(new DrawableManager(*s.pDrawMgr)),
	pCamMgr(new CameraManager(*s.pCamMgr))
{
	// do nothing
}

Scene& Scene::operator=(const Scene& s)
{
	pRegBroker = new RegistrationBroker(*s.pRegBroker);
	pUpMgr = new UpdatableManager(*s.pUpMgr);
	pDrawMgr = new DrawableManager(*s.pDrawMgr);
	pCamMgr = new CameraManager(*s.pCamMgr);

	return *this;
}

Scene::~Scene()
{
	delete pCamMgr;
	delete pDrawMgr;
	delete pUpMgr;

	delete pRegBroker;
}

void Scene::Update()
{
	pRegBroker->ExecuteCommands();

	pUpMgr->UpdateElements();
}

void Scene::Draw()
{
	pDrawMgr->DrawElements();
}
