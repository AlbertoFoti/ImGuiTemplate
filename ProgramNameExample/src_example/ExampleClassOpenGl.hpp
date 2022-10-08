#pragma once
#include "../Core/RenderCore_OpenGl.hpp"

class ExampleClassOpenGl : public RenderCoreOpenGl {
private:
    std::vector<std::function<void()>> callbacks;

public:
    void Register();

    void Update();

    /**
     * @brief Central View Rendering
     *
     */
    static void ShowMainView();
};