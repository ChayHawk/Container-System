#include <iostream>
#include <string>
#include <vector>
#include <utility>

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
    auto compareItemNames = [&item](const std::pair<Item, int> pair)
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
            std::cout << GetName() << " doesnt have " << amount << " " << it->first.GetName() << " in it!\n";
        }
    }
}

void Container::Sort(bool ascending)
{

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

    Container playerInventory("Player Inventory");

    playerInventory.Insert(handgun, 1);
    playerInventory.Insert(medipack, 5);

    playerInventory.Open();

    playerInventory.Remove(medipack, 6);

    playerInventory.Open();
}