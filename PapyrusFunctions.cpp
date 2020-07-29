#include "PapyrusFunctions.h"

#include <functional>
#include <chrono>
#include <future>
#include <cstdio>



class later
{
public:
	template <class callable, class... arguments>
	later(int after, bool async, callable&& f, arguments&&... args)
	{
		std::function<typename std::result_of<callable(arguments...)>::type()> task(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

		if (async)
		{
			std::thread([after, task]() {
				std::this_thread::sleep_for(std::chrono::milliseconds(after));
				task();
			}).detach();
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(after));
			task();
		}
	}

};

typedef void(*_SetAnimationVariableBool)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, BSFixedString asVariableName, bool newVal);
RelocAddr <_SetAnimationVariableBool > SetAnimationVariableBoolInternal(0x140EA10);

typedef bool(*_PlayIdle)(VirtualMachine* vm, UInt32 stackId, Actor* actor, TESIdleForm* idle);
RelocAddr <_PlayIdle > PlayIdleInternal(0x13863A0);

typedef bool(*_PlayIdle2)(Actor* actor, TESIdleForm* idle, UInt64 unk, VirtualMachine* vm, UInt32 stackId);
RelocAddr <_PlayIdle2 > PlayIdleInternal2(0x13864C0);

typedef bool(*_PlayIdleAction)(Actor* actor, void* action, TESObjectREFR target, VirtualMachine* vm, UInt32 stackId);
RelocAddr <_PlayIdleAction > PlayIdleAction(0x13864A0);

typedef bool(*_HasNode)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, BSFixedString* nodeName);
RelocAddr <_HasNode> HasNodeInternal(0x14088C0);

typedef TESObjectREFR*(*_PlaceAtNode)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, BSFixedString* nodeName, TESForm* formToPlace,
	UInt32 count, bool forcePersist, bool initiallyDisabled, bool deleteWhenAble, bool attach);
RelocAddr <_PlaceAtNode> PlaceAtNodeInternal(0x140B720);

typedef void(*_SetAngle)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, float x, float y, float z);
RelocAddr <_SetAngle> SetAngleInternal(0x140E8E0);

typedef void(*_SetScale)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, float val);
RelocAddr <_SetScale> SetScaleInternal(0x140EF10);

typedef float(*_GetScale)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref);
RelocAddr <_GetScale> GetScaleInternal(0x1416300);


typedef void(*_SetMotionType)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* ref, SInt32 type, bool allowActivate);
RelocAddr <_SetMotionType> SetMotionTypeInternal(0x140F510);

typedef void(*_SplineTranslateToRefNode)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* target, TESObjectREFR* ref, BSFixedString* nodeName, float magnitude, float speed, float rotationSpeed);
RelocAddr <_SplineTranslateToRefNode> SplineTranslateToRefNodeInternal(0x14101D0);

typedef bool(*_IsWeaponDrawn)(VirtualMachine* vm, UInt32 stackId, Actor* actor);
RelocAddr <_IsWeaponDrawn> IsWeaponDrawnInternal(0x1391380);

typedef void(*_DrawWeapon)(VirtualMachine* vm, UInt32 stackId, Actor* actor);
RelocAddr <_DrawWeapon> DrawWeaponInternal(0x138C700);

typedef VMValue*(*_FindAllReferencesWithKeyword)(VirtualMachine* vm, UInt32 stackId, TESObjectREFR* target, TESForm* form, float val );
RelocAddr <_FindAllReferencesWithKeyword> FindAllReferencesWithKeywordInternal(0x1405B00);

VMValue* FindAllReferencesWithKeyword(TESObjectREFR* target, TESForm* form, float val) {
	return FindAllReferencesWithKeywordInternal((*g_gameVM)->m_virtualMachine, 0, target,form,val);
}

//bool IsWeaponDrawn(Actor* actor) {
//	return IsWeaponDrawnInternal((*g_gameVM)->m_virtualMachine, 0, actor);
//}

void DrawWeapon(Actor* actor) {
	return DrawWeaponInternal((*g_gameVM)->m_virtualMachine, 0, actor);
}

bool HasNode(TESObjectREFR* ref, BSFixedString nodeName) {
	return HasNodeInternal((*g_gameVM)->m_virtualMachine, 0, ref, &nodeName);
}

TESObjectREFR* PlaceAtNode(TESObjectREFR* ref, BSFixedString nodeName, TESForm* formToPlace,
	UInt32 count, bool forcePersist, bool initiallyDisabled, bool deleteWhenAble, bool attach) {

	return PlaceAtNodeInternal((*g_gameVM)->m_virtualMachine, 0, ref, &nodeName, formToPlace, count,
		forcePersist, initiallyDisabled, deleteWhenAble, attach);

}

void SetMotionType(TESObjectREFR* ref, SInt32 type, bool allowActivate) {
	//SetMotionTypeInternal((*g_gameVM)->m_virtualMachine, 0, ref, type, allowActivate);
	VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&type);
	varr.Push(&b1);
	VMVariable b2;
	b2.Set(&allowActivate);
	varr.Push(&b2);
	CallFunctionNoWait(ref, "SetMotionType", varr);
}

