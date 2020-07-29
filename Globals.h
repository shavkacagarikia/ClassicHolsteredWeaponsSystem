#pragma once
#include "f4se\GameForms.h"
#include "f4se\GameFormComponents.h"
#include "f4se\GameExtraData.h"
#include "f4se\GameObjects.h"
#include "f4se\NiNodes.h"
#include <vector>

enum HolsterType {
	NotSet = 0,
	Rifle,
	Pistol,
	OneHMelee,
	TwoHMelee
};

extern ActorValueInfo* CheckAvif;
extern BGSTerminal* CheckTerminal;

extern bool logEnabled;

extern TESObjectWEAP::InstanceData* GWeaponInstance;
extern TESObjectWEAP* GWeaponForm;

extern const char* ActorSkeletonPath;
extern const char* WeaponsPath;
extern const char* VHWMark;

extern BGSKeyword* WeaponTypeRifle;
extern BGSKeyword* WeaponTypeBigGun;
extern BGSKeyword* WeaponTypePistol;
extern BGSKeyword* WeaponType1HMelee;
extern BGSKeyword* WeaponType2HMelee;

extern std::string mAbbrv;

extern bool IsWeaponDrawn;
extern bool IsWeaponHolstered;

extern BGSKeyword* ActorTypeNPC;
extern std::vector<const char*> ExcludedFolderPaths;


//ini options
extern bool IsHolsterVisibleOnNPCs;

extern bool IsRiflesDisplayed;
extern bool IsPistolsDisplayed;
extern bool Is1HMeleeDisplayed;
extern bool Is2HMeleeDisplayed;
extern bool IsBigGunsDisplayed;

extern bool IsPositioningToolEnabled;
extern bool IsHolsterPositionSaveLogginEnabled;

extern std::vector<UInt32> ExcludedForms;

extern bool IsGameDataReady;

