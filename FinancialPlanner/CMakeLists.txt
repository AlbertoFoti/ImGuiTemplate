cmake_minimum_required (VERSION 3.8)

add_executable (main "main.cpp" "FinancialPlanner.cpp" "FinancialPlanner.h"  "core.cpp" "Core.h"  )

# Dependencies

find_package(imgui CONFIG REQUIRED)
target_link_libraries(main PRIVATE imgui::imgui)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(glad CONFIG REQUIRED)
target_link_libraries(main PRIVATE glad::glad)
