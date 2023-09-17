#include <view_models/reports_vm.hpp>

namespace view_models 
{
    reports_vm::reports_vm()
        : iter(0)
        , graphs_iter(0)
        , domain_model()
    {
        months = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Agst", "Sep", "Oct", "Nov", "Dec"
        };
        graphs = {"Categories", "Ratio", "Difference"};

        ConstructView();
    }

    void reports_vm::Update()
    {
        // empty
    }

    void reports_vm::ConstructView()
    {
        auto tab_toggle = Toggle(&graphs, &graphs_iter);
        Component stats_container = Container::Vertical({ 
            tab_toggle
        }); 

        container_main = Container::Horizontal({
            Window("Month",     Menu(&months, &iter)),
            Window("Expenses",  Menu(&months, &iter)),
            Window("Stats",     stats_container),
        });

        m_component = Renderer(container_main,[&]   
        {
            return container_main->Render();
        });
    }

 
}