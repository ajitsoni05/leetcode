<h2><a href="https://leetcode.com/problems/maximum-number-of-matching-indices-after-right-shifts">Maximum Number of Matching Indices After Right Shifts</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given two integer arrays, <code>nums1</code> and <code>nums2</code>, of the same length.</p>

<p>An index <code>i</code> is considered <strong>matching</strong> if <code>nums1[i] == nums2[i]</code>.</p>

<p>Return the <strong>maximum</strong> number of <strong>matching</strong> indices after performing any number of <strong>right shifts</strong> on <code>nums1</code>.</p>

<p>A <strong>right shift</strong> is defined as shifting the element at index <code>i</code> to index <code>(i + 1) % n</code>, for all indices.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [3,1,2,3,1,2], nums2 = [1,2,3,1,2,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">6</span></p>

<p><strong>Explanation:</strong></p>

<p>If we right shift <code>nums1</code> 2 times, it becomes <code>[1, 2, 3, 1, 2, 3]</code>. Every index matches, so the output is 6.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums1 = [1,4,2,5,3,1], nums2 = [2,3,1,2,4,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>If we right shift <code>nums1</code> 3 times, it becomes <code>[5, 3, 1, 1, 4, 2]</code>. Indices 1, 2, and 4 match, so the output is 3.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>nums1.length == nums2.length</code></li>
	<li><code>1 &lt;= nums1.length, nums2.length &lt;= 3000</code></li>
	<li><code>1 &lt;= nums1[i], nums2[i] &lt;= 10<sup>9</sup></code></li>
</ul>
