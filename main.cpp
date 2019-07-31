#include <SDL2/SDL.h>
#include <GL/gl.h>
#include "ebmp.h"

void DrawBMP(int px, int py, Eternal::Bmp *b) {
    for(int x = 0;x < b->GetWidth();x++) {
        for(int y= 0;y < b->GetHeight();y++) {
            float red = (float)b->GetPixelRGBA(x,y).B / 255.0f;
            float green = (float)b->GetPixelRGBA(x,y).G / 255.0f;
            float blue = (float)b->GetPixelRGBA(x,y).R / 255.0f;

            glColor3f(red,green,blue);
            glBegin(GL_POINTS);
            glVertex2f(x + px,y + py);
            glEnd();

        }
     }
}

int main(int argc, char *args[]) {

    Eternal::Bmp bmp[5];
    bmp[0].Load("kawaii_alpha.bmp");

    SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window *myWindow = SDL_CreateWindow("...", 200, 200, 1024, 768, SDL_WINDOW_OPENGL);

	SDL_GLContext glContext = SDL_GL_CreateContext(myWindow);

	glClearColor(0, 0, 0.25f, 1);
	SDL_GL_SetSwapInterval(0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 768, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glViewport(0, 0, 1024, 768);


    SDL_Event e;
    for(;;) {
        SDL_PollEvent(&e);
        glClear(GL_COLOR_BUFFER_BIT);

        DrawBMP(0, 0, &bmp[0]);

        if(SDL_GetKeyboardState(0)[SDL_SCANCODE_ESCAPE]) {
            break;
        }
        SDL_GL_SwapWindow(myWindow);
    }

    SDL_Quit();
    return 0;
}
