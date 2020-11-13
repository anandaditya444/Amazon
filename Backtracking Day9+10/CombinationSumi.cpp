
Complexity Analysis

Let N be the number of candidates, T be the target value, and M be the minimal value among the candidates.

Time Complexity: O(N ^ (T / M) + 1)

As we illustrated before, the execution of the backtracking is unfolded as a DFS traversal in a n - ary tree.
The total number of steps during the backtracking would be the number of nodes in the tree.

At each node, it takes a constant time to process, except the leaf nodes which could take a linear time to
make a copy of combination. So we can say that the time complexity is linear to the number of nodes of the execution tree.

Here we provide a loose upper bound on the number of nodes.

First of all, the fan - out of each node would be bounded to NNN, i.e. the total number of candidates.

The maximal depth of the tree, would be TM\frac{T} {M} MT​, where we keep on adding the smallest element to
the combination.

As we know, the maximal number of nodes in N - ary tree of TM\frac{T} {M} MT​ height
would be NTM + 1N ^ {\frac{T}{M} +1} NMT​ +1.

Note that, the actual number of nodes in the execution tree would be much smaller than the
upper bound, since the fan - out of the nodes are decreasing level by level.

Space Complexity: O(TM)\mathcal{O}(\frac{T} {M})O(MT​)

We implement the algorithm in recursion, which consumes some additional memory in the function call stack.

The number of recursive calls can pile up to TM\frac{T} {M} MT​, where we keep on adding the smallest
element to the combination. As a result, the space overhead of the recursion is O(TM)\mathcal{O}(\frac{T} {M})O(MT​).

In addition, we keep a combination of numbers during the execution, which requires at most
O(TM)\mathcal{O}(\frac{T} {M})O(MT​) space as well.

To sum up, the total space complexity of the algorithm would be O(TM)\mathcal{O}(\frac{T} {M})O(MT​).

Note that, we did not take into the account the space used to hold the final results for the space complexity.




class Solution {
public:
	vector<vector<int> >v;
	vector<int>res;

	void combSum(vector<int> candidates, int target, int n, int start)
		{
			if (target == 0)
			{
				v.push_back(res);
				return;
			}
			if (target < 0)
				return;
			for (int i = start; i < n; i++)
			{
				res.push_back(candidates[i]);
				combSum(candidates, target - candidates[i], n, i);
				res.pop_back();
			}
		}

		vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
			sort(candidates.begin(), candidates.end());
			int n = candidates.size();

			combSum(candidates, target, n, 0);

			return v;
		}
	};