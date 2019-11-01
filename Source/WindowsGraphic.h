#pragma once

#include <SFML/Graphics.hpp>
#define FPS 60.0

class Window{
protected:
    int width, height;
    sf::RenderWindow renderWindow;
    sf::Event event;
    sf::Clock clock;
};
