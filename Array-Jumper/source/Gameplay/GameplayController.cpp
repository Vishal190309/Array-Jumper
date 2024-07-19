#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/BlockType.h"
#include "../../header/Main/GameService.h"

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

	bool GameplayController::isEndBlock(Level::BlockType value)
	{
		if (value == BlockType::TARGET)
			return true;
		return false;
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);
		Main::GameService::setGameState(Main::GameState::CREDITS);
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

		if(isEndBlock(value))
			processEndBlock();
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameOver()
	{
		Main::GameService::setGameState(Main::GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

}