void SetAngle(TESObjectREFR* ref, float x, float y, float z) {
	//SetAngleInternal((*g_gameVM)->m_virtualMachine, 0, ref, x, y, z);

	VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&x);
	varr.Push(&b1);
	VMVariable b2;
	b2.Set(&y);
	varr.Push(&b2);
	VMVariable b3;
	b3.Set(&y);
	varr.Push(&b3);
	CallFunctionNoWait(ref, "SetAngle", varr);
}

void SetScale(TESObjectREFR* ref, float val) {
	SetScaleInternal((*g_gameVM)->m_virtualMachine, 0, ref, val);

	/*VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&val);
	varr.Push(&b1);
	CallFunctionNoWait(ref, "SetScale", varr);*/
}



float GetScale(TESObjectREFR* ref) {
	return GetScaleInternal((*g_gameVM)->m_virtualMachine, 0, ref);

	/*VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&val);
	varr.Push(&b1);
	CallFunctionNoWait(ref, "SetScale", varr);*/
}

void SetPosition(TESObjectREFR* ref, float x, float y, float z) {
	x = 1;
	y = 1;
	z = 1;
	VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&x);
	varr.Push(&b1);
	VMVariable b2;
	b2.Set(&y);
	varr.Push(&b2);
	VMVariable b3;
	b3.Set(&y);
	varr.Push(&b3);
	VMVariable b4;
	float ii = 1;
	b4.Set(&ii);
	varr.Push(&b4);
	CallFunctionNoWait(ref, "ApplyHavokImpulse", varr);
}

void SplineTranslateToRefNode(TESObjectREFR* target, TESObjectREFR* ref, BSFixedString nodeName, float magnitude, float speed, float rotationSpeed) {
	SplineTranslateToRefNodeInternal((*g_gameVM)->m_virtualMachine, 0, target,ref, &nodeName, magnitude, speed, rotationSpeed);
}


void SetAnimationVariableBool(TESObjectREFR* ref, BSFixedString asVariableName, bool newVal) {
	SetAnimationVariableBoolInternal((*g_gameVM)->m_virtualMachine, 1, ref, asVariableName, newVal);
}


bool playAnimEvent(Actor* actor, TESIdleForm* idlePA, BSFixedString name) {
	BSFixedString tempname("");

	tempname = idlePA->idleName;
	idlePA->idleName = name;
	bool gonnaplay = false;
	gonnaplay = PlayIdleInternal2(actor, idlePA, 0, (*g_gameVM)->m_virtualMachine, 0);

	idlePA->idleName = tempname;

	return gonnaplay;
}

bool playAnimEvent2(Actor* actor, TESIdleForm* idlePA, BSFixedString name) {
	BSFixedString tempname("");
	//idlePA->animationFilePath = BSFixedString("Actors\\DLC03\\Character\\_1stPerson\\Animations\\LeverAction\\WPNBoltChargeReady.hkx");
	tempname = idlePA->idleName;
	idlePA->idleName = name;
	bool gonnaplay = false;
	gonnaplay = PlayIdleInternal2(actor, idlePA, 0, (*g_gameVM)->m_virtualMachine, 0);

	idlePA->idleName = tempname;
	//idlePA->animationFilePath = BSFixedString("");
	return gonnaplay;
}



//Play reload end idles when needed
bool PlayIdle(Actor* actor, TESIdleForm* idle, TESIdleForm* idlePA, bool isBoltAction) {
	static BSFixedString reloadEndAnimEvent("reloadEnd");
	static BSFixedString reloadEndAnimEvent2("reloadEndSlave");
	//static BSFixedString reloadEndAnimEvent3("rifleSightedEnd");
	bool resp = false;
	if (idlePA) {
		resp = playAnimEvent(actor, idlePA, reloadEndAnimEvent);

		playAnimEvent(actor, idlePA, reloadEndAnimEvent2);


		/*if (isBoltAction) {
		bool t = false;
		t = playAnimEvent2(actor, idlePA, reloadEndAnimEvent3);
		}*/


	}
	logIfNeeded("is animation stopped:");
	logIfNeeded(std::to_string(resp).c_str());
	return resp;
	/*VMArray<VMVariable> varr;
	VMVariable b1;
	b1.Set(&idle);
	varr.Push(&b1);
	CallFunctionNoWait(actor, "PlayIdle", varr);
	return true;*/
}



void ShowNotification(std::string asNotificationText) {
	CallGlobalFunctionNoWait1<BSFixedString>("Debug", "Notification", BSFixedString(asNotificationText.c_str()));
}

void ShowMessagebox(std::string asText) {
	CallGlobalFunctionNoWait1<BSFixedString>("Debug", "Messagebox", BSFixedString(asText.c_str()));
}


//------------------------------------------------------------------------------------------------------------------------
//Non papyrus



// returns the current camera state
// -1 - unknown / there is no camera yet
// 0 - first person
// 1 - auto vanity
// 2 - VATS
// 3 - free
// 4 - iron sights
// 5 - transition
// 6 - tween menu
// 7 - third person 1
// 8 - third person 2
// 9 - furniture
// 10 - horse
// 11 - bleedout
// 12 - dialogue
SInt32 GetCameraStateInt()
{
	PlayerCamera * playerCamera = *g_playerCamera;
	if (playerCamera)
		return playerCamera->GetCameraStateId(playerCamera->cameraState);

	return -1;
}