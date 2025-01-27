#include "Mode.hpp"

#include "Scene.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	//I really don't expect players to catch more than 255 apples.
	//if you do, what are you doing with your life
	uint8_t applecount = 0; 

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	Scene::Transform *apple = nullptr;
	Scene::Transform *shadow = nullptr;
	Scene::Transform *bin = nullptr;
	glm::quat apple_rotation;
	
	//camera:
	Scene::Camera *camera = nullptr;
	Scene::Light *light = nullptr;
};
