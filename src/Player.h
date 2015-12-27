#include <SFML/Graphics.hpp>


class Player
{

private:

public:


	sf::Sprite ship;

	float speed = 5.0f;

	Player(sf::Texture& texture);

	void Update(float delta);

	void Draw(sf::RenderWindow& window);

};
