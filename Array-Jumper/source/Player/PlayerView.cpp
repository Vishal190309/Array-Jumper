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
		player_image->initialize(Config::character_texture_path, player_width, player_height, sf::Vector2f(0.f, 0.f));
	}
	void PlayerView::drawPlayer()
	{
		player_image->render();
	}
	void PlayerView::loadPlayer()
	{
		calculatePlayerDimensions();
		initializePlayerImage();
	}
	void PlayerView::calculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
	}
	sf::Vector2f PlayerView::calculatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}
	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(calculatePlayerPosition());
	}
	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		game_window = nullptr;
		player_image = new ImageView();
	}
	PlayerView::~PlayerView()
	{
	}
	void PlayerView::initialize()
	{
		game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		loadPlayer();
	}
	void PlayerView::update()
	{
		updatePlayerPosition();
	}
	void PlayerView::render()
	{
		switch (player_controller->getPlayerState())
		{
		case PlayerState::ALIVE:
			drawPlayer();
			break;
		default:
			break;
		}
	}

	
}