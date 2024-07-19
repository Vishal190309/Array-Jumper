#pragma once
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	class PlayerController {
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void destroy();

		void resetPlayer();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		int getCurrentPosition();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
	};
}