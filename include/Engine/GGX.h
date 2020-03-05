#ifndef _CPPUTIL_ENGINE_MATERIAL_GGX_H_
#define _CPPUTIL_ENGINE_MATERIAL_GGX_H_

#include <Engine/MicrofacetDistribution.h>

namespace CppUtil {
	namespace Engine {
		class GGX : public MicrofacetDistribution {
		public:
			GGX() { SetAlpha(0.5f); }

		public:
			// roughness : 0 - 1
			void SetAlpha(float roughness) {
				roughness = std::max(roughness, (float)1e-3);
				//float x = std::log(roughness);
				//float x2 = x * x;
				//float x3 = x2 * x;
				//float x4 = x2 * x2;
				//alpha = 1.62142f + 0.819955f * x + 0.1734f * x2 +
				//	0.0171201f * x3 + 0.000640711f * x4;
				alpha = roughness * roughness;
			}

		public:
			// ���߷ֲ�����
			virtual float D(const Ubpa::normalf & wh) const override;
			virtual const Ubpa::normalf Sample_wh() const override;

		protected:
			virtual float Lambda(const Ubpa::normalf & w) const override;

		protected:
			float alpha;
		};
	}
}

#endif // !_CPPUTIL_ENGINE_MATERIAL_GGX_H_