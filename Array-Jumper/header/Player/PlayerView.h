#pragma once
#include "../../header/UI/UIElement/ImageView.h"
namespace Player {
	class PlayerView {
	private:
		UI::UIElement::ImageView* playerImage;
		sf::RenderWindow* gameWindow;
		class PlayerController* playerController;

		float playerWidth;
		float playerHeight;


		void initializePlayerImage(); //Initialize player_image 
		void drawPlayer(); //Called every frame to render the sprite on the screen
		void loadPlayer(); //Loads the information needed to render the player
		void calculatePlayerDimensions(); //Calculate the size of image
		sf::Vector2f calulcatePlayerPosition();
		void updatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}