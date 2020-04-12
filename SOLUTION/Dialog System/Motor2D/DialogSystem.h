#ifndef __DIALOGSYSTEM_H__
#define __DIALOGSYSTEM_H__

#include "j1Module.h"

#define CHOOSE_OPTION 1

struct SDL_Texture;
class GuiImage;
class GuiText;
class GuiButton;
class GuiInputText;

enum Option
{
	NONE,
	OPTION_A,
	OPTION_B,
	OPTION_C
};

class DialogSystem : j1Module
{
public:
	DialogSystem();
	~DialogSystem();
	
	bool Start();

	bool Update();

	bool CleanUp();

	void CreateScreenUI();
	void UpdateScreenUI(Option answer = NONE);


public:  

	GuiImage* retail;
	GuiText* txt;
	GuiText* txtOptionA;
	GuiText* txtOptionB;
	GuiText* txtOptionC;
	bool end;
	bool question;
	int dStep;
};
#endif