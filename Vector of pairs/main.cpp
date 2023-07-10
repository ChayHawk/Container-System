#include <iostream>

#include "Container.h"
#include "Item.h"


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