class Player : public Shape
{
	sf::Vector2f newPosition;
	sf::Vector2f newCoordinates;
	float speed;
	sf::RectangleShape rectangle;
public:
	Player();
	~Player();
	void Up();
	void Down();
	void Left();
	void Right();
	void Stop();
	void Move(int screenHeight, int screenWidth);
};
