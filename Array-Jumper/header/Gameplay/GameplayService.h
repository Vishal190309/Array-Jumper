#pragma once
#include "GameplayController.h"
namespace Gameplay {
	class GameplayService {
	private:
		GameplayController* gameplayController;
	public:
		GameplayService();
		~GameplayService();

		void initialize();

		void onPositionChanged(int position);
	};
}