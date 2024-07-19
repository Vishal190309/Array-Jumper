#pragma once
namespace Event {
	class EventService;
}
namespace Player {
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;
	enum MovementDirection;
	class PlayerController {
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;
		void destroy();


	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		void reset();
		void readInput();
		void move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool isPositionInBound(int targetPosition);
		void takeDamage();
		void onDeath();
		int getCurrentPosition();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentLives();

	};
}