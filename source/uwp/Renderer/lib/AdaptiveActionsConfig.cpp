#include "pch.h"
#include "AdaptiveActionsConfig.h"
#include "AdaptiveShowCardActionConfig.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::Rendering::Uwp;
using namespace ABI::Windows::UI;

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{

    HRESULT AdaptiveActionsConfig::RuntimeClassInitialize() noexcept try
    {
        ActionsConfig actionsConfig;
        return RuntimeClassInitialize(actionsConfig);
    } CATCH_RETURN;

    HRESULT AdaptiveActionsConfig::RuntimeClassInitialize(AdaptiveCards::ActionsConfig actionsConfig) noexcept
    {
        m_actionAlignment = static_cast<ABI::AdaptiveCards::Rendering::Uwp::ActionAlignment>(actionsConfig.actionAlignment);
        m_actionsOrientation = static_cast<ABI::AdaptiveCards::Rendering::Uwp::ActionsOrientation> (actionsConfig.actionsOrientation);
        m_buttonSpacing = actionsConfig.buttonSpacing;
        m_maxActions = actionsConfig.maxActions;
        m_spacing = static_cast<ABI::AdaptiveCards::Rendering::Uwp::Spacing>(actionsConfig.spacing);

        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveShowCardActionConfig>(m_showCardActionConfig.GetAddressOf(), actionsConfig.showCard));

        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_ShowCard(IAdaptiveShowCardActionConfig** showCardActionConfig)
    {
        return m_showCardActionConfig.CopyTo(showCardActionConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_ShowCard(IAdaptiveShowCardActionConfig* showCardActionConfig)
    {
        m_showCardActionConfig = showCardActionConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_ButtonSpacing(UINT32* value)
    {
        *value = m_buttonSpacing;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_ButtonSpacing(UINT32 value)
    {
        m_buttonSpacing = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_MaxActions(UINT32* value)
    {
        *value = m_maxActions;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_MaxActions(UINT32 value)
    {
        m_maxActions = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_Spacing(ABI::AdaptiveCards::Rendering::Uwp::Spacing* value)
    {
        *value = m_spacing;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_Spacing(ABI::AdaptiveCards::Rendering::Uwp::Spacing value)
    {
        m_spacing = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_ActionAlignment(ABI::AdaptiveCards::Rendering::Uwp::ActionAlignment* value)
    {
        *value = m_actionAlignment;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_ActionAlignment(ABI::AdaptiveCards::Rendering::Uwp::ActionAlignment value)
    {
        m_actionAlignment = value;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::get_ActionsOrientation(ABI::AdaptiveCards::Rendering::Uwp::ActionsOrientation* value)
    {
        *value = m_actionsOrientation;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionsConfig::put_ActionsOrientation(ABI::AdaptiveCards::Rendering::Uwp::ActionsOrientation value)
    {
        m_actionsOrientation = value;
        return S_OK;
    }
}}}
