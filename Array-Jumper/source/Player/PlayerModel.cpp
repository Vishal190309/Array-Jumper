#include "../../header/Player/PlayerModel.h"

namespace Player {
	int PlayerModel::getCurrentPosition()
	{
		return currentPosition;
	}
	void PlayerModel::setCurrentPosition(int position)
	{
		currentPosition = position;
	}
	PlayerState PlayerModel::getPlayerState()
	{
		return playerState;
	}
	void PlayerModel::setPlayerState(PlayerState state)
	{
		playerState = state;
	}
}