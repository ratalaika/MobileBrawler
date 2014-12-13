
#include "../Types.h"

#pragma once

namespace GameLibrary
{
#define RGBA(r,g,b,a) (((unsigned)a) | (((unsigned)b)<<8) | (((unsigned)g)<<16) | (((unsigned)r)<<24))
#define RGBX(r,g,b) RGBA(r,g,b,255)

	class Color
	{
	public:
		enum : GameLibrary::Uint32
		{
			BLACK = RGBX(0, 0, 0),
			BLUE = RGBX(0, 0, 255),
			CYAN = RGBX(0, 255, 255),
			DARKGRAY = RGBX(64, 64, 64),
			GRAY = RGBX(128, 128, 128),
			GREEN = RGBX(0, 255, 0),
			LIGHTGRAY = RGBX(192, 192, 192),
			MAGENTA = RGBX(255, 0, 255),
			ORANGE = RGBX(255, 200, 0),
			PINK = RGBX(255, 175, 175),
			RED = RGBX(255, 0, 0),
			WHITE = RGBX(255, 255, 255),
			YELLOW = RGBX(255, 255, 0),
			TRANSPARENT = RGBA(0, 0, 0, 0),

			ALICEBLUE = RGBX(240, 248, 255),
			ANTIQUEWHITE = RGBX(250, 235, 215),
			AQUA = RGBX(0, 255, 255),
			AQUAMARINE = RGBX(127, 255, 212),
			BEIGE = RGBX(245, 245, 220),
			BISQUE = RGBX(255, 228, 196),
			BLANCHEDALMOND = RGBX(255, 255, 205),
			BLUEVIOLET = RGBX(138, 43, 226),
			BROWN = RGBX(165, 42, 42),
			BURLYWOOD = RGBX(222, 184, 135),
			CADETBLUE = RGBX(95, 158, 160),
			CHARTREUSE = RGBX(127, 255, 0),
			CHOCOLATE = RGBX(210, 105, 30),
			CORAL = RGBX(255, 127, 80),
			CORNFLOWERBLUE = RGBX(100, 149, 237),
			CORNSILK = RGBX(255, 248, 220),
			CRIMSON = RGBX(220, 20, 60),
			DARKBLUE = RGBX(0, 0, 139),
			DARKCYAN = RGBX(0, 139, 139),
			DARKGOLDENROD = RGBX(184, 134, 11),
			DARKGREEN = RGBX(0, 100, 0),
			DARKKHAKI = RGBX(189, 183, 107),
			DARKMAGENTA = RGBX(139, 0, 139),
			DARKOLIVEGREEN = RGBX(85, 107, 47),
			DARKORANGE = RGBX(255, 140, 0),
			DARKORCHID = RGBX(153, 50, 204),
			DARKRED = RGBX(139, 0, 0),
			DARKSALMON = RGBX(233, 150, 122),
			DARKSEAGREEN = RGBX(143,188,143),
			DARKSLATEBLUE = RGBX(72, 61, 139),
			DARKSLATEGRAY = RGBX(40, 79, 79),
			DARKTURQUOISE = RGBX(0, 206, 209),
			DARKVIOLET = RGBX(148, 0, 211),
			DEEPPINK = RGBX(255, 20, 147),
			DEEPSKYBLUE = RGBX(0, 191, 255),
			DIMGRAY = RGBX(105, 105, 105),
			DODGERBLUE = RGBX(30, 144, 255),
			FIREBRICK = RGBX(178, 34, 34),
			FLORALWHITE = RGBX(255, 250, 240),
			FORESTGREEN = RGBX(34, 139, 34),
			FUSCHIA = RGBX(255, 0, 255),
			GAINSBORO = RGBX(220, 220, 220),
			GHOSTWHITE = RGBX(248, 248, 255),
			GOLD = RGBX(255, 215, 0),
			GOLDENROD = RGBX(218, 165, 32),
			GREENYELLOW = RGBX(173, 255, 47),
			HONEYDEW = RGBX(240, 255, 240),
			HOTPINK = RGBX(255, 105, 180),
			INDIANRED = RGBX(205, 92, 92),
			INDIGO = RGBX(75, 0, 130),
			IVORY = RGBX(255, 240, 240),
			KHAKI = RGBX(240, 230, 140),
			LAVENDER = RGBX(230, 230, 250),
			LAVENDERBLUSH = RGBX(255, 240, 245),
			LAWNGREEN = RGBX(124, 252, 0),
			LEMONCHIFFON = RGBX(255, 250, 205),
			LIGHTBLUE = RGBX(173, 216, 230),
			LIGHTCORAL = RGBX(240, 128, 128),
			LIGHTCYAN = RGBX(224, 255, 255),
			LIGHTGOLDENRODYELLOW = RGBX(250, 250, 210),
			LIGHTGREEN = RGBX(144, 238, 144),
			LIGHTPINK = RGBX(255, 182, 193),
			LIGHTSALMON = RGBX(255, 160, 122),
			LIGHTSEAGREEN = RGBX(32, 178, 170),
			LIGHTSKYBLUE = RGBX(135, 206, 250),
			LIGHTSLATEGRAY = RGBX(119, 136, 153),
			LIGHTSTEELBLUE = RGBX(176, 196, 222),
			LIGHTYELLOW = RGBX(255, 255, 224),
			LIME = RGBX(0, 255, 0),
			LIMEGREEN = RGBX(50, 205, 50),
			LINEN = RGBX(250, 240, 230),
			MAROON = RGBX(128, 0, 0),
			MEDIUMAQUAMARINE = RGBX(102, 205, 170),
			MEDIUMBLUE = RGBX(102, 205, 170),
			MEDIUMORCHID = RGBX(186, 85, 211),
			MEDIUMPURPLE = RGBX(147, 112, 219),
			MEDIUMSEAGREEN = RGBX(60, 179, 113),
			MEDIUMSLATEBLUE = RGBX(123, 104, 238),
			MEDIUMSPRINGGREEN = RGBX(0, 250, 154),
			MEDIUMTURQUOISE = RGBX(72, 209, 204),
			MEDIUMVIOLETRED = RGBX(199, 21, 112),
			MIDNIGHTBLUE = RGBX(25, 25, 112),
			MINTCREAM = RGBX(245, 255, 250),
			MISTYROSE = RGBX(255, 228, 225),
			MOCCASIN = RGBX(255, 228, 181),
			NAVAJOWHITE = RGBX(255, 222, 173),
			NAVY = RGBX(0, 0, 128),
			OLDLACE = RGBX(253, 245, 230),
			OLIVE = RGBX(128, 128, 0),
			OLIVEDRAB = RGBX(107, 142, 45),
			ORANGERED = RGBX(255, 69, 0),
			ORCHID = RGBX(218, 112, 214),
			PALEGOLDENROD = RGBX(238, 232, 170),
			PALEGREEN = RGBX(152, 251, 152),
			PALETURQUOISE = RGBX(175, 238, 238),
			PALEVIOLETRED = RGBX(219, 112, 147),
			PAPAYAWHIP = RGBX(255, 239, 213),
			PEACHPUFF = RGBX(255, 218, 155),
			PERU = RGBX(205, 133, 63),
			PLUM = RGBX(221, 160, 221),
			POWDERBLUE = RGBX(176, 224, 230),
			PURPLE = RGBX(128, 128, 128),
			ROSYBROWN = RGBX(188, 143, 143),
			ROYALBLUE = RGBX(65, 105, 255),
			SADDLEBROWN = RGBX(139, 69, 19),
			SALMON = RGBX(250, 128, 114),
			SANDYBROWN = RGBX(244, 264, 96),
			SEAGREEN = RGBX(46,	139, 87),
			SEASHELL = RGBX(255, 245, 238),
			SIENNA = RGBX(160, 82, 45),
			SILVER = RGBX(192, 192, 192),
			SKYBLUE = RGBX(135, 206, 235),
			SLATEBLUE = RGBX(106, 90, 205),
			SLATEGRAY = RGBX(112, 128, 144),
			SNOW = RGBX(255, 250, 250),
			SPRINGGREEN = RGBX(0, 255, 127),
			STEELBLUE = RGBX(70, 130, 180),
			TAN = RGBX(210, 180, 140),
			TEAL = RGBX(0, 128, 128),
			THISTLE = RGBX(216, 191, 216),
			TOMATO = RGBX(253, 99, 71),
			TURQUOISE = RGBX(64, 224, 208),
			VIOLET = RGBX(238, 130, 238),
			WHEAT = RGBX(245, 222, 179),
			WHITESMOKE = RGBX(245, 245, 245),
			YELLOWGREEN = RGBX(154, 205, 50),
		};
		
		byte a,g,b,r;
		
		Color();
		Color(const Color&);
		Color(const GameLibrary::Uint32&);
		Color(byte r, byte g, byte b, byte a=255);
		~Color();
		
		operator GameLibrary::Uint32() const;
		Color&operator=(const Color&);
		Color&operator=(GameLibrary::Uint32);
		bool operator==(const Color&) const;
		
		GameLibrary::Uint32 getRGBA() const;
		GameLibrary::Uint32 getARGB() const;
		GameLibrary::Uint32 getABGR() const;
		
		bool equals(const Color&) const;

		Color composite(const Color&) const;
	};
}