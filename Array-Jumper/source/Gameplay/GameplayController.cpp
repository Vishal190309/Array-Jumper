#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/BlockType.h"

namespace Gameplay {

	using namespace Global;
	using namespace Level;
	GameplayController::GameplayController()
	{
	}
	GameplayController::~GameplayController()
	{
	}
	void GameplayController::initialize()
	{
	}
	bool GameplayController::isObstacle(BlockType value)
	{
		if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
			return true;
		return false;
	}

	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	void GameplayController::onPositionChanged(int position)
	{
		BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
			processObstacle();
	}

}