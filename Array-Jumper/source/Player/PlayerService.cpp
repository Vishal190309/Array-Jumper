#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService() { playerController = new PlayerController(); }

	PlayerService::~PlayerService() { destroy(); }

	void PlayerService::initialize()
	{
		playerController->initialize();
	}

	void PlayerService::update()
	{
		playerController->update();
	}

	void PlayerService::render()
	{
		playerController->render();
	}

	void PlayerService::destroy() { delete(playerController); }
}
