#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "j1Module.h"


struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiButton;
class GuiInputText;

////TODO 4:
//
//Declare enum for options


class DialogSystem : j1Module
{
public:
	DialogSystem();
	~DialogSystem();
	
	bool Start();

	bool Update();

	bool CleanUp();
	////TODO 2:
	//
	//Declare function to create and update UI


	//TODO 4:
	//
	//Declare update UI function



public:  

	////TODO 2:
	//
	//Declare varibles for UI elements


	////TODO 4:
	//
	//Declare dialog control variables


	////Optional
	//
	//Declare variable for dialog end
};
#endif