#pragma once

#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

#include "Item.h"

class Container
{
    public:
        Container(const std::string& name) : mName(name)
        {}

        void Insert(Item& item, int amount);
        void Remove(Item& item, int amount);
        void Erase(Item& item);
        void Sort(bool ascending);
        void Open() const;

        std::string GetName() const;

    private:
        std::string mName{ "Container Name" };
        std::vector < std::pair<Item, int>> mContainer{ };
};