#ifndef TWITTER_CLEANUP_HPP
#define TWITTER_CLEANUP_HPP

#include <string>

using namespace std;

struct Tweet
{
    string tweetToBeExamined;
    bool offensive;
    Tweet* next;
};

struct OffensiveTweets
{
  string offensiveTweet;
  OffensiveTweets* next;
};

class Twitter
{
    private:
      string offensiveWords[25];
      Tweet* headOfTweets;
      OffensiveTweets* headOfOTweets;

    public:
      Twitter();
      //option 3 function
      ~Twitter();
      void ClearTxtFile(string);

      void openTXTFileAndStoreAllTweetsInLL(string);

      //option 1 functions
      void storeGeneratedListInArray(string);
      void printLLTweets();
      void compareLLandArray();
      void printOLL();

      //option 2 functions
      void compareLLandEnteredWord(string);

};
#endif
