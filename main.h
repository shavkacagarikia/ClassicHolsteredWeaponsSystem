#pragma once

TESForm * GetFormFromIdentifier(const std::string & identifier);

void logIfNeeded(std::string text);

void logMessage(std::string aString);

void RegisterForObjectLoaded();

bool RemoveObjectLoadedSink();