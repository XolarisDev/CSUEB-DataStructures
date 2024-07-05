#include <iostream>
#include <string>
using namespace std;
//protoypes
string numberToString(int n); //returns a string
int getFactorial(int n); //returns the quantity of permutations
void permutations(string s, int startIndex, int endIndex); //calculates the permutations. expects a string and 2 integers.


int main(){
  int n; //integer to turn into factorial and permutate.
  cout << "Enter a value between 1-25: ";
  cin >> n; //prompts the user to story a value in 'n'
  //check if n is within range
  while (n < 1 || n > 25){
    cout << "The value must be between 1 and 25. Please Re-enter: ";
    cin >> n;
  }
  //calls the getFactorial() function
  cout << endl << "There are " << getFactorial(n) << " permutations of the set {";
  //iterates from 1 to the 'n' value.
  for (int i = 1; i <= n; i++) //prints the set of numbers
  {
    if (i == n) //if the current iteration equals the 'n'. The set is done.
    {
      cout << i << "} " << "\n";
    }
    else{
      cout << i << ", "; //prints the current iteration into the set.
    }
  }
  //calls the numbertostring() function and then stores the string "1,2,3" that it returns, into the variable 's' of type string.
  string s = numberToString(n);
  //calls the permutations() function to print all the permutations
  //example: function("1,2,3", int 0, int 2)
  permutations(s, 0, s.length() - 1);
}


//definition of numberToString()
string numberToString(int n) // this takes the n and concatenates all the digits starting from 1
{
  string digits;
  for (int i = 1; i <= n; i++) //iterates from 1 to the 'n' value.
  {
    digits += to_string(i); //concatonates each iteration to the digits string
  }
  return digits;
}


//definition of getFactorial()
int getFactorial(int n) //expects int 'n' & Returns the factorial of a number
{
  if (n == 1 || n == 0) //checks if number is 0 or 1, if so then process is stopped and returns 1
  {
    return 1;
  }
  else
  {
    return (n * getFactorial(n - 1)); //multiplies n by the value before it until n equals 1 or 0
  }
}


//defintion of permutations()
void permutations(string s, int startIndex, int endIndex){
  if (startIndex == endIndex) //sets the base for the recursion method
  {
    cout << s << "\n";
  }
  else{
    for (int i = startIndex; i <= endIndex; i++)
    {
      swap(s[startIndex], s[i]); //swaps the 2 values
      //perform the recursive permutation
      permutations(s, startIndex + 1, endIndex);
      //swap again to cover all the combinations
      swap(s[startIndex], s[i]);
    }
  }
}
