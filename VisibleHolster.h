#pragma once
#include "f4se/PluginAPI.h"
#include "f4se/GameAPI.h"
#include "f4se/GameData.h"
#include "f4se/GameReferences.h"
#include "f4se/GameForms.h"
#include "f4se/GameMenus.h"
#include "f4se/GameRTTI.h"
#include "f4se_common\SafeWrite.h"
#include <shlobj.h>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Globals.h"
#include "Utils.h"
#include "f4se\NiNodes.h"
#include "f4se\NiObjects.h"
#include "f4se\NiCloningProcess.h"
#include "f4se\NiTypes.h"
#include "f4se\NiExtraData.h"
#include "f4se\BSGeometry.h"
#include "f4se\NiProperties.h"
#include "f4se\BSCollision.h"
#include "f4se\BSSkin.h"
#include "f4se\BSModelDB.h"
#include "Positioner.h"

namespace VisibleHolster {
	enum AffectedDimension {
		X,
		Y,
		Z,
		MinusX,
		MinusY,
		MinusZ
	};

	struct WeaponPosition {
		HolsterType type;
		const char* name;
		double eulerHeading;
		double eulerAttitude;
		double eulerBank;
		double posX;
		double posY;
		double posZ;
		bool isTop;
		const char* potentialParentNode;
		AffectedDimension dimmensionToAffect;

		void SetDataOnNode(NiNode* srcNode) {
			if (srcNode) {
				NiNode* clone = srcNode->Create(0);
				if (clone) {

					clone->m_name = name;
					srcNode->AttachChild(clone, true);
					NiAVObject* attachedBone = srcNode->GetObjectByName(&BSFixedString(name));
					//rr3->RemoveChildAt(0);

					if (attachedBone) {
						float a = 0;
						float b = 0;
						float c = 0;

						attachedBone->m_localTransform.rot.SetEulerAngles(eulerHeading, eulerAttitude, eulerBank);


						attachedBone->m_localTransform.pos.x = posX;
						attachedBone->m_localTransform.pos.y = posY;
						attachedBone->m_localTransform.pos.z = posZ;
					}
				}
			}
		}

		void ModDataOnAffectedDimension(NiNode* srcNode, float val) {
			if (srcNode) {
				NiAVObject* attachedBone = srcNode->GetObjectByName(&BSFixedString(name));
				//rr3->RemoveChildAt(0);

				if (attachedBone) {
						switch (dimmensionToAffect)
						{
						case X:
						{

							attachedBone->m_localTransform.pos.x += val;
						}
						break;
						case MinusZ:
						{

							attachedBone->m_localTransform.pos.z -= val;
							//clone2->m_localTransform.pos.z = 20;

						}
						break;
						default:
							break;
						}

					attachedBone->m_localTransform.pos.x = posX;
					attachedBone->m_localTransform.pos.y = posY;
					attachedBone->m_localTransform.pos.z = posZ;
				}
			}
		}

		void ResetDataOnNode(NiNode* srcNode) {
			if (srcNode) {
				NiAVObject* attachedBone = srcNode->GetObjectByName(&BSFixedString(name));
				//rr3->RemoveChildAt(0);

				if (attachedBone) {
					float a = 0;
					float b = 0;
					float c = 0;

					attachedBone->m_localTransform.rot.SetEulerAngles(eulerHeading, eulerAttitude, eulerBank);


					attachedBone->m_localTransform.pos.x = posX;
					attachedBone->m_localTransform.pos.y = posY;
					attachedBone->m_localTransform.pos.z = posZ;
				}

			}
		}
	};

	void ResetAllWeaponPos(NiNode* src);

	void attachCustomNodeOnRootNode(NiAVObject* rootNode);

	void handleMovingPartsTransformCorrection(NiAVObject* root);

	std::string GetAttachNodeFromWeapon(TESObjectWEAP::InstanceData* instance, TESObjectWEAP* weap);

	void ClearAllHolsters(Actor* actor);

	void HandleWeaponDisplay(bool isWeaponDrawn, NiAVObject* weaponNodeRef = nullptr, Actor* actor = nullptr, TESObjectWEAP* weap = nullptr, TESObjectWEAP::InstanceData* inst = nullptr, bool isManual = false);

	void cloneMovingPartTransforms(NiAVObject* root, const char * modelName);

	void SetModelProcessor();

	void SetArraysAfterFormsLoad();
	void InitMainVec();

	std::vector<WeaponPosition>* GetAttachPosVec();
}