#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
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
	texture.loadFromFile(s_cwd_images + "devilHead.png");

	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}




		window.clear();
		window.draw(sprite);
		window.display();
	}
    
    return 1;
}
