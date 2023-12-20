
#include <iostream>

#include <string>

#include <vector>

#include <cstdlib>

#include <ctime>

using namespace std;

// Function to check if the guessed letter is present in the word
bool isLetterPresent(char guess, string word) 
{
    for (char c : word) 
    {
        if (tolower(c) == tolower(guess)) 
        {
            return true;
        }
    }
    return false;
}

// Function to update the hidden word with correctly guessed letters
void updateHiddenWord(char guess, string& word, string& hiddenWord) 
{
    for (int i = 0; i < word.length(); ++i) 
    {
        if (tolower(word[i]) == tolower(guess)) 
        {
            hiddenWord[i] = word[i];
        }
    }
}

int main() 
{
    vector<string> words = {"hangman", "computer", "programming", "hello", "world", "gaming", "computer"}; // Words to guess
    srand(static_cast<unsigned int>(time(nullptr)));
    string word = words[rand() % words.size()]; // Select a random word from the list
    string hiddenWord(word.length(), '_'); // Initialize the hidden word

    int attempts = 6; // Number of attempts allowed

    char guess;
    bool isGameOver = false;

    cout << "Welcome to Hangman!" << endl;

    while (attempts > 0 && !isGameOver) 
    {
        cout << "Attempts left: " << attempts << endl;
        cout << "Word: " << hiddenWord << endl;
        cout << "Enter a letter guess: ";
        cin >> guess;

        if (isLetterPresent(guess, word)) 
        {
            updateHiddenWord(guess, word, hiddenWord);
            if (hiddenWord == word) {
                cout << "Congratulations! You guessed the word: " << word << endl;
                isGameOver = true;
            }
        } 
        else 
        {
            cout << "Incorrect guess." << endl;
            --attempts;
        }
    }

    if (!isGameOver) 
    {
        cout << "Oops! You ran out of attempts. The word was: " << word << endl;
    }

    return 0;
}
