#pragma once
#include"../Header/GraphicService.h"
class ServiceLocator {

private:

	GraphicsService* graphics_service;

	ServiceLocator();
	~ServiceLocator();

	void createServices();
	void clearAllServices();

public:
	static ServiceLocator* getInstance();

	void initialize();
	void update();
	void render();

	GraphicsService* getGraphicsService();
};