#pragma once

#include "Container.h"

class Player
{
	public:
		Player(const std::string& name, int health): mName(name), mHealth(health)
		{}

		std::string GetName() const;
		int GetHealth() const;

		void AddToInventory(Item& item, int amount);

		void RemoveFromInventory(Item& item, int amount);

		void OpenInventory() const;

		void SortInventory(bool ascending);


	private:
		std::string mName{ "Player Name" };
		int mHealth{ 100 };
		Container mInventory;
};