#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <conio.h>
#include <iostream>



Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->switchTime = switchTime;
	this->row = 0;
	this->stamina = 200000.0f;

	faceRight = true;
	body.setSize(sf::Vector2f(64.0f, 96.0f));
	//body_Player.setOrigin(sf::Vector2f(body.getSize().x / 2.0f, body.getSize().y / 2.0f));
	body.setOrigin(body.getSize() / 2.0f);
	
	body.setPosition(0.0f, 0.0f);
	body.setTexture(texture);

	
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	row = rowstop;
	sf::Vector2f movement(0.0f, 0.0f);

	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			movement.x -= speed * deltaTime;
			row = 1;
			rowstop = row + 4;
			RenderPlayer = 0.25;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			movement.x += speed * deltaTime;
			row = 2;
			rowstop = row + 4;
			RenderPlayer = 0.25;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			movement.y -= speed * deltaTime;
			row = 3;
			rowstop = row + 4;
			RenderPlayer = 0.25;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			movement.y += speed * deltaTime;
			row = 0;
			rowstop = row + 4;
			RenderPlayer = 0.25;
		}
	//}
	//************************************    Shift      ******************************//
		if (stamina > 1)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				movement.x -= speed * deltaTime * 1.2;
					RenderPlayer = 0.05;
					stamina -= 1;

			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				movement.x += speed * deltaTime * 1.2;
				RenderPlayer = 0.05;
				stamina -= 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				movement.y -= speed * deltaTime * 1.2;
				RenderPlayer = 0.05;
				stamina -= 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				movement.y += speed * deltaTime * 1.2;
				RenderPlayer = 0.05;
				stamina -= 1;
			}

		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
		{
			if (stamina <= 2000)
			{
				stamina += 0.25;
			}
		}

	

	//************************************    Shift      ******************************//




	animation.Update(row, deltaTime);/*, faceRight*/
	body.setTextureRect(animation.uvRect);
	body.move(movement);
	/*std::cout << player.GetPosition.x << std::endl;
		std::cout << player.GetPosition.y << std::endl;*/

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}