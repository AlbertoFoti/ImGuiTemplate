cmake_minimum_required (VERSION 3.8)

set(Sources 
    "EntryPointExample.cpp"
    "EntryPointExample.h")

# Packages (Dependencies)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

add_executable (${PROJECT_NAME} "main.cpp" ${Sources})

# sub directories
add_subdirectory("assets")

# Dependencies Targets
target_link_libraries(${PROJECT_NAME} PRIVATE glad::glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE imgui::imgui)
target_link_libraries(${PROJECT_NAME} PRIVATE implot::implot)