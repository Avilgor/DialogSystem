#include "p2Log.h"
#include "j1Scene.h"
#include "DialogSystem.h"


j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}


j1Scene::~j1Scene()
{}


bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	return true;
}


bool j1Scene::Start()
{
	dSystem = new DialogSystem();
	dSystem->Start();
	return true;
}



bool j1Scene::Update(float dt)
{
	dSystem->Update();
	return true;
}


bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	dSystem->CleanUp();
	return true;
}