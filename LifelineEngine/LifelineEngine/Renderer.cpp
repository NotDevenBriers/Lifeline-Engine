#include "Renderer.h"
#include <iostream>
 
Renderer::Renderer()
{
	m_ClearColor[0] = 0.1f;
	m_ClearColor[1] = 0.1f;
	m_ClearColor[2] = 0.1f;
	m_ClearColor[3] = 1.0f;
}

void Renderer::Init() {
	// state setup for opengl

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	std::cout << "[INFO]: Renderer Initialised.\n";
}

void Renderer::SetClearColor(float r, float g, float b, float a) {
	m_ClearColor[0] = r;
	m_ClearColor[1] = g;
	m_ClearColor[2] = b;
	m_ClearColor[3] = a;
}

void Renderer::Clear() {
	glClearColor(
		m_ClearColor[0],
		m_ClearColor[1],
		m_ClearColor[2],
		m_ClearColor[3]
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::OnWindowResize(int width, int height)
{
	glViewport(0, 0, width, height);
}