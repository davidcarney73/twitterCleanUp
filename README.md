# Twitter Clean Up Project

Project by David Carney

Twitter Clean Up - A way to help people clean up and be more aware of their Twitter posts. There are two .py files, two .cpp files and one .hpp to run this code.

During the first Python code, the user is asked to input their Twitter username and then follows by asking how many days back would they like to view their tweets. After the user enters in all their information the Python code uses the Twitter API to extract all of their tweets up to the entered day and stores them in a .txt file for later parsing.

Once the Python code has concluded, the c++ code starts to run which takes all the tweets from the .txt file and stores them into a stack implemented with linked lists to be examined. Once the stack has been created the user is then prompted with 3 options. Option 1, is to cross-reference all of the users tweets with a generated list of offensive words and phrases. Option 2, is to cross-reference all of the users tweets with a word or phrase that the user enters. While option 3, exits the program and deletes all the users saved information, such as the linked lists of all their tweets, the linked list of their offensive tweets and the .txt file containing all their tweets.

If the user chooses option 1 or 2 the program will find all of their offensive posts and flag them. Once a post has been flagged it is then stored in another stack implemented by linked lists so the most recent tweet is at the top. Once the final stack of only offensive words has been created, the user is taken through the entire stack and asked if they would like to delete or keep each offensive post. If the user chooses to delete one of their posts, that post is then stored into a .txt file to be deleted later using another Python code that uses the Twitter API to delete posts.
