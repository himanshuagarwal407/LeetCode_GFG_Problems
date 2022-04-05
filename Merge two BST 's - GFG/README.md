# Merge two BST 's
## Hard 
<div class="problem-statement">
                <p><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank"></a></p><div style="margin: 14px 0px !important;" class="row"><a onclick="gtagHelperFunction('clickopen','salesevent_gsc_problemspage_promobanner')" href="https://practice.geeksforgeeks.org/summer-carnival-2022?utm_source=practiceproblems&amp;utm_medium=problemspromobanner&amp;utm_campaign=gsc22" target="_blank">             <div class="col-md-12" style="cursor:pointer;background: #EFF8F3 0% 0% no-repeat padding-box; display: flex; align-items: center; position:                 relative; padding: 1.5%; border-radius: 10px; display: inline-block; text-align: center; font-weight: 600; color: #333"> <img src="https://media.geeksforgeeks.org/img-practice/gcs2022thumbnail-1649059370.png" alt="Lamp" width="46" height="40" style="background: transparent 0% 0% no-repeat padding-box;opacity: 1; margin: 0 16px;" class="img-responsive"> Geeks Summer Carnival is LIVE NOW &nbsp; <i class="fa fa-external-link" aria-hidden="true"></i> </div></a></div><p><span style="font-size:18px">Given two BSTs, return elements of both BSTs in <strong>sorted </strong>form.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
BST1:
       </strong>5
&nbsp;    /   \
&nbsp;   3     6
&nbsp;  / \
&nbsp; 2   4  <strong>
</strong><strong>BST2:
&nbsp;       </strong>2
&nbsp;     /   \
&nbsp;    1     3
&nbsp;           \
&nbsp;            7
&nbsp;           /
&nbsp;          6
<strong>Output: </strong>1 2 2 3 3 4 5 6 6 7<strong>
Explanation: 
</strong>After merging and sorting the
two BST we get 1 2 2 3 3 4 5 6 6 7.</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
BST1:
&nbsp;      </strong>12
&nbsp;    /   
&nbsp;   9
&nbsp;  / \ &nbsp;  
&nbsp; 6   11<strong>
</strong><strong>BST2:
&nbsp;     </strong>8
&nbsp;   /  \
&nbsp;  5    10
&nbsp; /
&nbsp;2
<strong>Output: </strong>2 5 6 8 9 10 11 12<strong>
Explanation: 
</strong>After merging and sorting the
two BST we get 2 5 6 8 9 10 11 12.</span></pre>

<p><br>
<strong><span style="font-size:18px">Your Task:</span></strong><br>
<span style="font-size:18px">You don't need to read input or print anything. Your task is to complete the function</span><span style="font-size:18px"><strong> merge() </strong>which takes roots of both the BSTs as its input and returns an array of integers denoting the node values of both the BSTs in a sorted order.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(M+N) where M and N are the sizes if the two BSTs.<br>
<strong>Expected Auxiliary Space:&nbsp;</strong>O(Height of BST1 + Height of BST2).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ Number of Nodes ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>