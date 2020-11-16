#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>


Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed,float y,float y2,float x, float x2,int xy,float positionX, float positionY) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->switchTime = switchTime;
	this->row = 0;
	float EnemyX = 32.0f, EnemyY = 48.0f;
	body.setSize(sf::Vector2f(EnemyX * 3, EnemyY * 3));
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
	//movement.y = 250;
	this->y = y;
	this->y2 = y2;
	this->x = x;
	this->x2 = x2;
	this->xy = xy;
	if (xy == 0) {
		body.setPosition(positionX, y);
	}
	else if(xy == 1){
		body.setPosition(x, positionY);
	}
	else if (xy == 2) {
		body.setPosition(positionX, positionY);
	}
	else if (xy == 3) {
		body.setPosition(positionX, positionY);
	}
	
}



void Enemy::Update( float deltaTime)
{
	if (xy == 0) {
		if (body.getPosition().y <= y) {
			movement.y = speed;
			row = 0;
		}
		else if (body.getPosition().y >= y2) {
			movement.y = -speed;
			row = 3;
		}
	}
	else if (xy == 1) {
		if (body.getPosition().x <= x) {
			movement.x = speed;
			row = 2;
		}
		else if (body.getPosition().x >= x2) {
			movement.x = -speed;
			row = 1;
		}
	}

	else if (xy == 2) {
		row = 0;
	}
	else if (xy == 3) {
		if (body.getPosition().y);
	}
	
	
	animation.Update(row, deltaTime);/*, faceRight*/
	body.setTextureRect(animation.uvRect);
	body.move(movement* deltaTime);


	//printf("movement Y = %.1f\n", movement.y);
	//std::cout << stamina << std::endl;
	//std::cout << player.GetPosition.y << std::endl;

}


void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}