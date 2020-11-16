#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include "Platform.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, bool CheckStartGame) :
	animation(texture, imageCount, switchTime)
{	
	this->CheckStartGame = CheckStartGame;
	this->speed = speed;
	this->switchTime = switchTime;
	this->row = 0;
	//this->stamina = 200.0f;//200
	
	float PlayerSizeX = 32.0f, PlayerSizeY = 48.0f;
	

	faceRight = true;
	body.setSize(sf::Vector2f(PlayerSizeX * 3, PlayerSizeY*3));
	//body_Player.setOrigin(sf::Vector2f(body.getSize().x , body.getSize().y ));
	body.setOrigin(body.getSize()/2.0f);
	//body.setPosition(2280.0f, 4440.0f);   //0
	//body.setPosition(2280.0f, 1800.0f);   //1
	//body.setPosition(0.0f, 0.0f);
	body.setTexture(texture);
	
	this-> Stamina = this-> MaxStamina;
	
}

Player::~Player()
{

}

void Player::Update(float deltaTime,bool PlayerHide, float PlayerSP, bool NMove)
{
	stamina = PlayerSP;
	sf::Vector2f movement(0.0f, 0.0f);
	row = rowstop;
	if (CheckStartGame == 1) {
		if (body.getPosition().y > 3720.0f)
		{
			movement.y = - (speed * deltaTime * 2.0);
			row = 3;
			rowstop = row + 4;
		}
		else {
			CheckStartGame = 0;
		}
	}
	else {
		if (NMove == 0) {
			if (PlayerHide == 0) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					movement.x -= speed * deltaTime * 2.0;
					row = 1;
					rowstop = row + 4;
					RenderPlayer = 0.25;

				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					movement.x += speed * deltaTime * 2.0;
					row = 2;
					rowstop = row + 4;
					RenderPlayer = 0.25;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				{
					movement.y -= speed * deltaTime * 2.0;
					row = 3;
					rowstop = row + 4;
					RenderPlayer = 0.25;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				{
					movement.y += speed * deltaTime * 2.0;
					row = 0;
					rowstop = row + 4;
					RenderPlayer = 0.25;
				}
				//}
				//************************************    Shift      ******************************//
				if (stamina <= 200)
				{

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						movement.x -= speed * deltaTime * 3;
						RenderPlayer = 0.05;
						//stamina -= 1;

					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					{
						movement.x += speed * deltaTime * 3;
						RenderPlayer = 0.05;
						//stamina -= 1;
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						movement.y -= speed * deltaTime * 3;
						RenderPlayer = 0.05;
						//stamina -= 1;
					}

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) and sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						movement.y += speed * deltaTime * 3;
						RenderPlayer = 0.05;
						//stamina -= 1;
					}

				}
				else {
					if (stamina >= 0)
					{
						//stamina += 0.25;
					}
				}

			}
		}

	}

	//************************************    Shift      ******************************//

		
		//printf("%.2f\n",body.getPosition());
	
	animation.Update(row, deltaTime);/*, faceRight*/
	body.setTextureRect(animation.uvRect);
	body.move(movement);


	//printf("movement Y = %.1f", movement.y);
	//std::cout << stamina << std::endl;
	//std::cout << player.GetPosition.y << std::endl;

}

void Player::StartGame(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	row = rowstop;
		if (body.getPosition().y > 3720)
		{
			movement.y = speed * deltaTime * 2.0;
			row = 3;
			rowstop = row + 4;
		}

		animation.Update(row, deltaTime);/*, faceRight*/
		body.setTextureRect(animation.uvRect);
		body.move(movement);

}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}