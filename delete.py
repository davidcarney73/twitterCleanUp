import tweepy
import privateAPIinfo
from datetime import datetime, timedelta

# options
delete_tweets = True
filename = "TweetIDs.txt"

# auth and api
consumer_key = privateAPIinfo.TWITTER_APP_KEY
consumer_secret = privateAPIinfo.TWITTER_APP_SECRET
access_token = privateAPIinfo.TWITTER_KEY
access_token_secret = privateAPIinfo.TWITTER_SECRET

auth = tweepy.OAuthHandler(consumer_key, consumer_secret)
auth.set_access_token(access_token, access_token_secret)
api = tweepy.API(auth)


# delete old tweets
if delete_tweets:
    # get all timeline tweets
    print "Retrieving tweets to be deleted..."
    timeline = tweepy.Cursor(api.user_timeline).items()
    deletion_count = 0
    ignored_count = 0
    count = 0
    tweets = []
    real = []

    file = open(filename, 'r')

    for line in file:
        tweets = line.split('^');

    for tweet in timeline:
        for element in tweets:
            if(element == tweet.text):
                api.destroy_status(tweet.id)
                print "Deleting: ", tweet.text
                deletion_count = deletion_count + 1
    print "Deleted %d tweets, ignored %d" % (deletion_count, ignored_count)
else:
    print "Not deleting tweets"
