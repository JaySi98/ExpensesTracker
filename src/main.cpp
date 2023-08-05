#include <iostream>
#include <transaction.hpp>
#include "transaction_type.hpp"
#include <options_parser.hpp>

// test
#include <gui/reports_view.hpp>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include <stddef.h>    // for size_t
#include <array>       // for array
#include <atomic>      // for atomic
#include <chrono>      // for operator""s, chrono_literals
#include <cmath>       // for sin
#include <functional>  // for ref, reference_wrapper, function
#include <memory>      // for allocator, shared_ptr, __shared_ptr_access
#include <string>  // for string, basic_string, char_traits, operator+, to_string
#include <thread>   // for sleep_for, thread
#include <utility>  // for move
#include <vector>   // for vector

#include "ftxui/component/component.hpp"  // for Checkbox, Renderer, Horizontal, Vertical, Input, Menu, Radiobox, ResizableSplitLeft, Tab
#include "ftxui/component/component_base.hpp"  // for ComponentBase, Component
#include "ftxui/component/component_options.hpp"  // for MenuOption, InputOption
#include "ftxui/component/event.hpp"              // for Event, Event::Custom
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for text, color, operator|, bgcolor, filler, Element, vbox, size, hbox, separator, flex, window, graph, EQUAL, paragraph, WIDTH, hcenter, Elements, bold, vscroll_indicator, HEIGHT, flexbox, hflow, border, frame, flex_grow, gauge, paragraphAlignCenter, paragraphAlignJustify, paragraphAlignLeft, paragraphAlignRight, dim, spinner, LESS_THAN, center, yframe, GREATER_THAN
#include "ftxui/dom/flexbox_config.hpp"  // for FlexboxConfig
#include "ftxui/screen/terminal.hpp"    // for Size, Dimensions
using namespace ftxui;

int main(int /*argc*/, char** /*argv*/) 
{
    auto screen = ScreenInteractive::Fullscreen();

    // ---------------------------------------------------------------------------
    // Months view
    // --------------------------------------------------------------------------- 
    int iter = 0;
    std::vector<std::string> months{
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Agst", "Seb", "Oct", "Nov", "Dec"
    };

    auto com_m = Container::Vertical({
        Collapsible("2020",{Menu(&months, &iter)}),
        Collapsible("2021",{Menu(&months, &iter)}),
        Collapsible("2022",{Menu(&months, &iter)}),
    });

    auto months_view = Renderer(com_m,[&] 
    {
        auto list_vbox = vbox(
        {
            text("Months") | hcenter,
            com_m->Render()
        });

        return vbox(
        {
            hbox(
            {
                list_vbox
            })
        });
    });

    // ---------------------------------------------------------------------------
    // Main view
    // ---------------------------------------------------------------------------

    int tab_index = 0;
    std::vector<std::string> tab_entries = {
        "Monthly reports"
    };
    
    auto tab_selection = Menu(&tab_entries, &tab_index, MenuOption::Horizontal()); 
    auto tab_content = Container::Tab(
    {
        months_view,
    }, &tab_index);

    auto main_container = Container::Vertical(
    {
        tab_selection,
        tab_content,
    });

    auto main_renderer = Renderer(main_container, [&] 
    {
        return vbox(
        {
            text("Expense Tracker") | bold | hcenter,
            tab_selection->Render(),
            tab_content->Render() | flex,
        });
    });

    std::atomic<bool> refresh_ui_continue = true;
    std::thread refresh_ui([&] 
    {
        while (refresh_ui_continue) 
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(0.05s);

            // After updating the state, request a new frame to be drawn. This is done
            // by simulating a new "custom" event to be handled.
            screen.Post(Event::Custom);
        }
    });

    screen.Loop(main_renderer);
    refresh_ui_continue = false;
    refresh_ui.join();
    
    return EXIT_SUCCESS;
}

/*
   date d1{2020,12,5};
   std::cout << d1.month() << std::endl;

   transaction trans1{d1,transaction_type::house_maintenance, "some note", 120  };
   std::cout << trans1 << std::endl;

//
options_parser parser(argc, argv);
auto variables = parser.get_variables();

if(variables.count("new_transaction"))
{
date d{};
std::string note{};
int value{0};
std::string s_type{};
transaction_type type{transaction_type::unknown};

if(variables.count("date"))
{
d = variables["date"].as<date>();
}

if(variables.count("note"))
{
note = variables["note"].as<std::string>();
}

if(variables.count("value"))
{
value = variables["value"].as<int>();
}

if(variables.count("type"))
{
s_type = variables["type"].as<std::string>();
}

transaction trans{d, type, note, value};
std::cout << trans << std::endl;
}
*/