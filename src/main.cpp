#include <iostream>
#include <transaction.hpp>
#include "transaction_type.hpp"
#include <options_parser.hpp>


#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/string.hpp>

int main(int argc, char** argv) 
{
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

    using namespace ftxui;

    auto summary = [&] {
        auto content = vbox({
                hbox({text(L"- done:   "), text(L"3") | bold}) | color(Color::Green),
                hbox({text(L"- active: "), text(L"2") | bold}) | color(Color::RedLight),
                hbox({text(L"- queue:  "), text(L"9") | bold}) | color(Color::Red),
                });
        return window(text(L" Summary "), content);
    };

    auto document =  //
        vbox({
                hbox({
                        summary(),
                        summary(),
                        summary() | flex,
                        }),
                summary(),
                summary(),
                });

    // Limit the size of the document to 80 char.
    document = document | size(WIDTH, LESS_THAN, 80);

    auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    Render(screen, document);

    std::cout << screen.ToString() << '\0' << std::endl;

    return EXIT_SUCCESS;
}