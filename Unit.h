#include"GameObject.h"

const int InitialUnitEnergy = 100;

class Unit : public GameObject {
public:
	Unit();
	Unit(int, int, Body*, int, int, int);
	~Unit();
	int Health() const { return health; };
	bool TakeDamage(int);
	void Hit();
	//std::vector<GameObject*> NearObject(Map&);
protected:
	int health;
	int damage;
	int pureDamage;
	int armor;
	int energy;
};