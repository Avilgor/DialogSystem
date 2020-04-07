#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "DialogSystem.h"

DialogSystem::DialogSystem() : j1Module()
{
	name.create("dialog_system");
}