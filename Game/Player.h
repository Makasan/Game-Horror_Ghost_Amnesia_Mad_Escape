#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"


class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, bool CheckStartGame);
	~Player();

	void Update(float deltaTime,bool PlayerHide,float PlayerSP,bool NMove);
	void StartGame(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void SetPosition(sf::Vector2f(xy)) { body.setPosition(xy); }
	sf::Vector2f GetPosition() { return body.getPosition();  }
	Collider GetCollider() { return Collider(body); }
	int rowstop = 4;
	float RenderPlayer = 0;
	float switchTime;
	float stamina;
	float speed;
	float MaxStamina = 200;
	float Stamina;
	bool CheckStartGame;

private:
	Animation animation;
	unsigned int row;
	sf::RectangleShape body;
	sf::RectangleShape body_Player;
	sf::RectangleShape Stamina_Shape;
	bool faceRight;


};

