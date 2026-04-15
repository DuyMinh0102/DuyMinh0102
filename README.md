This repo mainly serves as my own documentation of what I've done over the years studying informatics. It should be containing a variety of topics from Competitive Programming, AI to CTF.

### Contact me:
- Email: minhnguyenduy1234@gmail.com

### 🧩 Problem solving log

[//]: # (START_TABLE)

| Problem / File | Folder | Source | Status | Notes |
| :--- | :--- | :--- | :--- | :--- |
| [doan](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23022026/doan/doan.cpp) | `Learn` | Problems/DOAN.jpg, from a teacher of mine | Solved | You have N segments, each segment is labeled by two intergers L and R, which is that start and endpoint of the segment.<br>You're asked to take a segment, then another one so that the one that was taken after fits inside the one before that.<br>Find the maximum amount of segments that you can take.<br>Let's say you have two segments A [L_a, R_a], B [L_b, R_b]. B fits inside A L_a <= L_b and R_b <= R_a.<br>We sort the array prioritizing smaller L values. If Ls are equal, larger R values<br>Why? So for every i segment, L_i >= L_j for all j < i. => We only need to check for R.<br>=> Now we find the longest non-increasing subsequence of R values. |
| [eggs](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23022026/eggs/eggs.cpp) | `Learn` | Problems/EGGS.jpg, from a teacher of mine | Solved | You have M boxes and N eggs.<br>The N eggs are put onto a production belt in order, the i-th egg has a volume of A_i. At the end are the boxes.<br>You will move onto the next box if the current box is full.<br>Calculate the minimum capacity for each box so we can contain all egs.<br>Solution: Binary Search. Let P be the minimum capacity. We'll search on max(A_i) to sum(A_i) where i runs from 1 to n. |
| [move](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23022026/move/move.cpp) | `Learn` | Problems/MOVE.jpg, from a teacher of mine | Solved | Given an undirected graph with n (n <= 200) vertices, each node has a temperature t_i.<br>Find a path from A to B that the maximum difference of temperature between two vertices is minimized.<br>Output -1 if no path from A to B.<br>Solution: Djikstra Algorithm. |
| [mtwalk](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23022026/mtwalk/mtwalk.cpp) | `Learn` | Problems/MTWALK.jpg, from a teacher of mine | Solved | Given a N x N grid, find a 4 directional path from (1, 1) to (N, N) that minimizes<br>the difference between the value of the largest and smallest cell on the path.<br>Solution: Binary search the difference, use BFS to check if there exists a path with such difference or less. |
| [sequences](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23022026/sequences/sequences.cpp) | `Learn` | Problems/SEQUENCES.jpg, from a teacher of mine | Solved | Given N positive intergers, find the longest W-sequence<br>W-sequence:<br>- A sequence of odd length<br>- The first (length + 1) / 2 elements are strictly increasing<br>- The last (length + 1) / 2 elements are strictly decreasing<br>Solution: do LIS from 1 to n and LDS from n to 1.<br>let l[i] = the length of the longest strictly increasing subsequence that ends at i<br>let r[i] = the length of the longest strictly decreasing subsequence that starts at i |
| [chondo](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23032026/chondo/chondo.cpp) | `Learn` | Problems/solved/chondo.jpg, from a teacher of mine. | Solved | Just a classic 0/1 Knapsack problem. |
| [daycs](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23032026/daycs/daycs.cpp) | `Learn` | Problems/solved/daycs.jpg, from a teacher of mine | Solved | find the shortest common substring of A and B that occurs exactly once in each string.<br>Solution: String hashing and O(N^2).<br>String hashing: counting and quick comparison. |
| [muanha](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/23032026/muanha/muanha.cpp) | `Learn` | Problems/solved/muanha.jpg, from a teacher of mine | Solved | Given an array of n positive intergers and a parameter k = 0 or k = 1.<br>Form a subset sum by choosing a combination of any elements.<br>Count the subset with the most amount of elements, sum must be prime.<br>if k = 1 you can remove on element from the original array, so you don't have to count it.<br>Solution: precompute all values of primes, then use bitset to perform a knapsack. |
| [abinlis](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/30032026/abinlis/abinlis.cpp) | `Learn` | Problems/solved/abinlis.jpg, from a teacher of mine. | Solved | Find the longest common non decreasing subsequence of two array A and B.<br>Solution: we can test every possible amount of 0s from 1 to min(zero in A, zero in B),<br>the rest is determined by (1 to the right of i in A, 1 to the right of i in B).<br>We can precompute the suffix sum of 1s to get the answer in O(1) time. The complexity is O(n + m). |
| [captoc](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/30032026/captoc/captoc.cpp) | `Learn` | Problems/solved/captoc.jpg | Solved | You have to distribute X days of studying across N subjects to maximize your score.<br>A matrix A_ij is given where A_ij is the score you get it you spend j days to study subject i.<br>Solution: A Bounded knapsack problem<br>For every subject:<br>For every possible number of days to study:<br>For every possible number of days to study the previous subjects:<br>Update the maximum score.<br>Time complexity: O(N.X^2) |
| [bai1](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/BT_06042026/bai1/bai1.cpp) | `Learn` | Problems/solved/bai1.jpg | Solved | an array A is an infinite array which follows the following rule:<br>Pick 1 number that is divisibe by 1<br>Then two next numbers that is divisible by 2<br>Then for each number i, pick the next first i numbers that is divisible by i<br>Find the n-th number in the array A.<br>Solution: just compute it, since it's not that slow.<br>Time complexity: O(n). |
| [bai2](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/BT_06042026/bai2/bai2.cpp) | `Learn` | Problems/solved/bai2.jpg | Solved | you have M candies and N people.<br>Distribute the candies so that every has at least one candy, the amount of candies a person have is distinct,<br>the difference between the one with most candy and the one with least is minimize<br>Solution: The minimum amount of candies to distribute is 1 + 2 + ... + N = N * (N + 1) / 2 (*),<br>if M < N * (N + 1) / 2 then the answer is -1<br>If cannot written in (*) form, the remaining is distributed to the last person.<br>Time complexity: O(1). |
| [bonus](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/BT_06042026/bonus/bonus.cpp) | `Learn` | Problems/solved/bonus.jpg | Solved | Whenever the amount of sold tickets is not divisble by any number in the range [2; 10],<br>each employee will receive a bonus of 1000 VND.<br>Calculate the amount of bonus each employee recive for N tickets sold.<br>Solution: Not divisible by any number in the range [2; 10] <=> Not divisible by any prime number in the range [2; 10] <=> Not divisible by 2, 3, 5, 7.<br>Use Inclusion-Exclusion Principle to calculate the amount of numbers in the range [1; N] that are not divisible by 2, 3, 5, 7.<br>Time complexity O(1). |
| [computer](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/BT_06042026/computer/computer.cpp) | `Learn` | Problems/solved/computer.jpg | Solved | Match N system units to N monitors. Each can be VGA only, DVI only or both.<br>Find the maximmum number of compatible matchings.<br>Soluton: Greedy. Match VGA to VGA, DVI to DVI, then match the remaining VGA and DVI to the both.<br>Time complexity O(1). |
| [maxprime](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/DE14_09032026/maxprime/maxprime.cpp) | `Learn` | Problems/DE14.pdf | Solved | Given n positive intergers.<br>For each prime factor of every interger, find the maximum exponent among the n integers.<br>Then calculate the product of all prime factors raised to their maximum exponent.<br>Since the answer can be very large, output it modulo 1e9 + 7.<br>Solution: Prime sieve + frequency array  + binary exponentiation.<br>Time complexity:<br>O(n log n) for the sieve, O(n log x) for processing the integers, where x is the maximum integer. |
| [bc](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/DE9_09032026/bc/bc.cpp) | `Learn` | Problems/DE09.pdf | Solved | You are given a tree, and a target that starts moving from vertex 1. If the target reaches a leaf, you lose.<br>You can choose to place a guard at any vertex. A guard can move to an adjacent vertex in one second.<br>You win if you can catch the target before it reaches a leaf. What is the minimum number of guards you need to guarantee a win?<br>Solution: DP on tree<br>We calculate the distance from each vertex to the nearest leaf. And from the root to each vertex.<br>If the distance from the root to a vertex is greater than the distance from that vertex to the nearest leaf,<br>we need to place a guard at that vertex. |
| [dseq](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/DP16032026/dseq/dseq.cpp) | `Learn` | Problems/unsolved/dseq.jpg | Unsolved | - |
| [funbit](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/DP16032026/funbit/funbit.cpp) | `Learn` | Problems/solved/funbit.jpg | Solved | Given N non-negative intergers in the form of K bits.<br>Find the longest contiguous subsequence such that when display all elements<br>int the form of K bits, the nummber of 1s are equal for every bit.<br>Track the running total of 1-bits for each of the K bit positions as you go through the array.<br>Because a valid subarray requires all bit positions to increase by the exact same amount,<br>you can simply record the differences between the running total of the 0-th bit and every other bit at each step;<br>whenever you encounter a pattern of differences you've seen before,<br>the subarray between those two points is perfectly balanced.<br>Time complexity: O(N * K). |
| [cgraph](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/sqrt_decomposition/cgraph/cgraph.cpp) | `Learn` | Problems/unsolved/cgraph.jpg | 80% | Given an undirect graph with n vertices and m edges.<br>Answer Q queries. Each query is a pair of intergers L and R.<br>For each query, count the number of connected components in the graph formed by edges with indices<br>within the range [L, R]. |
| [dtwice](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Learn/sqrt_decomposition/dtwice/dtwice.cpp) | `Learn` | Problems/unsolved/dtwice.jpg | Solved | Given n intergers and m queries.<br>Each query is a pair of intergers u and v.<br>Count the amount of distinct values within the range [u, v] that appears twice. |
| [cpath](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT03022026/cpath/cpath.cpp) | `PTNK` | - | - | - |
| [loco](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT03022026/loco/loco.cpp) | `PTNK` | - | - | - |
| [rootless](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT03032026/rootless/rootless.cpp) | `PTNK` | - | - | - |
| [basestring](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT06042026/basestring/basestring.cpp) | `PTNK` | - | - | - |
| [similarity](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT06042026/similarity/similarity.cpp) | `PTNK` | - | - | - |
| [storage](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT13042026/storage/storage.cpp) | `PTNK` | - | - | - |
| [fib](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT16032026/fib/fib.cpp) | `PTNK` | - | - | - |
| [fib3](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT16032026/fib3/fib3.cpp) | `PTNK` | - | - | - |
| [tourist](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT17032026/tourist/tourist.cpp) | `PTNK` | - | - | - |
| [blackbox](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT23022026/blackbox/blackbox.cpp) | `PTNK` | - | - | - |
| [ances](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT24022026/ances/ances.cpp) | `PTNK` | - | - | - |
| [lca](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT24022026/lca/lca.cpp) | `PTNK` | - | - | - |
| [lca2](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT24022026/lca2/lca2.cpp) | `PTNK` | - | - | - |
| [minmm](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT26022026/minmm/minmm.cpp) | `PTNK` | - | - | - |
| [stringkc](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT26022026/stringkc/stringkc.cpp) | `PTNK` | - | - | - |
| [travel](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT26022026/travel/travel.cpp) | `PTNK` | - | - | - |
| [sborder](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT30032026/sborder/sborder.cpp) | `PTNK` | - | - | - |
| [swindow](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/BT30032026/swindow/swindow.cpp) | `PTNK` | - | - | - |
| [updtree2](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/CDLCA5_24032025/updtree2/updtree2.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_02042026/A/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_02042026/B/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_02042026/C/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_26032026/arithmos/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_26032026/cut_off_Ley/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_26032026/fredfarmland/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_26032026/gold_smth_smth/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Contest_26032026/isolated_island/main.cpp) | `PTNK` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/ConvexHullTrick/KHAITHACCKHOANGSAN/main.cpp) | `PTNK` | ptnkoj, Problems/ktqs.png | Solved | There are n mines indexed from 1 to n.<br>The i-th mine has a quantity of s_i.<br>Problem: Divide these mines into several groups. If a group starts from the l-th mine and ends at the r-th mine,<br>the total quantity of this group is S = sum(s_i) for i in [l, r].<br>The output is calculated using the formula: a.S^2 + b.S + c,<br>a, b, care constants given in the input.<br>let dp[i] be the maximum output for the first i mines,<br>we can either: starts a new group, or add the i-th mine to the previous group.<br>Then dp[i] = dp[j] + a(S_i - S_j)^2 + b(S_i - S_j) + c, for all j < i and i in range [1, n].<br>Then, dp[i] will be a.S_i^2 + 2.a.S_i.S_j + a.S_j^2 + b.S_i - b.S_j + c + dp[j].<br>We have a constant: a.S_i^2 + b.S_i + c.<br>The remaining part is a linear function of S_i: (2.a.S_j).S_i + (a.S_j^2 - b.S_j + dp[j]).<br>We see that the slope is 2.a.S_j, b is a.S_j^2 - b.S_j + dp[j].<br>We can use a convex hull trick and a deque to maintain the lines and query the maximum value for each S_i.<br>Time complexity: O(n) |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/ConvexHullTrick/MO_QUA/main.cpp) | `PTNK` | ptnkoj, Problems/moqua.png | Solved | There are n gifts, indexed 1 to n, the i-th gift has a weight w_i.<br>You can open multiple gifts at the same time, but if you open gifts in a range [l, r],<br>the cost will be (sum(w_i) for i in range [l, r])^2 + C,<br>where C is a constant given in the input.<br>Minimize the cost.<br>Solution:<br>let dp[i] be the minimum cost to open the first i gifts,<br>we can either: open the i-th gift alone, or open it together with the previous gifts.<br>we will now denote w_i as the sum of the first i weights.<br>Then dp[i] = min(dp[j] + (w_i - w_j)^2 + C) for all j < i and i in range [1, n].<br>Then, dp[i] will be w_i^2 + C - 2.w_i.w_j + w_j^2 + dp[j].<br>We have a constant: w_i^2 + C.<br>The remaining part is a linear function of w_i: (-2.w_j).w_i + (w_j^2 + dp[j]).<br>We see that the slope is -2.w_j, b is w_j^2 + dp[j].<br>We can use a convex hull trick and a deque to maintain the lines and query the minimum value |
| [pier](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KT23032026/pier/pier.cpp) | `PTNK` | - | - | - |
| [tsp](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KT23032026/tsp/tsp.cpp) | `PTNK` | - | - | - |
| [kdiff](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/done/kdiff.cpp) | `PTNK` | - | - | - |
| [maxdis](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/done/maxdis.cpp) | `PTNK` | - | - | - |
| [rtower](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/done/rtower.cpp) | `PTNK` | - | - | - |
| [subp](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/done/subp.cpp) | `PTNK` | - | - | - |
| [dtrain](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/dtrain/dtrain.cpp) | `PTNK` | - | - | - |
| [hattrick](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/hattrick/hattrick.cpp) | `PTNK` | - | - | - |
| [kdiff](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/kdiff/kdiff.cpp) | `PTNK` | - | - | - |
| [maxdis](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/maxdis/maxdis.cpp) | `PTNK` | - | - | - |
| [mpd](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/mpd/mpd.cpp) | `PTNK` | - | - | - |
| [rtower](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/rtower/rtower.cpp) | `PTNK` | - | - | - |
| [subp](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/PTNK/Tests/KTRADAUVAO31032026/subp/subp.cpp) | `PTNK` | - | - | - |
| [bai1](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/30_4_OLP_TDN/bai1/bai1.cpp) | `Train` | - | - | - |
| [bai2](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/30_4_OLP_TDN/bai2/bai2.cpp) | `Train` | - | - | - |
| [bai3](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/30_4_OLP_TDN/bai3/bai3.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BFS_DFS_MarisaOJ/bambooforestofthelost/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BFS_DFS_MarisaOJ/bipartite_graph/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BFS_DFS_MarisaOJ/fest1/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BFS_DFS_MarisaOJ/radar/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BFS_DFS_MarisaOJ/tom_n_jerry/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BinSearch/gnimnah_dist/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BinSearch/kthdigit/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/BinSearch/max_mean/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Binominal_Coefficient_MaOJ/BE_2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Binominal_Coefficient_MaOJ/equation/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Bitwise_Operation_MaOJ/bit_op_2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Bitwise_Operation_MaOJ/bit_op_3/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Bitwise_Operation_MaOJ/trickortreat/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DAG_MaOJ/dag/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DAG_MaOJ/longest_path/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DAG_MaOJ/max_path/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DAG_MaOJ/read_order/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/A_ChessFor3/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_AlsoTryMinecraft/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_BasketballTeam_CFBetaRound82_Div1/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_Cormen_CFRound377_Div2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_ImpostOrSus/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_LauraAndOperations/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_MakeItDivBy25/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_NapoleonCake/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_NonSubstrSubseq/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/B_Ugu/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/C_KTree_CFRound247_Div2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/C_NumberOfWays_CfRound266_Div2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/C_RoundTableKnights_Round65_Div2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/C_RudolfNString/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/D_Flowers_CFRound271_Div2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/E_GardenerNTree/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/MochaRedNBlue/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_CF/SantaNCandy_TestingRound13/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/brewing_pot_8/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/buildarray/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/hall/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/knapsack2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/lcs/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/marisa/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/merge_elements/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/palin_query/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_Intro1_MaOJ/rec_cutting/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_VNOI/frog_1/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DP_VNOI/frog_2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/fatalmeal/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/mst2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/mst3/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/parking/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/remedge/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/statement/main.cpp) | `Train` | - | - | - |
| [watering](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/watering/watering.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/DSU_MaOJ/yetanotherproblem/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/buiding_teams/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/highscore/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/monsters/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/roundtrip/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/shortest_routes_1/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Graph_CSES/shortest_routes_2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Hash_StringMatching_MaOJ/CmpString/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Hash_StringMatching_MaOJ/PalindromeSubstr2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Hash_StringMatching_MaOJ/RepeatedString/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Hash_StringMatching_MaOJ/StringCombo/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Hash_StringMatching_MaOJ/stringoccur2/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/STL_MaOJ/alotofqueries/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/STL_MaOJ/median/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/STL_MaOJ/mostfrequent/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/STL_MaOJ/set/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/apple_picking/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/div_by_3/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/greatest_subarr_sum/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/inversions/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/k_query/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/kss/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/mushroom_harvest/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/non_neg_subarr/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/ST_BIT_MaOJ/within_1/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/SparseTable_MaOJ/minimum_query/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Sqrt_Dcmp_MaOJ/nearest_vertex/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Trie_MaOJ/Compare_String/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/Trie_MaOJ/Prefix/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/bitmask_dp_MarisaOJ/bin_board/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/bitmask_dp_MarisaOJ/travel_salesman/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/euler_tour_MaOJ/ancestor/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/euler_tour_MaOJ/shallow/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/euler_tour_MaOJ/subtree_del/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/euler_tour_MaOJ/subtree_upd/main.cpp) | `Train` | - | - | - |
| [main](https://github.com/DuyMinh0102/DuyMinh0102/blob/main/Competitive_Programming/Train/pref_sum_MaOJ/ratio_subtr/main.cpp) | `Train` | - | - | - |

[//]: # (END_TABLE)

---
*Last updated by GitHub Actions bot.*
