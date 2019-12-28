#pragma  once
#include <glimac/SDLWindowManager.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl.h>

class Menu{
	private:
	bool m_running = true;
	
	public:
	//glimac::SDLWindowManager windowManager;
	//SDLWindowManager windowManager;
	Menu();
	~Menu();

	void startFrame() const;
	void endFrame() const;

	bool isRunning() const { return m_running; }
	void quit() { m_running = false; }

};