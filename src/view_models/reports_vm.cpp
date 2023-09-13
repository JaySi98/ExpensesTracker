#include <view_models/reports_vm.hpp>

namespace view_models 
{
    reports_vm::reports_vm()
        : iter(0)
    {
        months = {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Agst", "Sep", "Oct", "Nov", "Dec"
        };

        ConstructView();
    }

    void reports_vm::Update()
    {
        // empty
    }

    void reports_vm::ConstructView()
    {
        container = Container::Vertical({
            Collapsible("2020",{Menu(&months, &iter)}),
            Collapsible("2021",{Menu(&months, &iter)}),
            Collapsible("2022",{Menu(&months, &iter)}),
        });
        
        m_component = Renderer(container, [&] 
        {
            auto list_vbox = vbox(
            {
                text("Months") | hcenter,
                container->Render()
            });

            auto list_vbox_2 = vbox(
            {
                text("Transactions") | hcenter,
                //container->Render()
            });

            return vbox(
            {
                hbox(
                {
                    list_vbox,
                    list_vbox_2
                })
            });
        });
    }

 
}