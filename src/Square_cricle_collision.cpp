#include <SFML/Graphics.hpp>
#include <iostream>
#include <json.hpp> // I didnt succeed to implement JSON objects. 

using json = nlohmann::json;


int main()
{
	const int window_height = 500;
	const int window_width = 500;
	const float circle_radius = 50.f;
	const float frame_rate_limit = 60.f;
	const int square_lenght = 100;


	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Collider square and circle");
	window.setFramerateLimit(frame_rate_limit);

	//Setting size, color and position 
	sf::RectangleShape square;
	square.setSize(sf::Vector2f(square_lenght, square_lenght));
	square.setFillColor(sf::Color::Blue);
	square.setPosition(window_height/2 - square_lenght/2, window_width/2 - square_lenght/2);

	//Setting size and color
	sf::CircleShape circle;
	circle.setRadius(circle_radius);
	circle.setFillColor(sf::Color::Green);

	float speed = 5.0f;

	while (window.isOpen())
	{

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f delta_move;

		//Manage inputs
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (circle.getPosition().x <= 0)
			{
				delta_move.x -= 0.0f;
			}
			else
			{
				delta_move.x -= 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (circle.getPosition().x + circle.getRadius() * 2 >= window.getSize().x)
			{
				delta_move.x += 0.0f;
			}
			else
			{
				delta_move.x += 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (circle.getPosition().y <= 0)
			{
				delta_move.y -= 0.0f;
			}
			else
			{
				delta_move.y -= 1.0f;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (circle.getPosition().y + circle.getRadius() * 2 >= window.getSize().y)
			{
				delta_move.y += 0.0f;
			}
			else
			{
				delta_move.y += 1.0f;
			}
		}

		if (circle.getGlobalBounds().intersects(square.getGlobalBounds()))
		{
			circle.setFillColor(sf::Color::Red);
			square.setFillColor(sf::Color::Red);
		}
		else
		{
			circle.setFillColor(sf::Color::Green);
			square.setFillColor(sf::Color::Blue);
		}


			circle.setPosition(circle.getPosition()+delta_move*speed);

			window.clear();
			window.draw(square);
			window.draw(circle);

			window.display();

	}

	system("pause");
	return EXIT_SUCCESS;
}
//Done with GAY jordan.