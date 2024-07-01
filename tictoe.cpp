#include<iostream>
using namespace std;

//Taking Players Information
void Taking_Player_Info(string &s1 , string &s2){
	cout<<"\n\t\tEnter Player-1 Name :";
	getline(cin ,s1);
	cout<<"\n\t\tEnter Player-2 Name :";
	getline(cin ,s2);
	
	cout<<"\n\t\t"<<s1<<"will play First"<<endl;
	cout<<"\n\t\t"<<s2<<"will Play Second"<<endl;
	
}

//Game Board
void structure(char nums[3][3]){
	cout<<"\n\n";
	cout<<"\n\t\t"<<"    "<<"|    "<<"  "<<"|"<<endl;
	cout<<"\t\t"<<"  "<<nums[0][0]<<"|  "<<nums[0][1]<<"  "<<"|  "<<nums[0][2]<<endl;
	cout<<"\t\t"<<"  _____|_____|_____"<<endl;
	cout<<"\n\t\t"<<"    "<<"|    "<<"  "<<"|"<<endl;
	cout<<"\t\t"<<"  "<<nums[1][0]<<"|  "<<nums[1][1]<<"  "<<"|  "<<nums[1][2]<<endl;
	cout<<"\t\t"<<"  _____|_____|_____"<<endl;
	cout<<"\n\t\t"<<"    "<<"|    "<<"  "<<"|"<<endl;
	cout<<"\t\t"<<"  "<<nums[2][0]<<"|  "<<nums[2][1]<<"  "<<"|  "<<nums[2][2]<<endl;
	cout<<"\n\t\t"<<"    "<<"|    "<<"  "<<"|"<<endl;
}

//Player input

void Play_game(char nums[][3] , char &character , string &s1 , string &s2){
	int position , row ,col;
	if(character == 'x'){
		cout<<"\n\t\t"<<s1<<"enter your position :";
		cin>>position;
	}
	if(position == 1){
		row = 0;
		col = 0;
	}
	else if(position == 2){
		row = 0;
		col = 1;
	}
	else if(position == 3){
		row = 0;
		col = 2;
	}
	else if(position == 4){
		row = 1;
		col = 0;
	}
	else if(position == 5){
		row = 1;
		col = 1;
	}
	else if(position == 6){
		row = 1;
		col = 2;
	}
	else if(position == 7){
		row = 2;
		col = 0;
	}
	else if(position == 8){
		row = 2;
		col = 1;
	}
	else if(position == 9){
		row = 2;
		col = 2;
	}
	else{
		cout<<"\n\t\tInvalid Position.. Enetr Valid Position"<<endl;
	}
	
	if(character == 'x' && nums[row][col]!='x' && nums[row][col]!='0'){
		nums[row][col] = 'x';
		character = '0';
	}
	else if(character == '0' && nums[row][col]!='x' && nums[row][col]!='0'){
		nums[row][col] = '0';
		character = 'x';
	}
	else{
		cout<<"\n\t\tThere is no Empty Space"<<endl;
		Play_game(nums , character , s1 , s2);
	}	
}
//check for draw
// check for win

bool check_winner(char nums[][3] , bool &tie){
	for(int i=0 ; i<3 ;i++){
		if((nums[i][0]==nums[i][1] && nums[i][0] ==nums[i][2]) || (nums[0][i]==nums[1][i] && nums[0][i] ==nums[2][i]))
	       return true;
		}
	}
	if((nums[0][0]==nums[1][1] && nums[1][1] ==nums[2][2]) || (nums[0][2]==nums[1][1] && nums[1][1] ==nums[2][2]))
	{
	return true;
    }
    for(int i=0 ;i<3 ;i++){
    	for(int j=0;j<3 ;j++){
    		if(nums[i][j]!='0' || nums[i][j] !='x'){
    			return false;
			}
		}
	}
	tie = true;
	return false;
  }
void Display(char matrix[][3] , bool &tie , strind s1 , string &s2 , char &character){
	while(!check_winner(matrix , tie)){
		structure(matrix);
		Play_game(matrix , character , s1 , s2);
		
		check_winner(matrix , tie);
	}
	structure(matrix);
	if(character == 'x'&& tie == false){
		cout<<"\n\t\t"<<"Hey !! "<<s2<<"Congratulation....!!!"<<"\n\t\t You Win...!!";
	}
	else if(character == '0'&& tie == false){
		cout<<"\n\t\t"<<"Hey !! "<<s1<<"Congratulation....!!!"<<"\n\t\t You Win...!!";
	}
	else{
		cout<<"\n\t\t"<<"Its a Draw";
	}
  }
void Play_again(char matrix[][3] , bool tie, string &s1 , string &s2 , char character){
	structure(matrix);
	cout<<"\n\n\t\t 1 Play Again";
	cout<<"\n\t\t 0 Exit";
	int ch;
	cout<<"\n\t\tEnter Choice :";
	cin>>ch;
	if(ch == 1){
		Display(matrix , tie , s1 ,s2 , character);
	}
	else{
		cout<<"\n\t\tThank You...!!";
	}
  }
int main(){
	cout<<"\n\n\t\t*** Tic Tac Game ***\n"<<endl;
	int ch;
	string s1, s2;
	Taking_Player_info(s1 , s2);
	
	//Play again and again
	do{
		char character = 'x';
		char matrix[3][3] = {{'1','2','3'},
		                    {'4','5','6'},
		                    {'7','8','9'}};
		bool tie = false;
		
		Display(matrix , tie ,s1 ,s2,character);
		
		cout<<"\n\n\t\t 1 Play Again";
		cout<<"\n\t\t 0 Exit";
        cout<<"\n\t\tEnter Choice :";
	    cin>>ch;
		}while(ch ==1);
		if(ch == 1){
			cout<<"\n\t\tThank You ...!!!";
		}
		return 0;
}   
