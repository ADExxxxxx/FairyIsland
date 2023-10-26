#pragma once
#include <FairyIsland.h>

class ExampleLayer : public FI::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	virtual ~ExampleLayer() = default;

	void OnUpdate() override
	{
		// FI_INFO("ExampleLayer::Update");
	}

	void OnEvent(FI::Event& event) override
	{
		// FI_TRACE("{0}", event);
	}
};

class SandBox : public FI::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new FI::ImGuiLayer());
	}
	~SandBox()
	{

	}

	
};

FI::Application* FI::CreateApplication()
{
	return new SandBox();
}
