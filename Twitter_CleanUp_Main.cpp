#include <iostream>
#include "Twitter_CleanUp.hpp"

using namespace std;

void print()
{
  cout << endl;
  cout << "Welcome! Which option would you like to choose?" << endl;
  cout << "1. Cross-Reference all your tweets with a generated list of offensive words and phrases" << endl;
  cout << "2. Cross-Reference all your tweets with a word or phrase that you enter" << endl;
  cout << "3. Quit the program and delete all your information" << endl;
}


int main(int argc, char* argv[])
{
  string offensiveList = "OffensiveListOfWordsOrPhrases.txt";
  string txtFile = "Tweets.txt";
  string response;
  string userEnteredWord;
  Twitter T;

  print();
  getline(cin, response);

  while(response != "3")
  {
    if(response == "1")
    {
      cout << endl << "Generating offensive list:" << endl;
      T.storeGeneratedListInArray(offensiveList);
      //cout << endl << "Here are all your tweets:" << endl;
      T.openTXTFileAndStoreAllTweetsInLL(txtFile);
      //T.printLLTweets();
      cout << endl << "Comparing generated list with all tweets..." << endl;
      T.compareLLandArray();
      cout << endl << "List of offensive tweets..." << endl << endl;
      T.printOLL();

      //ask again
      print();
      getline(cin, response);
    }
    else if(response == "2")
    {
      cout << "Please enter the word or phrase you wish to cross-reference with:" << endl;
      getline(cin,userEnteredWord);

      //cout << "Here are all your tweets:" << endl;
      T.openTXTFileAndStoreAllTweetsInLL(txtFile);
      cout << endl << "Comparing entered word or phrase with all tweets..." << endl;
      T.compareLLandEnteredWord(userEnteredWord);
      cout << endl << "List of offensive tweets..." << endl << endl;
      T.printOLL();

      //ask again
      print();
      getline(cin, response);
    }
    else
    {
      //ask again
      cout << "You did not enter a valid number. Please select either 1, 2, or 3" << endl;
      getline(cin,response);
    }
    T.~Twitter();
  }

  cout << "Goodbye!" << endl;
  T.~Twitter();
  T.ClearTxtFile(txtFile);
}
