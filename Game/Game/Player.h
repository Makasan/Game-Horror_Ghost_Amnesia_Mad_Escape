#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);

	sf::Vector2f GetPosition() { return body.getPosition();  }
	Collider GetCollider() { return Collider(body); }
	int rowstop = 4;
	float RenderPlayer = 0;
	float switchTime;
	float stamina;
	float speed;
	
private:
	Animation animation;
	unsigned int row;
	sf::RectangleShape body;
	sf::RectangleShape body_Player;
	bool faceRight;

};

