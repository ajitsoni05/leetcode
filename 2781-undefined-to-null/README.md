<h2><a href="https://leetcode.com/problems/undefined-to-null">Undefined to Null</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given a deeply nested object or array <code>obj</code>, return the object <code>obj</code> with any <code>undefined</code> values replaced by <code>null</code>.</p>

<p><code>undefined</code> values are handled differently than <code>null</code> values when objects are converted to a JSON string using <code>JSON.stringify()</code>. This function helps ensure serialized data is free of unexpected errors.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> obj = {&quot;a&quot;: undefined, &quot;b&quot;: 3}
<strong>Output:</strong> {&quot;a&quot;: null, &quot;b&quot;: 3}
<strong>Explanation:</strong> The value for obj.a has been changed from undefined to null
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> obj = {&quot;a&quot;: undefined, &quot;b&quot;: [&quot;a&quot;, undefined]}
<strong>Output:</strong> {&quot;a&quot;: null,&quot;b&quot;: [&quot;a&quot;, null]}
<strong>Explanation:</strong> The values for obj.a and obj.b[1] have been changed from undefined to null
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>obj</code> is a valid JSON object or array</li>
	<li><code>2 &lt;= JSON.stringify(obj).length &lt;= 10<sup>5</sup></code></li>
</ul>
