Password: gb8KRRCsshuZXI0tUuR6ypOFjiZbf3G8
A daemon is listening on port 30002 and will give you the password for bandit25 if given the password for bandit24 and a secret numeric 4-digit pincode. There is no way to retrieve the pincode except by going through all of the 10000 combinations, called brute-forcing.

So, how do you do this?
If you want to send something to a port on localhost, do
```
echo "Something" | nc localhost <port>
```

To brute-force all 10000 combinations:
```
for i in {0000..9999}; do echo "gb8KRRCsshuZXI0tUuR6ypOFjiZbf3G8 $i" | nc localhost 30002; done
```
We can move on to [[Level 25 - 26]]