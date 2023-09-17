#pragma once

#include <string> 
#include <vector> 
#include <view_models/base_vm.hpp>
#include <domain_models/reports_dm.hpp>

namespace view_models {
    
    class reports_vm : public base_vm 
    {
    public:
        reports_vm();
        void Update() override;

    private:
        virtual void ConstructView() override;

        domain_models::reports_dm domain_model;

        // temp
        int iter;
        int graphs_iter;
        std::vector<std::string> months;
        std::vector<std::string> graphs;

        Component container;
        Component container_2;
        Component container_main;
    };
}

