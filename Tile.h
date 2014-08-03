#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"
#include "utility.h"
#include "PhysicalEntity.h"

// SETWORLD BEFORE CREATE ANY TILES
class Tile : public sf::Drawable, PhysicalEntity
{
public:
	Tile(b2BodyDef*);
	~Tile();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
	
	//setters
	void setTexture(sf::Texture*);
	
	//getters
	sf::Vector2f getPosition();

	void startContact(b2Body*, b2Manifold*);
	void endContact(b2Body*, b2Manifold*);
private:

private:
	sf::Sprite		m_sprite;
	b2Body*			m_body;
};

