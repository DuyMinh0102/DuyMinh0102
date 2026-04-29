Password to enter level 6: HWasnPhtq9AVKe0dmk45nxy20cvUa6EG
The level states:
![[Pasted image 20260429212352.png|697]]
It's quite clear that we're going to use the **find** command again

If you were to type **man find** into the shell (which is the command that opens the manual page for the find command)
![[Pasted image 20260429212535.png]]
![[Pasted image 20260429212504.png]]
![[Pasted image 20260429212520.png]]
Things should be clear at this point.
We execute the following command:
![[Pasted image 20260429213108.png]]
You can see there's a section **2>/dev/null**
The reason is, since we're looking through **every** file in inside of **/** or **root**, there will be files that we cannot, or does not have the permission to open. Which will output a Permission denied message from **stderr** (file descriptor **2**)
TLDR: this section skips anything that got output to stderr, leaving only what we need
We can now move to level 7.