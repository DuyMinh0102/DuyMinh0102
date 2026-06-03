import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from IPython.display import HTML
from sklearn.datasets import make_classification, make_blobs
plt.rcParams['animation.embed_limit'] = 100.0

def sigmoid(z):
  z = np.clip(z, -500, 500)
  return 1 / (1 + np.exp(-z))

def softmax(z):
  exp_z = np.exp(z - np.max(z, axis=1, keepdims=True))
  return exp_z / np.sum(exp_z, axis=1, keepdims=True)

def calc_gradient(error, X):
  return (1 / m) * X.T.dot(error)

epsilon = 1e-9
beta = 0.9
alpha = 0.05

# Linear Regression

def cost_function(error):
  return (1 / 2*m) * np.sum(error ** 2)

m = 500
X = 4 * np.random.rand(m, 1)
y = 3 * X + 17 + np.random.randn(m, 1) * 2
X_b = np.c_[np.ones((m, 1)), X]
theta = np.random.randn(2, 1)

velocity = np.zeros_like(theta)
cost_logs = []
theta_logs = []
logs_iterations = 0
iterations = 0

while True:
  iterations += 1
  prediction = (X_b.dot(theta))

  error = prediction - y
  cost = cost_function(error)
  gradient = calc_gradient(error, X_b)

  velocity = beta * velocity + gradient

  old_theta = theta.copy()
  theta = theta - alpha * velocity

  if iterations % 20 == 0:
    print(f"Vòng lặp {iterations}: Cost = {cost:}")
    cost_logs.append(cost)
    theta_logs.append(theta)
    logs_iterations += 1
      
  if (np.linalg.norm(theta - old_theta) < epsilon):
    break; 

print("Tổng số vòng lặp: ", iterations)

fig, ax = plt.subplots()
ax.scatter(X, y, color='blue', marker='.')
line, = ax.plot([], [], 'r-', lw=2)
ax.set_xlim(0, 4)
ax.set_ylim(0, 50)

def init():
    line.set_data([], [])
    return line,

def animate(i):
    theta_i = theta_logs[i]
    y_pred_line = X_b.dot(theta_i)
    line.set_data(X, y_pred_line)
    return line,

ani = FuncAnimation(fig, animate, frames=logs_iterations, init_func=init, blit=True)
HTML(ani.to_jshtml())
