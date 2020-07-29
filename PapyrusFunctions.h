#pragma once
#include "f4se\GameForms.h"
#include "f4se/GameTypes.h"
#include "f4se\PapyrusArgs.h"
#include "f4se\PapyrusEvents.h"
#include "f4se\GameObjects.h"
#include "f4se\GameReferences.h"
#include "f4se\GameRTTI.h"
#include "f4se/GameCamera.h"

#include "Globals.h"
#include "Utils.h"

VMValue* FindAllReferencesWithKeyword(TESObjectREFR* target, TESForm* form, float val);

void ShowNotification(std::string asNotificationText);

void ShowMessagebox(std::string asText);

void PlaySubgraphAnimation(Actor* target, BSFixedString asEventName);

void SetAnimationVariableBool(TESObjectREFR* ref, BSFixedString asVariableName, bool newVal);

bool PlayIdle(Actor* actor, TESIdleForm* idle, TESIdleForm* idlePA, bool isBoltAction);

bool HasNode(TESObjectREFR* ref, BSFixedString nodeName);

TESObjectREFR* PlaceAtNode(TESObjectREFR* ref, BSFixedString nodeName, TESForm* formToPlace,
	UInt32 count = 1, bool forcePersist = false, bool initiallyDisabled = false, bool deleteWhenAble = true, bool attach = false);

void SetAngle(TESObjectREFR* ref, float x, float y, float z);

void SplineTranslateToRefNode(TESObjectREFR* target, TESObjectREFR* ref, BSFixedString nodeName, float magnitude, float speed, float rotationSpeed);

void SetMotionType(TESObjectREFR* ref, SInt32 type, bool allowActivate=true);

//bool IsWeaponDrawn(Actor* actor);

void DrawWeapon(Actor* actor);

SInt32 GetCameraStateInt();

void SetScale(TESObjectREFR* ref, float val);
float GetScale(TESObjectREFR* ref);

void SetPosition(TESObjectREFR* ref, float x, float y, float z);