/**
 * @file Exercise2_maldosari.cpp
 * @author Musab Aldsoari
 * @date 2026-11-22
 * @brief A program that tranlates Morse code to English and vice versa.
 */

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

class MorseCodeTranslator {
public:
	void englishToMorse(char sentence[]);
	void morseToEnglish(char morseSentence[]);
};

class Translator {
public:
	void displayMenu();
	void run();
};

const char englishLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char morseCodes[26][5] = {
	".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
	"-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
	"..-", "...-", ".--", "-..-", "-.--", "--.."
};

/** 
 * @brief Translate Enlgish letters into Morse code.
 * @param sentence The English sentence entered  by the user.
 * @return None
 */
void MorseCodeTranslator::englishToMorse(char sentence[]) {
	cout << "Morse Code: ";

	for (int i = 0; i < strlen(sentence); i++) {
		char letter = toupper(sentence[i]);

		for (int j = 0; j < 26; j++) {
			if (letter == englishLetters[j]) {
				cout << morseCodes[j] << " ";
			}
		}
	}
	cout << endl;
}

/**
 * @brief Translates Morse Code into English letters.
 * @param morseSentence The Morse Code entered by the user.
 * @return None
 */
void MorseCodeTranslator::morseToEnglish(char morseSentence[]) {
	char morseLetter[5];
	int position = 0;

	cout << "English: ";

	for (int i = 0; i <= strlen(morseSentence); i++) {
		if (morseSentence[i] == ' ' || morseSentence[i] == '\0') {
			morseLetter[position] = '\0';

			for (int j = 0; j < 26; j++) {
				if (strcmp(morseLetter, morseCodes[j]) == 0) {
					cout << englishLetters[j];
				}
			}
			position = 0;
		}
		else {
			if (position < 4) {
				morseLetter[position] = morseSentence[i];
				position++;
			}
		}
	}
	cout << endl;
}

/**
 * @brief Displays the menu to translate to user
 * @param None
 * @return None
 */
void Translator::displayMenu() {
	cout << endl;
	cout << "=.= MORSE CODE TRANSLATOR =.=" << endl;
	cout << "1. English to Morse Code" << endl;
	cout << "2. Morse Code to English" << endl;
	cout << "3. Exit" << endl;
	cout << " Enter your choice: ";
}

/**
 * @brief Runs the Menu and allows the user to translate text.
 * @param None
 * @return None
 */
void Translator::run() {
	MorseCodeTranslator translator;
	char choice[10] = "";
	char sentence[251];

	while (choice[0] != '3') {
		displayMenu();
		cin.getline(choice, 10);

		if (choice[0] == '1') {
			cout << "Enter an English sentence: ";
			cin.getline(sentence, 251);

			if (strlen(sentence) > 50) {
				cout << "Error: Maximum 50 characters allowed!" << endl;
			}
			else {
				translator.englishToMorse(sentence);
			}
		}
		else if (choice[0] == '2') {
			cout << "Enter Morse Code: ";
			cin.getline(sentence, 251);
			translator.morseToEnglish(sentence);
		}
		else if (choice[0] == '3') {
			cout << "Goodbye!" << endl;
		}
		else {
			cout << "Invalid choice. Please try again!" << endl;
		}
	}
}

/**
 * @brief The main function that runs the TranslatorApp.
 * @param None
 * @return 0 when program finishes successfully.
 */
int main() {
	Translator app;
	app.run();

	return 0;
}
