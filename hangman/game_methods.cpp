#include "declarations.h"
#include <iostream>
#include <string>
using namespace std;

HangmanGame::HangmanGame() {
	points = 0;
}
void HangmanGame::gameLoop() {
	cout << "Welcome to hangman!" << endl;
	cout << "Whould you like to play? (y/n)" << endl;
	char answ;
	while (cin >> answ && answ == 'y') {
		this->getRandomWord();
		left_attempts = ATTEMPTS;
		int i;
		for (i = 0; i < strlen(secret_word); i++) {
			guessed_letters[i] = '_';
		}
		guessed_letters[i] = '\0';
		incorrect_letters_len = 0;
		guessed = false;
		while (left_attempts > 0 && !guessed) {
			this->printState();
			cout << "Enter your guess: " << endl;
			char guess;
			cin >> guess;
			this->letterGuess(guess);

		}
		cout << "The word was: " << secret_word << endl;
		if (guessed) {
			points++;
			cout << "Congratulations! You won!" << endl;
		}
		else {
			points = 0;
			cout << "Sorry, you lost." << endl;
		}
		cout << "Now your score is: " << points << endl;;
		cout << "Play again? (y/n)" << endl;

	}
	cout << "Your final score is: " << points << endl;
	cout << "Goodbye!" << endl;
}

void HangmanGame::letterGuess(char guess) {
	int i;
	for (i = 0; i < SIZE_MAX && (secret_word[i] && secret_word[i] != guess); i++);
	if (secret_word[i]) {
		cout << "\tCorrect!" << endl;
		for (int i2 = i; secret_word[i2]; i2++) {
			//mark guessed letter(s)
			if (secret_word[i2] == guess)guessed_letters[i2] = guess;
		}
		//check if won
		if (strncmp(secret_word, guessed_letters, strlen(secret_word))==0) guessed = true;


	}
	else {
		cout << "\tIncorrect!" << endl;
		incorrect_letters[incorrect_letters_len] = guess;
		incorrect_letters_len++;
		left_attempts--;
	}
}
//BAD!
void HangmanGame::getRandomWord() {
	strncpy_s(secret_word, "secret", 6);
}

void HangmanGame::printState() {
	cout << "Guessed: " << guessed << endl;
	cout << "Left attempts: " << left_attempts << endl;
	cout << "Incorrect letters: ";
	for (int i = 0; i < incorrect_letters_len; i++) {
		cout << incorrect_letters[i] << " ";
	}
	cout << endl;
	cout << "Guessed letters: " << endl;
	cout << "\t" << guessed_letters << endl;
}