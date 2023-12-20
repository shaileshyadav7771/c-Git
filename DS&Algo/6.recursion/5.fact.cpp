#include <stdio.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
        {
            return 1;
        }
    else
        return fact(n - 1)*n;
}

int main()
{
    int result;
    result = fact(-10);
    printf("%d\n", result);
    return 0;

}

///////////////////////////////////////////////////
// using Python
///////////////////////////////////////////////////
// def fact(n):
//     if n == 0:
//         return 1
//     else:
//         i=1
//         result = 1
//         for x in range(1, n+1):
//             print("x value is : ", x)
//             result = result * x
//             print(f"Result : {result}")

// result = fact(5)

// Time Complexity:

// The for loop iterates from 1 to n, which has n iterations.
// Each iteration performs a constant amount of work, which includes multiplying result by x.
// Therefore, the time complexity of the fact function is O(n), as the loop complexity is directly proportional to n.
// Space Complexity:

// The space complexity of the fact function is O(1) because it only uses a constant amount of additional space.
// Regardless of the input value n, the function only requires space for the result variable and the loop variable x.
// The space used by these variables does not depend on the input size, so the space complexity remains constant.
// In summary:

// Time Complexity: O(n)
// Space Complexity: O(1)
