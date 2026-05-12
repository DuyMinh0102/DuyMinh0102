Summary:
$N$ balls, indexed $1 \longrightarrow N$. $($$N \leq 10^5$)
The i-th ball has a color $c_i$ and a value $v_i$
You have $Q$ queries, each query give you two numbers $a, b$.
For each of those queries pick a subset of $N$ balls so that you can get the maximum value $S$. $S$ is calculated with these rules:
- If $i$ ball is not 1st ball, same color with $(i - 1)$ ball, 
	- $S$ += $v_i*a$

- Else:
	- S += $v_i * b$

Sub 1: $N \leq 1000, Q \leq 10$
Sub 2: $Q \leq 10$
Sub 3: No restriction

