#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

void StartGame();
void PrintHome();
int Action();
int Remove(int line,int d);
int RemoveO(int line,int d);
void Capital(int line2,int d2);
void exitt();

typedef enum
{
    BLACK = 0, BLUE = 1, GREEN = 2,
    AQUA = 3, RED = 4, PURPLE = 5,
    YELLOW = 6, WHITE = 7, GRAY = 8, 
    LIGHT_BLUE = 9, LIGHT_GREEN = 10,
    LIGHT_AQUA = 11, LIGHT_RED = 12, 
    LIGHT_PURPLE = 13, LIGHT_YELLOW = 14,
    LIGHT_WHITE = 15
} ConsoleColors;
typedef HANDLE Handle;
typedef CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
typedef WORD Word;
short setTextColor(const ConsoleColors foreground)
{
    Handle consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    BufferInfo bufferInfo;
    if(!GetConsoleScreenBufferInfo(consoleHandle, &bufferInfo))
        return 0;
    Word color = (bufferInfo.wAttributes & 0xF0) + (foreground & 0x0F);
    SetConsoleTextAttribute(consoleHandle, color);
    return 1;
}

char home[10][10]={' '};
int t=0;
int counto=12,countx=12;

int main(){
	
	
	
	StartGame();
	PrintHome();
	Action();
	
	return 0;
}

void StartGame(){
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			home[i][j]=' ';
		}
	}
	for(int i=0;i<10;i++){
		home[i][0]=home[i][9]='$';
		home[0][i]=home[9][i]='$';
	}
	
	home[1][2]=	home[1][4]=	home[1][6]=	home[1][8]= 'o';
	home[2][1]=	home[2][3]=	home[2][5]=	home[2][7]= 'o';
	home[3][2]=	home[3][4]=	home[3][6]=	home[3][8]= 'o';
	home[6][1]=	home[6][3]=	home[6][5]=	home[6][7]= 'x';
	home[7][2]=	home[7][4]=	home[7][6]=	home[7][8]= 'x';
	home[8][1]=	home[8][3]=	home[8][5]=	home[8][7]= 'x';
}



void PrintHome(){
	cout<<endl<<endl;
	
		setTextColor(AQUA);
		
		cout<<'\t'<<"  a   b   c   d   e   f   g   h";
		
	for(int i=1;i<9;i++){
		
		setTextColor(AQUA);
		cout<<endl<<'\t';
    	cout<<("+---+---+---+---+---+---+---+---+");
		cout<<endl<<'\t'<<'|';
		for(int j=1;j<9;j++){
			
			if(home[i][j]=='o' || home[i][j]=='O'){
				setTextColor(YELLOW);
			}
			else {
				setTextColor(WHITE);
			}
			
			cout<<' '<<home[i][j]<<' ';
			setTextColor(AQUA);
			cout<<'|';
			
		}
		cout<<' '<<i;
	}
	setTextColor(AQUA);
	cout<<endl<<'\t'<<"+---+---+---+---+---+---+---+---+"<<endl<<endl;
	setTextColor(WHITE);
}




