#include "Player.h"

std::string Player::GetName() const
{
	return mName;
}

int Player::GetHealth() const
{
	return mHealth;
}

void Player::AddToInventory(Item& item, int amount)
{
	mInventory.Insert(item, amount);
}

void Player::RemoveFromInventory(Item& item, int amount)
{
	mInventory.Remove(item, amount);
}

void Player::OpenInventory() const
{
	mInventory.Open();
}

void Player::SortInventory(bool ascending)
{
	mInventory.Sort(ascending);
}