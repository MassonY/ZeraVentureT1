#include "CollisionListener.h"


CollisionListener::CollisionListener(){
}


CollisionListener::~CollisionListener()
{
}

void CollisionListener::BeginContact(b2Contact* contact){
	//check if fixture A was a ball
	void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<PhysicalEntity*>(bodyUserData)->startContact(contact->GetFixtureB()->GetBody(), contact->GetManifold());
	//check if fixture B was a ball
	bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<PhysicalEntity*>(bodyUserData)->startContact(contact->GetFixtureA()->GetBody(), contact->GetManifold());
}

void CollisionListener::EndContact(b2Contact* contact){
	
		void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<PhysicalEntity*>(bodyUserData)->endContact(contact->GetFixtureB()->GetBody(), contact->GetManifold());
		//check if fixture B was a ball
		bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
		if (bodyUserData)
			static_cast<PhysicalEntity*>(bodyUserData)->endContact(contact->GetFixtureA()->GetBody(), contact->GetManifold());
}