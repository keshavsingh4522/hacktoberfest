# Essential Competitive Programming Algorithms

## Graph Algorithms
- **Breadth First Search (BFS)** - Level-by-level graph traversal
- **Depth First Search (DFS)** - Depth-wise graph exploration  
- **Dijkstra's Algorithm** - Shortest path algorithm for non-negative weights
- **Bellman-Ford Algorithm** - Shortest path with negative weights detection
- **Floyd-Warshall Algorithm** - All-pairs shortest paths
- **Kruskal's Algorithm** - Minimum spanning tree using edge sorting
- **Prim's Algorithm** - Minimum spanning tree using vertex growth
- **Topological Sorting** - Linear ordering of DAG vertices
- **Tarjan's Algorithm** - Strongly connected components detection
- **Kosaraju's Algorithm** - Alternative SCC algorithm
- **Articulation Points and Bridges** - Critical network components
- **Euler Path and Circuit** - Graph traversal visiting each edge once
- **Hamiltonian Path and Cycle** - Graph traversal visiting each vertex once
- **Johnson's Algorithm** - All-pairs shortest paths for sparse graphs

## Dynamic Programming
- **Longest Common Subsequence (LCS)** - Finding common subsequences
- **Longest Increasing Subsequence (LIS)** - Finding increasing patterns
- **Edit Distance** - String transformation operations
- **Coin Change Problem** - Optimal change making
- **0-1 Knapsack** - Binary item selection optimization
- **Unbounded Knapsack** - Unlimited item selection
- **Matrix Chain Multiplication** - Optimal matrix parenthesization
- **Subset Sum Problem** - Target sum subset detection
- **Rod Cutting Problem** - Optimal cutting strategy
- **Egg Dropping Puzzle** - Minimum trials optimization
- **Optimal Binary Search Tree** - Search cost minimization
- **Partition Problem** - Equal sum subset division
- **Maximum Subarray Sum (Kadane's Algorithm)** - Contiguous subarray optimization
- **Bitmask DP** - State compression using bits

## Searching and Sorting
- **Binary Search** - Efficient searching in sorted arrays
  - Lower bound and upper bound variations
- **Ternary Search** - Unimodal function optimization
- **Quick Sort** - Divide-and-conquer sorting
- **Merge Sort** - Stable divide-and-conquer sorting
- **Counting Sort** - Non-comparison integer sorting
- **Radix Sort** - Digit-by-digit sorting
- **Heap Sort** - Heap-based sorting algorithm
- **Order Statistics** - Finding kth smallest/largest element

## String Algorithms
- **Knuth-Morris-Pratt (KMP)** - Efficient pattern matching
- **Rabin-Karp Algorithm** - Rolling hash pattern matching
- **Z Algorithm** - String matching with Z-array
- **Aho-Corasick** - Multiple pattern matching
- **Suffix Arrays and Suffix Trees** - Suffix-based string processing
- **Manacher's Algorithm** - Longest palindromic substring
- **Trie (Prefix Tree)** - Prefix-based string storage
- **Rolling Hash** - Hash-based string comparison
- **Longest Palindromic Subsequence** - Palindrome optimization

## Number Theory and Mathematics
- **Euclidean Algorithm** - Greatest Common Divisor computation
- **Extended Euclidean Algorithm** - GCD with linear combination
- **Sieve of Eratosthenes** - Prime number generation
- **Segmented Sieve** - Range-based prime finding
- **Modular Arithmetic** - Operations under modulo
- **Modular Exponentiation** - Efficient power computation
- **Modular Multiplicative Inverse** - Inverse element finding
- **Chinese Remainder Theorem** - System of congruences solving
- **Prime Factorization** - Breaking numbers into prime factors
- **Euler's Totient Function** - Coprime counting function
- **Fast Exponentiation** - Binary exponentiation technique
- **Combinatorics** - nCr and nPr calculations
- **Catalan Numbers** - Special counting sequences

## Advanced Data Structures
- **Segment Tree** - Range query and update structure (with lazy propagation)
- **Fenwick Tree (Binary Indexed Tree)** - Efficient prefix sum queries
- **Disjoint Set Union (Union-Find)** - Set operations with path compression and union by rank
- **Trie** - Prefix tree for string operations
- **Sparse Table** - Static range minimum query
- **Square Root Decomposition** - Block-based query optimization
- **Policy-Based Data Structures (PBDS)** - Extended STL containers
- **K-D Trees** - Multi-dimensional space partitioning
- **Interval Trees** - Interval overlap queries
- **Persistent Data Structures** - Version-preserving structures

## Greedy Algorithms
- **Activity Selection Problem** - Non-overlapping activity scheduling
- **Huffman Coding** - Optimal prefix-free encoding
- **Job Sequencing Problem** - Deadline-based job scheduling
- **Fractional Knapsack** - Continuous item selection
- **Minimum Number of Coins** - Coin change optimization
- **Optimal Merge Patterns** - Minimum cost merging

## Backtracking
- **N-Queens Problem** - Non-attacking queen placement
- **Sudoku Solver** - Constraint satisfaction puzzle
- **Rat in a Maze** - Path finding with obstacles
- **Subset Sum using Backtracking** - Exhaustive subset search
- **Graph Coloring (m-coloring)** - Vertex coloring problem
- **Generating Permutations/Combinations** - Systematic enumeration

## Computational Geometry
- **Convex Hull** - Smallest enclosing convex polygon
  - Graham Scan and Jarvis March algorithms
- **Line Intersection** - Geometric line segment intersection
- **Point in Polygon Test** - Spatial containment checking
- **Closest Pair of Points** - Minimum distance point pair
- **Sweep Line Algorithm** - Event-driven geometric processing
- **Rotating Calipers** - Diameter and width computation

## Network Flow and Matching
- **Ford-Fulkerson Algorithm** - Maximum flow computation
- **Edmonds-Karp Algorithm** - BFS-based max flow
- **Dinic's Algorithm** - Level graph max flow
- **Maximum Bipartite Matching** - Optimal pairing in bipartite graphs
- **Hungarian Algorithm** - Assignment problem solver
- **Minimum Cut** - Network bottleneck identification
- **Max Flow Min Cut Theorem** - Flow-cut duality

## Game Theory
- **Nim Game** - Mathematical strategy game
- **Sprague-Grundy Theorem** - Impartial game theory
- **Minimax Algorithm** - Optimal play in zero-sum games
- **Optimal Game Strategies** - Strategic decision making

## Advanced Techniques
- **Two Pointers Technique** - Efficient array/string processing
- **Sliding Window** - Range-based optimization
- **Binary Search on Answer** - Solution space binary search
- **Meet in the Middle** - Exponential complexity reduction
- **Divide and Conquer** - Problem decomposition strategy
- **Bit Manipulation Tricks** - Efficient bitwise operations
- **Matrix Exponentiation** - Fast recurrence relation solving
- **Mo's Algorithm** - Query optimization technique

---

**Note:** Mastering these algorithms progressively from basic to advanced will significantly improve performance in competitive programming contests like Codeforces, ICPC, and coding interviews.

# Detailed Algorithm Explanations

## Graph Algorithms

### Breadth First Search (BFS)
BFS traverses a graph level by level using a FIFO queue, exploring all vertices at distance k before moving to distance k+1. It's ideal for finding shortest paths in unweighted graphs and minimum-hop paths. Starting from a source vertex, it marks it as visited, enqueues it, then repeatedly dequeues vertices and explores their unvisited neighbors. 
- **Time complexity:** O(V+E), where V is vertices and E is edges
### Depth First Search (DFS)
DFS explores graphs depth-wise using a LIFO stack (or recursion), going as deep as possible before backtracking. It's used for cycle detection, topological sorting, strongly connected components, and connectivity testing. The algorithm marks vertices as visited and recursively explores unvisited neighbors. 
- **Time complexity:** O(V+E)

### Dijkstra's Algorithm
Dijkstra's finds the shortest path from a source to all vertices in graphs with non-negative edge weights. It uses a priority queue (min-heap) to greedily select the unvisited vertex with the smallest distance, then relaxes all its edges. The algorithm maintains a distance array initialized to infinity (except source at 0) and updates distances when shorter paths are found. 
- **Time complexity:** O((V+E)log V) with a binary heap

### Bellman-Ford Algorithm
Bellman-Ford computes shortest paths from a single source and can handle negative edge weights. Unlike Dijkstra's, it can detect negative weight cycles. The algorithm performs V-1 iterations, relaxing all edges in each iteration. If distances can still be reduced after V-1 iterations, a negative cycle exists. 
- **Time complexity:** O(VE)

### Floyd-Warshall Algorithm
Floyd-Warshall finds shortest paths between all pairs of vertices. It uses dynamic programming with three nested loops, considering each vertex as an intermediate point. The algorithm updates distances: `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])` for all vertex pairs. It works with negative edges but not negative cycles. 
- **Time complexity:** O(V³)

### Kruskal's Algorithm
Kruskal's finds the Minimum Spanning Tree (MST) by sorting edges by weight and greedily adding edges that don't create cycles. It uses Union-Find (DSU) to efficiently detect cycles. The algorithm starts with each vertex as a separate component and merges components via edges in increasing weight order until V-1 edges are added. 
- **Time complexity:** O(E log E)
Prim's Algorithm
Prim's builds an MST by starting from a single vertex and growing the tree by adding the minimum-weight edge connecting a vertex in the tree to one outside. It uses a priority queue to efficiently select the next edge. The algorithm maintains a set of visited vertices and repeatedly adds the cheapest edge crossing the cut. Time complexity is O(Elog⁡V) with a binary heap.[9][1]
Topological Sorting
Topological sorting produces a linear ordering of vertices in a Directed Acyclic Graph (DAG) where for every edge (u,v), u comes before v. It's used for dependency resolution, task scheduling, and course prerequisites. The algorithm uses DFS, pushing vertices onto a stack after exploring all descendants, then reversing the stack. Time complexity is O(V+E).[10][1]
Tarjan's Algorithm for SCC
Tarjan's finds Strongly Connected Components in one DFS traversal. It maintains discovery indices and low-link values for each vertex, where low-link is the minimum discovery index reachable from that vertex. A vertex is an SCC head if disc[u] = low[u]. The algorithm uses a stack to track the current path and identifies SCCs when backtracking. Time complexity is O(V+E).[11][12][1]
Kosaraju's Algorithm
Kosaraju's finds SCCs using two DFS passes. First DFS records finish times, then it performs DFS on the transpose graph in decreasing finish time order. Each DFS tree in the second pass represents an SCC. Time complexity is O(V+E).[12][13]
Articulation Points and Bridges
Articulation points are vertices whose removal increases the number of connected components. Bridges are edges whose removal disconnects the graph. Both use DFS with discovery and low values, identifying critical structures in network reliability analysis.[1][12]
Johnson's Algorithm
Johnson's algorithm finds all-pairs shortest paths in sparse graphs with negative edges (but no negative cycles) more efficiently than Floyd-Warshall. It reweights edges to make them non-negative, then runs Dijkstra from each vertex. Time complexity is O(V^2 log⁡V+VE).[7][1]
Dynamic Programming
Longest Common Subsequence (LCS)
LCS finds the longest subsequence common to two sequences. Using a 2D DP table, dp[i][j] represents LCS length of first i characters of s1 and first j characters of s2. If characters match: dp[i][j] = dp[i-1][j-1] + 1, otherwise: dp[i][j] = max(dp[i-1][j], dp[i][j-1]). It's equivalent to minimum edit distance with insert/delete operations. Time complexity is O(mn).[14][15][1]
Longest Increasing Subsequence (LIS)
LIS finds the longest strictly increasing subsequence in an array. The naive DP approach is O(n^2), but using binary search optimization achieves O(nlog⁡n). The optimized version maintains an array where each position stores the smallest tail element of increasing subsequences of that length. For each element, binary search finds where it fits and updates the array.[16][1]
Edit Distance
Edit distance (Levenshtein distance) measures the minimum operations to transform one string into another using insertions, deletions, and substitutions. DP table dp[i][j] represents edit distance between first i and j characters. Recurrence: if characters match, dp[i][j] = dp[i-1][j-1]; otherwise, dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]). Time complexity is O(mn).[14][1]
0-1 Knapsack
0-1 Knapsack maximizes value of items selected with a weight constraint, where each item can be taken at most once. DP table dp[i][w] represents maximum value using first i items with capacity w. Recurrence: dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w-wt[i]]) if wt[i] ≤ w. Time complexity is O(nW) where W is capacity.[1][14]
Subset Sum Problem
Subset Sum determines if a subset exists with a given sum. DP table dp[i][j] indicates if sum j is achievable using first i elements. It's similar to 0-1 Knapsack with binary (true/false) values. Time complexity is O(n×sum).[17][1]
Matrix Chain Multiplication
Matrix Chain Multiplication finds the optimal parenthesization to minimize scalar multiplications when multiplying a chain of matrices. DP table dp[i][j] stores minimum operations to multiply matrices from i to j. Time complexity is O(n^3).[18][1]
Kadane's Algorithm
Kadane's finds the maximum sum contiguous subarray in linear time. It maintains current_sum = max(element, current_sum + element) and tracks the global maximum. This greedy-DP hybrid algorithm has time complexity O(n).[1]
Bitmask DP
Bitmask DP uses binary representations of subsets for problems involving sets or states. Each bit in an integer represents inclusion/exclusion of an element. It's used for Traveling Salesman Problem, Hamiltonian paths, and assignment problems. Time complexity depends on the state space, typically O(2^n×n).[19][1]
Searching and Sorting
Binary Search
Binary Search finds an element in a sorted array by repeatedly dividing the search interval in half. If target equals middle element, return; if target is less, search left half; otherwise search right half. Variations include lower_bound (first element ≥ target) and upper_bound (first element > target). Time complexity is O(log⁡n).[20][1]
Ternary Search
Ternary Search finds the maximum or minimum of unimodal functions by dividing the search space into three parts. It compares function values at two points and eliminates one-third of the search space. Time complexity is O(log⁡n).[1]
Quick Sort
Quick Sort is a divide-and-conquer algorithm that selects a pivot, partitions the array around it, then recursively sorts partitions. Average time complexity is O(nlog⁡n), worst case is O(n^2).[1]
Merge Sort
Merge Sort divides the array into halves, recursively sorts them, then merges sorted halves. It's stable with guaranteed O(nlog⁡n) time complexity.[1]
Counting Sort
Counting Sort is a non-comparison-based sorting algorithm for integers in a known range. It counts occurrences of each element and uses this to place elements in sorted order. Time complexity is O(n+k) where k is the range.[1]
Radix Sort
Radix Sort sorts integers by processing digits from least to most significant using a stable sort (like counting sort) for each digit. Time complexity is O(d(n+k)) where d is digit count.[1]
Order Statistics
Order Statistics finds the kth smallest/largest element without fully sorting. Quickselect algorithm achieves average O(n) time complexity.[21][1]
String Algorithms
Knuth-Morris-Pratt (KMP)
KMP performs pattern matching in O(n+m) time by avoiding re-examination of previously matched characters. It preprocesses the pattern to build a failure function (LPS array) indicating the longest proper prefix which is also a suffix. When a mismatch occurs, the pattern shifts using the failure function instead of starting over.[22][23][1]
Rabin-Karp Algorithm
Rabin-Karp uses rolling hash to find pattern occurrences. It computes hash values for the pattern and text windows, comparing hashes first (fast), then verifying character-by-character on hash matches. The rolling hash enables O(1) updates when sliding the window. Average time complexity is O(n+m), worst case is O(nm).[24][22][1]
Z Algorithm
Z Algorithm computes the Z array where Z[i] is the length of the longest substring starting at i that matches the prefix. It's used for pattern matching and finding all occurrences in O(n+m) time.[22][1]
Aho-Corasick Algorithm
Aho-Corasick efficiently searches for multiple patterns simultaneously in a text. It builds a trie of patterns with failure links for transitions on mismatches and output links for detecting overlapping matches. The algorithm processes text in linear time: O(n+m+z) where z is total occurrences. It's used in spam filtering, intrusion detection, and bioinformatics.[25][26][27][1]
Suffix Array
Suffix arrays store lexicographically sorted suffixes of a string. They enable efficient pattern matching, LCP (Longest Common Prefix) computation, and substring problems. Construction takes O(nlog⁡n) with modern algorithms.[1]
Trie (Prefix Tree)
Trie is a tree structure where each node represents a character, enabling fast prefix queries and autocomplete. Insert, search, and prefix operations take O(m) time where m is string length. Space complexity is O(N×M×C) where N is number of strings, M is max length, C is alphabet size.[28][1]
Manacher's Algorithm
Manacher's finds the longest palindromic substring in linear time. It transforms the string to handle even/odd length palindromes uniformly, then uses previously computed palindrome information to avoid redundant comparisons. Time complexity is O(n).[22][1]
Number Theory and Mathematics
Euclidean Algorithm (GCD)
Euclidean algorithm computes the Greatest Common Divisor using the property gcd(a,b) = gcd(b, a mod b). Base case: gcd(a, 0) = a. Time complexity is O(log⁡min(a,b)).[29][1]
Extended Euclidean Algorithm
Extended Euclidean finds integers x, y such that ax + by = gcd(a,b). It's used for finding modular multiplicative inverses. Time complexity is O(log⁡min(a,b)).[29][1]
Sieve of Eratosthenes
Sieve of Eratosthenes finds all primes up to n by iteratively marking multiples of each prime as composite. Starting from 2, mark all multiples of each prime. Time complexity is O(nlog⁡log⁡n), space complexity is O(n).[30][1]
Segmented Sieve
Segmented Sieve finds primes in a range [L, R] efficiently when R is large but R-L is small. It first finds primes up to √R using standard sieve, then uses them to sieve [L, R]. Time complexity is O((R-L)log⁡log⁡R).[1]
Modular Arithmetic
Modular arithmetic operations include addition, subtraction, multiplication under modulo. Key properties: (a+b) mod m = ((a mod m) + (b mod m)) mod m. Used extensively in competitive programming for handling large numbers.[31][1]
Modular Exponentiation
Modular exponentiation computes a^b  mod  m efficiently using binary exponentiation. It repeatedly squares the base and reduces modulo m, multiplying result when corresponding bit in exponent is 1. Time complexity is O(log⁡b).[31][29][1]
Modular Multiplicative Inverse
Modular inverse of a modulo m is x such that (a×x) mod  m=1. It exists only if gcd(a,m) = 1. Can be computed using Extended Euclidean or Fermat's Little Theorem (when m is prime: a^(m-2)  mod  m). Time complexity is O(log⁡m).[29][31][1]
Chinese Remainder Theorem (CRT)
CRT solves systems of congruences with pairwise coprime moduli. Given x ≡ c₁ (mod n₁), x ≡ c₂ (mod n₂), ..., it finds unique solution modulo N = n₁×n₂×.... Construction involves computing N_i = N/n_i, finding inverse of N_i mod n_i, then x = Σ(c_i × N_i × inverse). Used for computing large modular values.[29][1]
Euler's Totient Function
Euler's Totient φ(n) counts integers in [1, n] coprime to n. For prime p: φ(p) = p-1. For prime power: φ(p^k) = p^k - p^(k-1). Euler's Theorem: if gcd(a,n) = 1, then a^(φ(n))≡1 (mod n). Time complexity to compute is O(√n).[32][33][29][1]
Prime Factorization
Prime factorization decomposes n into prime powers. Trial division checks divisibility by primes up to √n. Time complexity is O(√n).[1]
Catalan Numbers
Catalan numbers appear in counting problems: binary trees, valid parentheses, polygon triangulations. The nth Catalan number is C_n=1/(n+1) (2n¦n)=((2n)!)/((n+1)!n!). Recurrence: C_n=∑_(i=0)^(n-1)▒  C_i C_(n-1-i).[1]
Advanced Data Structures
Segment Tree
Segment Tree supports range queries and updates in O(log⁡n) time. Each node represents an interval and stores aggregate information (sum, min, max). Construction takes O(n), space is O(4n). Lazy propagation optimizes range updates by deferring computations until necessary.[34][28][1]
Fenwick Tree (BIT)
Fenwick Tree (Binary Indexed Tree) efficiently computes prefix sums and point updates in O(log⁡n) time. It uses binary representation for indexing: update adds value to specific indices using i += i & -i, query sums using i -= i & -i. Space complexity is O(n), making it more memory-efficient than Segment Trees. However, it's primarily for prefix sums, while Segment Trees handle arbitrary ranges.[35][34][1]
Disjoint Set Union (DSU)
Union-Find maintains disjoint sets with two operations: find(x) returns set representative, union(x,y) merges sets. Path compression makes find flatten the tree by directly connecting nodes to root. Union by rank attaches smaller tree under larger one. With both optimizations, operations take nearly constant amortized time O(α(n)) where α is inverse Ackermann function. Used for cycle detection, Kruskal's MST, and connectivity queries.[36][37][1]
Sparse Table
Sparse Table answers static range queries (no updates) in O(1) after O(nlog⁡n) preprocessing. It precomputes answers for all ranges of length 2^k using DP. Ideal for Range Minimum/Maximum Query (RMQ).[1]
Policy-Based Data Structures (PBDS)
PBDS in C++ provides ordered sets with additional operations: order_of_key(k) returns count of elements less than k, find_by_order(k) returns kth element. Operations take O(log⁡n) time. Used for counting inversions and dynamic order statistics.[1]
K-D Tree
K-D Tree organizes points in k-dimensional space for efficient nearest neighbor and range search. Each level splits on a different dimension. Average query time is O(log⁡n).[1]
Interval Tree
Interval Tree stores intervals and efficiently finds overlapping intervals with a query interval. Each node stores an interval and maximum endpoint in its subtree. Query time is O(log⁡n+k) where k is matches.[1]
Computational Geometry
Convex Hull
Convex Hull is the smallest convex polygon enclosing all points. Graham Scan sorts points by polar angle from lowest point, then uses a stack to maintain hull vertices by checking cross products for left turns. Time complexity is O(nlog⁡n). Jarvis March wraps around points selecting the most counterclockwise point at each step, with O(nh) complexity where h is hull size.[38][39][40][1]
Line Intersection
Line intersection determines if two line segments intersect using orientation tests via cross products. Checks if endpoints of each segment lie on opposite sides of the other segment. Time complexity is O(1) per pair.[39][1]
Point in Polygon
Point in Polygon tests if a point lies inside a polygon using the ray casting algorithm. Cast a ray from the point and count intersections with polygon edges; odd count means inside. Time complexity is O(n).[1]
Closest Pair of Points
Closest Pair finds the two points with minimum distance in O(nlog⁡n) using divide-and-conquer. Divide points by x-coordinate, recursively solve, then check points near the dividing line.[1]
Sweep Line Algorithm
Sweep Line processes geometric events (points, segments) by sweeping a vertical line across the plane. Maintains active structures at current x-coordinate. Used for line intersection detection and rectangle union area.[1]
Network Flow and Matching
Ford-Fulkerson Algorithm
Ford-Fulkerson computes maximum flow in a flow network by repeatedly finding augmenting paths from source to sink in the residual graph. Each augmenting path increases flow by the minimum capacity along the path. The algorithm updates the residual graph by subtracting flow from forward edges and adding it to reverse edges. Time complexity depends on path-finding method; with arbitrary paths it's O(E×maxFlow).[41][42][43][44][1]
Edmonds-Karp Algorithm
Edmonds-Karp is Ford-Fulkerson using BFS to find shortest augmenting paths. BFS ensures paths have minimum edges, guaranteeing O(VE^2) time complexity. This bound is independent of flow values.[42][45][1]
Dinic's Algorithm
Dinic's improves max flow computation using level graphs and blocking flows. A level graph contains only edges on shortest paths from source. The algorithm finds blocking flows (paths where no additional flow can be pushed) in each level graph iteration. Time complexity is O(V^2 E), better in practice than Edmonds-Karp.[43][46][1]
Maximum Bipartite Matching
Maximum Bipartite Matching finds the largest matching in a bipartite graph. It can be solved by reducing to max flow: add source connected to left vertices, sink connected to right vertices, set all capacities to 1. Time complexity is O(VE) with specialized algorithms.[45][1]
Hungarian Algorithm
Hungarian algorithm solves the assignment problem (minimum weight perfect matching in bipartite graphs). It uses augmenting paths with reduced costs. Time complexity is O(n^3).[1]
Min Cut
Min Cut finds the minimum capacity cut separating source from sink. Max Flow Min Cut Theorem states that maximum flow equals minimum cut capacity. After computing max flow, vertices reachable from source in residual graph form one side of min cut.[45][1]
Game Theory
Nim Game
Nim is a two-player game with piles of stones; players alternate removing stones from a single pile. The player taking the last stone wins. Winning strategy: XOR all pile sizes; if result is 0, current player loses with optimal play, otherwise wins. The XOR is the Grundy number for Nim.[47][48][1]
Sprague-Grundy Theorem
Sprague-Grundy theorem assigns a Grundy number (nimber) to each state in impartial games. Grundy number is the MEX (minimum excludant) of Grundy numbers of reachable states. A state with Grundy number 0 is losing. For combined games, the Grundy number is XOR of individual game Grundy numbers. This reduces any impartial game to an equivalent Nim game.[49][50][48][47][1]
Minimax Algorithm
Minimax is used in zero-sum two-player games to find optimal moves assuming both players play perfectly. It recursively evaluates game tree: maximizing player chooses max child value, minimizing player chooses min child value. Alpha-beta pruning optimizes by eliminating branches that won't affect the final decision. Time complexity is O(b^d) where b is branching factor and d is depth.[1]
Advanced Techniques
Two Pointers Technique
Two Pointers uses two indices traversing a data structure to solve problems efficiently. Same direction: both pointers move forward, useful for subarrays with certain properties (sliding window). Opposite direction: pointers start at ends and move toward center, useful for pair sum in sorted arrays. Time complexity is typically O(n).[51][52][53][54]
Sliding Window
Sliding Window maintains a window over a sequence, expanding/shrinking based on conditions. Used for maximum/minimum subarray problems and substring problems. For fixed-size windows, add new element and remove old element; for variable size, expand until invalid, then shrink until valid. Time complexity is O(n).[55][1]
Binary Search on Answer
Binary search on answer applies binary search on the solution space rather than input array. For optimization problems, binary search on answer value and check feasibility with a decision function. Used for "minimize the maximum" or "maximize the minimum" problems. Time complexity depends on range and decision function.[19][1]
Meet in the Middle
Meet in the Middle divides the search space into two halves, solves each independently, then combines results. It reduces O(2^n) to O(2^(n/2)) by processing each half separately and merging with sorting or hashing. Used for subset sum and 4-sum problems.[51][1]
Divide and Conquer
Divide and Conquer breaks problems into smaller subproblems, solves recursively, then combines solutions. Examples include merge sort, quick sort, binary search, and closest pair. Time complexity often follows T(n)=2T(n/2)+O(n)=O(nlog⁡n).[1]
Bit Manipulation
Bit manipulation uses bitwise operations for efficient computation. Key tricks: check if number is power of 2 with (n & (n-1)) == 0, count set bits with Brian Kernighan's algorithm, iterate subsets of mask with submask = (submask - 1) & mask. XOR properties: x ^ x = 0, x ^ 0 = x, used for finding unique elements.[1]
Matrix Exponentiation
Matrix exponentiation computes M^n in O(log⁡n) using binary exponentiation. Used for solving linear recurrences like Fibonacci in O(log⁡n). Construct transformation matrix T where state vector at step i+1 equals T times state vector at step i, then result is T^n times initial state.[19][1]
Mo's Algorithm
Mo's algorithm answers range queries offline by cleverly ordering queries to minimize pointer movements. Divide array into √n blocks, sort queries by (block number, right endpoint). Process queries in order, adding/removing elements from current range. Time complexity is O((n+q)√n). 

