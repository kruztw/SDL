// setting a window title
#include <SDL2/SDL.h>
#include <string>

using std::string;

int main()
{
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window = SDL_CreateWindow("title", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 320, 240, SDL_WINDOW_RESIZABLE);
  
  string titles[] = {"a", "b"};

  int t = 0, i = 0;
  for (SDL_Event e; e.type != SDL_QUIT && e.type != SDL_KEYDOWN; SDL_PollEvent(&e)) { 
    if (++t >= 100) { 
    	SDL_SetWindowTitle(window, titles[i%2].c_str());
	i = (i+1)%2;
	t = 0;
    }

    SDL_Delay(10);
  }
  
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
  
}

