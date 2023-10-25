#pragma once
#include <FairyIsland.h>

class SandBox : public FI::Application
{
public:
	SandBox()
	{
	
	}
	~SandBox()
	{

	}

	
};

FI::Application* FI::CreateApplication()
{
	return new SandBox();
}
