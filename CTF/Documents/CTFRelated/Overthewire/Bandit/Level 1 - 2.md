After level 0, do
**ssh -l bandit1 bandit.labs.overthewire.org -p 2220**
password is: **ZjLjTmM6FvvyRnrb2rfNWOZOTa6ip5If**

This level asks us to take the password from a file that is named **-**
normal **cat** will result in this:
![[Pasted image 20260429205349.png]]
Which outputs nothing

Instead, we have to do this:
![[Pasted image 20260429205403.png]]

Because the file name is, well, odd, reading it the normal way isn't possible.
We can now move on to level 2.