#include "../../header/Player/PlayerModel.h"
#include "../../header/Level/BlockType.h"

namespace Player {
	PlayerModel::PlayerModel()
	{
	}
	PlayerModel::~PlayerModel()
	{
	}
	void PlayerModel::initialize()
	{
	}
	void PlayerModel::update()
	{
	}
	int PlayerModel::getCurrentPosition()
	{
		return current_position;
	}
	void PlayerModel::setCurrentPosition(int position)
	{
		current_position = position;
	}
	PlayerState PlayerModel::getPlayerState()
	{
		return player_state;
	}
	void PlayerModel::setPlayerState(PlayerState state)
	{
		player_state = state;
	}

	int PlayerModel::getCurrentLives()
	{
		return current_lives;
	}

	void PlayerModel::resetPlayer()
	{
		current_lives = max_lives;
		current_position = 0;
		player_state = PlayerState::ALIVE;
	}

	void PlayerModel::resetCurrentPosition() {
		current_position = 0;
	}

	void PlayerModel::decrementLife() { current_lives--; }

	
}