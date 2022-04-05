# Count BST nodes that lie in a given range
## Medium 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a Binary Search Tree (BST) and a range <strong>l-h(inclusive)</strong>, count the number of nodes in the BST that lie in the given range. </span></p>

<ul>
	<li><span style="font-size:18px">The values smaller than root go to the left side</span></li>
	<li><span style="font-size:18px">The values greater and equal to the root go to the right side</span></li>
</ul>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>      10
&nbsp;    /  \
&nbsp;   5    50
&nbsp;  /    /  \
&nbsp; 1    40  100
l = 5, h = 45
<strong>Output: </strong>3<strong>
Explanation: </strong>5 10 40 are the node in the
range</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
     5
&nbsp;   /  \
&nbsp;  4    6
&nbsp; /      \
&nbsp;3        7
l = 2, h = 8
<strong>Output: </strong>5<strong>
Explanation: </strong>All the nodes are in the
given range.</span>
</pre>

<p><strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">This is a function problem. You don't have to take input. You are required to complete the function&nbsp;<strong>getCountOfNode()&nbsp;</strong>that takes root, l ,h as parameters and returns the <strong>count</strong>.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N)<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the BST).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= Number of nodes &lt;= 100<br>
1 &lt;= l &lt; h &lt; 10<sup>3</sup></span></p>
 <p></p>
            </div>