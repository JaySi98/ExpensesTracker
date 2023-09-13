#include <iostream>
#include <array>
#include <atomic>
#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/event.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/dom/flexbox_config.hpp"
#include "ftxui/screen/terminal.hpp"

// #include <transaction.hpp>
// #include "transaction_type.hpp"
// #include <options_parser.hpp>
#include <view_models/main_vm.hpp>

using namespace ftxui;

int main(int /*argc*/, char** /*argv*/) 
{
    view_models::main_vm mainView;

    auto screen = ScreenInteractive::Fullscreen();
    std::atomic<bool> refresh_ui_continue = true;
    std::thread refresh_ui([&] 
    {
        while (refresh_ui_continue) 
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(0.05s);

            // After updating the state, request a new frame to be drawn. This is done
            // by simulating a new "custom" event to be handled.
            screen.Post([&] { mainView.Update(); });
            screen.Post(Event::Custom);
        }
    });

    screen.Loop(mainView.Render());
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