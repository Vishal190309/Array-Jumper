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
		bool isEndBlock(Level::BlockType value);
		void processEndBlock();
		void processObstacle();
		void onPositionChanged(int position);
	};
}