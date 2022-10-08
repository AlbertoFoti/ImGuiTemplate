#include "EntryPointExample.hpp"
#include "settings.hpp"

// OpenGL glad, GLFW, SFML  (Renderer)
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"

/**
 * @brief Main : Entry point for program control (update and render loop)
 * Prepares window and other graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
 */
int main()
{

#if __OPENGL_PROGRAM__

	// Setup Window
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Financial Planner", NULL, NULL);
	if (window == NULL) {
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	// glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw("Unable to context to OpenGL");

	// Screen setup
	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

#endif

#if __SFML_PROGRAM__

    // SFML window setup
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window Title");
    ImGui::SFML::Init(window);

#endif

	// Entry Point Example
	EntryPointExample entryPointExample;

#if __OPENGL_PROGRAM__

	// Entry Point core (Init(), Update(), Render(), Shutdown())
    entryPointExample.Init(window, glsl_version);

    while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT);

        entryPointExample.NewFrame();
        entryPointExample.Update();
        entryPointExample.Render();
        glfwSwapBuffers(window);
	}

#endif

#if __SFML_PROGRAM__

    // Entry Point core (Init(), Update(), Render(), Shutdown())
    entryPointExample.Init(window);

    // SFML Entry Point and loop
    sf::Clock deltaClock;
    while(window.isOpen())
    {
        // SFML Poll Events
        sf::Event event;
        while(window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            if(event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color(18, 33, 43));

        ImGui::SFML::Update(window, deltaClock.restart());
        entryPointExample.Update(&window);

        entryPointExample.Render(window);
        window.display();
    }

#endif

    // Shutdown
    entryPointExample.Shutdown();
	return 0;
}