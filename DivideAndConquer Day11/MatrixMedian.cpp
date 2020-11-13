
Simple Method: The simplest method to solve this problem is to store all the elements of the given matrix in
an array of size r*c. Then we can either sort the array and find the median element in O(r*clog(r*c)) or we
can use the approach discussed here to find the median in O(r*c). Auxiliary space required will be O(r*c) in
both the cases.

An efficient approach for this problem is to use binary search algorithm. The idea is that for a number to be
	median there should be exactly (n / 2) numbers which are less than this number. So, we try to find the count of
numbers less than all the numbers. Below is the step by step algorithm for this approach :
Algorithm :

			1.) First we find the minimum and maximum elements in the matrix. Minimum element can be easily found by
			comparing the first element of each row, and similarly the maximum element can be found by comparing the last element of
			each row.
			2.) Then we use binary search on our range of numbers from minimum to maximum, we find the mid of the min and max,
			and get count of numbers less than our mid. And accordingly change the min or max.
			3.) For a number to be median, there should be (r*c) / 2 numbers smaller than that number. So for every number, we
				get the count of numbers less than that by using upper_bound() in each row of matrix, if it is less than the
					required count, the median must be greater than the selected number, else the median must be less than or equal
						o the selected number.

Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time
						and is performed for each row. And since the numbers will be max of 32 bit, so binary
							search of numbers from min to max will be performed in at most 32 ( log2(2 ^ 32) = 32 )
							operations.
Auxiliary Space : O(1)





							const int N = 155;
							int mat[N][N];

							int findMedian(int r, int c)
						{

							int mn = 1e5, mx = 0;

							// Find minimum from 1st column
							for (int i = 0; i < r; i++)
									mn = min(mn, mat[i][0]);

								// Find maxximum from last column
								for (int i = 0; i < r; i++)
									mx = max(mx, mat[i][c - 1]);

								// Required, as median have n/2 numbers less than itself.
								int reqd = (r * c + 1) / 2;
								while (mn < mx)
								{
									int mid = mn + (mx - mn) / 2;
									int cnt = 0;
									for (int i = 0; i < r; i++)
									{
										cnt += upper_bound(mat[i], mat[i] + c, mid) - mat[i];
									}
									if (cnt < reqd)
										mn = mid + 1;
									else
										mx = mid;

								}
								return mn;
							}
