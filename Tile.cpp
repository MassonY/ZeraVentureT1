#include "Tile.h"

Tile::Tile(b2BodyDef* bodydef)
{
	m_body = PhysicalEntity::m_world->CreateBody(bodydef);
	m_sprite.setPosition(BtoSF<float>(m_body->GetPosition()) * PhysicalEntity::SCALE);
}

Tile::~Tile()
{
	m_body->DestroyFixture(m_body->GetFixtureList());
	m_world->DestroyBody(m_body);
}

void Tile::setTexture(sf::Texture* tex){
	m_sprite.setTexture(*tex);
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2));
	b2PolygonShape Box;
	Box.SetAsBox((tex->getSize().x/2)/PhysicalEntity::SCALE , (tex->getSize().y/2)/PhysicalEntity::SCALE);
	m_body->CreateFixture(&Box, 0.0f);
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	target.draw(m_sprite);
}


void Tile::startContact(b2Body*, b2Manifold*){}
void Tile::endContact(b2Body*, b2Manifold*){}
