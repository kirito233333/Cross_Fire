 // Cross_Fire.cpp: 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <SDL.h>
#include <SDL_mixer.h>
#include <stdlib.h>
#include <ctime>
#define windowWidth  1920
#define windowHeight   1080

void addnum(SDL_Renderer* rend, SDL_Texture** image,SDL_Rect* rectnum, int a,int pos) {
	SDL_RenderCopy(rend, image[a], NULL, &rectnum[pos]);
}
bool downp = true;
bool rightp = true;
void movePicture(SDL_Rect &rect) {
	if (downp == true) {
		rect.y++;
		if (rect.y >= windowHeight - rect.h) {
			downp = false;
		}
	}
	else {
		rect.y--;
		if (rect.y <= 0) {
			downp = true;
		}
	}
	if (rightp == true) {
		rect.x++;
		if (rect.x >= windowWidth - rect.w) {
			rightp = false;
		}
	}
	else {
		rect.x--;
		if (rect.x <= 0) {
			rightp = true;
		}
	}
}
int main(int argc, char** argv)
 {
	srand((unsigned int)time(0));
	 SDL_Init(SDL_INIT_VIDEO);
	 SDL_Window* window = SDL_CreateWindow("Cross_Fire 1.0",
		 SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		 windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	 
	 SDL_Renderer* rend = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	 SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
	 SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);

	 
	 SDL_Surface* cfSurface = SDL_LoadBMP("cf.bmp");
	 //SDL_Surface* cfbaSurface = SDL_LoadBMP("ba.bmp");
	 SDL_Surface* cfSurfaceba[2];
	 cfSurfaceba[0] = SDL_LoadBMP("ba1.bmp");
	 cfSurfaceba[1] = SDL_LoadBMP("ba2.bmp");
	 SDL_Surface* cfhuoSurface = SDL_LoadBMP("huo.bmp");
	 SDL_Surface* whiteWindow = SDL_LoadBMP("white.bmp");
	 SDL_Surface* numSurface[10];
	 //15*20像素
	 numSurface[0] = SDL_LoadBMP("0.bmp");
	 numSurface[1] = SDL_LoadBMP("1.bmp");
	 numSurface[2] = SDL_LoadBMP("2.bmp");
	 numSurface[3] = SDL_LoadBMP("3.bmp");
	 numSurface[4] = SDL_LoadBMP("4.bmp");
	 numSurface[5] = SDL_LoadBMP("5.bmp");
	 numSurface[6] = SDL_LoadBMP("6.bmp");
	 numSurface[7] = SDL_LoadBMP("7.bmp");
	 numSurface[8] = SDL_LoadBMP("8.bmp");
	 numSurface[9] = SDL_LoadBMP("9.bmp");
	 SDL_Surface* xieSurface = SDL_LoadBMP("xie.bmp");
	 SDL_Surface* killSurface[7];
	 killSurface[0] = SDL_LoadBMP("headshot.bmp");
	 killSurface[1] = SDL_LoadBMP("kill1.bmp");
	 killSurface[2] = SDL_LoadBMP("kill2.bmp");
	 killSurface[3] = SDL_LoadBMP("kill3.bmp");
	 killSurface[4] = SDL_LoadBMP("kill4.bmp");
	 killSurface[5] = SDL_LoadBMP("kill5.bmp");
	 killSurface[6] = SDL_LoadBMP("kill6.bmp");
	 SDL_SetColorKey(cfSurface, SDL_TRUE, SDL_MapRGB(cfSurface->format, 255, 255, 255));
	 //SDL_SetColorKey(cfbaSurface, SDL_TRUE, SDL_MapRGB(cfbaSurface->format, 246, 246, 246));
	 SDL_SetColorKey(cfSurfaceba[0], SDL_TRUE, SDL_MapRGB(cfSurfaceba[0]->format,255,255,255));
	 SDL_SetColorKey(cfSurfaceba[1], SDL_TRUE, SDL_MapRGB(cfSurfaceba[1]->format, 255, 255, 255));
	 SDL_SetColorKey(cfhuoSurface, SDL_TRUE, SDL_MapRGB(cfhuoSurface->format, 255, 255, 255));
	 for (int i = 0; i < 10; i++) {
		 SDL_SetColorKey(numSurface[i], SDL_TRUE, SDL_MapRGB(cfSurface->format, 0, 0, 0));
	 }
	 SDL_SetColorKey(xieSurface, SDL_TRUE, SDL_MapRGB(cfSurface->format, 0, 0, 0));
	 SDL_Texture* cf = SDL_CreateTextureFromSurface(rend, cfSurface);
	 //SDL_Texture* cfba = SDL_CreateTextureFromSurface(rend, cfbaSurface);
	 SDL_Texture* cfba[2];
	 cfba[0]= SDL_CreateTextureFromSurface(rend, cfSurfaceba[0]);
	 cfba[1] = SDL_CreateTextureFromSurface(rend, cfSurfaceba[1]);
	 SDL_Texture* cfhuo = SDL_CreateTextureFromSurface(rend, cfhuoSurface);
	 SDL_Texture* white = SDL_CreateTextureFromSurface(rend, whiteWindow);
	 SDL_Texture* num[10];
	 for (int i=0; i < 10; i++) {
		 num[i] = SDL_CreateTextureFromSurface(rend, numSurface[i]);
	 }
	 SDL_Texture* kill[7];
	 for (int i = 0; i < 7; i++) {
		 SDL_SetColorKey(killSurface[i], SDL_TRUE, SDL_MapRGB(killSurface[i]->format, 255, 255, 255));
		 kill[i] = SDL_CreateTextureFromSurface(rend, killSurface[i]);
	 }
	 SDL_Texture* xie = SDL_CreateTextureFromSurface(rend, xieSurface);
	 SDL_Rect rectxie;
	 rectxie.x = windowWidth - 60;
	 rectxie.y = windowHeight - 20;
	 rectxie.w = 15;
	 rectxie.h = 20;
	 SDL_Rect rectnum[5];
	 int i;
	 for (i = 0; i < 5; ++i) {
		 if (i < 3) {
			 rectnum[i].x = windowWidth - (i + 1) * 15;
		 }
		 else {
			 rectnum[i].x = windowWidth - (i + 2) * 15;
		 }
		 rectnum[i].y = windowHeight-20;
		 rectnum[i].w = 15;
		 rectnum[i].h = 20;
	 }
	 SDL_Rect rectcf;
	 rectcf.x = windowWidth-cfSurface->w;
	 rectcf.y = windowHeight-cfSurface->h;
	 rectcf.w = cfSurface->w;
	 rectcf.h = cfSurface->h;

	 SDL_Rect rectcfba[2];
	 rectcfba[0].w = cfSurfaceba[0]->w;
	 rectcfba[0].h = cfSurfaceba[0]->h;
	 rectcfba[0].x = rand() % (windowWidth - rectcfba[0].w);
	 rectcfba[0].y = rand() % (windowHeight - rectcfba[0].h);

	 rectcfba[1].w = cfSurfaceba[1]->w;
	 rectcfba[1].h = cfSurfaceba[1]->h;
	 rectcfba[1].x = rand() % (windowWidth - rectcfba[1].w);
	 rectcfba[1].y = rand() % (windowHeight - rectcfba[1].h);

	 SDL_Rect rectcfhuo;
	 rectcfhuo.x = windowWidth - cfhuoSurface->w-15*6;
	 rectcfhuo.y = windowHeight - cfhuoSurface->h;
	 rectcfhuo.w = cfhuoSurface->w;
	 rectcfhuo.h = cfhuoSurface->h;
	 
	 SDL_Rect rectkill;
	 rectkill.h = killSurface[1]->h*2;
	 rectkill.w = killSurface[1]->w*2;
	 rectkill.x = (windowWidth - rectkill.w) / 2;
	 rectkill.y = windowHeight - rectkill.h-10;

	 SDL_Rect rectkill_head_multi;
	 rectkill_head_multi.h = killSurface[1]->h * 2;
	 rectkill_head_multi.w = killSurface[1]->w * 2;
	 rectkill_head_multi.x = (windowWidth - rectkill_head_multi.w) / 2- rectkill_head_multi.w;
	 rectkill_head_multi.y = windowHeight - rectkill_head_multi.h - 10;
	 

	 Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	 Mix_Music* cfsound = Mix_LoadMUS("cf.wav");
	 Mix_Music* cfsound1 = Mix_LoadMUS("st.wav");
	 Mix_Music* cfsoundzhong = Mix_LoadMUS("knifekill_BL.wav");
	 Mix_Music* cfsounddouble = Mix_LoadMUS("MultiKill_2_BL.wav");
	 Mix_Music* cfsound_3 = Mix_LoadMUS("MultiKill_3_BL.wav");
	 Mix_Music* cfsound_4 = Mix_LoadMUS("MultiKill_4_BL.wav");
	 Mix_Music* cfsound_5 = Mix_LoadMUS("MultiKill_5_BL.wav");
	 Mix_Music* cfsound_6 = Mix_LoadMUS("MultiKill_6_BL.wav");
	 Mix_Music* cfsound_7 = Mix_LoadMUS("MultiKill_7_BL.wav");
	 Mix_Music* cfsound_8 = Mix_LoadMUS("MultiKill_8_GR.wav");
	 Mix_Music* cfsound_head = Mix_LoadMUS("Headshot_BL.wav");
	 Mix_Music* cfsound_start = Mix_LoadMUS("Round_Start_BL_4.wav");
	
	 
	 bool open = false;
	 
	 SDL_Event event;
	 Mix_PlayMusic(cfsound_start, 1);
	 int count = 0;
	 int maxshot = 0;
	 int ammunition = 135;
	 int clip = 35;
	 int who = 0;
	 int multible = 1;
	 int k = -1;
	 bool quit = false;
	 bool head_multi = false;
	 while (!quit) {
		 while (SDL_PollEvent(&event)) {
			 if (event.type == SDL_QUIT) {
				 quit = true;
			 }
			 else if (event.type == SDL_MOUSEMOTION) {
				 rectcf.x = event.motion.x-13;
				 rectcf.y = event.motion.y-13;//准心位置13像素
			 }
			 else if (event.type == SDL_MOUSEBUTTONDOWN) {
				 if (event.button.button == SDL_BUTTON_LEFT) {
					 int tempx,tempy;
					 if(clip>0) clip--;
					 else {
						 continue;
					 }
					 if (count==0&&event.motion.x - rectcfba[who].x <= 100/multible&& event.motion.x - rectcfba[who].x >= 65/ multible &&event.motion.y - rectcfba[who].y <= 60/multible) { //爆头区
						 Mix_PlayMusic(cfsound_head, 1);
						 downp = rand() % 2;
						 rightp = rand() % 2;
						 k = 0;
						 count++;
					 }
					 else if (event.motion.x - rectcfba[who].x >=0&&event.motion.x - rectcfba[who].x <= rectcfba[who].w&&event.motion.y - rectcfba[who].y>=0&&event.motion.y - rectcfba[who].y <= rectcfba[who].h) {
						 count++;
						 head_multi = false;
						 downp = rand() % 2;
						 rightp = rand() % 2;
						 int or78 = 0;
						 switch (count) {
						 case 1: Mix_PlayMusic(cfsoundzhong, 1); k = 1; break;
						 case 2: Mix_PlayMusic(cfsounddouble, 1); k = 2; break;
						case 3: Mix_PlayMusic(cfsound_3, 1); k = 3; break;
						case 4: Mix_PlayMusic(cfsound_4, 1); k = 4; break;
						case 5: Mix_PlayMusic(cfsound_5, 1); k = 5; break;
						case 6: Mix_PlayMusic(cfsound_6, 1); k = 6; break;
						case 7: Mix_PlayMusic(cfsound_7, 1); k = 6; break;
						case 8: Mix_PlayMusic(cfsound_8, 1); k = 6; break;
						default: or78 = rand() % 2; or78 > 0 ? Mix_PlayMusic(cfsound_7, 1) : Mix_PlayMusic(cfsound_8, 1); k = 6;
						 }
						 tempx = rectcfba[who].x;
						 tempy = rectcfba[who].y;
						 who = rand() % 2;
						 multible = rand() % 4+ 1;
						 rectcfba[who].w = cfSurfaceba[who]->w/multible;
						 rectcfba[who].h = cfSurfaceba[who]->h/multible;
						 rectcfba[who].x = (rand()+  who*100) % (windowWidth - rectcfba[who].w);
						 rectcfba[who].y = (rand() + who * 100) % (windowHeight - rectcfba[who].h);
					 }
					 else {
						 Mix_PlayMusic(cfsound, 1);
						 system("cls");
						 if (maxshot < count) maxshot = count;
						 printf("最大连击数：%d\n", maxshot);
						 head_multi = false;
						 count = 0;
						 k = -1;
					 }
					 
					 if (count>1&&event.motion.x - tempx <= 100 / multible && event.motion.x - tempx >= 65 / multible && event.motion.y - tempy <= 60 / multible) { //爆头区
						 head_multi = true;
						 
					 }
				 }
			 }
			 else if (event.type == SDL_KEYDOWN) {
				 if (event.key.keysym.sym == 'r' || event.key.keysym.sym == 'R') {
					 ammunition = ammunition + clip - 35;
					 clip = 35;
					 Mix_PlayMusic(cfsound1, 1);
				 }
				 else if (event.key.keysym.sym == SDLK_SPACE) {
					 quit = true;
				 }
			 }
		 }
		 SDL_RenderClear(rend);
		// SDL_RenderCopy(rend, white, NULL, &rectwhite);
		 movePicture(rectcfba[who]);
		 SDL_RenderCopy(rend, cfba[who], NULL, &rectcfba[who]);
		 SDL_RenderCopy(rend, cf, NULL, &rectcf);
		 int temp = ammunition;
		 int j = 0;
		 do {
			 int a = temp % 10;
			 addnum(rend, num,rectnum, a,j);
			 temp /= 10;
			 j++;
		 } while (temp != 0);
		 SDL_RenderCopy(rend, xie, NULL, &rectxie);
		 j = 3;
		 temp = clip;
		 do{
			 int a = temp % 10;
			 addnum(rend, num, rectnum, a, j);
			 temp /= 10;
			 j++;
		 } while (temp != 0); 
		
		 SDL_RenderCopy(rend, cfhuo, NULL, &rectcfhuo);
		 if (k >= 0) SDL_RenderCopy(rend, kill[k], NULL, &rectkill);
		 if(head_multi ) SDL_RenderCopy(rend, kill[0], NULL, &rectkill_head_multi);
		 SDL_RenderPresent(rend);
		 SDL_Delay(5);
	 }
	
	 SDL_DestroyRenderer(rend);
	 SDL_DestroyWindow(window);
	 SDL_Quit();
	 return 0;
 }


