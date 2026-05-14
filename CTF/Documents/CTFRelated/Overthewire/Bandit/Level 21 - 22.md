Password: EeoULMCra2q0dSkYj561DX7s1CpBuOBt

A program is running automatically at regular intervals from **cron**, the time-based job scheduler. Look in **/etc/cron.d/** for the configuration and see what command is being executed.
## Commands you may need to solve this level
cron, crontab, crontab(5) (use “man 5 crontab” to access this)

Within /etc/cron.d there will be some files, but we only focus on the *cronjob_bandit22* for now.
We read the file:
```
bandit21@bandit:/etc/cron.d$ cat cronjob_bandit22
@reboot bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
* * * * * bandit22 /usr/bin/cronjob_bandit22.sh &> /dev/null
```

So all of the output of a file called cronjob_bandit22.sh is being redirected to /dev/null, which basically means throwing all of it into a void. You won't see it.

But that's already plenty information, you can read the file itself and you'd get something like this:
~~~
bandit21@bandit:/etc/cron.d$ cat /usr/bin/cronjob_bandit22.sh
#!/bin/bash
chmod 644 /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
cat /etc/bandit_pass/bandit22 > /tmp/t7O6lds9S0RqQh9aMcz6ShpAoZKF7fgv
~~~
Everything is pretty clear now, let's move on to [[Level 22 - 23]]
