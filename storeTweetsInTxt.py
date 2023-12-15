import sys
sys.path.append('C:\Python\Scripts\Twitter')
import tweepy
import privateAPIinfo
import datetime, time


auth = tweepy.OAuthHandler(privateAPIinfo.TWITTER_APP_KEY, privateAPIinfo.TWITTER_APP_SECRET)
auth.set_access_token(privateAPIinfo.TWITTER_KEY ,privateAPIinfo.TWITTER_SECRET)
api = tweepy.API(auth)

def get_tweets(api,username,days):

    file = open("Tweets.txt", "w")
    page = 1
    deadend = False
    while True:
        tweets = api.user_timeline(username, page = page)

        for tweet in tweets:
            if (datetime.datetime.now() - tweet.created_at).days < days:
                time = tweet.created_at
                Id = tweet.id
                ID = str(Id)
                print "found tweet at...", time
                #print (time)
                file.write(tweet.text.encode("utf-8") + "\n")
            else:
                deadend = True
                print("No tweets found.")
                return
        if not deadend:
            page=page+1
            return
            #//time.sleep(500)

    file.close();

user = raw_input("Please enter in your twitter @ name:" + "\n")
day = input("How many days would you like to look up?" + "\n")


get_tweets(api, user, day)
