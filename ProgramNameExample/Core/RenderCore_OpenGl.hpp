#pragma once

#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <functional>
#include <memory>
#include <vector>
#include "RenderCore.hpp"

/**
 * @brief Entry Point Example : Main component managing views update and rendering
 *
 */
class RenderCoreOpenGl : public RenderCore
{
private:

public:

    /**
	 * @brief Sets up ImGui and ImPlot context, loads fonts, assets and themes.
	 * Initializes graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
	 *
	 * @param window self-explanatory
	 * @param glsl_version self-explanatory
	 */
	void Init(GLFWwindow *window, const char* glsl_version);

    /**
	 * @brief Update
	 *
	 */
	virtual void Update(std::vector<std::function<void()>> callbacks);

    /**
	 * @brief Docking Space Setup, Views loading. Rendering.
	 *
	 */
	void Render();

    /**
     * @brief Shutsdown ImGui and ImPlot context, rendering API cleanup.
     *
     */
    void Shutdown();

    /**
     * @brief Creates a New Frame
     *
     */
    void NewFrame();
};