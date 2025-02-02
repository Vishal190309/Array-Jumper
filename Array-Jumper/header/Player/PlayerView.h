#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/Level/LevelModel.h"
namespace Player {
	class PlayerView {
	private:
		UI::UIElement::ImageView* player_image;
		sf::RenderWindow* game_window;
		class PlayerController* player_controller;
		Level::BoxDimensions current_box_dimensions;

		float player_width;
		float player_height;


		void initializePlayerImage(); //Initialize player_image 
		void drawPlayer(); //Called every frame to render the sprite on the screen
		void loadPlayer(); //Loads the information needed to render the player
		void calculatePlayerDimensions(); //Calculate the size of image
		sf::Vector2f calculatePlayerPosition();
		void updatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
		
	};
}