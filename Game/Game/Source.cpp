#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Player.h"
#include "Platform.h"
#include <conio.h>
#include <vector>

static const float VIEW_HEIGHT = 512.0f;


void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 720), "SFML works!", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("SonyeoFull.png");
	Player player(&playerTexture, sf::Vector2u(4, 8), 0.25f, 100.0f);

	sf::Texture Map1;
	Map1.loadFromFile("Maptest.png");

	Platform Map1Texture(&Map1, sf::Vector2f(3840.0f, 2880.0f), sf::Vector2f(0.0f, 0.0f));
	Platform platform1(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(100.0f, 200.0f));
	Platform platform2(nullptr, sf::Vector2f(200.0f, 100.0f), sf::Vector2f(300.0f, 0.0f));
	
	float deltaTime = 0.0f;
	float counting_stop = 0;
	sf::Clock clock;
	sf::Clock stop;
	bool isShift=false;
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		counting_stop = stop.getElapsedTime().asMilliseconds();
		
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		
		player.Update(deltaTime);
		
		Collider Test = player.GetCollider();
		platform1.GetCollider().CheckCollision(Test, 0.5f);
		platform2.GetCollider().CheckCollision(Test, 1.0f);
		

		view.setCenter(player.GetPosition());
		
		window.clear(sf::Color(100, 100, 100));
		window.setView(view);
		Map1Texture.Draw(window);
		platform1.Draw(window);
		platform2.Draw(window);
		
		player.Draw(window);

		/*std::cout << player.GetPosition.x << std::endl;
		std::cout << player.GetPosition.y << std::endl;*/
		std::cout << player.GetCollider().GetPosition().x << ' ' << player.GetCollider().GetPosition().y << std::endl;
		window.display();
	}
	return 0;
}