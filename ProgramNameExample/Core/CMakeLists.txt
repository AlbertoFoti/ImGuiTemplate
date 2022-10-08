cmake_minimum_required (VERSION 3.8)

# Packages (Dependencies)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

add_library(
        RenderCore
        RenderCore.cpp
        RenderCore.hpp
        RenderCore_OpenGl.cpp
        RenderCore_OpenGl.hpp
        RenderCore_SFML.cpp
        RenderCore_SFML.hpp
)

target_link_libraries(RenderCore PRIVATE glad::glad)
target_link_libraries(RenderCore PRIVATE glfw)
target_link_libraries(RenderCore PRIVATE imgui::imgui)
target_link_libraries(RenderCore PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(RenderCore PRIVATE
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-system)
target_link_libraries(RenderCore PRIVATE implot::implot)