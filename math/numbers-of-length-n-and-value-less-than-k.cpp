/*



Given a set of digits (A) in sorted order, find how many numbers of length B are possible whose value is less than number C.

    NOTE: All numbers can only have digits from the given set. 

Examples:

	Input:
	  0 1 5  
	  1  
	  2  
	Output:  
	  2 (0 and 1 are possible)  

	Input:
	  0 1 2 5  
	  2  
	  21  
	Output:
	  5 (10, 11, 12, 15, 20 are possible)

Constraints:

    1 <= B <= 9, 0 <= C <= 1e9 & 0 <= A[i] <= 9

0 1 2 3 4 5 

3
2
if, K ka length is less than N, 
then no numbers

3 
345
[0,1,2] * [0,1,2,3,4,5] * [0, 1, 2, 3, 4, 5]
repeat for 2 guys, then 1 guy???
[3] + [0, 1, 2, 3, 4] + [0, 1, 2, 3, 4, 5]
[3] + [4]

3 * 6 * 6 + 

3 
2345
if, K ka length is more than N, 
then all numbers? 
so, that'll be 
pow(A.size(), N)


*/

vector <int> numToVec(int N) {   
    vector<int> digit;
    while(N != 0) {
        digit.push_back(N % 10);
        N = N / 10;
    }
    if(digit.size() == 0)
        digit.push_back(0);

    reverse(digit.begin(), digit.end());
    return digit; 
}

int Solution:: solve(vector<int> &A, int B, int C) {
    vector<int> digit;
    int  d, d2;
    // Convert number to digit array
    digit = numToVec(C);
    d = A.size();

    //Case 1
    if(B > digit.size()  || d == 0)
        return 0;

    // Case 2
    else if(B < digit.size()) {
        // contain 0
        if(A[0] == 0 && B != 1)
            return (d - 1) * pow(d, B - 1);
        else 
            return pow(d, B);
    }

    //Case 3
    else {
          int dp[B + 1], lower[11];
          for(int i = 0; i <= B; i++)
              dp[i] = 0;
          for(int i = 0; i <= 10; i++)
              lower[i] = 0;
          for(int i = 0; i < d; i++)
              lower[A[i] + 1] = 1;

          for(int i = 1; i <= 10; i++)
              lower[i] = lower[i-1] + lower[i]; 

          bool flag = true;
          dp[0] = 0;
          for(int i = 1; i <= B; i++) {
              d2 = lower[digit[i-1]];
              dp[i] = dp[i-1] * d;

              // For first index we can't use 0
             if(i == 1 &&  A[0] == 0 && B != 1)
                 d2 = d2 - 1;

             //Whether (i-1) digit of generated number can be equal to (i - 1) digit of C.
             if(flag)
                 dp[i] += d2;
             //Is digit[i - 1] present in A ?
                flag = flag & (lower[digit[i-1] + 1] == lower[digit[i-1]] + 1);
        }
    return dp[B];                   
    } 
}

