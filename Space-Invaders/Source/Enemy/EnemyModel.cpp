#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{

		enemy_type = type;
	}

	EnemyModel::~EnemyModel() { }

	void EnemyModel::initialize()
	{
		enemy_state = EnemyState::PATROLLING;
		enemy_position = reference_position;
		movement_direction = MovementDirection::RIGHT;
	}

	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	MovementDirection EnemyModel::getMovementDirection()
	{
		return movement_direction;
	}

	void EnemyModel::setMovementDirection(MovementDirection direction)
	{
		movement_direction = direction;
	}
	EnemyType EnemyModel::getEnemyType()
	{
		return enemy_type;
	}
	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}
	void EnemyModel::setEnemyType(EnemyType type)
	{
		enemy_type = type;
	}
	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}
}