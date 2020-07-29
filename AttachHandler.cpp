#include "AttachHandler.h"
#include  "f4se_common\SafeWrite.h"
#include "f4se_common\Utilities.h"
#include "Globals.h"

//template<class T, UInt32 type, UInt32 slot>
//UInt8 IHandlerFunctor<Actor, BSFixedString>::ProcessAction(Actor * actor, BSFixedString* str)
//{
//	_MESSAGE("aaa");
//	return CALL_MEMBER_FN(static_cast<T*>(this), Process_Origin)(actor, str);
//}


template<class T, UInt32 type, UInt32 slot>
UInt8 IHandlerFunctor<Actor, BSFixedString>::ProcessAction(Actor * actor, BSFixedString* unk04)
{
	//const char* nam = actor->GetFullName();
	//_MESSAGE(nam);
	//_MESSAGE(std::to_string(type).c_str());
	if (actor && actor == (*g_player) && actor->baseForm->formType == kFormType_NPC_) { 
		/*if (!IsHolsterVisibleOnNPCs) {
			if (actor != (*g_player)) {
				return CALL_MEMBER_FN(static_cast<T*>(this), Process_Origin)(actor, unk04);
			}
		}*/
		if (actor->baseForm->formType == kFormType_NPC_) {
			float val = actor->actorValueOwner.GetBase(CheckAvif);
			if (val == 1) {
				return CALL_MEMBER_FN(static_cast<T*>(this), Process_Origin)(actor, unk04);
			}
		}
		NiNode* node = actor->GetActorRootNode(false);
		if (node && node->GetObjectByName(&BSFixedString("WeaponRifleBone"))) {

			if (type == 1) {
				/*_MESSAGE("----------------------------------");
				const char* n = CALL_MEMBER_FN(actor, GetReferenceName)();
				_MESSAGE(n);
				_MESSAGE(std::to_string(actor->formID).c_str());

				_MESSAGE(std::to_string(type).c_str());
				_MESSAGE(std::to_string(actor->actorState.GetWeaponState()).c_str());
				UInt32 state = actor->actorState.GetWeaponState();
				if (state != 1) {

				}*/

				VisibleHolster::ClearAllHolsters(actor);
					VisibleHolster::HandleWeaponDisplay(false, nullptr, actor, nullptr, nullptr, true);
				//bool bDoFaceGen, UInt32 unk2, bool DoQueue, UInt32 flags
				//CALL_MEMBER_FN(actor, QueueUpdate)(false, 1, true, 0);

			}
			else if (type == 2) {
				/*_MESSAGE("----------------------------------");
				const char* n = CALL_MEMBER_FN(actor, GetReferenceName)();
				_MESSAGE(n);
				_MESSAGE(std::to_string(actor->formID).c_str());
				_MESSAGE(std::to_string(type).c_str());
				_MESSAGE(std::to_string(actor->actorState.GetWeaponState()).c_str());*/
				VisibleHolster::ClearAllHolsters(actor);
				//VisibleHolster::HandleWeaponDisplay(true, nullptr, actor);
			}
			/*else if (type == 3) {
				_MESSAGE("reevaluate");
				VisibleHolster::ClearAllHolsters(actor);
				VisibleHolster::HandleWeaponDisplay(false, nullptr, actor);
			}*/
		}


	}
	return CALL_MEMBER_FN(static_cast<T*>(this), Process_Origin)(actor, unk04);
}

RelocAddr <uintptr_t> WeaponSheatheHandler_Vtable(0x02D4BFC8);
RelocAddr <uintptr_t> WeaponDrawHandler_Vtable(0x02D4BFB0);

RelocAddr <uintptr_t> WeaponAttachHandler_Vtable(0x02D4CAD8);

RelocAddr <uintptr_t> PlayerFastEquipSoundHandler_Vtable(0x02D4CBB0);

