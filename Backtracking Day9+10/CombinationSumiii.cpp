
Complexity Analysis

Let KKK be the number of digits in a combination.

Time Complexity: O(9!⋅K / (9−K)!)

In a worst scenario, we have to explore all potential combinations to the very end, i.e. the sum nnn is a
large number (n > 9∗9n > 9 * 9n > 9∗9). At the first step, we have 999 choices, while at the second step,
      we have 888 choices, so on and so forth.
      The number of exploration we need to make in the worst case would be P(9, K)=9! / (9−K)!,
              assuming that K <= 9K <= 9K <= 9. By the way, KKK cannot be greater than 9, otherwise we cannot have a combination
              whose digits are all unique.
              Each exploration takes a constant time to process, except the last step where it takes O(K) time to make a copy
              of combination.
              To sum up, the overall time complexity of the algorithm would be O(9! / (9−K)!)⋅O(K) = O(9!⋅K / (9−K)!)



                      Space Complexity: O(K)\mathcal{O}(K)O(K)

During the backtracking, we used a list to keep the current combination, which holds up to KKK elements,
       i.e. O(K)
       Since we employed recursion in the backtracking, we would need some additional space for the function call stack,
             which could pile up to K consecutive invocations, i.e. O(K).
                 Hence, to sum up, the overall space complexity would be O(K).
                 Note that, we did not take into account the space for the final results in the space complexity.


    class Solution {
    public:
        vector<vector<int> >v;
        vector<int>res;
        void combSum(int num, int cnt, int k, int start)
            {
                if (num == 0 && cnt == k)
                {
                    v.push_back(res);
                    return;
                }
                if (num < 0 || cnt > k)
                {
                    return;
                }
                for (int i = start; i <= 9; i++)
                {
                    res.push_back(i);
                    combSum(num - i, cnt + 1, k, i + 1);
                    res.pop_back();
                }
            }

            vector<vector<int>> combinationSum3(int k, int n) {
                combSum(n, 0, k, 1);
                return v;
            }
        };