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
	question = false;
	dStep = 0;
	end = false;
	CreateScreenUI();
	UpdateScreenUI();
	return true;
}


bool DialogSystem::Update()
{
	bool ret = true;
	if (!end)
	{
		if (question)
		{
			if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
			{
				UpdateScreenUI(OPTION_A);
			}
			else if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
			{
				UpdateScreenUI(OPTION_B);
			}
			else if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
			{
				UpdateScreenUI(OPTION_C);
			}
		}
		else
		{
			if (App->input->GetKey(SDL_SCANCODE_SPACE))
			{
				UpdateScreenUI();
			}
		}		
	}

	if (end)
	{
		if (App->input->GetKey(SDL_SCANCODE_SPACE))
		{
			retail->to_delete = true;
			txt->to_delete = true;
			txtOptionA->to_delete = true;
			txtOptionB->to_delete = true;
			txtOptionC->to_delete = true;
		}
	}
	return ret;
}

void DialogSystem::CreateScreenUI()
{
	retail = (GuiImage*)App->gui->CreateUIElement(UI_Type::IMAGE, this);//Retail image
	retail->Init({ 40, 450 }, { 0,0,945,266 });

	p2SString line(" ");
	txt = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, retail);//Text	
	txt->Init({ 60, 470 }, line);

	txtOptionA = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, retail);//Option A
	txtOptionA->Init({ 60, 510 }, line);

	txtOptionB = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, retail);//Option B
	txtOptionB->Init({ 60, 550 }, line);

	txtOptionC = (GuiText*)App->gui->CreateUIElement(UI_Type::TEXT, this, retail);//Option C
	txtOptionC->Init({ 60, 590 }, line);
}

void DialogSystem::UpdateScreenUI(Option answer)
{
	switch (dStep)
	{
		case 0: 
			txt->text = "Press space to see next text.";
			dStep += 1;
			break;
		case 1:
			txt->text = "Now choose one option:";
			txtOptionA->text = "1-Option A.";
			txtOptionB->text = "2-Option B.";
			txtOptionC->text = "3-Option C.";
			txtOptionA->UpdateText();
			txtOptionB->UpdateText();
			txtOptionC->UpdateText();
			question = true;
			dStep += 1;
			break;
		case 2: 
			txtOptionA->text = "";
			txtOptionB->text = "";
			txtOptionC->text = "";
			txtOptionA->UpdateText();
			txtOptionB->UpdateText();
			txtOptionC->UpdateText();
			switch (answer)
			{
				case OPTION_A:
					txt->text = "This is option A.";
					question = false;
					dStep += 1;
					break;
				case OPTION_B:
					txt->text = "This is option B.";
					question = false;
					dStep += 1;
					break;
				case OPTION_C:
					txt->text = "This is option C.";
					question = false;
					dStep += 1;
					break;
			}
			break;
		case 3: 
			txt->text = "Want to finish?";
			txtOptionA->text = "1- Yes.";
			txtOptionB->text = "2- No.";
			txtOptionA->UpdateText();
			txtOptionB->UpdateText();
			question = true;
			dStep += 1;
			break;
		case 4:
			txtOptionA->text = "";
			txtOptionB->text = "";
			txtOptionA->UpdateText();
			txtOptionB->UpdateText();
			switch (answer)
			{
				case OPTION_A:
					txt->text = "Dialog end.";
					question = false;
					end = true;
					break;
				case OPTION_B:
					dStep = CHOOSE_OPTION;
					question = false;
					UpdateScreenUI();					
					break;
			}
			break;
	}
	txt->UpdateText();
}


bool DialogSystem::CleanUp()
{
	return true;
}
