#pragma once

#include "src/ElementComposable/LayoutAttribs.hpp"
#include "src/ElementComposable/TextAttribs.hpp"
#include "src/ElementComposable/VisualAttribs.hpp"
#include "src/ResourceLoaders/Font.hpp"
#include "src/ResourceLoaders/Shader.hpp"
#include "src/UIElements/UIBase.hpp"

namespace src::uielements
{
using namespace elementcomposable;

class UISlider : public UIBaseCPRT<UISlider>
{
public:
    UISlider();
    ~UISlider() = default;
    UISlider(const UISlider&) = delete;
    UISlider(UIBase&&) = delete;
    UISlider& operator=(const UISlider&) = delete;
    UISlider& operator=(UISlider&&) = delete;

    auto getKnobLayout() -> LayoutAttribs&;
    auto getKnobVisual() -> VisualAttribs&;
    auto getTextAttribs() -> TextAttribs&;
    auto getScrollPercentage() -> float;
    auto getScrollValue() -> float;
    auto setScrollValue(const float value) -> void;
    auto setScrollFrom(const float value) -> void;
    auto setScrollTo(const float value) -> void;
    auto setFont(const std::filesystem::path& fontPath) -> void;
    auto setText(std::string text) -> void;

private:
    auto render(const glm::mat4& projection) -> void override;
    auto layout() -> void override;
    auto event(framestate::FrameStatePtr& state) -> void override;

    auto calculatePercentage(const glm::ivec2& mPos) -> float;
    auto calculateKnobPosition() -> void;

protected:
    LayoutAttribs knobLayoutAttr_;
    VisualAttribs knobVisualAttr_;
    TextAttribs textAttribs_;
    float percentage_{0.0f};
    float scrollFrom_{0.0f};
    float scrollTo_{100.0f};
    float scrollValue_{0.0f};

};
using UISliderPtr = std::shared_ptr<UISlider>;
using UISliderWPtr = std::weak_ptr<UISlider>;
} // namespace src::uielements
