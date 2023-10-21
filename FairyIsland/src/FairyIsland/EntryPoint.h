#pragma once

#ifdef FI_PLATFORM_WINDOWS

extern FI::Application* FI::CreateApplication();
int main(int argc, char** argv)
{
	printf("Fairy Island\n");
	auto app = FI::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#else
	#error FairyIsland Only Support Windows!
#endif