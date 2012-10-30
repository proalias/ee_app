#ifndef ColorConstants_h
#define ColorConstants_h

#include "cinder/Color.h"

using namespace ci;

class ColorConstants
{
public:

	static const Color PRIMARY_TEAL;
	static const Color PRIMARY_YELLOW;
	
	static const Color TINT_TEAL_LIGHT;
	static const Color TINT_YELLOW;
	static const Color TINT_TEAL_DARK;
	static const Color TINT_YELLOW_DARK;

	static const Color PRIMARY_ACCENT_GREY_DARK;
	static const Color PRIMARY_ACCENT_WHITE;
	static const Color PRIMARY_ACCENT_GREY_LIGHT;

	static const Color TERTIARY_ACTION_PINK;
	static const Color TERTIARY_ACTION_PURPLE;

	static const Color TERTIARY_ACCENT_BLACK;
	static const Color TERTIARY_ACCENT_GREY;

	static const Color WHITE;

	ColorConstants(void);
	~ColorConstants(void);
};

#endif