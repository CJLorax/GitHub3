#include "Player.h"



Player::Player(sf::Texture& texture) {
	
	ship.setTexture(texture);

}

void Player::Update(float delta) {
	if (sf::Joystick::isButtonPressed(0, 1))
	{
		// yes: shoot!
		//cout << "Firing my gun" << endl;
	}

	// what's the current position of the X and Y axes of joystick number 0?
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


	ship.move((x * speed) * delta, (y * speed) * delta);
}

void Player::Draw(sf::RenderWindow& window) {
	
	window.draw(ship);

}
