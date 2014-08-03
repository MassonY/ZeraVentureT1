#include "PhysicalEntity.h"
b2World* PhysicalEntity::m_world;
const float PhysicalEntity::SCALE = 30.0f;
PhysicalEntity::PhysicalEntity(){
}

void PhysicalEntity::setWorld(b2World* world){
	m_world = world;
}

void PhysicalEntity::draw(sf::RenderTarget &target){
	m_sprite.setPosition(BtoSF<float>(m_body->GetPosition())*PhysicalEntity::SCALE);
	m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	draw(target, sf::RenderStates::Default);
}
void PhysicalEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_sprite);
}

void PhysicalEntity::create(b2BodyType type, sf::Vector2f& Position, std::string& path, float density, float friction, float restitution, bool fixrotate){
	b2BodyDef def;
	def.type = type;
	def.fixedRotation = fixrotate;
	def.position = SFtoB(Position / PhysicalEntity::SCALE);
	m_body = m_world->CreateBody(&def);
	m_sprite.setPosition(Position);
	m_sprite.setRotation(m_body->GetAngle() * 180 / b2_pi);
	m_body->SetUserData(this);
	m_sprite.setTexture(*TextureHolder::getTexture("player/" + path));
	m_sprite.setOrigin(sf::Vector2f(m_sprite.getLocalBounds().width / 2, m_sprite.getLocalBounds().height / 2));

	b2PolygonShape Box;
	Box.SetAsBox((m_sprite.getTexture()->getSize().x / 2) / PhysicalEntity::SCALE, (m_sprite.getTexture()->getSize().y / 2) / PhysicalEntity::SCALE);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &Box;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;

	m_body->CreateFixture(&fixtureDef);
}

const sf::Vector2f& PhysicalEntity::getPosition(){
	return m_sprite.getPosition();
}

const sf::Vector2f& PhysicalEntity::getSize(){
	return sf::Vector2f(m_sprite.getTexture()->getSize());
}