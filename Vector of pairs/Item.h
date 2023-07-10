#pragma once

#include <string>

class Item
{
    public:
        Item(const std::string& name) : mName(name)
        {}

        std::string GetName() const;

    private:
        std::string mName{ "Item Name" };
};