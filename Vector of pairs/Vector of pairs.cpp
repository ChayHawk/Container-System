#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

class Item
{
    public:
        Item(const std::string& name) : mName(name)
        {}

        std::string GetName() const;

    private:
        std::string mName{ "Item Name" };
};

std::string Item::GetName() const
{
    return mName;
}

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

void Container::Insert(Item& item, int amount)
{
    mContainer.push_back(std::make_pair(item, amount));
}

void Container::Remove(Item& item, int amount)
{
    auto compareItemNames = [&item](const std::pair<Item, int>& pair)
    {
        return pair.first.GetName() == item.GetName();
    };

    auto it = std::find_if(mContainer.begin(), mContainer.end(), compareItemNames);

    if (it != mContainer.end())
    {
        if (amount <= it->second)
        {
            it->second -= amount;
        }
        else
        {
            //We do not remove the item from the vector if there is 0, this is intended.
            std::cout << GetName() << " doesnt have " << amount << " " << it->first.GetName() << " in it!\n";
            std::cout << "Removed " << it->second << " " << it->first.GetName() << " instead.\n";
            it->second = 0;
        }
    }
}

void Container::Erase(Item& item)
{
    auto compareItemNames = [&item](const std::pair<Item, int>& pair)
    {
        return pair.first.GetName() == item.GetName();
    };

    auto it = std::find_if(mContainer.begin(), mContainer.end(), compareItemNames);

    if (it != mContainer.end())
    {
        mContainer.erase(it);
    }
}


using itemIntPair = std::pair<Item, int>;

void Container::Sort(bool ascending)
{

    if (ascending == true)
    {
        std::sort(mContainer.begin(), mContainer.end(), [](const itemIntPair& a, const itemIntPair& b)
            {
                return a.first.GetName() < b.first.GetName();
            });
    }
    else
    {
        std::sort(mContainer.begin(), mContainer.end(), [](const itemIntPair& a, const itemIntPair& b)
            {
                return a.first.GetName() > b.first.GetName();
            });
    }
}

void Container::Open() const
{
    int enumerate{ 1 };
    for (const auto& i : mContainer)
    {
        std::cout << enumerate++ << "). " << i.first.GetName() << " x" << i.second << '\n';
    }
}

std::string Container::GetName() const
{
    return mName;
}

int main()
{
    Item handgun("Handgun");
    Item medipack("Medipack");
    Item key("Key");
    Item map("Map");
    Item goldBar("Gold Bar");
    Item carKeys("Car Keys");
    Item hammer("Hammer");
    Item money("Money");

    Container playerInventory("Player Inventory");

    playerInventory.Insert(handgun, 1);
    playerInventory.Insert(medipack, 5);
    playerInventory.Insert(key, 1);
    playerInventory.Insert(map, 1);
    playerInventory.Insert(goldBar, 2);
    playerInventory.Insert(carKeys, 1);
    playerInventory.Insert(hammer, 1);
    playerInventory.Insert(money, 56);

    playerInventory.Open();

    playerInventory.Remove(medipack, 8);

    playerInventory.Sort(true);

    std::cout << "\n\n";

    playerInventory.Open();
}