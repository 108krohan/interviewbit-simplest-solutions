/*

Write a function that takes an unsigned integer and returns the number of 1 bits it has.

Example:

The 32-bit integer 11 has binary representation

00000000000000000000000000001011

so the function should return 3.

*/

int Solution::numSetBits(unsigned int A) {
    int result = 0;
    //cout << A << " " << endl;
    while(A > 0) {
        result += A % 2;
        A = A >> 1;
    }
    return result;
}
