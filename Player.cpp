#include "Player.h"


Player::Player() : PhysicalEntity()
{
}


Player::~Player()
{
}

void Player::OnEvent(){

	
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		m_body->SetLinearVelocity(b2Vec2(5, m_body->GetLinearVelocity().y));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_body->SetLinearVelocity(b2Vec2(-5, m_body->GetLinearVelocity().y));

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		m_body->SetLinearVelocity(b2Vec2(0, m_body->GetLinearVelocity().y));
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && isOnjump())
		m_body->ApplyLinearImpulse(b2Vec2(0, -20), m_body->GetWorldCenter(), true);
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		m_body->ApplyLinearImpulse(b2Vec2(0, 1), m_body->GetWorldCenter(), true);

	//std::cout << m_allowjump << std::endl;
}

void Player::init(){
	this->create(b2_dynamicBody, sf::Vector2f(100, 100), std::string("loltest"), 1.f, 0.f, 0.05f, true);
	m_body->SetUserData(this);
}

b2Body* Player::getBody(){
	return m_body;
}

void Player::startContact(b2Body* body, b2Manifold* mani){
	std::cout << (float)mani->localNormal.x << " " << (float)mani->localNormal.y << std::endl;
	std::cout << m_allowjump << std::endl;
	if(mani->localNormal.y == 1) 
	m_allowjump ++;
}
void Player::endContact(b2Body* body, b2Manifold* mani){
	std::cout << (float)mani->localNormal.x << " " << (float)mani->localNormal.y << std::endl;
	std::cout << m_allowjump << std::endl;
	if (mani->localNormal.y == 1 )
	m_allowjump --;
}

bool Player::isOnjump(){ 
	return m_allowjump > 0; 
}