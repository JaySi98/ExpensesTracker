#include <view_models/main_vm.hpp>
#include <view_models/reports_vm.hpp>


namespace view_models 
{
   main_vm::main_vm() 
        : tabSelected(0)
    {
        tabEntries = std::vector<std::string>
        {
            "Months review",
        };

        views = std::vector<std::shared_ptr<base_vm>>
        {
            std::shared_ptr<base_vm>(new reports_vm),
        };

        ConstructView();
    }

    void main_vm::ConstructView()
    {
        auto getViews = [&]
        {
            std::vector<Component> components;
            std::for_each(views.begin(), views.end(), [&](std::shared_ptr<base_vm>& view)
            {
                components.push_back(view->Render());
            });

            return components;
        };

        tabSelection = Menu(&tabEntries, &tabSelected, MenuOption::Horizontal());

        tabContent = Container::Tab(
        {
            getViews()
        }, &tabSelected);
    
        container = Container::Vertical(
        {
            tabSelection,
            tabContent,
        });
    
        m_component = Renderer(container, [&] 
        {
            return vbox(
            {
                text("Expense Tracker") | bold | hcenter,
                tabSelection->Render()  | border,
                tabContent->Render()    | flex,
            });
        });
    }

    void main_vm::Update() 
    {
        std::for_each(views.begin(), views.end(), [&](std::shared_ptr<base_vm>& view)
        {
            view->Update();
        });
    }
}