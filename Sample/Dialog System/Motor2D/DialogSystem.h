#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "j1Module.h"
#include "j1App.h"


struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiButton;
class GuiInputText;

class DialogSystem : j1Module
{
	DialogSystem();
	~DialogSystem();

	// Called before render is available
	bool Awake(pugi::xml_node& config);
	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();
	// Called each loop iteration
	bool Update(float dt);
	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();


	void CreateScreenUI();

	void UpdateScreenUI();
};
#endif