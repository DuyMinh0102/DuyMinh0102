import random as rd
import matplotlib.pyplot as plt
import numpy as np

epsilon, alpha, beta = 1e-7, 0.01, 0.9

thetas = [rd.uniform(-6, 6) for _ in range(5)]
velocities = [0, 0, 0, 0, 0]
colors = ['ro', 'go', 'bo', 'mo', 'co']

def J(x):
    return 0.1 * x**2 + np.cos(np.pi * x)

def J_derv(x):
    return 0.2 * x - np.pi * np.sin(np.pi * x)

plt.ion()
fig, ax = plt.subplots(figsize=(10, 6))

x_vals = np.linspace(-6, 6, 400)
ax.plot(x_vals, J(x_vals), 'k-', alpha=0.6)

points = []
for i in range(5):
    p, = ax.plot([thetas[i]], [J(thetas[i])], colors[i], markersize=8, label=f'Start {i+1}: {thetas[i]:.2f}')
    points.append(p)

ax.set_title('Optimization on a Function with 6 Minima')
ax.set_xlabel('x')
ax.set_ylabel('J(x)')
ax.legend()
ax.grid(True)

active_indices = [0, 1, 2, 3, 4]

while active_indices:
    for i in active_indices[:]:
        derv = J_derv(thetas[i])
        velocities[i] = alpha * derv + beta * velocities[i]
        thetas[i] = thetas[i] - velocities[i]
        
        points[i].set_xdata([thetas[i]])
        points[i].set_ydata([J(thetas[i])])
        
        if abs(velocities[i]) < epsilon:
            active_indices.remove(i)
            
    plt.draw()
    plt.pause(0.1)

plt.ioff()
plt.show()

print("\nFinal Results:")
for i, t in enumerate(thetas):
    print(f"Point {i+1} stopped at theta: {t:.4f} | J(theta) height: {J(t):.4f}")