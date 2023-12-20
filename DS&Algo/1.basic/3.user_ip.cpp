#include<iostream>
using namespace std;

int main(){
  int n;
  cout << "Enter a number:";
  cin >> n;
  int A[n];

  A[0] = 7;

  for (int x:A)
  {
      cout << x << endl;
  }


  return 0 ;
}
