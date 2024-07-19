#pragma once
#include "GameplayController.h"
namespace Gameplay {
	class GameplayService {
	private:
		GameplayController* gameplay_controller;
	public:
		GameplayService();
		~GameplayService();

		void initialize();

		void onPositionChanged(int position);
		void onDeath();
	};
}