#include "UCW.h"




//Map* map;

SDL_Renderer* UCW::renderer = nullptr;
SDL_Event UCW::event;
SDL_Rect position[25][25];

/*
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

auto& tile0(manager.addEntity());
auto& tile1(manager.addEntity());
auto& tile2(manager.addEntity());
*/

UCW::UCW()
{
}


UCW::~UCW()
{
}

void UCW::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystems Initialised!..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			std::cout << "Window created!" << std::endl;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}
		isRunning = true;
	}
	else {
		isRunning = false;

	}


	map = new Map();
	//getPosition


	for (int row = 0; row < 25; row++) {
		for (int column = 0; column < 25; column++) {
			position[row][column].h = 32;
			position[row][column].w = 32;
			if (row % 2 == 0) {
				position[row][column].x = column * 32;
				position[row][column].y = row * 32 - 8 * row;
			}
			else {
				position[row][column].x = column * 32 + 16;
				position[row][column].y = row * 32 - 8 * row;
			}

		}
	}


	//ecs

	//tile0.addComponent<TileComponent>(200, 200, 32, 32, 0);
	//tile1.addComponent<TileComponent>(250, 250, 32, 32, 1);
	//tile1.addComponent<ColliderComponent>("mount");
	//tile2.addComponent<TileComponent>(150, 150, 32, 32, 2);
	//tile2.addComponent<ColliderComponent>("grass");

	//player.addComponent<TransformComponent>(position[20][10], 1);
	//player.addComponent<SpriteComponent>("assets/chicken.png");
	//player.addComponent<Keyboard_Controller>();
	//player.addComponent<ColliderComponent>("player");

	//wall.addComponent<TransformComponent>(position[11][11],1);
	//wall.addComponent<SpriteComponent>("assets/mout.png");
	//wall.addComponent<ColliderComponent>("mout");



}

void UCW::handleEvents() {

	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
};
void UCW::update() {
	manager.refresh();
	manager.update();
	
};

void UCW::render() {
	SDL_RenderClear(renderer);
	//this add stuffs to render
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);

};
void UCW::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << " Game Cleaned" << std::endl;

};

