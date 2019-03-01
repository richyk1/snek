#include "Common.h"
#include "Entity.h"
#include "Game.h"

int main()
{
	Game myGame;
	myGame.Run();
}

Game::Game()
{
	window.create(sf::VideoMode(WIDTH, HEIGHT), "My window");
	window.setFramerateLimit(30);
	food = new Food(WIDTH, HEIGHT);
	food->NewFood();
}


Game::~Game()
{
	delete food;
}

void Game::Run()
{
	while (window.isOpen())
	{
		Update();
		Render();
	}
}

void Game::Update()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::EventType::Closed:
			window.close();
			break;
		case sf::Event::EventType::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if(player.Up()) std::cout << "User pressed up." << std::endl; 
				break;
			case sf::Keyboard::Down:
				if(player.Down()) std::cout << "User pressed down." << std::endl;
				break;
			case sf::Keyboard::Left:
				if(player.Left()) std::cout << "User pressed left." << std::endl;
				break;
			case sf::Keyboard::Right:
				if(player.Right()) std::cout << "User pressed right." << std::endl;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	player.Move(HEIGHT, WIDTH);
	if (player.GetRectangle().getGlobalBounds().intersects(food->GetRectangle().getGlobalBounds()))
	{
		std::cout << "Got food" << std::endl;
		food->NewFood();
		player.Grow();
	}
}

void Game::Render()
{
	window.clear();
	// Render all players
	for (const auto& part : player.GetParts())
	{
		window.draw(part);
	}
	window.draw(food->GetRectangle());

	window.display();
}