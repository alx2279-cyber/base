#include <iostream>
#include <vector>
#include <string>
#include "src/render/OS-ImGui_External.h"

// Cheat settings
namespace Settings {
    bool ESP = true;
    bool Box = true;
    bool HealthBar = true;
    bool AimBot = false;
    float AimSmooth = 5.0f;
}

// This function will be called every frame
void DrawCallback() {
    ImGui::Begin("AI Cheat Base", nullptr, ImGuiWindowFlags_AlwaysAutoResize);
    
    ImGui::Text("Welcome to the AI-generated Base");
    ImGui::Separator();
    
    ImGui::Checkbox("Enable ESP", &Settings::ESP);
    if (Settings::ESP) {
        ImGui::Indent();
        ImGui::Checkbox("Box", &Settings::Box);
        ImGui::Checkbox("Health Bar", &Settings::HealthBar);
        ImGui::Unindent();
    }
    
    ImGui::Separator();
    ImGui::Checkbox("Aimbot", &Settings::AimBot);
    ImGui::SliderFloat("Smooth", &Settings::AimSmooth, 1.0f, 20.0f);
    
    ImGui::Separator();
    if (ImGui::Button("Unload Cheat")) {
        exit(0);
    }
    
    ImGui::End();
}

int main() {
    try {
        std::cout << "Starting AI Cheat Base..." << std::endl;
        
        // "TargetWindowTitle" and "TargetProcessClass" should match your game
        RenderCore::OSImGui_External.AttachAnotherWindow("TargetWindowTitle", "TargetProcessClass", DrawCallback);
        
    } catch (RenderCore::OSException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
