#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"
#include "Enums.h"
#include "HostConfig.h"

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{

    class AdaptiveFontSizesConfig :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveFontSizesConfig>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveFontSizesConfig, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize() noexcept;
        HRESULT RuntimeClassInitialize(FontSizesConfig fontSizesConfig) noexcept;

        IFACEMETHODIMP get_Small(_Out_ UINT32* value);
        IFACEMETHODIMP put_Small(_In_ UINT32 value);

        IFACEMETHODIMP get_Default(_Out_ UINT32* value);
        IFACEMETHODIMP put_Default(_In_ UINT32 value);

        IFACEMETHODIMP get_Medium(_Out_ UINT32* value);
        IFACEMETHODIMP put_Medium(_In_ UINT32 value);

        IFACEMETHODIMP get_Large(_Out_ UINT32* value);
        IFACEMETHODIMP put_Large(_In_ UINT32 value);

        IFACEMETHODIMP get_ExtraLarge(_Out_ UINT32* value);
        IFACEMETHODIMP put_ExtraLarge(_In_ UINT32 value);

    private:
        UINT32 m_default;
        UINT32 m_small;
        UINT32 m_medium;
        UINT32 m_large;
        UINT32 m_extraLarge;

    };

    ActivatableClass(AdaptiveFontSizesConfig);
}}}