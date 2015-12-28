#include <SFML/Graphics.hpp>


class Bullet
{

private:

public:

	sf::Texture texture;
	sf::Sprite bullet;

	float speed = 5.0f;

	Bullet(std::string fileName);

	//Bullet(sf::Texture& texture);

	void Update(float delta);

	void Draw(sf::RenderWindow& window);

};
