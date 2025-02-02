#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Event/EventService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Gameplay;
	using namespace Player;
	using namespace Level;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		player_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		gameplay_service = new GameplayService();
		player_service = new PlayerService();
		level_service = new LevelService();
		event_service = new EventService();
		sound_service = new SoundService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		sound_service->initialize();
		ui_service->initialize();
		gameplay_service->initialize();
		level_service->initialize();
		player_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		ui_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->update();
			player_service->update();
			
		}
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		ui_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->render();
			player_service->render();
			
		}
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(player_service);
		delete(level_service);
		delete(event_service);
		delete(sound_service);
		delete(ui_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	Player::PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	Level::LevelService* ServiceLocator::getLevelService()
	{
		return level_service;
	}

	Gameplay::GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }
}