#include "../../Header/Player/PlayerModel.h";

namespace Player {

	PlayerModel::PlayerModel() { }

	PlayerModel::~PlayerModel() { }

	void PlayerModel::initialize() { reset(); }

	void PlayerModel::reset()
	{
		player_state = PlayerState::ALIVE;
		player_position = initial_player_position;
		player_score = 0;
	}

	int PlayerModel::getPlayerScore()
	{
		return player_score;
	}

	void PlayerModel::setPlayerScore(int value)
	{
		player_score = value;
	}

	sf::Vector2f PlayerModel::getPlayerPosition()
	{
		return player_position;
	}

	void PlayerModel::setPlayerPosition(sf::Vector2f position)
	{
		player_position = position;
	}

	bool PlayerModel::getPlayerAlive()
	{
		return player_alive;
	}

	void PlayerModel::setPlayerAlive(bool alive)
	{
		player_alive = alive;
	}
}