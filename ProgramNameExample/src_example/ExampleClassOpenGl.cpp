#include "ExampleClassOpenGl.hpp"

void ExampleClassOpenGl::Register()
{
    // Add Callbacks Here
    this->callbacks.push_back(ExampleClassOpenGl::ShowMainView);
}

void ExampleClassOpenGl::Update() {
    RenderCoreOpenGl::Update(this->callbacks);
}

void ExampleClassOpenGl::ShowMainView()
{
    ImGui::Begin("Program Name");

    // Views
    ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_Reorderable;
    if (ImGui::BeginTabBar("MyTabBar", tab_bar_flags))
    {
        if (ImGui::BeginTabItem("Tab1"))
        {
            ImGui::EndTabItem();
        }
        if (ImGui::BeginTabItem("Tab2"))
        {
            ImGui::EndTabItem();
        }
        ImGui::EndTabBar();
    }
    ImGui::End();
}