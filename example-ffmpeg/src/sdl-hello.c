#include <stdio.h>
#include "SDL2/SDL.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[])
{
    //The window we'll be rendering to
    SDL_Window *window = NULL;

    //The surface contained by the window
    SDL_Surface *screenSurface = NULL;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        //Create window
        window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            return -1;
        }
        // Get the surface from the window
        screenSurface = SDL_GetWindowSurface(window);
        // Make sure getting the surface succeeded

        if(!screenSurface){
            printf("Error getting surface: %s",SDL_GetError());
            return 1;
        }

        // Fill the window with a white rectangle
        SDL_FillRect(screenSurface,NULL,SDL_MapRGB(screenSurface->format,255,255,255));
        // Update the window display
        SDL_UpdateWindowSurface(window);

        SDL_Delay(30000);

        // Destroy the window. This will also destroy the surface
        SDL_DestroyWindow( window );

        // Quit SDL
        SDL_Quit();
    }

    return 0;
}