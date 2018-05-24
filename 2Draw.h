#pragma once

#include <cmath>
#include <vector>

#ifdef VISOR_ENABLE
#include <SDL2/SDL.h>
//typedef std::vector<std::pair<int,int>> pointList;

#define SCALE 30

class Draw2D
{
public:
	Draw2D(int windowSize=500)
	{	SDL_Init(SDL_INIT_VIDEO);
		win= SDL_CreateWindow("Visor",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,windowSize,windowSize,0);
		ren=SDL_CreateRenderer(win,-1,0);	
	}
	void FullDraw(std::vector<double> directions,int xsize,int ysize)
	{	SDL_SetRenderDrawColor(ren,255,255,255,255);
		SDL_RenderClear(ren);
		SDL_SetRenderDrawColor(ren,0,0,0,255);
		for(int i=0;i<ysize;i++)
		{	int x=SCALE*i+SCALE/2;
			for(int j=0;j<xsize;j++)
			{	
				int y=SCALE*j+SCALE/2;	
				auto angle=directions.at(i+j*ysize);
				int dx=int((SCALE*cos(angle))/2+0.5);
				int dy=int((SCALE*sin(angle)/2)+0.5);
				SDL_RenderDrawLine(ren,x+dx,y+dy,x-dx,y-dy);				
			
			}
		}
		
	SDL_RenderPresent(ren);	
	SDL_Event e;
	while(SDL_PollEvent(&e)!=0)
    {	if( e.type == SDL_QUIT )
		{	exit(0);
        }
        }
	}
	~Draw2D(){SDL_Quit();}

private:
	SDL_Window *win;
	SDL_Renderer *ren;	
};


#endif

#ifndef VISOR_ENABLE
class Draw2D
{
public:
	Draw2D(int windowSize=500){}
	void FullDraw(std::vector<double> directions,int xsize,int ysize){}
	~Draw2D(){
	}
};



#endif
