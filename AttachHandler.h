#pragma once
#include "f4se\GameReferences.h"
#include "f4se\GameTypes.h"
#include "VisibleHolster.h"
#include "Globals.h"


//template <typename FormT, typename DataT>
//class IHandlerFunctor
//{
//public:
//	virtual ~IHandlerFunctor();
//	virtual	UInt8	Process(FormT * form, DataT str); // pure
//
//	BSIntrusiveRefCounted refCount;
//};
//
//template<>
//class IHandlerFunctor<Actor, BSFixedString>
//{
//public:
//	virtual ~IHandlerFunctor();
//	virtual	UInt8	Process(Actor * form, BSFixedString* str); // pure
//
//	template<class T, UInt32 type, UInt32 slot>
//	UInt8	ProcessAction(Actor * form, BSFixedString* str);
//};
//
//
//class WeaponAttachHandler : public IHandlerFunctor<Actor, BSFixedString>
//{
//public:
//	virtual ~WeaponAttachHandler();
//	virtual	UInt8	Process(Actor * form, BSFixedString* str);
//
//	MEMBER_FN_PREFIX(WeaponAttachHandler);
//	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6AD7A, Actor * form, BSFixedString* str);
//};

template <typename FormT, typename DataT>
class IHandlerFunctor
{
public:
	virtual ~IHandlerFunctor();
	virtual	UInt8	Process(FormT * form, DataT unk04); // pure

	BSIntrusiveRefCounted refCount;
};

template<>
class IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~IHandlerFunctor();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04); // pure

	template<class T, UInt32 type, UInt32 slot>
	UInt8	ProcessAction(Actor * form, BSFixedString* unk04);
};

// All member functions below are merely the original vtbl function address
class WeaponSheatheHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~WeaponSheatheHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(WeaponSheatheHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6B880, Actor * form, BSFixedString* unk04);
};

class WeaponDrawHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~WeaponDrawHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(WeaponDrawHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6B860, Actor * form, BSFixedString *unk04);
};

class WeaponAttachHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~WeaponAttachHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(WeaponAttachHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6F870, Actor * form, UInt32 unk04);
};

class PlayerFastEquipSoundHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~PlayerFastEquipSoundHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(PlayerFastEquipSoundHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6FE60, Actor * form, UInt32 unk04);
};

class CullWeaponsHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~CullWeaponsHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(CullWeaponsHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6ED70, Actor * form, BSFixedString* unk04);
};

class ReevaluateGraphStateHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~ReevaluateGraphStateHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(ReevaluateGraphStateHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EAF0, Actor * form, BSFixedString* unk04);
};

class UncullWeaponsHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~UncullWeaponsHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(UncullWeaponsHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EDB0, Actor * form, UInt32 unk04);
};

class RelaxedStateChangeHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~RelaxedStateChangeHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(RelaxedStateChangeHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6E890, Actor * form, UInt32 unk04);
};



class ReadyStateChangeHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~ReadyStateChangeHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(ReadyStateChangeHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6E950, Actor * form, UInt32 unk04);
};

class AttachReferenceHandler : public IHandlerFunctor<Actor, UInt32>
{
public:
	virtual ~AttachReferenceHandler();
	virtual	UInt8	Process(Actor * form, UInt32 unk04);

	MEMBER_FN_PREFIX(AttachReferenceHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EF40, Actor * form, UInt32 unk04);
};

class NPCAttachHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~NPCAttachHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(NPCAttachHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EF40, Actor * form, BSFixedString* unk04);
};

class CullFurnitureBoneHandle : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~CullFurnitureBoneHandle();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(CullFurnitureBoneHandle);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EF40, Actor * form, BSFixedString* unk04);
};

class UncullBoneHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~UncullBoneHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(UncullBoneHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6EBD0, Actor * form, BSFixedString* unk04);
};

class AnimationObjectLoadHandler : public IHandlerFunctor<Actor, BSFixedString>
{
public:
	virtual ~AnimationObjectLoadHandler();
	virtual	UInt8	Process(Actor * form, BSFixedString* unk04);

	MEMBER_FN_PREFIX(AnimationObjectLoadHandler);
	DEFINE_MEMBER_FN(Process_Origin, UInt8, 0x00F6DF60, Actor * form, BSFixedString* unk04);
};

void Hooks_Handlers_Commit(void);