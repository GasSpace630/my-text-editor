
/*
Use this to compile and run:
g++ src/main.cpp src/uiLib.cpp -lraylib -lm -o app && ./app && clear
*/

#include "iostream"
#include "raylib.h"

#include "uiLib.h"

int screenWidth = 960;
int screenHeight = 540;
const int FPS = 60;

int main()
{
	InitWindow(screenWidth, screenHeight, "My text editor");
	SetTargetFPS(FPS);

	int fontSize = 24;
	float textSpacing = 0.1;

	Font pixelFont = LoadFontEx("res/pixantiqua.ttf", fontSize, 0, 0);

	const char* text = "My Code Editor";
	Vector2 textSize = MeasureTextEx(pixelFont, text, fontSize, textSpacing);
	Vector2 textPos = { (float)screenWidth / 2.0f - (float)textSize.x / 2.0f, 0.0f };

	Label label1(text, textPos, fontSize, pixelFont, WHITE);
	TextBox textBox1({25, 25, 800, 400}, fontSize, GRAY, DARKGRAY, WHITE);


	while(!WindowShouldClose())
	{
		textBox1.Update();
		BeginDrawing();

		ClearBackground(BLACK);
		label1.Draw();
		textBox1.Draw();
		DrawRectangle(0, 0, 20, screenHeight, GRAY);

		EndDrawing();
	}

	UnloadFont(pixelFont);
	CloseWindow();

	return 0;
}