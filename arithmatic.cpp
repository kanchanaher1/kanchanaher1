#include<iostream>
using namespace std;
int main()
{
	char operation;
	double num1,num2,result;
	cout<<"enter operator(+,-,*,/):";
	cin>>operation;
	cout<<"enter two numbers:";
	cin>>num1>>num2;
	
	switch(operation){
		case'+':
			result=num1+num2;
		    break;
		case'-':
		    result=num1-num2;
			break;
		case'*':
		    result=num1*num2;
			break;
		case'/':
			if(num2!=0){
		    result=num1/num2;
		}
		    else
			{
			cout<<"Error:division by zero is not allowed";
			return 1;
			}
			break;
		default:
		  cout<<"invalid operator!";
		  return 1;	
	}
	cout<<"result:"<<result<<endl;
	return 0;
}
