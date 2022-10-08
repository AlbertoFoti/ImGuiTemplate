cmake_minimum_required (VERSION 3.8)

set(Sources
        settings.hpp
    )

# Packages (Dependencies)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

add_executable (${PROJECT_NAME} "main.cpp" ${Sources})

# sub directories
add_subdirectory("Core")
add_subdirectory("Src")
add_subdirectory("src_example")
add_subdirectory("assets")

# Dependencies Targets
target_link_libraries(${PROJECT_NAME} PRIVATE RenderCore)
target_link_libraries(${PROJECT_NAME} PRIVATE ProgramSrc)
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE
        sfml-graphics
        sfml-window
        sfml-audio
        sfml-system)
target_link_libraries(${PROJECT_NAME} PRIVATE implot::implot)