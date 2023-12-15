#include <iostream>
#include <string>
#include <fstream>
#include "Twitter_CleanUp.hpp"


using namespace std;


Twitter::Twitter()
{
  //use API from twitter to store all tweets into .txt file.
  //Each line in the file should contain a single tweet
  for(int i = 0; i < 25; i++)
  {
    offensiveWords[i] = "NULL";
  }
  headOfTweets = NULL;
  headOfOTweets = NULL;

}

//option 3 function

Twitter::~Twitter()
{
  while(headOfTweets != NULL)
  {
    Tweet* ptr = headOfTweets;
    headOfTweets = headOfTweets -> next;
    delete ptr;
  }

  while(headOfOTweets != NULL)
  {
    OffensiveTweets* ptr1 = headOfOTweets;
    headOfOTweets = headOfOTweets -> next;
    delete ptr1;
  }
}



void Twitter::ClearTxtFile(string filename)
{
  //deletes .txt file containing all tweets of user
  ifstream readTweets (filename);
  ofstream tweets (filename);
  string line;

  if(tweets.is_open() && readTweets.is_open())
  {
    while(getline(readTweets,line))
    {
      tweets << "";
    }
  }
  else
  {
    cout << "File did not open." << endl;
  }
  readTweets.close();
  tweets.close();
}



//------------------------------------------------------------------------------




void Twitter::openTXTFileAndStoreAllTweetsInLL(string filename)
{
  string line;
  ifstream allTweets (filename);

  if(allTweets.is_open())
  {
    while(getline(allTweets,line))
    {
      Tweet* newTweet = new Tweet;
      Tweet* ptr = headOfTweets;

      headOfTweets = newTweet;
      newTweet -> tweetToBeExamined = line;
      newTweet -> offensive = false;
      //cout << newTweet -> tweetToBeExamined << endl;
      newTweet -> next = ptr;

    }
  }
  else
  {
    cout << "File did not open." << endl;
  }
  allTweets.close();
}



//option 1 functions

void Twitter::storeGeneratedListInArray(string offensiveFile)
{
  string line;
  int i = 0;
  ifstream offensiveWordFile (offensiveFile);

  if(offensiveWordFile.is_open())
  {
    while(getline(offensiveWordFile,line))
    {
        offensiveWords[i] = line;
        //cout << offensiveWords[i] << endl;
        i++;
    }
  }
}


void Twitter::printLLTweets()
{
  Tweet* ptr = headOfTweets;

  if(ptr == NULL)
  {
    cout << "No tweets found!" << endl;
  }
  else
  {
    while(ptr != NULL)
    {
      cout << ptr -> tweetToBeExamined << endl;
      ptr = ptr -> next;
    }
  }
}

void Twitter::compareLLandArray()
{
  Tweet* tweet = headOfTweets;

  if(tweet == NULL)
  {
    cout << "No tweets found!" << endl;
  }
  else
  {
    while(tweet != NULL)
    {
      for(int i = 0; i < 25; i++)
      {

          int lengthOfOffensiveWord = offensiveWords[i].length();
          int lengthOfTweet = (tweet -> tweetToBeExamined).length();
          int counter = lengthOfTweet - lengthOfOffensiveWord;

          if(counter == 0)
          {
            if((tweet -> tweetToBeExamined).compare(0,lengthOfOffensiveWord,offensiveWords[i]) == 0)
            {
              if(tweet -> offensive == false)
              {
                OffensiveTweets* newOffensiveTweet = new OffensiveTweets;
                OffensiveTweets* ptr = headOfOTweets;
                headOfOTweets = newOffensiveTweet;
                newOffensiveTweet -> offensiveTweet = (tweet -> tweetToBeExamined);
                newOffensiveTweet -> next = ptr;
                tweet -> offensive = true;
              }
            }
          }
          else
          {
            for(int j = 0; j < counter; j++)
            {
              //cout << j << endl;
              if((tweet -> tweetToBeExamined).compare(j,lengthOfOffensiveWord,offensiveWords[i]) == 0)
              {
                // cout << "Tweet contains offensive word or phrase!" << endl;
                // cout << (tweet -> tweetToBeExamined) << endl;

                if(tweet -> offensive == false)
                {
                  OffensiveTweets* newOffensiveTweet = new OffensiveTweets;
                  OffensiveTweets* ptr = headOfOTweets;
                  headOfOTweets = newOffensiveTweet;
                  newOffensiveTweet -> offensiveTweet = (tweet -> tweetToBeExamined);
                  newOffensiveTweet -> next = ptr;
                  tweet -> offensive = true;
                }
              }
            }
          }

      }
      tweet = tweet -> next;
    }
  }
}


