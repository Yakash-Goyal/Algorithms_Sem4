# Analysis and designs of Algorithms

---

## 📌 LAB 1: Peak Finding

### 🔹 1D Peak Finding (Binary Search Approach)
**Steps:**
- Select the middle element.
- Check if it’s a peak:
  - A peak is an element greater than or equal to its neighbors.
- If left neighbor is greater → search left subarray.
- Else → search right subarray.

**⏱ Time Complexity:** `O(log n)`

---

### 🔹 2D Peak Finding (Divide and Conquer)
**Steps:**
- Choose middle column and find max in that column.
- Check neighbors (right, left, top, bottom):
  - If neighbor is greater → move in that direction recursively.
- Stop when current element is larger than all neighbors.

**⏱ Time Complexity:** `O(n log m)` for `n x m` matrix

---

## 📌 LAB 2: Sorting Algorithms

### 🔹 Merge Sort
**Divide and Conquer Strategy:**
- Divide array into halves recursively.
- Merge sorted halves by comparing elements.

**⏱ Time Complexity:** `O(n log n)` in all cases

---

### 🔹 Quick Sort
**Steps:**
- Select pivot.
- Partition elements into two parts.
- Recursively sort both partitions.

**⏱ Time Complexity:**
- Best: `O(n log n)`
- Average: `O(n log n)`
- Worst: `O(n²)`

---

### 🔹 Iterative Quick Sort
**Non-Recursive Method:**
- Use stack to mimic recursion.
- Partition and push subarray indices onto the stack.

**⏱ Time Complexity:** Same as recursive version

---

### 🔹 Odd-Order Magic Square (Siamese Method)
**Steps:**
- Start in middle of first row.
- Move up-right to place numbers.
- If cell is occupied or out-of-bounds, move down.

**⏱ Time Complexity:** `O(n²)`

---

### 🔹 Fractional Knapsack
**Steps:**
- Compute value-to-weight ratio.
- Sort items by ratio.
- Take items fully or partially until the knapsack is full.

**⏱ Time Complexity:** `O(n log n)`

---

## 📌 LAB 3: Convex Hull (Quick Hull)

**Steps:**
- Find leftmost and rightmost points.
- Recursively find farthest points from current line segment.
- Continue until all outermost points are included.

**⏱ Time Complexity:**
- Average: `O(n log n)`
- Worst: `O(n²)`

---

## 📌 LAB 4: Dijkstra's Algorithm

**Steps:**
- Initialize distance from source to all vertices as infinite.
- Use a `near[]` array to track shortest known distance.
- In each step, pick vertex with minimum distance and update neighbors.

**⏱ Time Complexity:** `O(V²)` with adjacency matrix

---

## 📌 LAB 5: Minimum Spanning Tree (MST)

### 🔹 Prim’s Algorithm
**Steps:**
- Start with an arbitrary vertex.
- Always choose the lowest weight edge connecting MST to new vertex.
- Repeat until all vertices are included.

**⏱ Time Complexity:** `O(V²)`

---

### 🔹 Kruskal’s Algorithm
**Steps:**
- Sort edges by weight.
- Use Union-Find (DSU) to avoid cycles.
- Add edge if it doesn’t form a cycle.

**⏱ Time Complexity:** `O(E log E)`

---
