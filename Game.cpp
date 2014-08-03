#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include "Game.h"


Game::Game() : m_world(b2World(b2Vec2(0.0f, 10.0f)))
{
	m_window.create(sf::VideoMode(800, 600), "SFML works!");
	m_window.setFramerateLimit(60);
	
	PhysicalEntity::setWorld(&m_world);
	
	m_player.init();

	m_map.loadMap("data/maps/Map1.xml");

	m_camera.init(m_map.size(), sf::Vector2f(m_window.getSize()), &m_player);
	
	m_world.SetContactListener(&m_collisionsEvents);
	setBorder();
}


Game::~Game()
{
}

void Game::OnRun()
{
	while (m_window.isOpen())
	{
		sf::Event event;
		while (m_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				m_window.close();
		}
		m_player.OnEvent();
		m_world.Step(1.0f / 60.0f, 8, 3);
		m_camera.onUpdate();
		m_window.setView(m_camera);
		m_window.clear(sf::Color(208, 244, 247));
		m_player.draw(m_window);
		m_window.draw(m_map);
		m_window.display();
		if (!m_map.getBounds().contains(BtoSF<float>(m_player.getBody()->GetPosition())*PhysicalEntity::SCALE)) m_window.close();
	}
}


void Game::setBorder(){
	b2Body* body;
	b2EdgeShape Edge;
	b2BodyDef def;
	
	def.position = b2Vec2(0, 0);
	def.type = b2_staticBody;
	body = m_world.CreateBody(&def);
	Edge.Set(b2Vec2(0, 0), b2Vec2(m_map.size().x / PhysicalEntity::SCALE, 0));
	body->CreateFixture(&Edge, 0.0f);
	m_borders.push_back(body);

	def.position = b2Vec2(0, 0);
	def.type = b2_staticBody;
	body = m_world.CreateBody(&def);
	Edge.Set(b2Vec2(0, 0), b2Vec2(0, m_map.size().y / PhysicalEntity::SCALE));
	body->CreateFixture(&Edge, 0.0f);
	m_borders.push_back(body);

	def.position = b2Vec2(m_map.size().x / PhysicalEntity::SCALE, 0);
	def.type = b2_staticBody;
	body = m_world.CreateBody(&def);
	body->CreateFixture(&Edge, 0.0f);
	m_borders.push_back(body);
}