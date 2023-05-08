#include<iostream>
using namespace std;

bool checkPalindrome(char str[]){
	int len = 0, end, middle, begin;
    //getting the length
	while(str[len] != '\0'){
    len++;
    }
    end = len -1;
    middle = len/2;
    
    for(begin = 0; begin < middle; begin++){
    if(str[begin] != str[end]){
    return false;
    }
        end--;
    }
    if(begin == middle){
    return true;
    }
  	 
    return false;
}



int main(){

  char str[10000];
  cin.getline(str,10000);

  if(checkPalindrome(str)){
  	cout << "true" << endl; 	
  }else{
  cout << "false" << endl;
  }
}
