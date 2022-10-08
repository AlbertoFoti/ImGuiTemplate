#pragma once

#include "imgui.h"
#include "imgui-SFML.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "implot_internal.h"
#include "SFML/Graphics.hpp"
#include "SFML/System/Clock.hpp"
#include <iostream>
#include <math.h>
#include <climits>
#include <string>
#include <memory>
#include <vector>
#include "RenderCore.hpp"

/**
 * @brief Entry Point Example : Main component managing views update and rendering
 * 
 */
class RenderCore_SFML : public RenderCore
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
    void Init(sf::RenderWindow& window);

    /**
	 * @brief Update
	 *
	 */
    virtual void Update(sf::RenderWindow *window, std::vector<std::function<void(sf::RenderWindow*)>> callbacks);

    /**
	 * @brief SFML Canvas, Views loading. Rendering.
	 *
	 */
    void Render(sf::RenderWindow& window);

	/**
	 * @brief Shutsdown ImGui and ImPlot context, rendering API cleanup.
	 * 
	 */
	void Shutdown();
};
