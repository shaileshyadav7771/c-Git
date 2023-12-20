#include<iostream>
using namespace std;

#include <vector>


int main(){

  vector<int> v={10,20,30,40,50};
  cout << "- - - - - - - - - - - - - - - - - - -   "<<endl;
  v.push_back(120);
  v.push_back(130);

  cout << "   - - - - - Now value are- - - - - - - -"<<endl;
  for(int x:v)
       cout << x << endl;

  //to remove last value we can write..
  v.pop_back();
  cout << "   - - - - - Now value are- - - - - - - -"<<endl;
  for(int x:v)
       cout << x << endl;

}
