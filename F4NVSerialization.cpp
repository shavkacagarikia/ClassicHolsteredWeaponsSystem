#include <fstream>

#include "F4NVSerialization.h"
#include "f4se/PluginAPI.h"
#include "f4se\GameObjects.h"
#include "f4se\GameReferences.h"
#include "VisibleHolster.h"
#include <array>
#include <algorithm>>


namespace F4NVSerialization
{


	std::array<VisibleHolster::WeaponPosition, 10> SavedWeaponPosisitionsArr{};
	void RevertCallback(const F4SESerializationInterface * intfc)
	{
		//_DMESSAGE("Clearing CHW serialization data.");
	}

	void LoadCallback(const F4SESerializationInterface * intfc)
	{
		//_DMESSAGE("Loading CHW serialization data.");
		UInt32 type, version, length;
		VisibleHolster::ResetAllWeaponPos((*g_player)->GetActorRootNode(false)->GetAsNiNode());
		while (intfc->GetNextRecordInfo(&type, &version, &length))
		{
			//_DMESSAGE("type %i", type);
			switch (type)
			{
			case 'CHW':
				//_DMESSAGE("Loading CHW type");
				Load(intfc, InternalEventVersion::kCurrentVersion);
				break;
			}
		}

	}

	void LoadSavedPositionsData() {
		std::vector<VisibleHolster::WeaponPosition>* AttachPosVec = VisibleHolster::GetAttachPosVec();
		for (size_t i = 0; i < SavedWeaponPosisitionsArr.size(); i++)
		{
			VisibleHolster::WeaponPosition currPos = SavedWeaponPosisitionsArr[i];
			for (size_t i = 0; i < AttachPosVec->size(); i++)
			{
				VisibleHolster::WeaponPosition* originalPos = &AttachPosVec->at(i);
				if (currPos.type == NULL || currPos.type == HolsterType::NotSet || !originalPos) {
					continue;
				}

				if (currPos.type == originalPos->type) {
					originalPos->posX = currPos.posX;
					originalPos->posY = currPos.posY;
					originalPos->posZ = currPos.posZ;
					originalPos->eulerAttitude = currPos.eulerAttitude;
					originalPos->eulerBank = currPos.eulerBank;
					originalPos->eulerHeading = currPos.eulerHeading;
					originalPos->ResetDataOnNode((*g_player)->GetActorRootNode(false)->GetAsNiNode());
				}
			}
		}
	}

	void UpsertWeaponPosition(HolsterType type, float posX, float posY, float posZ, float eulerAttitude, float eulerBank, float eulerHeading) {
		bool found = false;
		for (size_t i = 0; i < SavedWeaponPosisitionsArr.size(); i++)
		{
			VisibleHolster::WeaponPosition* currPos = (&SavedWeaponPosisitionsArr[i]);
			if (currPos->type == NULL || currPos->type == HolsterType::NotSet) {
				continue;
			}
			if (currPos->type == type) {
				found = true;
				currPos->posX = posX;
				currPos->posY = posY;
				currPos->posZ = posZ;
				currPos->eulerAttitude = eulerAttitude;
				currPos->eulerBank = eulerBank;
				currPos->eulerHeading = eulerHeading;
				currPos->ResetDataOnNode((*g_player)->GetActorRootNode(false)->GetAsNiNode());
				break;
			}
		}
		if (!found) {

			if (type == HolsterType::NotSet) {
				_MESSAGE("Unexpected holster type when saving");
				return;
			}

			VisibleHolster::WeaponPosition newPos = {};
			newPos.type = type;
			newPos.posX = posX;
			newPos.posY = posY;
			newPos.posZ = posZ;
			newPos.eulerAttitude = eulerAttitude;
			newPos.eulerBank = eulerBank;
			newPos.eulerHeading = eulerHeading;
			newPos.ResetDataOnNode((*g_player)->GetActorRootNode(false)->GetAsNiNode());
			int index = type - 1;

			SavedWeaponPosisitionsArr[index] = newPos;
		}
	}
	 
	bool Load(const F4SESerializationInterface * intfc, UInt32 version)
	{

		if (!Serialization::ReadData(intfc, &SavedWeaponPosisitionsArr))
		{
			_MESSAGE("Cant Load SavedWeaponPosisitionsVec");
		}
		else {
			LoadSavedPositionsData();
		}

		return true;
	}

	void SaveCallback(const F4SESerializationInterface * intfc)
	{
		//_DMESSAGE("Save F4NV serialization data.");
		Save(intfc, 'CHW', InternalEventVersion::kCurrentVersion);
	}

	bool Save(const F4SESerializationInterface * intfc, UInt32 type, UInt32 version)
	{
		intfc->OpenRecord(type, version);




		if (!intfc->WriteRecordData(&SavedWeaponPosisitionsArr, sizeof(SavedWeaponPosisitionsArr))) {
			_MESSAGE("Error write GoodAndBadFactionsSaveArray parameter");
		}
		return true;
	}



}