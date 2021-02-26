#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main()
{
   //Declaration de variables;

   //Variables
   int continuer = 1;
   //Variables

   //Images
   SDL_Surface *screen = NULL;
   //Images

   //Events
   SDL_Event event;
   //Events

   //Sound
   Mix_Music *music;
   Mix_Chunk *sound;
   //Sound

   //Declaration de variables;

   //Initialisation video
   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) != 0)
   {
      printf("Unuable to initialize SDL: %s \n", SDL_GetError());
      return 1;
   }
   //Initialisation video

   screen = SDL_SetVideoMode(1260, 700, 32, SDL_HWSURFACE | SDL_RESIZABLE);

   //Initialisation son
   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
   {
      printf("%s", Mix_GetError());
   }
   music = Mix_LoadMUS("Music.mp3");
   Mix_PlayMusic(music,-1);
   //Initialisation son

   //Main Loop
   while (continuer)
   {
      while (SDL_PollEvent(&event))
      {
         switch (event.type)
         {
         case (SDL_QUIT):
            continuer = 0;
            break;

         case (SDL_KEYDOWN):
         {
            switch (event.key.keysym.sym)
            {
            case (SDLK_ESCAPE):
               continuer = 0;
               break;
            }
         }
         }
      }
   }
   //Main loop
   return 0;
}
