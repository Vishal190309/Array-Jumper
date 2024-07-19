#pragma once
#include "../../header/Level/BlockType.h"
namespace Gameplay {
	class GameplayController {
	private:

		bool isObstacle(Level::BlockType value);
		bool isEndBlock(Level::BlockType value);
		void processEndBlock();
		bool isLastLevel();
		void gameWon();
		void loadNextLevel();
		void processObstacle();
		void gameOver();
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void onPositionChanged(int position);
		void onDeath();
	};
}