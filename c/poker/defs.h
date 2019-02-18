#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Suits
{
    Diamond = 0,
    Spade,
    Hearts,
    Club,
    MAX_Suit
};

enum Numbers
{
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    MAX_Number
};

const short red_joker_;
const short black_joker_;
const char max_cards_in_deck_;
const char max_decks_;

typedef struct PokerCard
{
	enum Suits suit_;
	enum Numbers number_;
} PokerCard;


typedef struct Deck
{
	PokerCard * cards_in_deck_;
} Deck;

#endif