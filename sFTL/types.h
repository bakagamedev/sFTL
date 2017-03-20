#pragma once

enum class State : uint8_t
{
	menu,
	game,
	pause,
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
	bridge,
	sickbay,
	weapons,
	shields,
	engine,
};