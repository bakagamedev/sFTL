#pragma once

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

enum class Species : uint8_t
{
	human,
	martian,
};

enum class ShipType : uint8_t
{
	kestrel,
	ship1,
	ship2,
};

enum class RoomType : uint8_t
{
	empty = 0,
	bridge = 1,
	sickbay = 2, 
	weapons = 3,
	shield = 4,
	engine = 5,
};

