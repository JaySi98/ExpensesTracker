/*
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

    #include <view_models/main_vm.hpp>

    using namespace ftxui;

    int main() 
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
*/

#include <data/transaction_type.hpp>
#include <data/monthly_budget.hpp>
#include <data/options_parser.hpp>

void add_transaction(const po::variables_map& parsed_variables);
void print_monthly_budget(const po::variables_map& parsed_variables);
void print_help();
void print_transaction_types();


int main(int argc, char** argv) 
{
    options_parser parser(argc, argv);
    auto variables = parser.get_variables();

    if(variables.count("add"))
    {
        add_transaction(variables);
    }
    else if(variables.count("print"))
    {
        print_monthly_budget(variables);
    }
    else if(variables.count("help"))
    {
        print_help();
    }

    else if(variables.count("transaction types"))
    {
        print_transaction_types();
    }
}

void add_transaction(const po::variables_map& parsed_variables)
{
    date d{};
    std::string note{};
    float value{0};
    transaction_type type{transaction_type::unknown};

    if(parsed_variables.count("date"))
    {
        std::string date_str = parsed_variables["date"].as<std::string>(); 
        d = from_simple_string(date_str);
    }

    if(parsed_variables.count("note"))
    {
        note = parsed_variables["note"].as<std::string>();
    }

    if(parsed_variables.count("value"))
    {
        value = parsed_variables["value"].as<float>();
    }

    if(parsed_variables.count("type"))
    {
        std::string s_type = parsed_variables["type"].as<std::string>();
        
        auto find_type = std::find_if(std::begin(str_tran_type), std::end(str_tran_type), [&](const std::pair<transaction_type, std::string>& pair)
        {
            return pair.second.compare(s_type) == 0; 
        });

        if(find_type != std::end(str_tran_type))
        {
            type = find_type->first;
        }
    }

    transaction trans{0, d, type, note, value};
    std::cout << trans << std::endl;
}

void print_monthly_budget(const po::variables_map& parsed_variables)
{
    std::cout << "monthly budget hehe" << std::endl;
}

void print_help()
{
    std::cout << "help hehe" << std::endl;
    print_transaction_types();
}

void print_transaction_types()
{
    std::cout << "transaction types hehe" << std::endl;
}