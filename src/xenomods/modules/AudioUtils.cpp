#include "AudioUtils.hpp"
#include "DebugStuff.hpp"

namespace {

	// #define LOAD_WWISE_VO_BASE_GAME_ADDR 0x7100bfc0a4
	// // struct LoadWWiseVOBaseGame : skylaunch::hook::Trampoline<LoadWWiseVOBaseGame> {
  // //   static void Hook(void* wwise, unsigned long dlc1, unsigned long dlc2, unsigned long dlc3, unsigned long langFlags) {
  // //     xenomods::g_Logger->LogDebug("Calling LoadWWiseVOBaseGame");
  // //     Orig(wwise, dlc1, dlc2, dlc3, langFlags);

  // //     xenomods::g_Logger->LogDebug("Force loading DLC4");
  // //     auto LoadWWiseVODLC4 = reinterpret_cast<void(*)(void*, unsigned long)>(0xbfbe04);  
  // //     LoadWWiseVODLC4(wwise, langFlags);
  // //   }
	// // };

	const uintptr_t LoadWWiseBnkAddr = 0x7100061430;
	struct LoadWWiseBnk : skylaunch::hook::Trampoline<LoadWWiseBnk> {
    static void Hook(unsigned long wwise, unsigned long flags, const char* bnkName, unsigned long unk2, unsigned long unk3, unsigned long unk4) {
			xenomods::g_Logger->LogDebug("Loading WWise Bank: {}", bnkName);
			Orig(wwise, flags, bnkName, unk2, unk3, unk4);
			
			if (strcmp(bnkName, "vo_035.bnk") == 0) { // rex hero
        xenomods::g_Logger->LogDebug("Rex Hero detected, loading DLC4 party VO");
				for (int i = 0x24; i <= 0x2B; i++) {
					xenomods::g_Logger->LogDebug("vo_{:03d}.bnk Force Loading VO", i);
					Orig(wwise, flags, fmt::format("vo_{:03d}.bnk", i).c_str(), unk2, unk3, unk4);
				}
        xenomods::g_Logger->LogDebug("DLC4 party loaded");
				return;
	    }

			if (strcmp(bnkName, "vo_043.bnk") == 0) { // na'el alpha
				xenomods::g_Logger->LogDebug("Na'el / Alpha detected, loading base game party + heroes VO");
				for (int i = 0x1; i <= 0x23; i++) {
					if (
						i == 0x0E || // Joran
						i == 0x1C || // Nimue
						i == 0x20 || // Ino (TODO: need to load DLC2 voice pck)
						i == 0x21    // Masha (TODO: need to load DLC3 voice pck)
					) {
						continue;
					}

					xenomods::g_Logger->LogDebug("vo_{:03d}.bnk Force Loading VO", i);
					Orig(wwise, flags, fmt::format("vo_{:03d}.bnk", i).c_str(), unk2, unk3, unk4);
				}
				xenomods::g_Logger->LogDebug("Base game party + heroes loaded");
				return;
			}
		}
	};
}

namespace xenomods {
	void AudioUtils::Initialize() {
		UpdatableModule::Initialize();
		g_Logger->LogDebug("Setting up audio utils...");
    
    // LoadWWiseVOBaseGame::HookFromBase(LOAD_WWISE_VO_BASE_GAME_ADDR);
		LoadWWiseBnk::HookFromBase(LoadWWiseBnkAddr);


		auto modules = g_Menu->FindSection("modules");
		if (modules != nullptr) {
			auto section = modules->RegisterSection(STRINGIFY(AudioUtils), "Audio Utils");

			// auto toggles = section->RegisterSection(toggleKey, "Toggles...");
			// toggles->RegisterOption<bool>(skipUIRendering, "Skip UI rendering");
		}
	}

	XENOMODS_REGISTER_MODULE(AudioUtils);
} // namespace xenomods
