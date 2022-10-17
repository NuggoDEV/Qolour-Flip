#include "main.hpp"
#include "QolourFlipHooks.hpp"
#include "QolourFlipConfig.hpp"

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

#include "chroma/shared/NoteAPI.hpp"
using namespace Chroma;


#include "GlobalNamespace/PlayerDataModel.hpp"
#include "GlobalNamespace/PlayerData.hpp"
#include "GlobalNamespace/ColorScheme.hpp"
#include "GlobalNamespace/ColorSchemesSettings.hpp"

#include "GlobalNamespace/BeatEffectSpawner.hpp"
#include "GlobalNamespace/AudioTimeSyncController.hpp"
using namespace GlobalNamespace;

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

Color leftBloq;
Color rightBloq;

int timeA;
int timeB;
int timeC;
int timeD;
int timeE;
int timeF;
int timeG;
int timeH;
int timeI;
int timeJ;
int timeK;
int timeL;

int timeTest;
int songTimes;

MAKE_AUTO_HOOK_MATCH(BeatEffectSpawner_Start, &BeatEffectSpawner::Start, void, BeatEffectSpawner *self)
{
    BeatEffectSpawner_Start(self);

    if (!getModConfig().ModToggle.GetValue())
    {
        auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
        auto playerData = playerDataModel->playerData;
        auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

        leftBloq = colourScheme->get_saberAColor();
        rightBloq = colourScheme->get_saberBColor();


        auto audioTimeSyncController = Object::FindObjectOfType<AudioTimeSyncController *>();
        int songTime = audioTimeSyncController->songTime;

        timeA = rand() % 1 + 20;
        timeB = rand() % timeA + 20;
        timeC = rand() % timeB + 20;
        timeD = rand() % timeC + 20;
        timeE = rand() % timeD + 20;
        timeF = rand() % timeE + 20;
        timeG = rand() % timeF + 20;
        timeH = rand() % timeG + 20;
        timeI = rand() % timeH + 20;
        timeJ = rand() % timeI + 20;
        timeK = rand() % timeJ + 20;

        timeTest = songTimes + (rand() % 1 + 20);
    } else {  }
}

MAKE_AUTO_HOOK_MATCH(AudioTimeSyncController_Update, &AudioTimeSyncController::Update, void, AudioTimeSyncController *self)
{
    AudioTimeSyncController_Update(self);

    if (!getModConfig().ModToggle.GetValue())
    {
        auto playerDataModel = Object::FindObjectOfType<PlayerDataModel *>();
        auto playerData = playerDataModel->playerData;
        auto colourScheme = playerData->colorSchemesSettings->GetColorSchemeForId(playerData->colorSchemesSettings->selectedColorSchemeId);

        auto audioTimeSyncController = Object::FindObjectOfType<AudioTimeSyncController *>();
        int songTime = audioTimeSyncController->songTime;

        if (timeTest == songTime)
        {
            
        }

        //if (songTime == timeA) {
        //    NoteAPI::setGlobalNoteColorSafe(rightBloq, leftBloq);
        //} else if (songTime == timeB) {
        //    NoteAPI::setGlobalNoteColorSafe(leftBloq, rightBloq);
        //} else if (songTime == timeC) {
        //    NoteAPI::setGlobalNoteColorSafe(rightBloq, leftBloq);
        //} else if (songTime == timeD) {
        //    NoteAPI::setGlobalNoteColorSafe(leftBloq, rightBloq);
        //} else if (songTime == timeE) {
        //    NoteAPI::setGlobalNoteColorSafe(rightBloq, leftBloq);
        //} else if (songTime == timeF) {
        //    NoteAPI::setGlobalNoteColorSafe(leftBloq, rightBloq);
        //} else if (songTime == timeG) {
        //    NoteAPI::setGlobalNoteColorSafe(rightBloq, leftBloq);
        //} else {  }

    } else {  }
}

