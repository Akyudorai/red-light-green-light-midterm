#pragma once
#include "Application/ApplicationLayer.h"
#include "json.hpp"

#include "Gameplay/Scene.h"
#include "Gameplay/GameObject.h"

/**
 * This example layer handles creating a default test scene, which we will use 
 * as an entry point for creating a sample scene
 */
class DefaultSceneLayer final : public ApplicationLayer {
public:
	MAKE_PTRS(DefaultSceneLayer)

	DefaultSceneLayer();
	virtual ~DefaultSceneLayer();

	// Inherited from ApplicationLayer

	virtual void OnUpdate() override;
	virtual void OnAppLoad(const nlohmann::json& config) override;

protected:
	void _CreateScene();

protected:
	Gameplay::Scene::Sptr _currentScene;
	
	float currTime = 0.0f;
	float randTime = 0.0f;

	Gameplay::GameObject::Sptr lightPar;

	float lastFrame = 0.0f;

	bool redLightBool = false;
	bool moving = false;
	bool cameraTest = true;

	bool lightsEnabled = true;
	bool specularEnabled = true;
};