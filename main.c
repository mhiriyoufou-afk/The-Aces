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
   int Res_Width = 1920;
   int Res_Length = 1080;
   //Variables

   //Background
   SDL_Surface *screen = NULL;
   SDL_Surface *Bg_Image_1 = NULL, *Bg_Image_2 = NULL, *Bg_Image_3;
   //Background

   //Buttons
   SDL_Surface *Continue_Button = NULL;
   SDL_Surface *New_Button = NULL;
   SDL_Surface *Load_Button = NULL;
   SDL_Surface *Options_Button = NULL;
   SDL_Surface *Quit_Button = NULL;
   //Buttons

   //Button Coordinates
   SDL_Rect continue_start,continue_end;
   SDL_Rect new_start,new_end;
   SDL_Rect load_start,load_end;
   SDL_Rect options_start,options_end;
   SDL_Rect quit_start,quit_end;
   continue_start.x = 194, continue_end.x = 461;
   continue_start.y = 155, continue_end.y = 274;
   new_start.x = 194, new_end.x=534;
   new_start.y = 305, new_end.y=424;
   load_start.x = 194, load_end.x = 526;
   load_start.y = 455, load_end.y = 574;
   options_start.x = 194, options_end.x = 426;
   options_start.y = 605, options_end.y = 724;
   quit_start.x = 194, quit_end.x = 320;
   quit_start.y = 755, quit_end.y = 874;
   //Button Coordinates

   //Positions
   SDL_Rect Pos_Bg;
   Pos_Bg.x = 0;
   Pos_Bg.y = 0;
   //Positions

   //Events
   SDL_Event event;
   //Events

   //Sound
   Mix_Music *music;
   Mix_Chunk *sound;
   //Sound

   //Volume
   int Volume = 80;
   //Volume

   //Declaration de variables;

   
      //Animation Background
   //Background blit

   //Initialisation video
   SDL_Init(SDL_INIT_VIDEO);

   if (SDL_Init(SDL_INIT_VIDEO) != 0)
   {
      printf("Unable to initialize SDL: %s \n", SDL_GetError());
      return 1;
   }
   //Initialisation video

   //Load Images
   screen = SDL_SetVideoMode(Res_Width, Res_Length, 32, SDL_HWSURFACE |SDL_DOUBLEBUF | SDL_RESIZABLE);
   Bg_Image_1 = IMG_Load("Assets/Images/Backgrounds/first.png");
   Bg_Image_2 = IMG_Load("Assets/Images/Backgrounds/second.png");
   Bg_Image_3 = IMG_Load("Assets/Images/Backgrounds/third.png");
   Continue_Button = IMG_Load("Assets/Images/UI/Continue0.png");
   New_Button = IMG_Load("Assets/Images/UI/New.png");
   Load_Button = IMG_Load("Assets/Images/UI/Load.png");
   Options_Button = IMG_Load("Assets/Images/UI/Options.png");
   Quit_Button = IMG_Load("Assets/Images/UI/Quit.png");
   //Load Images

   //Affichage Bouttons
     SDL_BlitSurface(Continue_Button, NULL, screen, &continue_start); 
     SDL_Flip(screen);

   //Affichage Boutons

   //Initialisation son
   if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
   {
      printf("%s", Mix_GetError());
   }
   music = Mix_LoadMUS("Assets/Audio/Music/Music.mp3");
   sound = Mix_LoadWAV("Assets/Audio/SFX/clickk.wav");
   Mix_PlayMusic(music, -1);
   //Initialisation son

   //Main Loop
   while (continuer)
   {
      SDL_BlitSurface(Bg_Image_1, NULL, screen, &Pos_Bg);
      //SDL_Flip(screen);
      SDL_BlitSurface(Continue_Button, NULL, screen, &continue_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(New_Button, NULL, screen, &new_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Load_Button, NULL, screen, &load_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Options_Button, NULL, screen, &options_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Quit_Button, NULL, screen, &quit_start);
      SDL_Flip(screen);
      //SDL_Delay(1000);
      SDL_BlitSurface(Bg_Image_2, NULL, screen, &Pos_Bg);
      //SDL_Flip(screen);
      SDL_BlitSurface(Continue_Button, NULL, screen, &continue_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(New_Button, NULL, screen, &new_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Load_Button, NULL, screen, &load_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Options_Button, NULL, screen, &options_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Quit_Button, NULL, screen, &quit_start);
      SDL_Flip(screen);
      //SDL_Delay(1000);
      SDL_BlitSurface(Bg_Image_3, NULL, screen, &Pos_Bg);
      //SDL_Flip(screen);
      SDL_BlitSurface(Continue_Button, NULL, screen, &continue_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(New_Button, NULL, screen, &new_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Load_Button, NULL, screen, &load_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Options_Button, NULL, screen, &options_start);
      //SDL_Flip(screen);
      SDL_BlitSurface(Quit_Button, NULL, screen, &quit_start);
      SDL_Flip(screen);
      //SDL_Delay(1000);

      while (SDL_PollEvent(&event))
      {
         switch (event.type)
         {
         case (SDL_QUIT):
            continuer = 0;
            break;
         case (SDL_MOUSEMOTION):
         {
            //printf("x = %d\n",event.motion.x);
            //printf("y = %d\n",event.motion.y);
            if ((event.motion.x) >= (continue_start.x) && (event.motion.x) <= (continue_end.x) && (event.motion.y) >= (continue_start.y) && (event.motion.y) <= (continue_end.y) || (event.motion.x) >= (new_start.x) && (event.motion.x) <= (new_end.x) && (event.motion.y) >= (new_start.y) && (event.motion.y) <= (new_end.y) || (event.motion.x) >= (load_start.x) && (event.motion.x) <= (load_end.x) && (event.motion.y) >= (load_start.y) && (event.motion.y) <= (load_end.y) || (event.motion.x) >= (options_start.x) && (event.motion.x) <= (options_end.x) && (event.motion.y) >= (options_start.y) && (event.motion.y) <= (options_end.y) || (event.motion.x) >= (quit_start.x) && (event.motion.x) <= (quit_end.x) && (event.motion.y) >= (quit_start.y) && (event.motion.y) <= (quit_end.y))
            {
               Mix_PlayChannel(-1, sound, 0);
            }
         }
         case SDL_MOUSEBUTTONDOWN:
         {
            if ((event.motion.x) >= (continue_start.x) && (event.motion.x) <= (continue_end.x) && (event.motion.y) >= (continue_start.y) && (event.motion.y) <= (continue_end.y) || (event.motion.x) >= (new_start.x) && (event.motion.x) <= (new_end.x) && (event.motion.y) >= (new_start.y) && (event.motion.y) <= (new_end.y) || (event.motion.x) >= (load_start.x) && (event.motion.x) <= (load_end.x) && (event.motion.y) >= (load_start.y) && (event.motion.y) <= (load_end.y) || (event.motion.x) >= (options_start.x) && (event.motion.x) <= (options_end.x) && (event.motion.y) >= (options_start.y) && (event.motion.y) <= (options_end.y) || (event.motion.x) >= (quit_start.x) && (event.motion.x) <= (quit_end.x) && (event.motion.y) >= (quit_start.y) && (event.motion.y) <= (quit_end.y))
               if (event.button.button = SDL_BUTTON_LEFT)
               {
                  Mix_PlayChannel(-1, sound, 0);
               }
         }

         case (SDL_KEYDOWN):
         {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
               Mix_VolumeMusic(Volume += 10);
               break;
            case SDLK_DOWN:
               Mix_VolumeMusic(Volume -= 10);
               break;
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
