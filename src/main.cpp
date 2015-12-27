
#include <SFML/Graphics.hpp>
#include "Bullet.h"

#include <stdio.h>
#include <string>
#include <iostream>



#if defined (_WIN32) ||  (_WIN64)
#include <direct.h>
#define getcwd _getcwd
#endif

#if defined (__linux__)
#include <unistd.h>
#endif

using namespace std;


int main(int argc, const char * argv[]) {
    
#if defined (_WIN32) ||  (_WIN64)
	cout << "This is Windows" << endl;
	
	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "\\images\\";

	cout << s_cwd << endl;

#endif
    
#if defined (__APPLE__)
    
    cout << "This is Apple" << endl;
    
    // Here is a small helper for you ! Have a look.
    #include "ResourcePath.hpp"
    
    string s_cwd_images = resourcePath();

#endif
    
#if defined (__linux__)
    
    cout << "This is Linux" << endl;
	
	string s_cwd(getcwd(NULL, 0));

	string s_cwd_images = s_cwd + "/images/";

	//cout << s_cwd_images << endl;

#endif
    
	sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");

	sf::Texture texture;
	texture.loadFromFile(s_cwd_images + "player.png");

	sf::Sprite player;
	player.setTexture(texture);
	
	sf::Clock clock;
	sf::Time time;
    
    // Our speed in pixels per second
    float speed = 5.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			                window.close();
	
		}

		// Get elapsed time
        float delta = clock.restart().asSeconds();

		if (sf::Joystick::isButtonPressed(0, 1))
		{
			// yes: shoot!
			cout << "Firing my gun" << endl;
		}

		// what's the current position of the X and Y axes of joystick number 0?
		float x = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
		float y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

        
        player.move( (x * speed) * delta, (y * speed) * delta);



		window.clear();
		window.draw(player);
		window.display();
	}
    
    return 1;
}
