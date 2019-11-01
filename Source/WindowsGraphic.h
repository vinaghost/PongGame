#pragma once

#include <SFML/Graphics.hpp>
#define FPS 60.0

float const mSPF = 1000000.0/FPS;

class Window{
protected:
    int width, height;
    sf::RenderWindow renderWindow;
    sf::Event event;
    sf::Clock clock;
};
