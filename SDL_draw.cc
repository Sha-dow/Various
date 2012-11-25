// Simple SDL Sprite test
// Hannu Ranta

//Compile: g++ SDL_draw.cc -o Draw -lSDL


#include "SDL/SDL.h" 
int main( int argc, char* args[] ) 
{
  //Luodaan kuvapointterit
  SDL_Surface* hello = NULL;
  SDL_Surface* screen = NULL;
  
  //Käynnistä SDL
  SDL_Init(SDL_INIT_EVERYTHING);
  
  //Aseta näyttö
  screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE);
  
  //Lataa kuva
  hello = SDL_LoadBMP("hello.bmp");
  
  //Kuva näyttöön
  SDL_BlitSurface(hello,NULL,screen,NULL);
  
  //Päivitä näyttö
  SDL_Flip(screen);
  SDL_Delay(2000);
  
  //Vapauta ladattu kuva
  SDL_FreeSurface(hello);
  SDL_Quit();

  return 0;
   
} 
