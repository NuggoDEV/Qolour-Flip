#include "main.hpp"
#include "QolourFlipHooks.hpp"
#include "QolourFlipConfig.hpp"

#include "ModUI/QolourFlipUI.hpp"
using namespace QolourFlip;

#include "UnityEngine/GameObject.hpp"
using namespace UnityEngine;

#include "questui/shared/BeatSaberUI.hpp"
using namespace QuestUI;

DEFINE_TYPE(QolourFlip, QolourFlipUI);

void QolourFlipUI::DidActivate(bool firstActivation, bool addedToHierarchy, bool screenSystemEnabling)
{
    if (firstActivation)
    {
        GameObject *container = BeatSaberUI::CreateScrollView(get_transform());

        BeatSaberUI::CreateToggle(container->get_transform(), "Disable Qolour Flip", getModConfig().ModToggle.GetValue(), [](bool value)
        {
            getModConfig().ModToggle.SetValue(value);
        });
    }
}