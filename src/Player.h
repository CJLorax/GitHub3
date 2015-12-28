#include <SFML/Graphics.hpp>

#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;


class Player
{

private:

public:


	sf::Sprite ship;

	string imageDir;

	float speed = 5.0f;

	Player(string bulletDir, sf::Texture& texture);

	void Update(float delta);

	void Draw(sf::RenderWindow& window);

};