void Twitter::printOLL()
{
  OffensiveTweets* ptr = headOfOTweets;
  string answer;

  ofstream file ("TweetIDs.txt");

  if(ptr == NULL)
  {
    cout << "No offensive tweets found!" << endl;
  }
  else
  {
    cout << "Your tweets:" << endl;
    while(ptr != NULL)
    {
      cout << endl << "-----" << endl;
      cout << ptr -> offensiveTweet << endl;
      cout << "-----" << endl;

      cout << "Delete this post:" << endl;
      cout << "(yes) or (no)" << endl;
      getline(cin,answer);

      while(answer != "yes" && answer != "Yes" && answer != "YES" && answer != "YEs" && answer != "yeS" && answer != "yEs" && answer != "yES" && answer != "no" && answer != "NO" && answer != "No" && answer != "nO")
      {
        cout << "please enter either yes or no!" << endl;
        getline(cin,answer);
      }

      if(answer == "yes" || answer == "Yes" || answer == "YES" || answer == "YEs" || answer == "yeS" || answer == "yEs" || answer == "yES")
      {
        //delete post using twitter API
        file << ptr -> offensiveTweet << "^";
        cout << "Tweet in the list to be deleted!" << endl;
      }
      else if(answer == "no" || answer == "NO" || answer == "No" || answer == "nO")
      {
        cout << "Tweet not deleted, on to the next one!" << endl;
      }

      ptr = ptr -> next;
    }
  }
  file.close();
}




//option 2 functions

void Twitter::compareLLandEnteredWord(string enteredWord)
{
  Tweet* tweet = headOfTweets;

  if(tweet == NULL)
  {
    cout << "No tweets found!" << endl;
  }
  else
  {
    while(tweet != NULL)
    {
      int lengthOfOffensiveWord = enteredWord.length();
      int lengthOfTweet = (tweet -> tweetToBeExamined).length();
      int counter = lengthOfTweet - lengthOfOffensiveWord;

      if(counter == 0)
      {
        if((tweet -> tweetToBeExamined).compare(0,lengthOfOffensiveWord,enteredWord) == 0)
        {
          if(tweet -> offensive == false)
          {
            OffensiveTweets* newOffensiveTweet = new OffensiveTweets;
            OffensiveTweets* ptr = headOfOTweets;
            headOfOTweets = newOffensiveTweet;
            newOffensiveTweet -> offensiveTweet = (tweet -> tweetToBeExamined);
            newOffensiveTweet -> next = ptr;
            tweet -> offensive = true;
          }
        }
      }
      else
      {
        for(int j = 0; j < counter; j++)
        {
          //cout << j << endl;
          if((tweet -> tweetToBeExamined).compare(j,lengthOfOffensiveWord,enteredWord) == 0)
          {
            // cout << "Tweet contains offensive word or phrase!" << endl;
            // cout << (tweet -> tweetToBeExamined) << endl;

            if(tweet -> offensive == false)
            {
              OffensiveTweets* newOffensiveTweet = new OffensiveTweets;
              OffensiveTweets* ptr = headOfOTweets;
              headOfOTweets = newOffensiveTweet;
              newOffensiveTweet -> offensiveTweet = (tweet -> tweetToBeExamined);
              newOffensiveTweet -> next = ptr;
              tweet -> offensive = true;
            }
          }
        }
      }
      tweet = tweet -> next;
    }
  }
}
