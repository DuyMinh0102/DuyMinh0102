Password: kSkvUpMQ7lBYyCM4GBPvCvT1BfWRy0Dx

![[Pasted image 20260430141836.png]]
scan all the ports from 31000 to 32000 using : **nmap -sV -p 31000-32000 localhost**
![[Pasted image 20260430144451.png]]

We will get something like this
From there we can see that  only port 31518 and 31790 speaks SSL, and 31518 will return anything we send it.
Sending the password to port 31790 will give us a key which we already know how to handle
[[Level 17 - 18]]