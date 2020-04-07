#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Scene.h"
#include "j1Gui.h"
#include "DialogSystem.h"


j1Scene::j1Scene() : j1Module()
{
	name.create("scene");

	blocked_camera = false;
	
	max_time = relative_max_time = time_left =200;
	
	camera_margin = 5;
	initial_camera_position = { 0,0 };
	showing_menu = false;
	fullscreen = false;
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	folder.create(config.child("folder").child_value());
	camera_frame_x_margin = config.child("camera_frame").attribute("x").as_int();
	camera_frame_y_margin = config.child("camera_frame").attribute("y").as_int();
	camera_frame.w = config.child("camera_frame").attribute("w").as_int();
	camera_frame.h = config.child("camera_frame").attribute("h").as_int();
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	SDL_Rect*	camera = &App->render->camera;
	float		camera_frame_x_center = ceil(camera_frame.x + camera_frame.w * 0.5f);
	float		camera_frame_y_center = ceil(camera_frame.y + camera_frame.h * 0.5f);
	bool		camera_manual_control = false;
	camera_frame.x = -camera->x + camera_frame_x_margin;
	camera_frame.y = -camera->y + camera_frame_y_margin;


	if (App->input->GetKey(SDL_SCANCODE_F5) == KEY_DOWN)
		App->SaveGame();

	if(App->input->GetKey(SDL_SCANCODE_F6) == KEY_DOWN)
		App->LoadGame();

	
	UpdateScreenUI();

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;
	return ret;
}

bool j1Scene::CleanUp()
{
	LOG("Freeing scene");
	return true;
}


void j1Scene::UpdateScreenUI() {

	if (App->entities->player_pointer != nullptr) {
		if ((lives.start != nullptr) && (on_screen_lives > App->entities->player_pointer->lives))
		{
			App->gui->DestroyUIElement(lives.end->data);
			lives.del(lives.end);
			on_screen_lives--;
			relative_max_time = max_time;
			timer.Start();
		}

		if ((stars.start != nullptr) && (timer.Read() > time_star1 * 1000)) {

			App->gui->DestroyUIElement(stars.end->data);
			stars.del(stars.end);
		}

		if ((stars.start != nullptr) && (timer.Read() > time_star2 * 1000)) {

			App->gui->DestroyUIElement(stars.end->data);
			stars.del(stars.end);
		}

		if ((stars.start != nullptr) && (timer.Read() > time_star3 * 1000)) {

			App->gui->DestroyUIElement(stars.end->data);
			stars.del(stars.end);
		}

		if (time_text != nullptr)
		{
			if (performance_timer.Read() > 1000)
			{
				time_left = relative_max_time - timer.ReadSec();
				p2SString temp("%i", time_left);
				time_count->text.Clear();
				if (temp.Length() > 0) time_count->text = temp;
				time_count->UpdateText();
				performance_timer.Start();
			}


			if (on_screen_score != App->entities->player_pointer->score) {
				p2SString coin("     %i points", App->entities->player_pointer->score);
				score->text.Clear();
				score->text = coin;
				score->UpdateText();
				on_screen_score = App->entities->player_pointer->score;
			}
		}
	}
}


void j1Scene::CreatePauseMenu() {

	GuiImage* menu_background = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this);
	menu_background->Init({ 250, 250 }, { 0,0,512,264 });
	pause_menu.add(menu_background);

	GuiImage* pause_text = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this,menu_background);
	pause_text->Init({ 298, 155 }, { 897,0,420,104 });
	pause_menu.add(pause_text);

	GuiButton* resume_button = (GuiButton*)App->gui->CreateUIElement(UI_Type::BUTTON, this, menu_background, false, true);
	resume_button->Init({ 445, 325 }, { 658,837,117,120 }, { 658,837,117,120 }, { 775,837,117,120 }, "", ButtonAction::CONTINUE);
	pause_menu.add(resume_button);

	GuiButton* home_button = (GuiButton*)App->gui->CreateUIElement(UI_Type::BUTTON, this, menu_background, false, true);
	home_button->Init({ 285, 325 }, { 416,837,117,120 }, { 416,837,117,120 }, { 534,837,117,120 },"",ButtonAction::QUIT);
	pause_menu.add(home_button);

	GuiButton* settings_button = (GuiButton*)App->gui->CreateUIElement(UI_Type::BUTTON, this, menu_background, false, true);
	settings_button->Init({ 605,325 }, { 658,596,117,120 }, { 658,596,117,120 }, { 777,596,117,120 }, "", ButtonAction::SETTINGS);
	pause_menu.add(settings_button);

	if ((stars.start != nullptr) && (timer.Read() < time_star1 * 1000)) {

		star1 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star1->Init({ 420 , 225 }, { 589,124, 76, 69 });

		star2 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star2->Init({ 470 , 225 }, { 589,124, 76, 69 });

		star3 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star3->Init({ 520 , 225 }, { 589,124, 76, 69 });

		pause_menu.add(star1);
		pause_menu.add(star2);
		pause_menu.add(star3);
	}

	if ((stars.start != nullptr) && (timer.Read() < time_star2 * 1000) && (timer.Read() > time_star1 * 1000)) {
		star1 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star1->Init({ 420 , 225 }, { 589,124, 76, 69 });

		star2 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star2->Init({ 470 , 225 }, { 589,124, 76, 69 });

		pause_menu.add(star1);
		pause_menu.add(star2);
	}

	if ((stars.start != nullptr) && (timer.Read() < time_star3 * 1000) && (timer.Read() > time_star2 * 1000)) {
		star3 = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star3->Init({  420 , 225 }, { 589,124, 76, 69 });

		pause_menu.add(star1);
	}
}

void j1Scene::CreateScreenUI()
{
	timer.Start();
	int livesXpos = 50;
	int livesXDistance = 90;

	int starsXpos = 400;
	int starsXDistance = 50;

	int nostarsXpos = 400;
	int nostarsXDistance = 50;

	int timeXpos = 700;



	for (int i = 0; i < 3; i++)
	{
		GuiImage* star = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
		star->Init({ starsXpos , 20 }, { 589,124, 76, 69 });
		starsXpos += starsXDistance;
		stars.add(star);
		on_screen_ui.add(star);
	}

	coins = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
	coins->Init({ 30, 625 }, { 9,865,294,69 });
	on_screen_ui.add(coins);

	timer_background = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this, nullptr);
	timer_background->Init({ 700, 10 }, { 240,978, 289,78 });
	on_screen_ui.add(timer_background);

	time_left = time_left - timer.ReadSec() * 0.001f;
	time_text = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, timer_background);
	time_text->Init({ 730, 20 }, "Time: ");
	on_screen_ui.add(time_text);

	time_count = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, timer_background);
	p2SString temp("%i", time_left);
	time_count->Init({ 810, 20 }, temp);
	on_screen_ui.add(time_count);

	score = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, coins);
	p2SString coin("     %i points", App->entities->player_pointer->score);
	score->Init({ 100, 632 }, coin);
	on_screen_ui.add(score);
}