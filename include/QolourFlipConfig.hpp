#pragma once

#include "config-utils/shared/config-utils.hpp"

#include "UnityEngine/Color.hpp"
using namespace UnityEngine;

DECLARE_CONFIG(ModConfig, 
    CONFIG_VALUE(ModToggle, bool, "Disable Qolour Flip", false);
    
    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(ModToggle);
    )
)