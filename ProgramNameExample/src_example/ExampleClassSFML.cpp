#include "ExampleClassSFML.hpp"

void ExampleClassSFML::Register() {
    // Add Callbacks Here
    this->callbacks.push_back(ExampleClassSFML::ShowCircleDrawingExample);
}

void ExampleClassSFML::Update(sf::RenderWindow *window) {
    RenderCore_SFML::Update(window, callbacks);
}

void ExampleClassSFML::ShowCircleDrawingExample(sf::RenderWindow *window) {
    ImGui::Begin("Window Title");

    ImGui::Text("Hello, world!");
    // Circle Drawing
    sf::CircleShape shape(200.f, 100);
    shape.setFillColor(sf::Color(204, 77, 5));
    shape.setPosition(200, 200);
    static int show_circle = false;
    if(ImGui::Button("Toggle Circle")) {
        show_circle = !show_circle;
    }
    if(show_circle)
        window->draw(shape);

    ImGui::End();
}