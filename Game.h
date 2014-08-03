#pragma once
#include <SFML/Graphics.hpp>
#include "Box2D\Box2D.h"
#include <iostream>
#include "TilesetedMap.h"
#include "Player.h"
#include "Camera.h"
#include "CollisionListener.h"
class Game
{
public:
	Game();
	~Game();

public:

	void OnRun();

private:
	void setBorder();

private:
	//Rendering
	sf::RenderWindow		m_window;
	Camera					m_camera;
	//Physic
	b2World					m_world;
	//Map
	TileSetedMap			m_map;
	std::vector<b2Body*>	m_borders;
	//Entities
	Player					m_player;
	CollisionListener		m_collisionsEvents;
};

