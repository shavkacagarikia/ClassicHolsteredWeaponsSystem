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


namespace Positioner {
	void SetSkeletonNode(NiNode* seletonNode);
	NiNode* GetSkeletonNode();

	void SetPositioningEnabled(bool enable);
	bool GetPositioningEnabled();

	void SetActiveAttachBone(const char* boneName);

	std::string GetActiveBoneName();

	//0-x 1-y 2-z
	void SetActiveDimension(UInt32 keycode);

	//0-move 1-rotate 2-scale
	void SetOperationType(UInt32 keycode);

	void DoOperation(bool add);

	void ResetAllChanges();

	void ShowCurrentState();

	void LogCurrentPositions();

	void SaveCurrentPositions();
}