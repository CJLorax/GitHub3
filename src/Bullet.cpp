#include "Bullet.h"

//sf::Texture& texture



Bullet::Bullet(std::string fileName) {

	

	texture.loadFromFile(fileName);
	
	bullet.setTexture(texture);

}

void Bullet::Update(float delta) {



	bullet.move(0, 10.0f * delta);
}

void Bullet::Draw(sf::RenderWindow& window) {

	window.draw(bullet);

}
