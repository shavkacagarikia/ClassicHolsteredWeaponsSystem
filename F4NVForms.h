
#pragma once
#include "f4se\GameForms.h"
#include "Globals.h"

bool GetForms() {
	bool toReturn = true;

	//WardDefelection obsolete avif is use for some checkings
	CheckAvif = reinterpret_cast<ActorValueInfo*>(GetFormFromIdentifier("Fallout4.esm|300"));
	WeaponTypeRifle = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|4A0A1"));
	WeaponTypeBigGun = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|4A0A3"));
	WeaponTypePistol = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|4A0A0"));
	WeaponType1HMelee = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|4A0A4"));
	WeaponType2HMelee = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|4A0A5"));

	ActorTypeNPC = reinterpret_cast<BGSKeyword*>(GetFormFromIdentifier("Fallout4.esm|13794"));

	CheckTerminal = reinterpret_cast<BGSTerminal*>(GetFormFromIdentifier("Fallout4.esm|710D7"));

	return toReturn;
}