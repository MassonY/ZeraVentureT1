#include "Camera.h"

Camera::Camera() {}

void Camera::init(const sf::Vector2f& worldSize, const sf::Vector2f& windowSize, PhysicalEntity* player) {
	m_worldSize = worldSize;
	this->setSize(windowSize);
	m_cage.left = windowSize.x / 4;
	m_cage.top = windowSize.y / 4;
	m_cage.width = windowSize.x / 2;
	m_cage.height = windowSize.y / 2;
	centerOn(player);
	clamp();
}

void Camera::onUpdate() {
	if (m_centerOn == nullptr) return;
	sf::Vector2f relativePosition = m_centerOn->getPosition() - getPosition();
	if (!m_cage.contains(relativePosition))
	{
		sf::Vector2f delta(0,0);
		if (relativePosition.x < m_cage.left) delta.x = relativePosition.x - m_cage.left ;
		else if (relativePosition.x > m_cage.left + m_cage.width) delta.x = relativePosition.x - (m_cage.left + m_cage.width);
		if (relativePosition.y < m_cage.top) delta.y = relativePosition.y - m_cage.top;
		else if (relativePosition.y > m_cage.top + m_cage.height) delta.y = relativePosition.y - (m_cage.top + m_cage.height);
		this->move(delta);
		clamp();
	}
}

void Camera::clamp() {
	if (this->getPosition().x <= 0) this->setPosition(0, this->getPosition().y);
	else if (this->getPosition().x + this->getSize().x >= m_worldSize.x) this->setPosition(m_worldSize.x - this->getSize().x, this->getPosition().y);
	if (this->getPosition().y <= 0) this->setPosition(this->getPosition().x, 0);
	else if (this->getPosition().y + this->getSize().y >= m_worldSize.y) this->setPosition(this->getPosition().x, m_worldSize.y - this->getSize().y);
}

sf::Vector2f Camera::getPosition() const {
	return sf::Vector2f(this->getCenter().x - this->getSize().x / 2, this->getCenter().y - this->getSize().y / 2);
}

sf::IntRect Camera::getCameraBounds() const {
	return sf::IntRect(static_cast<int>(this->getPosition().x), static_cast<int>(this->getPosition().y),
		static_cast<int>(this->getSize().x), static_cast<int>(this->getSize().y));
}

void Camera::setPosition(float x, float y) {
	this->setCenter(x + this->getSize().x / 2, y + this->getSize().y / 2);
}

void Camera::centerOn(PhysicalEntity* player){
	m_centerOn = player;
	this->setCenter(player->getPosition());
	Log::wp(player->getPosition());
}