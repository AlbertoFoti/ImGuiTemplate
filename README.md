# ImGui Template for C++ on Windows

ImGui Template to develop C++ Desktop Apps

## Vcpkg install
Follow instruction on https://vcpkg.io/en/getting-started.html :

in C:\dev

    git clone <url>
    .\vcpkg\bootstrap-vcpkg.bat

    cd vcpkg
    vcpkg integrate install

Then, follow the procedure of your IDE to add vcpkg as a CMake Option:

For Clion

    -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake

install dependencies 

    sudo apt-get install libx11-dev
    sudo apt-get install xorg-dev
    sudo apt-get install freeglut3-dev
    sudo apt-get install libudev-dev

If you want to search additional libraries use

    vcpkg search <library_name>
    vcpkg install <library_name>[<feature>]:<target>

Just as an example for imgui

    vcpkg install imgui[docking-experimental,glfw-binding, opengl3-binding]:x64-windows

## How to use

- in "settings.hpp" set the rendering API you want to use to true and all others to false
- To develop your application use the examples in the src_example folder

(they extend the correponding rending api core renderer and allow you to simply define callbacks to create GUI windows and elements)
- Develop your functions
- Register them in the Register() function

## Libraries Used

- vcpkg library manager

- ImGui library (docking branch)

## License and Copyright
© 2022 Alberto Foti. MIT License.
