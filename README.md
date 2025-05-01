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
Dynamic Programming (DP)
Dynamic Programming solves problems by breaking them into overlapping subproblems and storing results.

🔹 Multi-Stage Graph Problem (MGP.cpp)
Solves shortest path problems in a multi-stage graph.
Time Complexity : O(V+E)
🔹 All Pairs Shortest Path (Floyd-Warshall) (allPairdp.cpp)
Finds shortest paths between all pairs of nodes.
O(n³) complexity, useful for dense graphs.
🔹 0/1 Knapsack using Set (knapsack_set.cpp)
Solves the 0/1 Knapsack problem using a set to efficiently track possible states.
Improves over traditional DP by reducing unnecessary state transitions.
Time Complexity: O(n × maxWeight)
Space Complexity: Optimized using Set Data Structure.
Used in optimization problems where space constraints are crucial.
🔹 Travelling Salesman Problem (TSP) (tsp_dp.cpp)
Solves the TSP using Dynamic Programming and Bitmasking.
Finds the shortest possible route that visits each city exactly once and returns to the origin.
Time Complexity: O(n² × 2ⁿ)
Space Complexity: O(n × 2ⁿ)
Used in logistics, delivery services, and routing optimization.
🔹 Matrix Chain Multiplication (matrixchain.cpp)
Finds the most efficient way to multiply a given sequence of matrices by selecting the best parenthesization.

Problem: Order of multiplication affects the total number of scalar multiplications.

Goal: Minimize the total number of multiplications needed.

-Approach:

Use a DP table where dp[i][j] represents the minimum number of multiplications needed to compute the matrix chain from matrix i to j.
dp[i][j] = min(dp[i][k] + dp[k+1][j] + (cost of multiplying resulting matrices))
for all k between i and j -Time Complexity: O(n³), where n is the number of matrices.
-Space Complexity: O(n²) (to store intermediate results).

-Applications:

Used in database query optimization.

Used in compiler design for code optimization.

image

Backtracking
Backtracking is a powerful algorithmic paradigm used to solve problems by exploring all possible solutions. It works by building solutions incrementally and abandoning a solution as soon as it is determined that it cannot be completed to a valid solution. This makes backtracking a more efficient way of solving problems than brute-force.

Characteristics of Backtracking:
Recursive Structure: Backtracking problems are typically solved recursively.
Pruning: Infeasible solutions are discarded early, reducing the search space.
Choice Tree: Backtracking problems can be represented as a decision tree where each branch corresponds to a decision.
Algorithms Using Backtracking
1. N-Queens Problem
The N-Queens problem involves placing N queens on an N×N chessboard such that no two queens threaten each other. This problem is commonly solved using backtracking, where each queen is placed on the board one by one, and we backtrack when an invalid position is reached.

Time Complexity: Worst-case time complexity for the backtracking solution is O(N!), where N is the number of queens (or the size of the chessboard).
Space Complexity: The space complexity is O(N) because: We need to maintain a list of size N to store the positions of the queens (in a 1D array or list, where each index represents a row and the value at the index represents the column of the queen). Additionally, recursive calls will consume extra space on the call stack, which adds O(N) to the space complexity.
2. 2. Graph Coloring Problem
Graph Coloring is the process of assigning colors to the nodes of a graph such that no two adjacent nodes have the same color. This is a classic backtracking problem used to solve problems like scheduling and register allocation.

Time Complexity: Worst-case time complexity for backtracking-based graph coloring is O(m^n), where: n is the number of vertices in the graph. m is the number of colors available. This is because, in the worst case, for each vertex, you might try all m colors, and you have n vertices to color. Thus, the backtracking search explores all possible color assignments.
Space Complexity: The space complexity is O(n) for storing the color assignments and the graph itself (if represented with an adjacency list or matrix). This includes: O(n) for storing the colors of the vertices. O(n + e) for storing the graph itself, where e is the number of edges. The call stack for the recursive backtracking algorithm also contributes to the space complexity, which would be O(n) in the worst case.
