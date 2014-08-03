#ifndef CAMERA_H
#define CAMERA_H

#include <SFML/Graphics.hpp>
#include "Player.h"
class Camera : public sf::View {
public:
	Camera();

	void					init(const sf::Vector2f& , const sf::Vector2f&, PhysicalEntity* = nullptr);

	void					onUpdate();

	void					centerOn(PhysicalEntity*);

	void					setPosition(float, float);

	sf::Vector2f			getPosition() const;
	sf::IntRect				getCameraBounds() const;

private:
	// Clamps the camera to the world's size. Called by onMove().
	// Since this function is called internally, it's private.
	void					clamp();

private:
	PhysicalEntity*			m_centerOn;

	sf::Vector2f			m_worldSize;
	sf::FloatRect			m_cage;
};

#endif