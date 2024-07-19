#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay {
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
	}
	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}
	void GameplayService::onPositionChanged(int position)
	{
		gameplay_controller->onPositionChanged(position);
	}
	void GameplayService::onDeath() 
	{ 
		gameplay_controller->onDeath(); 
	}
}