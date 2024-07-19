#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay {
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		delete(gameplayController);
	}
	void GameplayService::initialize()
	{
		gameplayController->initialize();
	}
	void GameplayService::onPositionChanged(int position)
	{
		gameplayController->onPositionChanged(position);
	}
}