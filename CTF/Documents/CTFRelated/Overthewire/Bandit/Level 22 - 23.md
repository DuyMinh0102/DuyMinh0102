A program is running automatically at regular intervals from **cron**, the time-based job scheduler. Look in **/etc/cron.d/** for the configuration and see what command is being executed.

**NOTE:** Looking at shell scripts written by other people is a very useful skill. The script for this level is intentionally made easy to read. If you are having problems understanding what it does, try executing it to see the debug information it prints.

We read the *cronjob_bandit23*
~~~
bandit22@bandit:/$ cat /etc/cron.d/cronjob_bandit23
@reboot bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
* * * * * bandit23 /usr/bin/cronjob_bandit23.sh  &> /dev/null
~~~
Now read the file /usr/bin/cronjob_bandit23.sh
```
#!/bin/bash

myname=$(whoami)
mytarget=$(echo I am user $myname | md5sum | cut -d ' ' -f 1)

echo "Copying passwordfile /etc/bandit_pass/$myname to /tmp/$mytarget"

cat /etc/bandit_pass/$myname > /tmp/$mytarget
```
So what this does is to copy bandit_pass of a user to a encrypted folder inside of /tmp.
what do we do?
copy the whole encrypted code and paste it into our commandline.
```
bandit22@bandit:/$ cat /tmp/$(echo I am user bandit23 | md5sum | cut -d ' ' -f 1)
```
Since we need bandit23's password, we'd pass in that name.
Now we can move on to the next level. [[Level 23 - 24]]