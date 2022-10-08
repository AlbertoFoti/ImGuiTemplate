#include "Core/RenderCore_SFML.hpp"

// OpenGL glad, GLFW, SFML  (Renderer)
#include "settings.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include "src_example/ExampleClassSFML.hpp"
#include "src_example/ExampleClassOpenGl.hpp"

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

    // Entry Point Example
    ExampleClassOpenGl entryPointExample;

#endif

#if __SFML_PROGRAM__

    // SFML window setup
    sf::RenderWindow window(sf::VideoMode(800, 800), "Window Title");
    if(!ImGui::SFML::Init(window))
        return 2;

    // Entry Point Example
	ExampleClassSFML entryPointExample;

#endif

#if __OPENGL_PROGRAM__

	// Entry Point core (Init(), Update(), Render(), Shutdown())
    entryPointExample.Init(window, glsl_version);

    // Register callbacks (views)
    entryPointExample.Register();

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

    // Register all callbacks (views)
    entryPointExample.Register();

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