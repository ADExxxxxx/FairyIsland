#pragma once
#include "Core.h"
namespace FI 
{

	class FAIRY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	Application* CreateApplication();
}

