#include "uiLib.h"
#include <raylib.h>

// ########## LABEL Class ##########

Label::Label(const std::string& text, Vector2 position, int fontSize, Font font, Color color):
	m_text(text),
	m_position(position),
	m_fontSize(fontSize),
	m_font(font),
	m_color(color)
	{}

void Label::Draw() const
{
	DrawTextEx(m_font, m_text.c_str(), {m_position.x, m_position.y}, m_fontSize, 0.0, m_color);
}

// ########## TEXT BOX Class ##########

TextBox::TextBox(Rectangle bounds, int fontSize, Color boxColor, Color focusedColor, Color textColor):
	m_bounds(bounds),
	m_fontSize(fontSize),
	m_boxColor(boxColor),
	m_focusedColor(focusedColor),
	m_textColor(textColor)
	{
		m_text = "";
	}

void TextBox::Update()
{
	Vector2 MousePos = GetMousePosition();
	// focus the text box when you click on it
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		m_isFocused = CheckCollisionPointRec(MousePos, m_bounds);
		if (m_isFocused)
		{
			m_cursorTimer = 0.0;
		}
	}

	if (m_isFocused)
	{
		// get the ASCII key presssed
		int pressedKey = GetKeyPressed();
		int textWidth = MeasureText(m_text.c_str(), m_fontSize);
		if (pressedKey >= 32 && pressedKey <= 126 && textWidth <= m_bounds.width - m_fontSize)
		{
			if (IsKeyDown(KEY_LEFT_SHIFT))
			{
				pressedKey -= 32;
			}
			pressedKey += 32;
			m_text += (char)pressedKey;
			m_cursorPos.x++;
		}
		if (IsKeyPressed(KEY_BACKSPACE))
		{
			if (!m_text.empty())
			{
				m_text.pop_back();
				m_cursorPos.x--;
			}
		}
		if (IsKeyPressed(KEY_ENTER))
		{
			m_text += "\n";
			m_cursorPos.y += m_fontSize;
		}
	}

	m_cursorTimer += GetFrameTime();
	if (m_cursorTimer > 1.5)
	{
		m_cursorTimer = 0.0;
	}
}

void TextBox::Draw() const
{
	Color bgColor = m_isFocused ? m_focusedColor : m_boxColor;
	DrawRectangleRec(m_bounds, bgColor);
	std::string textBeforeCursor = m_text.substr(0, m_cursorPos.x);
	int textWidth = MeasureText(textBeforeCursor.c_str(), m_fontSize);
	int cursorX = m_bounds.x + 5 + textWidth;
	if (m_isFocused && m_cursorTimer > 1.0)
	{
		DrawText("|", cursorX, m_bounds.y + 5 + m_cursorPos.y, m_fontSize, m_textColor);
	}
	DrawText(m_text.c_str(), m_bounds.x + 5, m_bounds.y + 5, m_fontSize, WHITE);
}