RelocAddr <uintptr_t> CullWeaponsHandler_Vtable(0x02D4C970);

RelocAddr <uintptr_t> ReevaluateGraphStateHandler_Vtable(0x02D4C910);

RelocAddr <uintptr_t> UncullWeaponsHandler_Vtable(0x02D4C988);

RelocAddr <uintptr_t> ReadyStateChangeHandler_Vtable(0x02D4C898);

RelocAddr <uintptr_t> AttachReferenceHandler_Vtable(0x02D4C9D0);

RelocAddr <uintptr_t> NPCAttachHandler_Vtable(0x02D4C568);

RelocAddr <uintptr_t> CullFurnitureBoneHandle_Vtable(0x02D4C958);

RelocAddr <uintptr_t> UncullBoneHandler_Vtable(0x02D4C928);

RelocAddr <uintptr_t> MountDismountEndHandler_Vtable(0x02D4C550);

RelocAddr <uintptr_t> AnimationObjectLoadHandler_Vtable(0x02D4C628);




//0142D4C568 2  NPCAttachHandler NPCAttachHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4CAF0 2  WeaponDetachHandler WeaponDetachHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4BFC8 2  WeaponSheatheHandler WeaponSheatheHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4BFB0 2  WeaponDrawHandler WeaponDrawHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4CAD8 2  WeaponAttachHandler WeaponAttachHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C970 2  CullWeaponsHandler CullWeaponsHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C988 2  UncullWeaponsHandler UncullWeaponsHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4BF80 2  WeaponBeginDrawHandler WeaponBeginDrawHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C628 2  AnimationObjectLoadHandler AnimationObjectLoadHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C868 2  RelaxedStateChangeHandler RelaxedStateChangeHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C898 2  ReadyStateChangeHandler ReadyStateChangeHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted;
//0142D4C9D0 2  AttachReferenceHandler AttachReferenceHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; NOT FIRE
//0142D4C940 2  CullFurnitureBoneHandler CullFurnitureBoneHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; NOT FIRE
//0142D4C958 2  UncullFurnitureBoneHandler UncullFurnitureBoneHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; NOT FIRE
//0142D4C928 2  UncullBoneHandler UncullBoneHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; FIRES
//0142D4C550 2  MountDismountEndHandler MountDismountEndHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; NOT FIRE
//0142D4C910 2  ReevaluateGraphStateHandler ReevaluateGraphStateHandler: IHandlerFunctor<Actor,BSFixedString>, struct BSIntrusiveRefCounted; FIRES
//0142D4CBB0 2  PlayerFastEquipSoundHandler PlayerFastEquipSoundHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; NOT FIRE
//0142D4C628 2  AnimationObjectLoadHandler AnimationObjectLoadHandler : IHandlerFunctor<Actor, BSFixedString>, struct BSIntrusiveRefCounted; FIRES


void Hooks_Handlers_Commit(void)
{
	// vtbl overwrites
	//SafeWrite64(WeaponAttachHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, BSFixedString>::ProcessAction<WeaponAttachHandler, 2, 1>));
	//_MESSAGE("SAFE WRITE");
	SafeWrite64(WeaponSheatheHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, BSFixedString>::ProcessAction<WeaponSheatheHandler, 1, 2>));
	SafeWrite64(WeaponDrawHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, BSFixedString>::ProcessAction<WeaponDrawHandler, 2, 3>));
	//SafeWrite64(NPCAttachHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, BSFixedString>::ProcessAction<NPCAttachHandler, 3, 4>));

	//SafeWrite64(AnimationObjectLoadHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, BSFixedString>::ProcessAction<AnimationObjectLoadHandler, 3, 4>));
	//SafeWrite64(AttachReferenceHandler_Vtable.GetUIntPtr() + 0x08, GetFnAddr(&IHandlerFunctor<Actor, UInt32>::ProcessAction<ReadyStateChangeHandler, 4, 4>));

}