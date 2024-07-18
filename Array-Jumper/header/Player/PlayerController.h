#pragma once
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	class PlayerController {
	private:
		PlayerModel* playe_model;
		PlayerView* player_view;

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
	};
}