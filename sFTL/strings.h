#pragma once

//Menu stuff
const PROGMEM char pageShip[] = "Ship";
const PROGMEM char pagePeeps[]= "Crew";
const PROGMEM char pageTarget[]= "Target";
const PROGMEM char pageDunno[]= "???";
const PROGMEM char pageWarp[] = "Travel";

const char* const pageNames[] PROGMEM = {
	pageShip,pagePeeps,pageTarget,pageDunno,pageWarp
};

//Ship bits
const PROGMEM char nameEmpty[] = "";
const PROGMEM char nameBridge[] = "Bridge";
const PROGMEM char nameSickbay[]= "Sickbay";
const PROGMEM char nameWeapons[]= "Weapons";
const PROGMEM char nameShield[] = "Shield";
const PROGMEM char nameEngine[] = "Engine";

const char* const nameShipParts[] PROGMEM = {	//Make sure to line this up with enum RoomType in types.h
	nameEmpty,nameBridge,nameSickbay,nameWeapons,nameShield,nameEngine
};

///Crew names
const PROGMEM char name1[] = "Dave";
const PROGMEM char name2[] = "Geoff";
const PROGMEM char name3[] = "Noah";
const PROGMEM char name4[] = "Butts";
const PROGMEM char name5[] = "Fred";
const PROGMEM char name6[] = "Gary";

const char* const nameCrew[] PROGMEM = {
	name1,name2,name3,name4,name5,name6
};