#pragma once

#include <string> 
#include <vector> 
#include <view_models/base_vm.hpp>

namespace view_models {
    
    class reports_vm : public base_vm 
    {
    public:
        reports_vm();
        void Update() override;

    private:
        virtual void ConstructView() override;

        // temp
        int iter;
        std::vector<std::string> months;
        Component container; 
    };
}

