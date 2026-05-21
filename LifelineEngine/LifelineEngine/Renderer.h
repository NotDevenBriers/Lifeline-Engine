#pragma once

#include <glad/glad.h>

class Renderer
{
public:
	Renderer();

	void Init();

	void SetClearColor(float r, float g, float b, float a);
	void Clear();

	void OnWindowResize(int width, int height);

private:
	float m_ClearColor[4];

};

