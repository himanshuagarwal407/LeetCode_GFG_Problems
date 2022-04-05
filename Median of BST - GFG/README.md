# Median of BST
## Easy 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given a Binary Search Tree of size N, find the Median of its Node values.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp;6
&nbsp; &nbsp; &nbsp;/&nbsp; &nbsp;\
&nbsp; &nbsp;3&nbsp; &nbsp; &nbsp; 8&nbsp; &nbsp;
&nbsp;/&nbsp; \&nbsp; &nbsp; /&nbsp; \
1&nbsp; &nbsp; 4&nbsp; 7&nbsp;   9<strong>
Output: </strong>6
<strong>Explanation: </strong>Inorder of Given BST will be:
1, 3, 4, 6, 7, 8, 9. So, here median will 6.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>&nbsp; &nbsp; &nbsp; &nbsp;6
&nbsp; &nbsp; &nbsp;/&nbsp; &nbsp;\
&nbsp; &nbsp;3&nbsp; &nbsp; &nbsp; 8&nbsp; &nbsp;
&nbsp;/&nbsp; &nbsp;\&nbsp; &nbsp; /&nbsp; &nbsp;
1&nbsp; &nbsp; 4&nbsp;  7&nbsp; &nbsp;</span><span style="font-size:18px"><strong>
Output: </strong>5<strong>
Explanation:</strong>Inorder of Given BST will be:
1, 3, 4, 6, 7, 8. So, here median will
(4 + 6)/2 = 10/2 = 5.</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findMedian()</strong>&nbsp;which takes the root of the Binary Search Tree as input&nbsp;and returns the Median of Node values in the given BST.<br>
Median of the BST is:</span></p>

<ul>
	<li><span style="font-size:18px">If number&nbsp;of nodes are even: then median = (N/2 th node + (N/2)+1 th node)/2</span></li>
	<li><span style="font-size:18px">If number&nbsp;of nodes are odd : then median = (N+1)/2th node.</span></li>
</ul>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N).<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of the Tree).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=N&lt;=1000</span></p>

<p>&nbsp;</p>
 <p></p>
            </div>