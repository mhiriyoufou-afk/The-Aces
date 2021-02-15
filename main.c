#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
int main ()
{
//background;
SDL_Event event;
SDL_Surface *screen=NULL,*image=NULL,*image2=NULL,*image3=NULL,*image4=NULL;
SDL_Init(SDL_INIT_VIDEO);
SDL_Rect positionecran;
SDL_Rect positionecran2;
SDL_Rect positionecran3;
SDL_Rect positionecran4;
SDL_Rect Bp;
SDL_Rect Bo;
SDL_Rect Bq;
Bp.x=550;
Bp.y=180;
Bp.w=105;
Bo.h=55;
Bo.x=550;
Bo.y=280;
Bo.w=105;
Bo.h=55;
Bq.x=550;
Bq.y=380;
Bq.w=191;
Bq.h=55;

int continuer=1;
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unuable to initialize SDL: %s \n",SDL_GetError());
return 1;
}
screen = SDL_SetVideoMode(1260,700,32, SDL_HWSURFACE |SDL_DOUBLEBUF);
image2 =IMG_Load("play.png");
image =IMG_Load("time.jpg");
image3 =IMG_Load("options.png");
image4 =IMG_Load("QUIT.png");
if(image==NULL)
{
printf("Unuable to load bitmap:%s \n",SDL_GetError());
return 1;
}

positionecran.x=0;
positionecran.y=0;
SDL_BlitSurface(image,NULL,screen,&positionecran);
SDL_Flip(screen);
positionecran2.x=550;
positionecran2.y=180;
SDL_BlitSurface(image2,NULL,screen,&positionecran2);
SDL_Flip(screen);
positionecran3.x=550;
positionecran3.y=280;
SDL_BlitSurface(image3,NULL,screen,&positionecran3);
SDL_Flip(screen);
positionecran4.x=550;
positionecran4.y=380;
SDL_BlitSurface(image4,NULL,screen,&positionecran4);
SDL_Flip(screen);


//music;
Mix_Music *music;
Mix_Chunk *son;
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,1024)==-1)
{
printf("%s",Mix_GetError());
}
music=Mix_LoadMUS("ghribi.mp3");
son=Mix_LoadWAV("clickk.wav");
Mix_PlayMusic(music,-1);



while(continuer)
{
while(SDL_PollEvent(&event))
{
switch(event.type)
{
case SDL_QUIT:
continuer=0;
break;
           case SDL_MOUSEMOTION:
              if(((event.motion.x>=550)&&(event.motion.x<=655))&&((event.motion.y>=180)&&(event.motion.y<=235))||                   ((event.motion.x>=550)&&(event.motion.x<=655))&&((event.motion.y>=280)&&(event.motion.y<=335))||((event.motion.x>=550)&&(event.motion.x<=741))&&((event.motion.y>=380)&&(event.motion.y<=435)))

Mix_PlayChannel(-1,son,0);



break;
}
}
}

return 0 ; 
}

