#include "Player.h"
#include "Bullet.h"

#include <string>
#include <stdio.h>
#include <iostream>

#include <vector>

using namespace std;

vector<Bullet> BulletList;

sf::Clock playerClock;
sf::Time playerTime;

Player::Player(string bulletDir, sf::Texture& texture) {
	
	imageDir = bulletDir;
	ship.setTexture(texture);



}

void Player::Update(float delta) {

	playerTime = playerClock.getElapsedTime();

	cout << playerTime.asSeconds() << endl;

	if (sf::Joystick::isButtonPressed(0, 1))
	{
		if (playerTime.asSeconds() >= 1.0f) {
			// yes: shoot!
			//load texture for player
			string tempString = imageDir + "pBullet.png";

			cout << imageDir + "pBullet.png" << endl;

			//sf::Texture &texture;

			//texture.loadFromFile(imageDir + "pBullet.png");

			Bullet tempBullet = Bullet(tempString);

			tempBullet.bullet.move(300, 300);



			BulletList.push_back(tempBullet);

			playerClock.restart();

		}
	}

	// what's the current position of the X and Y axes of joystick number 0?
	float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
	float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);


	ship.move((x * speed) * delta, (y * speed) * delta);

	


}

void Player::Draw(sf::RenderWindow& window) {
	
	window.draw(ship);

	//draw bullets
	for (int i = 0; i<BulletList.size(); i++)
	{
		Bullet cur = BulletList[i];

		window.draw(cur.bullet);
	}



}
