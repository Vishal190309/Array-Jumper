#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService() { playe_controller = new PlayerController(); }

	PlayerService::~PlayerService() { destroy(); }

	void PlayerService::initialize()
	{
		playe_controller->initialize();
	}

	void PlayerService::update()
	{
		playe_controller->update();
	}

	void PlayerService::render()
	{
		playe_controller->render();
	}

	void PlayerService::destroy() { delete(playe_controller); }
}
