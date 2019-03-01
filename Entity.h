#pragma once
class Entity
{
protected:
	float x, y, height, width;
	sf::Color color;
	sf::RectangleShape rectangle;
	int screenWidth, screenHeight;
public:
	Entity();
	~Entity();
	virtual sf::RectangleShape GetRectangle();
	virtual sf::Vector2f GetPosition();
};

class Player : public Entity
{
private:
	sf::Vector2f direction;
	sf::Vector2f newCoordinates;
	sf::Vector2f partCoordinates;
	float speed;
	std::vector<sf::RectangleShape> snek;
public:
	Player();
	~Player();
	bool Up();
	bool Down();
	bool Left();
	bool Right();
	void Move(int screenHeight, int screenWidth);
	void Grow();
	sf::RectangleShape GetRectangle();
	sf::Vector2f GetPosition();
	std::vector<sf::RectangleShape> GetParts();
};

class Food : public Entity
{
public:
	Food();
	Food(const int& screenWidth, const int& screenHeight);
	~Food();
	void NewFood();
};
