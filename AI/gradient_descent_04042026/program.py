import random as rd
import matplotlib.pyplot as plt
import numpy as np

theta = rd.randrange(-20, 20)
alpha, epsilon = 0.01, 0.0001

def J_func(x):
    return float(5*x**2 - 6*x + 7)

def J_derv(x):
    return float((J_func(x + epsilon) - J_func(x)) / epsilon)

history_theta = [theta]
history_y = [J_derv(theta)]
current_theta = theta

while True:
    step_diff = alpha * J_derv(current_theta)
    print(f"Theta: {current_theta:.5f} | Difference: {-step_diff:.5f}")
    
    if abs(J_derv(current_theta)) < epsilon:
        break
        
    current_theta -= step_diff
    history_theta.append(current_theta)
    history_y.append(J_derv(current_theta))

print(f"Final Theta: {current_theta:.5f}")

plt.ion()
fig, ax = plt.subplots(figsize=(8, 6))

x_min, x_max = min(history_theta) - 2, max(history_theta) + 2
x_vals = np.linspace(x_min, x_max, 200)
y_vals = [J_derv(x) for x in x_vals]

ax.plot(x_vals, y_vals, 'b-', label="J'(x) = 2x")
ax.axhline(0, color='black', linewidth=1)
ax.axvline(0, color='black', linewidth=1)
ax.set_title("Gradient Descent on the Derivative")
ax.set_xlabel("Theta")
ax.set_ylabel("J'(Theta)")
ax.legend()

for i in range(len(history_theta)):
    ax.scatter(history_theta[i], history_y[i], color='red', zorder=5)
    plt.draw()
    plt.pause(0.5)

plt.ioff()
plt.show()