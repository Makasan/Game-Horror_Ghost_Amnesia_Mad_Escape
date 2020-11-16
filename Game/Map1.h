#pragma once
#include <SFML/Graphics.hpp>
#include"collider.h"

using namespace sf;
class Map1
{
public:
	Collider GetCollider() { return Collider(body); }
	Map1(Texture* texture, Vector2f position, Vector2f size);
	void draw(RenderWindow& window);
	int p;

private:
	RectangleShape body;
};

