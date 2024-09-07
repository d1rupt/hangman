#ifndef DECL_
#define DECL_

#define ATTEMPTS 6
#define MAX_LEN 100
class HangmanGame {
public:
	HangmanGame();
	void letterGuess(char letter);
	void getRandomWord();
	void gameLoop();
	void printState();
private:
	char secret_word[MAX_LEN];
	char guessed_letters[MAX_LEN];
	//int guessed_letters_len;
	char incorrect_letters[MAX_LEN];
	int incorrect_letters_len;
	bool guessed;
	int left_attempts;
	int points;

};

#endif // !DECL_

