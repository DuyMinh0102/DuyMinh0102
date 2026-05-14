Password: Yz9IpL0sBcCeuG7m9uQFt8ZNpS4HZRcN
There is a git repository at `ssh://bandit28-git@bandit.labs.overthewire.org/home/bandit28-git/repo` via the port `2220`. The password for the user `bandit28-git` is the same as for the user `bandit28`.

From your local machine (not the OverTheWire machine!), clone the repository and find the password for the next level. This needs git installed locally on your machine.

There will be a markdown (.md) file inside of the repo
```
❯ cat README.md 
# Bandit Notes
Some notes for level29 of bandit.

## credentials

- username: bandit29
- password: xxxxxxxxxx
```
So it mentioned the password but doesn't show it.
Some might think it's covered up later on, because if it's hidden from the start, there's no way to find the password.
Use ```git log``` to see the changes
```
❯ git log
commit adc7f885a129baee883058b8a870739489f80194 (HEAD -> master, origin/master, origin/HEAD)
Author: Morla Porla <morla@overthewire.org>
Date:   Fri Apr 3 15:17:54 2026 +0000

    fix info leak

commit a3437bddd447f2d496731658e86b98cbea9d3c98
Author: Morla Porla <morla@overthewire.org>
Date:   Fri Apr 3 15:17:54 2026 +0000

    add missing data

commit cb630ec182b75bc289595511f8bcf4d47cfec50d
Author: Ben Dover <noone@overthewire.org>
Date:   Fri Apr 3 15:17:54 2026 +0000

    initial commit of README.md
```
Read the ```git``` manual, there will be a command to see the changes between commits.
Next level: [[Level 29 - 30]]