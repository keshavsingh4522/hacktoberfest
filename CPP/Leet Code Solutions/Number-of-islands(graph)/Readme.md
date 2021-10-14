<h2>200. Number of Islands</h2><h3>Medium</h3><hr><div><p>Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]

<strong>Output:</strong> 1
<strong>Explanation:</strong> There is one island(i.e one block of connected 1's in the matrix)
["1","1","1","1"," "],
["1","1"," ","1"," "],
["1","1"," "," "," "]

and the rest is water .
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

<strong>Output:</strong> 3
</pre>


<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == grid.length</code></li>
	<li><code>n == grid[i].length</code></li>
	<li><code>1 <= m, n <= 300</code></li>
	<li><code>grid[i][j] is '0' or '1'</code></li>
</ul>
<br/>
<a href="https://leetcode.com/problems/number-of-islands/" >Link to Question</a>
<p>&nbsp;</p>
</div>