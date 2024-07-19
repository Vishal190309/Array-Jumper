#pragma once
#include "../../header/Level/BlockType.h"
namespace Gameplay {
	class GameplayController {
	private:
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		bool isObstacle(Level::BlockType value);
		void processObstacle();
		void onPositionChanged(int position);
	};
}