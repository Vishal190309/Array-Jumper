#pragma once
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	class PlayerController {
	private:
		PlayerModel* playerModel;
		PlayerView* playerView;

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState newPlayerState);
	};
}