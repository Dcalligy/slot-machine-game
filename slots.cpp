#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// function prototypes
int randRange(int low, int high);
int slotResults(int slot1, int slot2, int slot3, int chips, int bets);

int main() {

	srand(time(NULL));
	int chips = 5000;
	int high1(6), high2(6), high3(6);// high slot combination
	int low1(2), low2(2), low3(2);// low slot combination
	int bets;
	int userChoice;

	cout << "User starts with $5000 chips!\n";
	system("pause");

	do {
		cout << "----------------------------------------------\n";
		cout << "Welcome to the Hundi slots!\n" << "What would you like to do? \n";
		cout << "Press (1) to Bet Hundi's\n";
		cout << "Press (2) Cash out\n";
		cout << "Press (3) to display the amount of your chips\n";
		cout << "----------------------------------------------\n";
		cin >> userChoice;

		switch (userChoice) {
		case 1:
			cout << "How much would you like to bet? \n";
			cin >> bets;
			if (bets <= 0) {
				cout << "Sorry, you entered an invalid amount\n";
			}
			else if (bets > chips) {
				cout << "Sorry, you don't have enough chips to make that bet\n";
			}
			else {
				int slot1 = randRange(low1, high1);
				int slot2 = randRange(low2, high2);
				int slot3 = randRange(low3, high3);
				cout << slot1 << " " << slot2 << " " << slot3 << " " << "\n";
				chips = slotResults(slot1, slot2, slot3, chips, bets);
				cout << "Current earnings: $" << chips << "\n";
			}
			break;
		case 2:
			cout << "Hope you enjoyed your time! Please come back again\n";
			cout << "You won $ " << chips << "\n";
			system("pause");
			return 0;
		case 3:
			// Don't really need this bc I added it in the first case... but oh well.
			cout << "You currently have: $"<< chips << "\n";
			break;
		default:
			cout << "Invalid option...please try again!\n";
		}
		if (chips <= 0) {
			cout << "You lost all of your chips! GAME OVER\n";
			system("pause");
			return 0;
		}
	} while (userChoice != 2);
	system("pause");
	return 0;
}

// gets random num between our set range.
int randRange(int low, int high) {
	return rand() % (high - low + 1) + low;
}

int slotResults(int slot1, int slot2, int slot3, int chips, int bets) {

	// hits 3 high combinations
	if (slot1 == 6 && slot2 == 6 && slot3 == 6) {
		cout << "You have won 20 times your bet! $" << bets * 20 << "\n";
		chips = chips + (bets * 20);

	}
	// hits 3 low combinations
	if (slot1 == slot2 == slot3 && !(slot1 == 6 && slot2 == 6 && slot3 == 6)) {
		cout << "You have won 10 times your best! $" << bets * 10 << "\n";
		chips = chips + (bets * 10);
	}
	// hits 2 combinations
	if (slot1 == slot2 || slot1 == slot3 || slot2 == slot3 && !(slot1 == slot2 == slot3) && !(slot1 == 6 && slot2 == 6 && slot3 == 6)) {
		cout << "You have won 5 times your bet! $" << bets * 5 << "\n";
		chips = chips + (bets * 5);
	}
	else {
		cout << "You didn't hit! -$" << bets << "\n";
		chips = chips - bets;
	}
	return chips;
}
