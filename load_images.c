#include "load_images.h"
void load_images( int Res_Width, int Res_Length, SDL_Surface * screen, SDL_Surface *Bg_Image_1, SDL_Surface *Bg_Image_2, SDL_Surface *Bg_Image_3, SDL_Surface* Continue_Button, SDL_Surface* New_Button, SDL_Surface* Load_Button, SDL_Surface* Options_Button, SDL_Surface* Quit_Button)
{
    screen = SDL_SetVideoMode(Res_Width, Res_Length, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
    Bg_Image_1 = IMG_Load("Assets/Images/Backgrounds/first.png");
    Bg_Image_2 = IMG_Load("Assets/Images/Backgrounds/second.png");
    Bg_Image_3 = IMG_Load("Assets/Images/Backgrounds/third.png");
    Continue_Button = IMG_Load("Assets/Images/UI/Continue0.png");
    New_Button = IMG_Load("Assets/Images/UI/New.png");
    Load_Button = IMG_Load("Assets/Images/UI/Load.png");
    Options_Button = IMG_Load("Assets/Images/UI/Options.png");
    Quit_Button = IMG_Load("Assets/Images/UI/Quit.png");
}