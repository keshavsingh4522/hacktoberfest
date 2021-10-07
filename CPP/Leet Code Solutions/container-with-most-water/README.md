<h2>11. Container With Most Water</h2><h3>Medium</h3><hr>
<div><p>Given <code>n</code> non-negative integers <code>a1, a2, ..., an</code> , where each represents a point at coordinate <code>(i, ai)</code>. <code>n</code> vertical lines are drawn such that the two endpoints of the line <code>i</code> is at <code>(i, ai)</code> and <code>(i, 0)</code>. Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.<br>
<strong>Notice</strong> that you may not slant the container.

<p>&nbsp;</p>

<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>  height = [1,8,6,2,5,4,8,3,7]
<strong>Output:</strong> 49
<strong>Explanation:</strong> The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
</pre>
<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> height = [1,1]
<strong>Output:</strong> 1
</pre>

<p><strong>Example 3:</strong></p>
<pre><strong>Input:</strong> height = [4,3,2,1,4]
<strong>Output:</strong> 16
</pre>
<p><strong>Example 4:</strong></p>
<pre><strong>Input:</strong> height = [1,2,1]
<strong>Output:</strong> 2
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == height.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= height[i] &lt;= 10<sup>4</sup></code></li>
</ul>
</div>
