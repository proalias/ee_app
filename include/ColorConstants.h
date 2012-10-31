#ifndef ColorConstants_h
#define ColorConstants_h

#include "cinder/Color.h"


class ColorConstants
{
public:

	static const ci::Color PRIMARY_TEAL;
	static const ci::Color PRIMARY_YELLOW;
	
	static const ci::Color TINT_TEAL_LIGHT;
	static const ci::Color TINT_YELLOW;
	static const ci::Color TINT_TEAL_DARK;
	static const ci::Color TINT_YELLOW_DARK;

	static const ci::Color PRIMARY_ACCENT_GREY_DARK;
	static const ci::Color PRIMARY_ACCENT_WHITE;
	static const ci::Color PRIMARY_ACCENT_GREY_LIGHT;

	static const ci::Color TERTIARY_ACTION_PINK;
	static const ci::Color TERTIARY_ACTION_PURPLE;

	static const ci::Color TERTIARY_ACCENT_BLACK;
	static const ci::Color TERTIARY_ACCENT_GREY;

	static const ci::Color WHITE;

	ColorConstants(void);
	~ColorConstants(void);
};

#endif