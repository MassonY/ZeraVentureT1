#pragma once
#include <SFML\Graphics.hpp>
#include "Box2D\Box2D.h"

template<typename T>
sf::Vector2<T> BtoSF(const b2Vec2& vector){
	return sf::Vector2<T>(vector.x, vector.y);
}

template<typename T>
b2Vec2 SFtoB(const sf::Vector2<T>& vector){
	return b2Vec2(vector.x, vector.y);
}