#include "Color.h"

Color getOposite(const Color& color)
{
	return color == Color::White ? Color::Black : Color::White;
}
