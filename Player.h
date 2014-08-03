#pragma once
#include "PhysicalEntity.h"
class Player : public PhysicalEntity
{
public:
	Player();
	~Player();

	void OnEvent();
	void init();
	
	b2Body* getBody();

	void startContact(b2Body*, b2Manifold*);
	void endContact(b2Body*, b2Manifold*);

private:
	int m_allowjump = 0;

	bool isOnjump();
private:

};

