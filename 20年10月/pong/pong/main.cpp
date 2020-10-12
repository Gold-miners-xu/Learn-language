#include <SDL.h>
#include <stdio.h>
class Game {
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();
private:
	struct Vector2
	{
		float x;
		float y;
	};
	Vector2 mPaddlePos{
		(float)thickness / 2,
		(float)768 / 2
	};
	Vector2 mBallPos{
		(float)1024 / 2,
		(float)768 / 2
	};
	Vector2 mBallVel{
		-200.0f,
		235.0f
	};
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	SDL_Window* mWindow;
	bool mIsRunning;
	SDL_Renderer* mRenderer;
	const int thickness = 15;
	Uint32 mTicksCount;
	int mPaddleDir;
	float paddleH;
};
Game::Game(){
	paddleH = 100.f;
	mPaddleDir = 0;
	mTicksCount = 0;
	mWindow = nullptr;
	mIsRunning = true;
}
bool Game::Initialize() {
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
		return false;
	}
	mWindow = SDL_CreateWindow("my first game", 100, 100, 1024, 768, 0);
	if (!mWindow) {
		SDL_Log("Failed to create window: %s", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer) {
		SDL_Log("Renderer creation failed: %s", SDL_GetError());
		return false;
	}

	return true;
}
void Game::Shutdown() {
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}
void Game::RunLoop() {
	while (mIsRunning) {
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}
void Game::ProcessInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			mIsRunning = false;
			break;
		}
	}
	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_ESCAPE]) {
		mIsRunning = false;
	}
	mPaddleDir = 0;
	if (state[SDL_SCANCODE_W])
		mPaddleDir -= 1;
	if (state[SDL_SCANCODE_S])
		mPaddleDir += 1;
};
void Game::UpdateGame() {
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16))
		;
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.f;
	if (deltaTime > 0.05f)
		deltaTime = 0.05f;
	mTicksCount = SDL_GetTicks();

	if (mPaddleDir != 0) {
		mPaddlePos.y += mPaddleDir * 300.0f * deltaTime;
		if (mPaddlePos.y < (paddleH / 2.0f + thickness)) {
			mPaddlePos.y = paddleH / 2.0f + thickness;
		}
		else if (mPaddlePos.y > (768.0f - paddleH / 2.0f - thickness)){
			mPaddlePos.y = 768.0f - paddleH / 2.0f - thickness;
		}
	}
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;
	float diff = mPaddlePos.y - mBallPos.y;
	if (diff < 0.0f)
		diff *= -1;
	if (mBallPos.y <= thickness && mBallVel.y < 0.0f) {
		mBallVel.y *= -1;
	}
	else if (mBallPos.y >= 768.0 - thickness && mBallVel.y > 0.0f) {
		mBallVel.y *= -1;
	}
	if (mBallPos.x >= 1024.0 - thickness && mBallVel.x > 0.0f) {
		mBallVel.x *= -1;
	}
	else if (mBallPos.x <= 25.0f && mBallPos.x >= 20.0f
		&&mBallVel.x < 0.0f && diff <= paddleH/2.0f) {
		mBallVel.x *= -1;
	}
	if (mBallPos.x < 0)
		mIsRunning = false;

};
void Game::GenerateOutput() {

	SDL_Rect ball{
		static_cast<int>(mBallPos.x - thickness / 2),
		static_cast<int>(mBallPos.y - thickness / 2),
		thickness,
		thickness
	};
	SDL_Rect paddle{
		0,
		static_cast<int>(mPaddlePos.y - thickness * 4),
		thickness,
		static_cast<int>(paddleH)
	};
	SDL_Rect wallUp{
		0,
		0,
		1024,
		thickness
	};
	SDL_Rect wallDown{
		0,
		768 - thickness,
		1024,
		thickness
	};
	SDL_Rect wallRight{
		1024 - thickness,
		thickness,
		thickness,
		768 - thickness - thickness
	};
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 255, 255);
	SDL_RenderClear(mRenderer);
	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderFillRect(mRenderer, &wallUp);
	SDL_RenderFillRect(mRenderer, &wallDown);
	SDL_RenderFillRect(mRenderer, &wallRight);
	SDL_RenderFillRect(mRenderer, &ball);
	SDL_RenderFillRect(mRenderer, &paddle);
	SDL_RenderPresent(mRenderer);
};
int main(int argc, char* argv[]) {
	Game game;
	bool success = game.Initialize();
	if (success) {
		game.RunLoop();
	}
	game.Shutdown();
	return 0;
}