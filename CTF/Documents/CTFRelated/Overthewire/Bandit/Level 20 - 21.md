Pass: 0qXahG8ZjOVMN9Ghs7iOWsCfZyXOUbYO

./suconnect on this level connects to a port and sees if it receives the correct password (the current level's password). If yes, it return the password to the next level.
So basically ./suconnect is a client, you'd need to set up a port that has the password on it and use ./suconnect to connect to it, you'll then get the password.
To setup a network:
*echo "bandit_passwd" | echo -l -p port-number &*
the port-number should be a high number (like 4444 or 5555).
Move on to the next level:  [[Level 21 - 22]]
