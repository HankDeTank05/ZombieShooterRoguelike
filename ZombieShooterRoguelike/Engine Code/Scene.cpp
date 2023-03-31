#include "Scene.h"

#include "RegistrationBroker.h"
#include "UpdatableManager.h"
#include "TDrawableManager.h"
#include "CameraManager.h"
#include "Updatable.h"
#include "TDrawable.h"

Scene::Scene()
	: pRegBroker(new RegistrationBroker()),
	pUpMgr(new UpdatableManager()),
	pDrawMgr(new TDrawableManager()),
	pCamMgr(new CameraManager())
{
	// do nothing
}

Scene::Scene(const Scene& s)
	: pRegBroker(new RegistrationBroker(*s.pRegBroker)),
	pUpMgr(new UpdatableManager(*s.pUpMgr)),
	pDrawMgr(new TDrawableManager(*s.pDrawMgr)),
	pCamMgr(new CameraManager(*s.pCamMgr))
{
	// do nothing
}

Scene& Scene::operator=(const Scene& s)
{
	pRegBroker = new RegistrationBroker(*s.pRegBroker);
	pUpMgr = new UpdatableManager(*s.pUpMgr);
	pDrawMgr = new TDrawableManager(*s.pDrawMgr);
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

void Scene::EnqueueCommand(Command* pCommand)
{
	pRegBroker->AddCommand(pCommand);
}

UpdatableManager::UpdateListPos Scene::Register(Updatable* pUpdatable)
{
	return pUpMgr->Register(pUpdatable);
}

void Scene::Deregister(UpdatableManager::UpdateListPos updateRef)
{
	pUpMgr->Deregister(updateRef);
}

TDrawableManager::DrawListPos Scene::Register(TDrawable* pDrawable)
{
	return pDrawMgr->Register(pDrawable);
}

void Scene::Deregister(TDrawableManager::DrawListPos drawRef)
{
	pDrawMgr->Deregister(drawRef);
}
