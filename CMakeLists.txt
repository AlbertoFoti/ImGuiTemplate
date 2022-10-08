cmake_minimum_required (VERSION 3.8)

project ("ProgramNameExample")

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Include subdirectories
add_subdirectory ("ProgramNameExample")

#file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/imgui.ini
#        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME})
