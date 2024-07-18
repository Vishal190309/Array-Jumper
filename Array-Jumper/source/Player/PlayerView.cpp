#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

namespace Player {
	using namespace UI::UIElement;
	using namespace Global;
	void PlayerView::initializePlayerImage()
	{
		playerImage->initialize(Config::character_texture_path, playerWidth, playerHeight, sf::Vector2f(0.f, 0.f));
	}
	void PlayerView::drawPlayer()
	{
		playerImage->render();
	}
	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}
	void PlayerView::calculatePlayerDimensions()
	{
		playerWidth = 1000.f;
		playerHeight = 1000.f;
	}
	sf::Vector2f PlayerView::calulcatePlayerPosition()
	{
		return sf::Vector2f(0.f,0.f);
	}
	void PlayerView::updatePlayerPosition()
	{
		playerImage->setPosition(calulcatePlayerPosition());
	}
	PlayerView::PlayerView(PlayerController* controller)
	{
		playerController = controller;
		gameWindow = nullptr;
		playerImage = new ImageView();
	}
	PlayerView::~PlayerView()
	{
	}
	void PlayerView::initialize()
	{
		gameWindow = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}
	void PlayerView::update()
	{
		updatePlayerPosition();
	}
	void PlayerView::render()
	{
		switch (playerController->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		default:
			break;
		}
	}
}