#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(50.0f, 75.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(texture);

	
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime;
		row = 1;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime;
		row = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		movement.y -= speed * deltaTime;
		row = 3;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += speed * deltaTime;
		row = 0;
	}
	
	//************************************    Shift      ******************************//

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movement.x -= speed * deltaTime * 1.2;
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movement.x += speed * deltaTime * 1.2;
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movement.y -= speed * deltaTime * 1.2;
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movement.y += speed * deltaTime * 1.2;
		
	}

	//************************************    Shift      ******************************//


	

	
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}