#pragma once

#include "UpdatableModule.hpp"

namespace xenomods {

	struct AudioUtils : public xenomods::UpdatableModule {
		void Initialize() override;
		bool NeedsUpdate() const override {
			return false;
		}
	};

} // namespace xenomods
