#pragma once
#include "string"
#include "raylib.h"

// ########## LABEL Class ##########
class Label
{
public:
	Label(const std::string& text, Vector2 position, int fontSize, Font font, Color color);

	void Draw() const;

private:
	std::string m_text;
	Vector2 m_position;
	int m_fontSize;
	Font m_font;
	Color m_color;
};

// ########## TEXT BOX Class ##########
class TextBox
{
private:
	Vector2 m_size;
	Vector2 m_position;

	Font m_font;
	int m_fontSize;

	int m_cursorPos;
	Vector2 m_caretPos;

public:
	TextBox(Vector2 size, Vector2 position, Font font, int fontSize);

	std::string m_textBoxText;

	void Draw() const;
	void Update();
};