We define $h(x)$ as a function where we put inside of it a vector $x$ and it outputs a singular value $y$.
For this note, $h(x)$ will try to predict the value of a house so:
- $y$: house price
- Vector $x$: contains $x_0, x_1, x_2,...,x_n$ which are the features of the house has (rooms, windows, area of living,...)

So how exactly do we present $h(x)$ inside of our code?
Let's think simply. More features = higher price.
So each feature adds a certain amount to the total price.
Let's call that "certain amount": $\theta$
So, we now have $h(x) = \theta_0 + \theta_1x_1 + \theta_2x_2$
Here $\theta_0$ is the baseline if every other features were nonexistent.

Now we have a cost function $J(\theta)$, the cost function determines how far we are from the actual value.
Or difference between predicted price vs actual price.
We define $J(\theta)$ as:
![[Pasted image 20260603140447.png]]
Here, $h_\theta(x^{(i)})$ is the prediction price of the $i_{th}$ house, $y^{(i)}$ is the actual price of the $i_{th}$ house
But why this particular function?
This is the Ordinary Least Squares (OLS), a statistical method use in linear regression estimate unknown parameters by minimizing the sum of squared differences between predicted and actual values.
In short, a way to determine in total how wrong we are.

Now, to LMS algorithm
We want to choose $\theta$ so it minimizes $J(\theta)$ (make our predictions as close as possible)
We look at gradient descent, which first initializes some $\theta$ value and then continuously update $\theta$ by:
$$\theta_j = \theta_j - \alpha\frac{∂}{∂\theta_j}$$


