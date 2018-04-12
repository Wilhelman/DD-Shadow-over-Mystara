#include "ctDefs.h"
#include "ctLog.h"
#include "ctApp.h"
#include "ctInput.h"
#include "ctTextures.h"
#include "ctAudio.h"
#include "ctRender.h"
#include "ctWindow.h"
#include "ctEntities.h"
#include "ctTaskManager.h"
#include "j1Map.h"

#include "ctTabernScene.h"
#include "ctCombat.h"
#include "Entity.h"

#include "MiniHeroes.h"

#include "ctFadeToBlack.h"

#include "ctGui.h"
#include "UIElement.h"
#include "UIDecision.h"


//randomize libs
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */



ctTabernScene::ctTabernScene() : ctModule()
{
	name = "world_map";
}

// Destructor
ctTabernScene::~ctTabernScene()
{}

// Called before render is available

bool ctTabernScene::Awake(pugi::xml_node& config)
{
	LOG("Loading World Map");
	bool ret = true;



	return ret;
}

// Called before the first frame
bool ctTabernScene::Start()
{
	bool ret = true;

	background = App->gui->AddUIImage(0, 0, { 313, 144, 484, 324 }, this);

	return ret;
}

// Called each loop iteration
bool ctTabernScene::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool ctTabernScene::Update(float dt)
{



	// Draw everything --------------------------------------
	App->map->Draw();
	
	return true;
}

// Called each loop iteration
bool ctTabernScene::PostUpdate()
{
	bool ret = true;


	return ret;
}

// Called before quitting
bool ctTabernScene::CleanUp()
{
	LOG("Freeing ctWorldMap");

	App->audio->StopMusic();
	//App->audio->UnLoadFx(menu_move_fx);




	//TODO CLEAN THIS
	/*std::vector<WorldMapElement*>::const_iterator it_map_elements = map_elements.begin();

	while (it_map_elements != map_elements.end()) {
	delete *it_map_elements;
	it_map_elements++;
	}

	map_elements.clear();*/

	if (App->entities->GetMiniheroes() != nullptr)
		App->entities->GetMiniheroes()->to_destroy = true;

	App->map->CleanUp();

	return true;
}

bool ctTabernScene::Load(pugi::xml_node& load)
{
	bool ret = true;

	return ret;
}

bool ctTabernScene::Save(pugi::xml_node& save) const
{
	bool ret = true;

	return ret;
}

void ctTabernScene::OnUITrigger(UIElement* elementTriggered, UI_State ui_state)
{

}

