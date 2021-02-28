Aces:load_images.o main.o
	gcc load_images.o main.o -o Aces -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c
load_images.o:load_images.c
	gcc -c load_images.c
