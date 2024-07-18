#pragma once
namespace Player {
	enum class PlayerState {
		ALIVE,
		DEAD
	};

	class PlayerModel {
	private:
		int currentPosition;
		PlayerState playerState;
	public:
		PlayerModel();
		~PlayerModel();
		void initialize();
		void update();
		int getCurrentPosition();
		void setCurrentPosition(int position);

		PlayerState getPlayerState();
		void setPlayerState(PlayerState state);
	};

	
}