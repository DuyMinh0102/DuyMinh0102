Password: s0773xxkk0MXfdqOfPRVr9L3jJBUOgCZ
Repeat the steps from before to get a shell, within this level is a file ```bandit27-do``` 
Running it will do this:
```
bandit26@bandit:~$ ./bandit27-do 
Run a command as another user.
  Example: ./bandit27-do id
```
Running the command it gives as an example
```
uid=11026(bandit26) gid=11026(bandit26) euid=11027(bandit27) groups=11026(bandit26)
```
euid (Effective User ID) determines what processes/privileges the user gets to perform/get.
What does this mean? This executable file is basically user bandit27.
Read the password using
```
./bandit27-do cat /etc/bandit_pass/bandit27
```
Next level: [[Level 27 - 28]]
