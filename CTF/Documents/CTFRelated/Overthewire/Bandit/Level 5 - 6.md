The password for level 5: 4oQYVPkxZOOEOO5pTW81FB8j8lxXGUQw
When you look inside the inhere/ folder, you'll see something like this
![[Pasted image 20260429211921.png]]
Brute-force finding will take too long
There's a hint on the web itself.![[Pasted image 20260429211939.png]]
We will use the **find** command for this problem
We execute the following command:
![[Pasted image 20260429212049.png]]
Let's break it down
the *.* means to find in this directory and it's sub-directory
**-type f** means to search for normal files only
**! -executable**: ! is the operator that means "negation", so this part mean not executable
-readable: self-explanatory
-size 1033c: a file with the size of 1033c where c is the data size measure in bytes.
We can now move on to level 6