cmake_minimum_required (VERSION 3.8)

# Packages (Dependencies)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

add_library(
        ProgramSrc
        ExampleClassOpenGl.hpp
        ExampleClassOpenGl.cpp
        ExampleClassSFML.hpp
        ExampleClassSFML.cpp
)

target_link_libraries(ProgramSrc PRIVATE glad::glad)
target_link_libraries(ProgramSrc PRIVATE glfw)
target_link_libraries(ProgramSrc PRIVATE imgui::imgui)
target_link_libraries(ProgramSrc PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(ProgramSrc PRIVATE
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-system)
target_link_libraries(ProgramSrc PRIVATE implot::implot)