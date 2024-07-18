#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"

namespace Player {

	PlayerController::PlayerController()
	{
		playerModel = new PlayerModel();
		playerView = new PlayerView(this);
	}

	PlayerController::~PlayerController() { destroy(); }

	void PlayerController::initialize()
	{
		playerModel->initialize();
		playerView->initialize();
	}

	void PlayerController::update()
	{
		playerView->update();
	}

	void PlayerController::render()
	{
		playerView->render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return playerModel->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState newPlayerState)
	{
		playerModel->setPlayerState(newPlayerState);
	}

	void PlayerController::destroy()
	{
		delete(playerModel);
		delete(playerView);
	}
}