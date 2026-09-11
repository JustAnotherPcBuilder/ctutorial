### Watch for New TIL Facts

Create a program that receives data from the /r/todayilearned subreddit, and looks for new facts that have been posted.

- Each time the program comes across a new fact, the fact should be printed into the command line. However, phrases like "TIL ", "TIL that", etc should be removed so the only thing that is printed is the fact.

There are a couple things to note about this:

- According to Reddit's API Access Rules Page, the API pages are only updated once every thirty seconds, so you'll have to have your code pause for at least thirty seconds before it tries to find more posts.
- If for some reason you decide to try to get data sooner than every thirty seconds, make sure to not send more than thirty requests per minute. That is the maximum you are allowed to do.

Subgoals:

- Print the link to the source of the fact too.
- Try to further clean up the fact by adding punctuation to the end if it is missing, capitalize the first word, etc.
- Write the facts to a separate text file so you end up with a giant compilation of random facts.
- Create a bot that posts the facts to Twitter.

