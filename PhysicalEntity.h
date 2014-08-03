#pragma once
#include "Box2D\Box2D.h"
#include "log.h"
#include "utility.h"
#include "TextureHolder.h"
class PhysicalEntity : public sf::Drawable
{
public:
	PhysicalEntity();
	static void setWorld(b2World* world);

	void draw(sf::RenderTarget &target);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	
	void create(b2BodyType, sf::Vector2f&, std::string&, float density = 1.0f, float friction = 10.f, float restitution = 0.05f, bool = false);

	const sf::Vector2f& getPosition();
	const sf::Vector2f& getSize();
	static const float SCALE;

	virtual void startContact(b2Body*, b2Manifold*) = 0;
	virtual void endContact(b2Body*, b2Manifold*) = 0;

protected:


protected:
	static b2World* m_world;

	b2Body*			m_body;
	sf::Sprite		m_sprite;

};