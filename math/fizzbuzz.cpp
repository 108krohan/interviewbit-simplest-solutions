/*


    Fizzbuzz is one of the most basic problems in the coding interview world. Try to write a small and elegant code for this problem. 

Given a positive integer A, return an array of strings with all the integers from 1 to N.
But for multiples of 3 the array should have “Fizz” instead of the number.
For the multiples of 5, the array should have “Buzz” instead of the number.
For numbers which are multiple of 3 and 5 both, the array should have “FizzBuzz” instead of the number.

Look at the example for more details.

Example

A = 5
Return: [1 2 Fizz 4 Buzz]

*/

vector<string> Solution::fizzBuzz(int A) {
    vector<string> result;
    for(int i = 1; i <- A; i++) {
        string str;
        if(i % 3 == 0) {
            str = "Fizz";
        }
        else if(i % 5 == 0) {
            str = "Buzz";
        }
        else if(i % 15 == 0) {
            str = "FizzBuzz";
        }
        else {
            str = to_string(i);
        }
        result.push_back(str);
    }
    return result;
}