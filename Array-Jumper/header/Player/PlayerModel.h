#pragma once
namespace Player {
	enum class PlayerState {
		ALIVE,
		DEAD
	};

	class PlayerModel {
	private:
		int current_position;
		PlayerState player_state;

		const int max_lives = 3;
		int current_lives;
	public:
		PlayerModel();
		~PlayerModel();
		void initialize();
		void update();
		int getCurrentPosition();
		void setCurrentPosition(int position);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);

		int getCurrentLives();
		void resetPlayer();
		void resetCurrentPosition();
		void decrementLife();
	};

	
}