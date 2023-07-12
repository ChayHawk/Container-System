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

    player.AddToInventory(handgun, 1);
    player.AddToInventory(medipack, 5);
    player.AddToInventory(key, 1);
    player.AddToInventory(map, 1);
    player.AddToInventory(goldBar, 2);
    player.AddToInventory(carKeys, 1);
    player.AddToInventory(hammer, 1);
    player.AddToInventory(money, 56);

    player.OpenInventory();

    player.RemoveFromInventory(medipack, 8);

    player.SortInventory(true);

    std::cout << "\n\n";

    player.OpenInventory();
}