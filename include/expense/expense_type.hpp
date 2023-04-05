#pragma once

#include <string>

namespace expense
{
    class expense_type
    {
    public:
        expense_type(int id_, const std::string& name_)
            : id(id_), name(name_) 
        {}

    private:
        std::string name;
        int id;
    };
}

