#pragma once

#ifdef FI_PLATFORM_WINDOWS

extern FI::Application* FI::CreateApplication();
int main(int argc, char** argv)
{
	FI::Log::Init();
	FI_CORE_WARN("Log System Init!");
	FI_CLIENT_INFO("Start!");


	auto app = FI::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#else
	#error FairyIsland Only Support Windows!
#endif