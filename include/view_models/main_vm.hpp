#pragma once

#include <view_models/base_vm.hpp>
#include <vector> 

namespace view_models {
    class main_vm : public base_vm
    {
    public:
        main_vm();
        void Update() override;

    private:
        std::vector<std::shared_ptr<base_vm>> views;
        std::vector<std::string> tabEntries;
        int tabSelected;

        Component container; 
        Component tabSelection;
        Component tabContent;

        virtual void ConstructView() override;
    };
}