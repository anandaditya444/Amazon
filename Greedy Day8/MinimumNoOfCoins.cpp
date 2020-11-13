

Time - O(Amount)
Space - O(1)

Approach: A common intuition would be to take coins with greater value first.
This can reduce the total number of coins needed. Start from the largest possible denomination
and keep adding denominations while the remaining value is greater than 0.

Algorithm Steps:

Sort the array of coins in decreasing order.
Initialize result as empty.
Find the largest denomination that is smaller than current amount.
Add found denomination to result. Subtract value of found denomination from amount.
If amount becomes 0, then print result.
Else repeat steps 3 and 4 for new value of V.
