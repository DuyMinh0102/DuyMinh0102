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

# Logistic Regression

def cost_function(error):
    pred = sigmoid(X_b.dot(theta))
    return -(1/m) * np.sum(y * np.log(pred + 1e-15) + (1-y) * np.log(1-pred + 1e-15))

np.random.seed(42)
X_raw, y_raw = make_classification(n_samples=200, n_features=2, n_redundant=0, n_informative=2, n_clusters_per_class=1, class_sep=1.5)
m = len(y_raw)
X = X_raw
y = y_raw.reshape(-1, 1)

X_b = np.c_[np.ones((m, 1)), X]
theta = np.random.randn(3, 1) 

velocity = np.zeros_like(theta)

cost_logs = []
theta_logs = []
logs_iterations = 0
iterations = 0

while True:
    iterations += 1
    prediction = sigmoid(X_b.dot(theta))

    error = prediction - y
    cost = cost_function(error)
    gradient = calc_gradient(error, X_b)

    velocity = beta * velocity + gradient
    
    old_theta = theta.copy()
    theta = theta - alpha * velocity

    if iterations % 20 == 0:
        cost_logs.append(cost)
        theta_logs.append(theta.copy())
        logs_iterations += 1
        print(f"Vòng lặp {iterations}: Cost = {cost}")
        
    if np.linalg.norm(theta - old_theta) < epsilon or iterations > 10000:
        print(f"Hội tụ tại vòng lặp {iterations}!")
        break

# Visualize
fig, ax = plt.subplots()
ax.scatter(X[y[:,0]==0, 0], X[y[:,0]==0, 1], color='red', label='0')
ax.scatter(X[y[:,0]==1, 0], X[y[:,0]==1, 1], color='blue', label='1')
line, = ax.plot([], [], 'k-', lw=2)
ax.set_xlim(X[:,0].min() - 0.5, X[:,0].max() + 0.5)
ax.set_ylim(X[:,1].min() - 0.5, X[:,1].max() + 0.5)
ax.legend()
plt.close()

def animate_log(i):
    t = theta_logs[i]
    x1_vals = np.array([X[:,0].min(), X[:,0].max()])
    if t[2] != 0:
        x2_vals = -(t[0] + t[1] * x1_vals) / t[2]
        line.set_data(x1_vals, x2_vals)
    return line,

ani_log = FuncAnimation(fig, animate_log, frames=logs_iterations, init_func=init, blit=True)
HTML(ani_log.to_jshtml())
