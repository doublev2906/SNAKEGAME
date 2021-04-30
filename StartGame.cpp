#include"StartGame.h"
StartGame::StartGame()
{
	SDL_Texture* BG = NULL;
	start = false;
	quitgame = false;
	check = true;
	lv = 190;
}

StartGame::~StartGame()
{
	;
}



void StartGame::loadBackGround(SDL_Renderer* ren)
{
	BG = loadTexture("images/images.bmp", ren);
	renderTexture(BG, ren, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}



void StartGame::mainMenu(SDL_Renderer* renderer)
{
	loadBackGround(renderer);
	SDL_Color white = { 255, 255,255 };
	SDL_Color red = { 255, 0,0 };
	SDL_Color yellow = { 255,255,51 };

	SDL_Event e;

	
	/*createText("New Game", renderer, 140, 200, 150, 80, white);
	createText("Quit Game", renderer, 140, 300, 150, 80, white);*/

	bool isQuit = false;
	while (!isQuit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				isQuit = true;
			}
			
			if (e.type == SDL_MOUSEMOTION)
			{
				int x = e.motion.x;
				int y = e.motion.y;

				loadBackGround(renderer);
				createText("S.N.A.K.E", renderer, 80, 80, 300, 100, red);

				if(x>140 && x<290 && y<300 && y>200) createText("New Game", renderer, 140, 200, 150, 80, yellow);
				else createText("New Game", renderer, 140, 200, 150, 80, white);

				if (x > 140 && x < 290 && y < 400 && y>300) createText("Quit Game", renderer, 140, 300, 150, 80, yellow);
				else createText("Quit Game", renderer, 140, 300, 150, 80, white);
				SDL_RenderPresent(renderer);
			}

			if (check)
			{
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (e.button.x >= 140 && e.button.x <= 300 && e.button.y >= 200 && e.button.y <= 300)
						{
							createLevel(renderer);
							check = false;
							isQuit = true;
							break;
						}
					}

				}
			}

			if (check == true)
			{
				if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
				{
					if (e.button.x >= 160 && e.button.x <= 310 && e.button.y >= 300 && e.button.y <= 400);
					{
						quitgame = true;
						isQuit = true;
					}
				}
			}
		}
	}


	
}

void StartGame::createLevel(SDL_Renderer* renderer)
{
	red = loadTexture("images/red.bmp", renderer);
	white = loadTexture("images/white.bmp", renderer);
	loadBackGround(renderer);

	SDL_Color white_ = { 255, 255,255 };
	SDL_Color yellow = { 255,255,51 };

	SDL_Event e;
	bool isQuit = false;

	bool cr = true;
	while (!isQuit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				isQuit = true;
			}

			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_LEFT) lv -= 50;
				if (e.key.keysym.sym == SDLK_RIGHT) lv += 50;
				if (lv < 190) lv = 190;
				else if (lv > 390) lv = 390;
				SDL_RenderClear(renderer);
			}


			if (e.type == SDL_MOUSEMOTION)
			{
				int x = e.motion.x;
				int y = e.motion.y;

				if (x > 160 && x < 310 && y < 500 && y>400) cr = false;
				else cr = true;
			}
			loadBackGround(renderer);
			createText("level", renderer, 140, 100, 200, 100, white_);

			if(cr) createText("Start", renderer, 160, 400, 150, 80, white_);
			else createText("Start", renderer, 160, 400, 150, 80, yellow);


			for (int i = 140; i < 390; i += 50)
			{
				renderTexture(white, renderer, i, 230, 50, 50);
			}
			for (int i = 140; i < lv; i += 50)
			{
				renderTexture(red, renderer, i, 230, 50, 50);
			}
			SDL_RenderPresent(renderer);

				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					if (e.button.button == SDL_BUTTON_LEFT)
					{
						if (e.button.x >= 160 && e.button.x <= 310 && e.button.y >= 400 && e.button.y <= 500) {
							start = true;
							isQuit = true;
							break;
						}
					}
				}

			}
		}
	}


	
void StartGame::select(SDL_Renderer* renderer)
{
	SDL_Event e;
	SDL_Event ev;
	bool isQuit = false;
	while (!isQuit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				isQuit = true;
			}

		}
	}
}

void StartGame::Refresh()
{
	SDL_Texture* BG = NULL;
	start = false;
	lv = 190;
	quitgame = false;
	check = true;
}