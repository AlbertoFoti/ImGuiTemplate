#pragma once

#include "settings.hpp"
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

/**
 * @brief Entry Point Example : Main component managing views update and rendering
 * 
 */
class EntryPointExample
{
private:

public:

#if __OPENGL_PROGRAM__
    /**
	 * @brief Sets up ImGui and ImPlot context, loads fonts, assets and themes.
	 * Initializes graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
	 *
	 * @param window self-explanatory
	 * @param glsl_version self-explanatory
	 */
	void Init(GLFWwindow *window, const char* glsl_version);
#endif

#if __SFML_PROGRAM__
    /**
	 * @brief Sets up ImGui and ImPlot context, loads fonts, assets and themes.
	 * Initializes graphical components through some rendering API (ex. glfw/opengl3/glad, Vulkan, DirectX)
	 *
	 * @param window self-explanatory
	 * @param glsl_version self-explanatory
	 */
    void Init(sf::RenderWindow& window);
#endif

#if __OPENGL_PROGRAM__
	/**
	 * @brief Update
	 * 
	 */
	virtual void Update();
#endif

#if __SFML_PROGRAM__
    /**
	 * @brief Update
	 *
	 */
    virtual void Update(sf::RenderWindow *window);
#endif

#if __OPENGL_PROGRAM__
	/**
	 * @brief Docking Space Setup, Views loading. Rendering.
	 * 
	 */
	void Render();
#endif

#if __SFML_PROGRAM__
    /**
	 * @brief SFML Canvas, Views loading. Rendering.
	 *
	 */
    void Render(sf::RenderWindow& window);
#endif

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

private:
	/**
	 * @brief Central View Rendering
	 * 
	 */
	void ShowMainView();

    /**
     * @brief SFML Circle Drawing Example
     */
    void ShowCircleDrawingExample(sf::RenderWindow *window);

	/**
	 * @brief Demo View : ImGui Demo panel
	 * 
	 */
	void ShowDemoWindow();

	/**
	 * @brief Demo View : ImPlot Demo panel
	 * 
	 */
	void ShowDemoPlot();

	/**
	 * @brief Demo View : Fonts Testing panel
	 * 
	 */
	void ShowFontTesting();

	/**
	 * @brief Utility : ImGui Configuration Options/Settings
	 * 
	 * @param label 
	 * @return ignore 
	 * @return ignore 
	 */
	bool ShowStyleSelectorGUI(const char* label);

	/**
	 * @brief Utility : ImPlot Configuration Options/Settings
	 * 
	 * @param label 
	 * @return ignore 
	 * @return ignore 
	 */
	bool ShowStyleSelectorPLOT(const char* label);

	/**
	 * @brief Set Custom "Dark" Theme Colors
	 * 
	 */
	void SetDarkThemeColors();

	/**
	 * @brief Utility : shows Helper Marker
	 * 
	 * @param desc 
	 */
	void HelpMarker(const char* desc);

	/**
	 * @brief Load Fonts
	 * 
	 */
	void loadFonts();

	/**
	 * @brief Set the Theme
	 * 
	 */
	void setTheme();

	/**
	 * @brief Set the Minimum Size of a Window 
	 * 
	 */
	float setMinimumSizeWindow();
};
