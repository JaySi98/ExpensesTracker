#pragma once

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include "ftxui/component/component.hpp" 
#include "ftxui/component/component_base.hpp"  
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/event.hpp"
#include <ftxui/dom/table.hpp>
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/flexbox_config.hpp"

namespace view_models {
    using namespace ftxui;

    class base_vm
    {
        public:
            base_vm() = default;
            virtual ~base_vm() = default; 

            virtual void Update() = 0;
            virtual void ConstructView() = 0;
            virtual ftxui::Component& Render()
            { return m_component; }

        protected:
            Component m_component;


        Component Window(std::string title, Component component) 
        {
            return Renderer(component, [component, title] 
            { 
                return window(text(title) | hcenter, component->Render()) | flex;
            });
        }
    };
}
