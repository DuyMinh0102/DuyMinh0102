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

# Softmax Regression

epsilon = 1e-9
beta = 0.9
alpha = 0.05

np.random.seed(42)
layer = 3
X_raw, y_raw = make_blobs(n_samples=300, centers=layer, n_features=2, cluster_std=1.0)
m = len(y_raw)
X = X_raw
Y_onehot = np.eye(layer)[y_raw] 
X_b = np.c_[np.ones((m, 1)), X]

theta = np.random.randn(3, layer) 
velocity = np.zeros_like(theta)
iterations = 0
theta_logs = []

while True:
    iterations += 1
    scores = X_b.dot(theta)
    prediction = softmax(scores) 
    
    error = prediction - Y_onehot
    gradient = calc_gradient(error, X_b)
    
    velocity = beta * velocity + gradient
    
    old_theta = theta.copy()
    theta = theta - alpha * velocity

    if iterations % 50 == 0:
        print(f"Đang chạy vòng lặp {iterations}...")
        theta_logs.append(theta.copy())

    if np.linalg.norm(theta - old_theta) < epsilon or iterations > 10000:
        print(f"Hội tụ tại vòng lặp {iterations}!")
        break

x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.05),
                     np.arange(y_min, y_max, 0.05))

grid_points = np.c_[xx.ravel(), yy.ravel()]
grid_points_b = np.c_[np.ones((len(grid_points), 1)), grid_points]

fig, ax = plt.subplots(figsize=(8, 6))
plt.close() 

def animate_soft(i):
    ax.clear()
    
    theta_i = theta_logs[i]
    grid_scores = grid_points_b.dot(theta_i)
    grid_preds = np.argmax(softmax(grid_scores), axis=1).reshape(xx.shape)
    
    ax.contourf(xx, yy, grid_preds, alpha=0.4, cmap=plt.cm.coolwarm)

    ax.scatter(X[:, 0], X[:, 1], c=y_raw, edgecolors='k', cmap=plt.cm.coolwarm)
    
    ax.set_title(f"Softmax Regression - Vòng lặp {i+1}/{len(theta_logs)}")
    ax.set_xlabel("Feature 1")
    ax.set_ylabel("Feature 2")

ani_soft = FuncAnimation(fig, animate_soft, frames=50, interval=150, blit=False)

HTML(ani_soft.to_jshtml())
