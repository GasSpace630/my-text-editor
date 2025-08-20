#include "uiLib.h"
#include <raylib.h>
#include <string>

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
	DrawTextEx(m_font, m_text.c_str(), {m_position.x, m_position.y}, m_fontSize, 1, m_color);
}

// ########## TEXT BOX Class ##########

TextBox::TextBox(Vector2 size, Vector2 position, Font font,  int fontSize):
	m_size(size),
	m_position(position),
	m_font(font),
	m_fontSize(fontSize)
	{}

void TextBox::Draw() const
{
	Vector2 textPos = {m_position.x + 5, m_position.y + 5};
	DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, DARKGRAY);
	DrawTextEx(m_font, m_textBoxText.c_str(), textPos, m_fontSize, 1, WHITE);

	DrawRectangle(m_caretPos.x + 5, m_caretPos.y + 5, 5, 20, RED);
}

void TextBox::Update()
{
	Vector2 textSize = MeasureTextEx(m_font, m_textBoxText.c_str(), m_fontSize, 1.0);
	m_caretPos.y = textSize.y;

	int key = GetCharPressed();

	while (key > 0)
	{
		if ((key >= 32) && (key <= 125))
		{
			m_textBoxText.push_back(static_cast<char>(key));
			m_cursorPos++;
		}
		key = GetCharPressed();
	}
	if ((IsKeyPressed(KEY_BACKSPACE)) && (!m_textBoxText.empty()))
	{
		m_textBoxText.erase(m_cursorPos - 1, 1);
		m_cursorPos--;
	}
	if (IsKeyPressed(KEY_ENTER))
	{
		m_textBoxText.insert(m_cursorPos, 1, '\n');
	}

	if (m_cursorPos < 0) m_cursorPos = 0;
	if (m_cursorPos > m_textBoxText.length()) m_cursorPos = m_textBoxText.length();
}
