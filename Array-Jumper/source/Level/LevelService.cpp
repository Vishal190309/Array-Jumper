
#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelService.h"



namespace Level
{
	LevelService::LevelService()
	{
		level_controller = new LevelController();
	}

	LevelService::~LevelService() { destroy(); }
	



	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	BoxDimensions LevelService::getBoxDimensions() {
		return level_controller->getBoxDimensions();
	}
	

	void LevelService::destroy()
	{
		delete(level_controller);
	}
}