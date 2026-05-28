Password: 4pT1t5DENaYuqnqvadYs1oE4QLCdjmJ7
## Level Goal

There is a git repository at `ssh://bandit29-git@bandit.labs.overthewire.org/home/bandit29-git/repo` via the port `2220`. The password for the user `bandit29-git` is the same as for the user `bandit29`.

From your local machine (not the OverTheWire machine!), clone the repository and find the password for the next level. This needs git installed locally on your machine.


Clone the repo into a temporary directory.
```
❯ ls -a
.  ..  .git  README.md
❯ cat README.md
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: <no passwords in production!>
```
No password in production.
Check the logs show nothing.
Another thing we can check is the branches
```
❯ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/dev
  remotes/origin/master
  remotes/origin/sploits-dev
```
To check a branch out, do:
```
❯ git checkout origin/<name>
```

So we checkout the /dev branch
```
❯ git checkout origin/dev
Note: switching to 'origin/dev'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by switching back to a branch.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -c with the switch command. Example:

  git switch -c <new-branch-name>

Or undo this operation with:

  git switch -

Turn off this advice by setting config variable advice.detachedHead to false

HEAD is now at 4a8f414 add data needed for development
❯ ls
code  README.md
```
Check the markdown
❯ cat README.md
```
# Bandit Notes
Some notes for bandit30 of bandit.

## credentials

- username: bandit30
- password: qp30ex3VLz5MDG1n91YowTv4Q8l7CDZL
```

Move on to [[Level 30 - 31]]
