#pragma once

#include "UpdatableModule.hpp"
#include "xenomods/engine/ml/Scene.hpp"

namespace xenomods {

	struct RenderingControls : public xenomods::UpdatableModule {
		static bool straightenFont;
		static bool skipUIRendering;
		static bool skipParticleRendering;
		static bool skipCloudRendering;
		static bool skipSkyDomeRendering;
		static float shadowStrength;

		struct ForcedRenderParameters {
			bool DisableDOF;
			bool DisableMotionBlur;
			bool DisableColorFilter;

			bool Any() {
				return DisableDOF || DisableMotionBlur || DisableColorFilter;
			}
		};
		static ForcedRenderParameters ForcedParameters;

		void Initialize() override;
		void Update(fw::UpdateInfo* updateInfo) override;
		bool NeedsUpdate() const override {
			return true;
		}
	};

} // namespace xenomods
