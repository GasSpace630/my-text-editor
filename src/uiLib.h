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
public:
	TextBox(Rectangle bounds, int fontSize, Color boxColor, Color focusedColor, Color textColor);

	void Update();

	void Draw() const;

	std::string GetText() const;

private:
	Rectangle m_bounds;
	std::string m_text;
	int m_fontSize;

	Color m_boxColor;
	Color m_focusedColor;
	Color m_textColor;

	bool m_isFocused;
	Vector2 m_cursorPos;
	double m_cursorTimer = 0.0;
};