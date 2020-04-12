#include "j1App.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "DialogSystem.h"
#include "p2Log.h"

DialogSystem::DialogSystem() : j1Module()
{
	name.create("dialogSystem");
}

DialogSystem::~DialogSystem()
{}

bool DialogSystem::Start()
{
	////TODO 5:
	//
	//Set varibles values 


	////TODO 3:
	//
	//Call create UI function


	////TODO 5:
	//
	//Call update UI function

	return true;
}


bool DialogSystem::Update()
{
	bool ret = true;

	////Optional:
	//
	//Check only if dialog is not ended

	////TODO 5:
	//
	//Check keyboard keys
	//Call update UI function if needed


	////Optional:
	//
	//If dialog ends and key pressed, clean screen
	
	return ret;
}


////TODO3:
//
//Define create UI function


////TODO 6:
//
//Define update UI function



bool DialogSystem::CleanUp()
{
	return true;
}
