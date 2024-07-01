#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void Interface(){
	cout<<"\n\t\tWelcome to Guess Number Game....|||"<<endl;
	cout<<"\n\t\tYou Have To Guess Number Between 1 and 100."<<endl;
	cout<<"\t\tYou'll Have Limited Choices Based on Level You Choose."<<endl;
}
void operation(int option, int & answer ,int & num){
	cout<<"\n\t\tYou have "<<option<<"Chioces for Guessing the Secret Number."<<endl;
	int choiceleft = option;
	for(int i=1; i<=option; i++){
		cout<<"\n\t\tEnter Number :";
		cin>>answer;
		if(answer==num){
			cout<<"\n\t\tWell Played..!!You Won,"<<num<<"is the Secret Number"<<endl;
			cout<<"\t\tThanks..! For Playing...."<<endl;
			cout<<"\n\t\tPlaying Game Again with Us..||"<<endl;
			break;
		}
		else{
			cout<<"\n\t\tNope ,"<<answer<<" is not Right Number"<<endl;
			if(answer>num){
				cout<<"\t\tThe Secret Number is Smaller than the Number You Have Choosen"<<endl;
			}
			else{
				cout<<"\t\tThe Secret Number is Greater than the Number You Choosen"<<endl;
			}
			choiceleft--;
			cout<<"\t\tYou Have"<<choiceleft<<"Remaining Choice"<<endl;
			if(choiceleft==0){
				cout<<"\n\t\tYou Couldn't find the Secret Number , it was"<<num<<", You Loss the Game ";
				cout<<"\t\tPlay The Game Again to Win..!\n\n";
			}
		}
	}
}
int main(){
	Interface();
	while(true){
		cout<<"\n\t\t\t1 Easy \n\t\t\t2 Medium \n\t\t\t3 Difficult \n\t\t\t0 Ending the Game";
		int choice;
		cout<<"\n\n\t\tEnter Your Choice : ";
		cin>>choice;
		
		srand(time(0));
		int num =1+(rand()%100);
		
		int answer;
		if(choice ==1){
			operation(10 , answer ,num);
		}
		else if(choice ==2){
			operation(7, answer ,num);
		}
		else if(choice ==3){
			operation(5, answer ,num);
		}
		else if(choice ==0){
			break;
		}
		else{
			cout<<"Wrong Choice , Enter Valid Choice to Play the Game {0,1,2,3}"<<endl;
		}
	}
	return 0;
}
