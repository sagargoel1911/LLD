#include <iostream>
#include <map>
using namespace std;

class Bullet
{
	string image;
	string type;
	double weight;
	double radius;

public:
	void setType(string bulletType)
	{
		this->type = bulletType;
	}
};

class FlyingBullet
{
	double x_coord;
	double y_coord;
	double z_coord;
	double angle;
	double speed;
	Bullet *bullet;

public:
	void setBullet(Bullet *bullet)
	{
		this->bullet = bullet;
	}
	void setSpeed(double speed)
	{
		this->speed = speed;
	}
};

class BulletRegistry
{
	map<string, Bullet *> mp;

public:
	void add(string type, Bullet *bullet)
	{
		mp[type] = bullet;
	}

	Bullet *get(string type)
	{
		return mp[type];
	}
};

int main()
{

	BulletRegistry *bulletRegistry = new BulletRegistry();

	Bullet *fiveMMBullet = new Bullet();
	fiveMMBullet->setType("fiveMMBullet");
	bulletRegistry->add("fiveMMBullet", fiveMMBullet);

	Bullet *sevenMMBullet = new Bullet();
	sevenMMBullet->setType("sevenMMBullet");
	bulletRegistry->add("sevenMMBullet", sevenMMBullet);

	vector<FlyingBullet *> bulletList;

	for (int i = 0; i < 200000; i++)
	{
		FlyingBullet *flyingBullet = new FlyingBullet();
		Bullet *bullet = bulletRegistry->get("fiveMMBullet");
		flyingBullet->setBullet(bullet);
		flyingBullet->setSpeed(10.00);
		bulletList.push_back(flyingBullet);
	}

	return 0;
}