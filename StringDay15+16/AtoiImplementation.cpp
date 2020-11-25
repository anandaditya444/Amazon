
Time - O(N)
Space - O(1)

// A utility function to check
// whether x is numeric
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}

// A simple atoi() function.
// If the given string contains
// any invalid character, then
// this function returns 0
int myAtoi(char* str)
{
	if (*str == '\0')
		return 0;

	// Initialize result
	int res = 0;

	// Initialize sign as positive
	int sign = 1;

	// Initialize index of first digit
	int i = 0;

	// If number is negative,
	// then update sign
	if (str[0] == '-')
	{
		sign = -1;

		// Also update index of first digit
		i++;
	}

	// Iterate through all digits of
	// input string and update result
	for (; str[i] != '\0'; ++i)
	{

		// You may add some lines
		// to write error message
		if (isNumericChar(str[i]) == false)
			return 0;

		// to error stream
		res = res * 10 + str[i] - '0';
	}

	// Return result with sign
	return sign * res;
}