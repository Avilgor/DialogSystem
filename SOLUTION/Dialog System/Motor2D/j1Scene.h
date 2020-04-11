#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "j1App.h"
#include "p2Point.h"
#include "j1Timer.h"
#include "DialogSystem.h"
#include "p2Point.h"

struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiButton;
class GuiInputText;


class j1Scene : public j1Module
{
public:

	j1Scene();

	virtual ~j1Scene();

	bool Awake(pugi::xml_node& config);

	bool Start();

	bool Update(float dt);

	bool CleanUp();


public:

	iPoint initial_camera_position;
	DialogSystem* dSystem;

};

#endif // __j1SCENE_H__