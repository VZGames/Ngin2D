#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

SDL_Window* window;
SDL_Renderer* renderer;

int cameraX = 0;
int cameraY = 0;

bool quit = false;

// Rectangle position
int redRectX = 100;
int redRectY = 100;
int blueRectX = 300;
int blueRectY = 200;

void renderRect(int x, int y, int w, int h) {
    SDL_Rect rect = { x - cameraX, y - cameraY, w, h };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void renderOtherRect(int x, int y, int w, int h) {
    SDL_Rect rect = { x, y, w, h };
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            quit = true;
        }
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                cameraX -= 10;
                break;
            case SDLK_RIGHT:
                cameraX += 10;
                break;
            case SDLK_UP:
                cameraY -= 10;
                break;
            case SDLK_DOWN:
                cameraY += 10;
                break;
            }
            std::cout << "x:" << cameraX << ", y:" << cameraY << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("SDL Camera Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    while (!quit) {
        handleInput();

        // Adjust the camera to keep the red rectangle centered
        cameraX = redRectX - SCREEN_WIDTH / 2;
        cameraY = redRectY - SCREEN_HEIGHT / 2;

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Render objects
        renderRect(redRectX, redRectY, 50, 50);
        renderOtherRect(blueRectX, blueRectY, 50, 50);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
