#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include "implot_internal.h"

class RenderCore {

public:
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