/*************************************************************************
> File Name: Console.h
> Project Name: Hearthstone++
> Author: Chan-Ho Chris Ohk
> Purpose: Console version of Hearthstone++ game.
> Created Time: 2017/10/08
> Copyright (c) 2017, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef HEARTHSTONEPP_CONSOLE_H
#define HEARTHSTONEPP_CONSOLE_H

#include <Commons/Constants.h>
#include <Models/Deck.h>

#include <array>
#include <functional>

namespace Hearthstonepp
{
	class Console
	{
	public:
		template<std::size_t SIZE>
		void ShowMenu(std::array<std::string, SIZE>& menus);
		size_t InputMenuNum(std::string questionStr, const int menuSize);
		bool InputYesNo(std::string sentence) const;
		int Play();

		void SearchCard();
		void MakeDeck();
		void AddCardInDeck(Deck& deck, const Card* card, std::string& selectedCardID);
		void DeleteCardInDeck(Deck& deck, const Card* card, std::string& selectedCardID);
		void LoadDeck();
		void StoreDeck();
		void SimulateGame();

	private:
		std::array<std::string, MENU_SIZE> m_menuStr =
		{
			"1. Search Card",
			"2. Make Deck",
			"3. Load Deck",
			"4. Store Deck",
			"5. Simulate Game",
			"6. Exit"
		};
		std::array<std::function<void(Console&)>, MENU_SIZE - 1> m_menuFuncs =
		{
			&Console::SearchCard,
			&Console::MakeDeck,
			&Console::LoadDeck,
			&Console::StoreDeck,
			&Console::SimulateGame
		};
		std::array<std::string, PLAYER_CLASS_SIZE> m_playerClassStr =
		{
			"1. Druid",
			"2. Hunter",
			"3. Mage",
			"4. Paladin",
			"5. Priest",
			"6. Rogue",
			"7. Shaman",
			"8. Warlock",
			"9. Warrior"
		};
		std::array<std::string, 2> m_makeDeckOperationStr =
		{
			"1. Add Card(s)",
			"2. Delete Card(s)"
		};
		std::array<std::function<void(Console&, Deck&, const Card*, std::string&)>, 2> m_makeDeckOperationFuncs =
		{
			&Console::AddCardInDeck,
			&Console::DeleteCardInDeck
		};
	};
}

#endif