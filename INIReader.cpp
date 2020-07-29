#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>  
#include <vector>  
#include <iterator>
#include "f4se\GameData.h"
#include "Utils.h"

typedef std::pair<std::string, std::string> entry;


namespace std {
	std::istream &operator >> (std::istream &is, entry &d) {
		std::getline(is, d.first, '=');
		std::getline(is, d.second);
		return is;
	}
}

inline bool exists_file(const std::string& name) {
	struct stat buffer;
	return (stat(name.c_str(), &buffer) == 0);
}

bool IsHolsterVisibleOnNPCs = true;

bool IsRiflesDisplayed = true;
bool IsPistolsDisplayed = true;
bool Is1HMeleeDisplayed = true;
bool Is2HMeleeDisplayed = true;

bool IsBigGunsDisplayed = false;
bool IsPositioningToolEnabled = true;
bool IsHolsterPositionSaveLogginEnabled = false;

std::vector<UInt32> ExcludedForms = {};

int formsCounter = 0;

void Getinis(std::vector<WIN32_FIND_DATA>* arr) {
	char* modSettingsDirectory = "Data\\F4SE\\Plugins\\ClassicHolsteredWeaponsConfig.ini";

	HANDLE hFind;
	WIN32_FIND_DATA data;
	hFind = FindFirstFile(modSettingsDirectory, &data);
	if (hFind != INVALID_HANDLE_VALUE) {
		do {
			arr->push_back(data);
		} while (FindNextFile(hFind, &data));
		FindClose(hFind);
	}
}

void HandleIniFiles() {

	if (!exists_file("Data\\F4SE\\Plugins\\ClassicHolsteredWeaponsConfig.ini")) {
		_MESSAGE("ini doesnt exist");
		return;
	}
	std::vector<WIN32_FIND_DATA> modSettingFiles;
	Getinis(&modSettingFiles);
	for (size_t i = 0; i < modSettingFiles.size(); i++)
	{
		std::string fileName = modSettingFiles[i].cFileName;
		std::string fileNameNoSuffix = fileName.substr(0, fileName.size() - 4);

		std::string ff = "Data\\F4SE\\Plugins\\" + fileName;

		std::ifstream in(ff);

		std::map<std::string, std::string> dict((std::istream_iterator<entry>(in)),
			std::istream_iterator<entry>());


		for (entry const &e : dict) {
			if (e.first.find("IsHolsterVisibleOnNPCs") != std::string::npos) {

				IsHolsterVisibleOnNPCs = (bool)std::stoi(e.second);
				//_MESSAGE("IsHolsterVisibleOnNPCs");
			}

			else if (e.first.find("IsRiflesDisplayed") != std::string::npos) {

				IsRiflesDisplayed = (bool)std::stoi(e.second);
				//_MESSAGE("IsRiflesDisplayed");
			}
			else if (e.first.find("IsPistolsDisplayed") != std::string::npos) {

				IsPistolsDisplayed = (bool)std::stoi(e.second);
				//_MESSAGE("IsPistolsDisplayed");
			}
			else if (e.first.find("Is1HMeleeDisplayed") != std::string::npos) {

				Is1HMeleeDisplayed = (bool)std::stoi(e.second);
				//_MESSAGE("Is1HMeleeDisplayed");
			}
			else if (e.first.find("Is2HMeleeDisplayed") != std::string::npos) {

				Is2HMeleeDisplayed = (bool)std::stoi(e.second);
				//_MESSAGE("Is2HMeleeDisplayed");
			}
			else if (e.first.find("IsBigGunsDisplayed") != std::string::npos) {

				IsBigGunsDisplayed = (bool)std::stoi(e.second);
				//_MESSAGE("IsBigGunsDisplayed");
			}

			else if (e.first.find("IsPositioningToolEnabled") != std::string::npos) {

				IsPositioningToolEnabled = (bool)std::stoi(e.second);
				//_MESSAGE("IsPositioningToolEnabled");
			}
			else if (e.first.find("IsHolsterPositionSaveLogginEnabled") != std::string::npos) {

				IsHolsterPositionSaveLogginEnabled = (bool)std::stoi(e.second);
				//_MESSAGE("IsHolsterPositionSaveLogginEnabled");
			}
			else if (e.first.find(";Excluded") == std::string::npos) {

				if (e.first.find("ExcludedWeaponFormId") != std::string::npos) {
					std::string frmidstr = e.second;
					TESForm* f = GetFormFromIdentifier(frmidstr);
					if (f) {
						TESObjectWEAP* w = (TESObjectWEAP*)f;
						if (w) {
							_MESSAGE("Excluded weapon form:");
							if (IsValidBSString(w->fullName.name)) {

								_MESSAGE(w->fullName.name.c_str());
							}
							else {
								_MESSAGE("Weapon with wrong name");
							}
							w->weapData.damageResist = CheckAvif;
							//ExcludedForms.push_back(w->formID);
							//formsCounter++;
						}
					}
				}
				if (e.first.find("ExcludedNPCFormId") != std::string::npos) {
					std::string frmidstr = e.second;
					TESForm* f = GetFormFromIdentifier(frmidstr);
					if (f) {
						TESNPC* n = (TESNPC*)f;
						if (n) {
							//n->nativeTerminalForm.terminal = reinterpret_cast<BGSTerminal*>(GetFormFromIdentifier("Fallout4.esm|710D7"));
							n->actorValueOwner.SetBase(reinterpret_cast<ActorValueInfo*>(GetFormFromIdentifier("Fallout4.esm|300")), 1);

							//n->actorValueOwner.ModBase(CheckAvif, 999);
							float cc = n->actorValueOwner.GetBase(CheckAvif);
							_MESSAGE("Excluded npc form:");
							if (IsValidBSString(n->fullName.name)) {

								_MESSAGE(n->fullName.name.c_str());
							}
							else {
								_MESSAGE("npc with wrong name");
							}
							;
						}
					}
				}
			}
		}

	}
}