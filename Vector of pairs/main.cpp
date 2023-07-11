#include <iostream>

#include "Container.h"
#include "Item.h"
#include "Player.h"


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

    Player player("Hero", 100);

    player.AddItemToInventory(handgun, 1);
    player.AddItemToInventory(medipack, 5);
    player.AddItemToInventory(key, 1);
    player.AddItemToInventory(map, 1);
    player.AddItemToInventory(goldBar, 2);
    player.AddItemToInventory(carKeys, 1);
    player.AddItemToInventory(hammer, 1);
    player.AddItemToInventory(money, 56);

    player.OpenInventory();

    player.RemoveItemFromInventory(medipack, 8);

    player.SortInventory(true);

    std::cout << "\n\n";

    player.OpenInventory();
}