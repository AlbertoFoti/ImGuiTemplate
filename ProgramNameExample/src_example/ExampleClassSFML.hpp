#pragma once
#include "../Core/RenderCore_SFML.hpp"

class ExampleClassSFML : public RenderCore_SFML {
private:
    std::vector<std::function<void(sf::RenderWindow* window)>> callbacks;

public:
    void Register();

    void Update(sf::RenderWindow *window);

private:
    static void ShowCircleDrawingExample(sf::RenderWindow *window);
};