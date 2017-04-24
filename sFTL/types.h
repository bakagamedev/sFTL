#pragma once
#include "ardutils\Geometry.h"

using ByteClamped = Ardutils::ClampedValue<uint8_t>;
using ByteRectangle = Ardutils::Rectangle<int8_t,int8_t>;
using BytePoint = Ardutils::Point2<uint8_t>;

//Game state
enum class State : uint8_t
{
	menu,
	game,
	pause,
};

enum class Page : uint8_t
{
	ship,
	peeps,
	target,
	travel,
};

//Environment
enum class BackgroundType : uint8_t
{
	Stars,
	Planet,
};

//Ship bits and pieces
enum class Species : uint8_t
{
	human,
	martian,
};

enum class ShipType : uint8_t
{
	Kestrel,
	Engi,
};

enum class RoomType : uint8_t
{
	empty = 0,
	bridge = 1,
	sickbay = 2, 
	weapons = 3,
	shield = 4,
	engine = 5,
	oxygen = 6,
};

