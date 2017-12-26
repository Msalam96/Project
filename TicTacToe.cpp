#include <iostream>

using namespace std;

// The Tic Tac Toe Board with all 9 positions to be filled
char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Struct for Player 1 and 2 who will either use X or O, num is to output the player number
struct Player {
	int num;
	char mark;
	bool flag;
};

//Initialize the player
Player p = {1, 'X', true};


//Display the tic tac toe grid
void display() {
	cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
	cout << "-|-|-" << endl;
	cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
	cout << "-|-|-" << endl;
	cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
}

//Function to change the player after every turn, Player 1 -> Player 2 -> Player 1
void changePlayer() {
	if (p.mark == 'X' && p.flag == true) {
		p.mark = 'O';
		p.num = 2;
	}
	else if (p.mark == 'O' && p.flag == true) {
		p.mark = 'X';
		p.num = 1;
	}
}

//Function that determines if a player has won the game, the flag variable will be set to false and the loop will end
void win() {
	for (int i = 0; i < 9; i++) {
		if ((board[0] == board[1] && board[0] == board[2]) || 
			(board[3] == board[4] && board[3] == board[5]) ||
			(board[6] == board[7] && board[6] == board[8]) ||
			(board[2] == board[4] && board[2] == board[6]) ||
			(board[0] == board[4] && board[0] == board[8]) ||
			(board[0] == board[3] && board[0] == board[6]) ||
			(board[1] == board[4] && board[1] == board[7]) ||
			(board[2] == board[5] && board[2] == board[8])) {			
			p.flag = false;
		}
	}
}

//Function to choose where the Player wishes to place their X or O
//Function checks to see if Player has won after their move, if they have not then the loop will continue
//and Change Player function will be used
void choose() {
	char num;
	do {
		cout << "Choose your position Player " << p.num << ":" << endl;
		cin >> num;
		for (int i = 0; i < 9; i++) {
			if (num == board[i]) {
				board[i] = p.mark;
				win();
				changePlayer();
			}
		}
		system("clear"); //Clear the board
		display(); //Display the new board
	} while(p.flag == true);
}

//Function that ouputs who the winner is
void winner() {
	if (p.flag == false) {
		cout << "Congrats Player " << p.num << " has won!" << endl;
	}
}

int main() {
	cout << "Player One - X and Player Two - O" << endl;
	display();
	choose();
	winner();
}