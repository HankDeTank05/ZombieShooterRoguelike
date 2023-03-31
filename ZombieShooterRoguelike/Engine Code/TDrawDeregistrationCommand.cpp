#include "TDrawDeregistrationCommand.h"

#include "SceneManager.h"
#include "Scene.h"

TDrawDeregistrationCommand::TDrawDeregistrationCommand(TDrawable* _pDrawable)
	: pDrawable(_pDrawable)
{
	// do nothing
}

TDrawDeregistrationCommand::~TDrawDeregistrationCommand()
{
	// do nothing
}

void TDrawDeregistrationCommand::Execute()
{
	SceneManager::GetCurrentScene()->
}