int Action(){
	
	setTextColor(WHITE);
	cout<<endl;
		
	int ss=0;
	int z=0;
	t%2==0 ? cout<<"X turn.."<<endl : cout<<"O turn.."<<endl;
	
	cout<<endl<<"Enter your action: ";
	int line,d;char column;
	cin >> line >> column;
	
	switch (column){
		
		case 'a':
			d=1;break;
		case 'b':
			d=2;break;
		case 'c':
			d=3;break;
		case 'd':
			d=4;break;
		case 'e':
			d=5;break;
		case 'f':
			d=6;break;
		case 'g':
			d=7;break;
		case 'h':
			d=8;break;
	
	}
	
	

	
	
if(t%2==0){
	
		if(home[line][d]!='x' && home[line][d]!='X'){
		cout<<endl<<"are you koskhol? the emty place!"<<endl<<"Press a key to chose again.";
		getch();
		system("CLS");
		PrintHome();
		Action();
		
	}
	   
	cout<<endl;
		
	for(int i=1;i<9;i++){
		
		for(int j=1;j<9;j++){
			
		if(home[i][j]=='x' || home[i][j]=='X'){
			
		if((home[i-1][j-1]=='o' &&  home[i-2][j-2]==' ')   
		
		 	||  (home[i-1][j+1]=='o' && home[i-2][j+2]==' ') 
		 
		 	||  (home[i+1][j-1]=='o' && home[i+2][j-2]==' ') 
		 
		 	||  (home[i+1][j+1]=='o' && home[i+2][j+2]==' ')  
		 
		 	||  (home[i-1][j-1]=='O' && home[i-2][j-2]==' ' )    
		 
			||  (home[i-1][j+1]=='O' && home[i-2][j+2]==' ')    
		 
		 	||  (home[i+1][j-1]=='O' &&  home[i+2][j-2]==' ' ) 
		 
		 	||  (home[i+1][j+1]=='O' && home[i+2][j+2]==' ')) {
		 		
		 		if(line==i && d==j){
		 			z=1;
				 }
				 ss=1;
		 		cout<<"you should chose from -> "<<i<<' ';
		 		
		 			switch (j){
		
				case 1:
					cout<<'a';break;
				case 2:
					cout<<'b';break;
				case 3:
					cout<<'c';break;
				case 4:
					cout<<'d';break;
				case 5:
					cout<<'e';break;
				case 6:
					cout<<'f';break;
				case 7:
					cout<<'g';break;
				case 8:
					cout<<'h';break;
			 }
			 cout<<endl;
			
		}
		
	}
	
}
}

if(ss==1 && z==0){
		//cout<<"press a key to chose again "	<<endl;
	//getch();
		Action();
}
    int s=0;
	s=Remove(line,d);
	if(s==1) t+=2;
	
	if(s==0){
		if(home[line][d]=='x'){
			
			cout<<"1 to left 2 to right:  ";
			int st;cin>>st;
			
			if (st==2){
				
				if(home[line-1][d+1]==' '){
					home[line][d]=' ';
					home[line-1][d+1]='x';
					Capital(line-1,d+1);
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line-1][d-1]==' '){
					home[line][d]=' ';
					home[line-1][d-1]='x';
					Capital(line-1,d-1);
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
		
		
		else if(home[line][d]=='X'){
			
			cout<<"1 to up 2 to down:  ";
			int sd; cin>>sd;
			if(sd==1){
				cout<<endl<<endl;
				
				cout<<"1 to left 2 to right:  ";
			int st;cin>>st;
			
			if (st==2){
				
				if(home[line-1][d+1]==' '){
					home[line][d]=' ';
					home[line-1][d+1]='X';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line-1][d-1]==' '){
					home[line][d]=' ';
					home[line-1][d-1]='X';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
			
			else if(sd==2){
				
				cout<<"1 to left 2 to right:  ";
				int st;cin>>st;
			
				if (st==2){
				
					if(home[line+1][d+1]==' '){
						home[line][d]=' ';
						home[line+1][d+1]='X';
						
					}
					else{
						cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
						getch();
						system("CLS");
						PrintHome();
						Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line+1][d-1]==' '){
					home[line][d]=' ';
					home[line+1][d-1]='X';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
		
			}
			}
			
			
		
			
			t++;
			

		}
		
	
	
else if(t%2==1){
	
		if(home[line][d]!='o' && home[line][d]!='O'){
		cout<<endl<<"are you koskhol? the emty place!"<<endl<<"Press a key to chose again.";
		getch();
		system("CLS");
		PrintHome();
		Action();
		
	}
	
	
	 cout<<endl;
	 
	for(int i=1;i<9;i++){
		
		for(int j=1;j<9;j++){
			
		if(home[i][j]=='o' || home[i][j]=='O'){
			
			if(( home[i-1][j-1]=='x' &&  home[i-2][j-2]==' ')  
		
		 	||  (home[i-1][j+1]=='x' && home[i-2][j+2]==' ')  
		 
		 	||  (home[i+1][j-1]=='x' && home[i+2][j-2]==' ') 
		 
		 	||  (home[i+1][j+1]=='x' && home[i+2][j+2]==' ')  
		 
		 	||  (home[i-1][j-1]=='X' && home[i-2][j-2]==' ' )   
		 
			||  (home[i-1][j+1]=='X' && home[i-2][j+2]==' ') 
		 
		 	||  (home[i+1][j-1]=='X' &&  home[i+2][j-2]==' ' ) 
		 
		 	||  (home[i+1][j+1]=='X' && home[i+2][j+2]==' ')) {
		 		
		 		if(line==i && d==j){
		 			z=1;
				 }
				 ss=1;
		 		cout<<"you should chose from -> "<<i<<' ';
		 		
		 			switch (j){
		
				case 1:
					cout<<'a';break;
				case 2:
					cout<<'b';break;
				case 3:
					cout<<'c';break;
				case 4:
					cout<<'d';break;
				case 5:
					cout<<'e';break;
				case 6:
					cout<<'f';break;
				case 7:
					cout<<'g';break;
				case 8:
					cout<<'h';break;
			 }
			 cout<<endl;
			
		}
	}
}
}

if(ss==1 && z==0){
 	
	Action();
}
	int s=0;	
	s=RemoveO(line,d);
	
	if(s==1){
		t+=2;
	} 
	
	if(s==0){
		
		
		if(home[line][d]=='o'){
			
			cout<<"1 to left 2 to right:  ";
			int st;cin>>st;
			
			if (st==2){
				
				if(home[line+1][d+1]==' '){
					home[line][d]=' ';
					home[line+1][d+1]='o';
					Capital(line+1,d+1);
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line+1][d-1]==' '){
					home[line][d]=' ';
					home[line+1][d-1]='o';
					Capital(line+1,d-1);
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
		
		
		else if(home[line][d]=='O'){
			
			cout<<"1 to up 2 to down:  ";
			int sd; cin>>sd;
			if(sd==1){
				cout<<endl<<endl;
				
				cout<<"1 to left 2 to right:  ";
			int st;cin>>st;
			
			if (st==2){
				
				if(home[line-1][d+1]==' '){
					home[line][d]=' ';
					home[line-1][d+1]='O';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line-1][d-1]==' '){
					home[line][d]=' ';
					home[line-1][d-1]='O';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
			
			else if(sd==2){
				
				cout<<"1 to left 2 to right:  ";
				int st;cin>>st;
			
				if (st==2){
				
					if(home[line+1][d+1]==' '){
						home[line][d]=' ';
						home[line+1][d+1]='O';
						
					}
					else{
						cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
						getch();
						system("CLS");
						PrintHome();
						Action();
					
				}	
			}
			
			else if (st==1){
				
				if(home[line+1][d-1]==' '){
					home[line][d]=' ';
					home[line+1][d-1]='O';
					
				}
				else{
					cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
					
				}	
			}
			
		  	else{
		  		cout<<endl<<"you cant go this home!"<<endl<<"Press a key to chose again.";
					getch();
					system("CLS");
					PrintHome();
					Action();
			  }
			}
		
			}
			}
			
			
		
			
			t++;
			

		}
		
	
	
	system("CLS");
	
	PrintHome();
	Action();
	
	

}


int Remove(int line,int d){
	
	int s=0;
	
		if((home[line-1][d-1]=='o' &&  home[line-2][d-2]==' ') 
		
		 ||  (home[line-1][d+1]=='o' && home[line-2][d+2]==' ')
		 
		 ||  (home[line+1][d-1]=='o' && home[line+2][d-2]==' ') 
		 
		 || (home[line+1][d+1]=='o' && home[line+2][d+2]==' ')  
		 
		 || (home[line-1][d-1]=='O' && home[line-2][d-2]==' ' ) 
		 
		 || (home[line-1][d+1]=='O' && home[line-2][d+2]==' ') 
		 
		 || (home[line+1][d-1]=='O' &&  home[line+2][d-2]==' ' ) 
		 
		 || (home[line+1][d+1]=='O' && home[line+2][d+2]==' ')) {
		 	
	
		cout<<endl<<"Enter your chose(to remove): ";
		int line1,d1;  char column1;
		cin >> line1 >> column1;
		
		switch (column1){
		
			case 'a':
				d1=1;break;
			case 'b':
				d1=2;break;
			case 'c':
				d1=3;break;
			case 'd':
				d1=4;break;
			case 'e':
				d1=5;break;
			case 'f':
				d1=6;break;
			case 'g':
				d1=7;break;
			case 'h':
				d1=8;break;
		}
		 
	int tempr=line1-line;
	int tempc=d1-d;	
	
	s=1;
		
		if((tempr==2 || tempr==-2) && (tempc==2 || tempc==-2) && (home[line+tempr/2][d+tempc/2]=='o' || home[line+tempr/2][d+tempc/2]=='O')){
			home[line+tempr/2][d+tempc/2]=' ';
			home[line1][d1]=home[line][d];
			home[line][d]=' ';
			counto--;
			exitt();
			
		}
		
		
		else {
			cout<<"You cant go to this place."<<endl;
			
			Remove(line,d);
		}
		
	
	
	
	Capital(line1,d1);
	system("CLS");
	PrintHome();
	Remove(line1,d1);
		
		
	}
	
		if((home[line-1][d-1]=='o' &&  home[line-2][d-2]==' ') 
		
		 ||  (home[line-1][d+1]=='o' && home[line-2][d+2]==' ')
		 
		 ||  (home[line+1][d-1]=='o' && home[line+2][d-2]==' ') 
		 
		 || (home[line+1][d+1]=='o' && home[line+2][d+2]==' ')  
		 
		 || (home[line-1][d-1]=='O' && home[line-2][d-2]==' ' ) 
		 
		 || (home[line-1][d+1]=='O' && home[line-2][d+2]==' ') 
		 
		 || (home[line+1][d-1]=='O' &&  home[line+2][d-2]==' ' ) 
		 
		 || (home[line+1][d+1]=='O' && home[line+2][d+2]==' ')) s=1;
		 
		 
		
return s;		
}



int RemoveO(int line,int d){
	
	int  s=0;
	
		if((home[line-1][d-1]=='x' &&  home[line-2][d-2]==' ') 
		
		 ||  (home[line-1][d+1]=='x' && home[line-2][d+2]==' ')
		 
		 ||  (home[line+1][d-1]=='x' && home[line+2][d-2]==' ') 
		 
		 || (home[line+1][d+1]=='x' && home[line+2][d+2]==' ')  
		 
		 || (home[line-1][d-1]=='X' && home[line-2][d-2]==' ' )
		 
		 || (home[line-1][d+1]=='X' && home[line-2][d+2]==' ') 
		 
		 || (home[line+1][d-1]=='X' &&  home[line+2][d-2]==' ' ) 
		 
		 || (home[line+1][d+1]=='X' && home[line+2][d+2]==' ')) {
		 	
		s=1;
		cout<<endl<<"Enter your chose(to remove): ";
		int line1,d1;  char column1;
		cin >> line1 >> column1;
		
		switch (column1){
		
			case 'a':
				d1=1;break;
			case 'b':
				d1=2;break;
			case 'c':
				d1=3;break;
			case 'd':
				d1=4;break;
			case 'e':
				d1=5;break;
			case 'f':
				d1=6;break;
			case 'g':
				d1=7;break;
			case 'h':
				d1=8;break;
		}
		 
	int tempr=line1-line;
	int tempc=d1-d;	
	
	s=1;
		
		if((tempr==2 || tempr==-2) && (tempc==2 || tempc==-2) && (home[line+tempr/2][d+tempc/2]=='x' || home[line+tempr/2][d+tempc/2]=='X')){
			home[line+tempr/2][d+tempc/2]=' ';
			home[line1][d1]=home[line][d];
			home[line][d]=' ';
			countx--;
			exitt();
			
		}
		
		
		else {
			cout<<"You cant go to this place."<<endl;
			
			RemoveO(line,d);
		}
		
		
	Capital(line1,d1);
	system("CLS");
	PrintHome();
	RemoveO(line1,d1);
		
	}
	
	if((home[line-1][d-1]=='x' &&  home[line-2][d-2]==' ') 
		
		 ||  (home[line-1][d+1]=='x' && home[line-2][d+2]==' ')
		 
		 ||  (home[line+1][d-1]=='x' && home[line+2][d-2]==' ') 
		 
		 || (home[line+1][d+1]=='x' && home[line+2][d+2]==' ')  
		 
		 || (home[line-1][d-1]=='X' && home[line-2][d-2]==' ' )
		 
		 || (home[line-1][d+1]=='X' && home[line-2][d+2]==' ') 
		 
		 || (home[line+1][d-1]=='X' &&  home[line+2][d-2]==' ' ) 
		 
		 || (home[line+1][d+1]=='X' && home[line+2][d+2]==' ')) s=1;
		
return s;		
}




void Capital(int line2,int d2){
	
	if(line2==1 && home[line2][d2]=='x'){
		if(home[line2][d2] >=97){
			home[line2][d2]-=32;
		}
	}
	
	if(line2==8 && home[line2][d2]=='o'){
		if(home[line2][d2] >=97){
			home[line2][d2]-=32;
		}
	}
	

	
}

void exitt(){
	if(counto==0){
	system("CLS");
	cout<<endl<<"The X win!"<<endl;
	exit(0);
		
	}
	if(countx==0){
	system("CLS");
	cout<<endl<<"The O win!"<<endl;
	exit(0);
		
	}
}












