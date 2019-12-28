#include "../include/menu.hpp"

Menu::Menu() : windowManager(glimac::SDLWindowManager(800, 600, "WorldIMaker")){
	// Initialize ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    //ImGui_ImplSDL2_InitForOpenGL(windowManager.window, windowManager.openglContext);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    ImGui::StyleColorsDark();
}

void Menu::startFrame() const{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame(windowManager.window);
    ImGui::NewFrame();
}

void Menu::endFrame() const{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(windowManager.window);
}

Menu::~Menu(){
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    //SDL_GL_DeleteContext(windowManager.openglContext);
    SDL_DestroyWindow(windowManager.window);
    SDL_Quit();
}