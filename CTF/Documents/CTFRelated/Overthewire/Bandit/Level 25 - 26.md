Password: iCi86ttT4KSNe1armKiwbQNmB3YJP3q4
Logging in to bandit26 from bandit25 should be fairly easy… The shell for user bandit26 is not **/bin/bash**, but something else. Find out what it is, how it works and how to break out of it.

> NOTE: if you’re a Windows user and typically use Powershell to `ssh` into bandit: Powershell is known to cause issues with the intended solution to this level. You should use command prompt instead.

To check what shell bandit26 has.
```
cat /etc/passwd | grep bandit26
```
Then you can read the manual for the ```more``` command.
We can move on to [[Level 26 - 27]]
