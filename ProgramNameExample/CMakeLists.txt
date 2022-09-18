cmake_minimum_required (VERSION 3.8)

set(Sources 
    "EntryPointExample.cpp"
    "EntryPointExample.h")

# Packages (Dependencies)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)

add_executable (main "main.cpp" ${Sources})

# sub directories
add_subdirectory("assets")

# Dependencies Targets
target_link_libraries(main PRIVATE glad::glad)
target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE imgui::imgui)
target_link_libraries(main PRIVATE implot::implot)