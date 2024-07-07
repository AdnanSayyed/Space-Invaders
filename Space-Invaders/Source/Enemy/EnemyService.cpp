#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	using namespace Global;


	EnemyService::EnemyService()
	{
		enemy_controller = nullptr;
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
		enemy_controller->update();
	}

	void EnemyService::render()
	{
		enemy_controller->render();
	}

	EnemyController* EnemyService::spawnEnemy()
	{
		enemy_controller = new EnemyController();
		enemy_controller->initialize();

		return enemy_controller;
	}

	void EnemyService::destroy()
	{
		delete(enemy_controller);
	}
	

}