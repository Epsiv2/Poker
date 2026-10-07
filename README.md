# Poker

A console-based poker game written in C++ with a focus on object-oriented programming, card management, hand evaluation, and a simple computer opponent.

The project implements a complete poker round where the player competes against a computer-controlled opponent, including card dealing, card exchange, hand evaluation, and winner determination.

## Features

- Standard 52-card deck
- Card shuffling
- Five-card poker hands
- Card exchange system
- Hand evaluation
- Hand ranking comparison
- Tie-breaker logic
- Simple computer opponent
- Multiple rounds
- Replay option
- Console-based user interface
- Input validation

## Poker Hands

The game recognizes the following poker hands:

1. Royal Flush
2. Straight Flush
3. Four of a Kind
4. Full House
5. Flush
6. Straight
7. Three of a Kind
8. Two Pair
9. One Pair
10. High Card

The program also handles special cases such as the Ace-low straight (`A-2-3-4-5`).

## Gameplay

At the start of each round:

1. A new deck is created and shuffled.
2. The player and computer receive five cards.
3. The player can exchange up to four cards.
4. The computer decides whether to exchange cards.
5. Both hands are evaluated again.
6. The hands are compared.
7. The winner is displayed.
8. The player can start another round.

## Object-Oriented Design

The project is divided into several classes, each responsible for a specific part of the game:

### `Card`

Represents a single playing card using:

- `Suit`
- `Rank`

### `Deck`

Responsible for:

- Creating the 52-card deck
- Shuffling cards
- Dealing cards

### `Player`

Represents a poker player and manages:

- Player's hand
- Adding cards
- Removing cards
- Exchanging cards

### `ComputerPlayer`

Inherits from `Player` and adds simple computer-controlled behaviour for exchanging cards.

### `PokerHand`

Responsible for:

- Evaluating poker hands
- Determining hand rankings
- Comparing hands
- Handling tie-breakers

## Technologies

- **C++**
- Standard Template Library (STL)
- `std::vector`
- `std::array`
- Random number generation
- Object-Oriented Programming
- Inheritance
- Encapsulation
- Console I/O

## Concepts Practiced

This project was created to practice:

- Classes and objects
- Constructors
- Header and source files
- Encapsulation
- Inheritance
- `enum class`
- `std::vector`
- `std::array`
- References and `const` references
- Iterators
- `erase()` and `push_back()`
- Random number generation
- Basic game logic
- Hand evaluation and comparison
- Input handling

## Project Structure

```text
Poker/
├── Card.h
├── Card.cpp
├── Deck.h
├── Deck.cpp
├── Player.h
├── Player.cpp
├── ComputerPlayer.h
├── ComputerPlayer.cpp
├── PokerHand.h
├── PokerHand.cpp
├── Poker.vcxproj
├── Poker.vcxproj.filters
├── .gitignore
└── main.cpp
```
## Platform
This project is currently designed for Windows and runs as a console application.

## Author
EpsiV2
Junior C++ & Unreal Engine Developer
