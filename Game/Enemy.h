#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Enemy
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float i, float j, float x, float x2, int xy, float positionX, float positionY);
	
	void Update(float deltaTime);

	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(xy)) { body.setPosition(xy); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	int rowstop = 4;
	float RenderPlayer = 0;
	float switchTime;
	float stamina;
	float speed;
	int xy;
	sf::Vector2f movement;

private:
	float y, y2, x, x2;
	Animation animation;
	unsigned int row;
	sf::RectangleShape body;
	sf::RectangleShape body_Player;
	bool faceRight;

};

