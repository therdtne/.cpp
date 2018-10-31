#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;


int processGuess(char* word, const char* targetWord, char guess);


const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int numTurns = 10;

  // Picks a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  
  char word[80];  // a blank array to use to build up the answer

  
  int i;
  
  for (i = 0; targetWord[i] != '\0'; i++)
    {
      word[i] = '*';
    } 
    word[i] = '\0';
  
  do
   {
    cout << "Current word: " << word << endl;
    cout << numTurns << " remain... Enter a letter to guess: " << endl;
    cin >> guess;

    if (processGuess(word, targetWord, guess) == 0)
    {
      numTurns--;
    }
    if (strcmp(word,targetWord) == 0)
    {
      wordGuessed = true;
    }
   }
  while (wordGuessed == false && numTurns != 0);

  if (wordGuessed == true)
    {
      cout << "The word was: " << targetWord << "." << " " << "You win!" << endl;
    }
  else
    {
      cout << "Too many turns... You lose!" << endl;
    }

    
  return 0;
}


int processGuess(char* word, const char* targetWord, char guess)
{
  int correct_guesses = 0;
 
  for (int i = 0; targetWord[i] != '\0'; i++)
  {
    if (targetWord[i] == guess)
    {
      correct_guesses++;
      word[i] = guess;
    }
  }
  return correct_guesses;
}