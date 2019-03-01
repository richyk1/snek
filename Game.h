#pragma once
class Game
{
	float lastTime;
	float currentTime;
	float fps;
	static const int WIDTH = 800;
	static const int HEIGHT = 600;
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	Player player;
	Food* food;
	sf::RectangleShape foodShape;
public:
	Game();
	~Game();
	void Update();
	void Render();
	void Run();
};
