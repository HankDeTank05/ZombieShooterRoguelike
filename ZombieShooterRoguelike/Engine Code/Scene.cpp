#include "Scene.h"

#include "RegistrationBroker.h"
#include "UpdateManager.h"
#include "DrawManager.h"
#include "CameraManager.h"
#include "UpdateObject.h"
#include "DrawObject.h"

Scene::Scene()
	: pRegBroker(new RegistrationBroker()),
	pUpMgr(new UpdateManager()),
	pDrawMgr(new DrawManager()),
	pInMgr(new InputManager()),
	pCamMgr(new CameraManager())
{
	// do nothing
}
//
//Scene::Scene(const Scene& s)
//	: pRegBroker(new RegistrationBroker(*s.pRegBroker)),
//	pUpMgr(new UpdateManager(*s.pUpMgr)),
//	pDrawMgr(new DrawManager(*s.pDrawMgr)),
//	pCamMgr(new CameraManager(*s.pCamMgr))
//{
//	// do nothing
//}
//
//Scene& Scene::operator=(const Scene& s)
//{
//	pRegBroker = new RegistrationBroker(*s.pRegBroker);
//	pUpMgr = new UpdateManager(*s.pUpMgr);
//	pDrawMgr = new DrawManager(*s.pDrawMgr);
//	pCamMgr = new CameraManager(*s.pCamMgr);
//
//	return *this;
//}

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

UpdateManager::UpdateListPos Scene::Register(UpdateObject* pUpdatable)
{
	return pUpMgr->Register(pUpdatable);
}

void Scene::Deregister(UpdateManager::UpdateListPos updateRef)
{
	pUpMgr->Deregister(updateRef);
}

DrawManager::DrawListPos Scene::Register(DrawObject* pDrawable)
{
	return pDrawMgr->Register(pDrawable);
}

void Scene::Deregister(DrawManager::DrawListPos drawRef)
{
	pDrawMgr->Deregister(drawRef);
}

KeyListener::NotifyListPos Scene::Register(sf::Keyboard::Key key, KeyEvent eventToRegFor, InputObject* pInputable)
{
	return pInMgr->Register(key, eventToRegFor, pInputable);
}

void Scene::Deregister(sf::Keyboard::Key key, KeyEvent eventToDeregFor, KeyListener::NotifyListPos inputRef)
{
	pInMgr->Deregister(key, eventToDeregFor, inputRef);
}
