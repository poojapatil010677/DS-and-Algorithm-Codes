/*
A Tic-Tac-Toe board is given after some moves are played. Find out if the given board is valid, i.e., is it possible to reach this board position after some moves or not.

Note that every arbitrary filled grid of 9 spaces isn’t valid e.g. a grid filled with 3 X and 6 O isn’t valid situation because each player needs to take alternate turns.

Input:
2
X X O O X O O O O 
X X O O O X X O X

Output:
Invalid
Valid

*/

#include <iostream>
using namespace std;

int isWin(char* board,char c)
{
    int win[8][3] = {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };
    for(int i=0;i<8;i++)
    {
        if(board[win[i][0]]==c && board[win[i][1]]==c && board[win[i][2]]==c)
            return 1;
    }
    return 0;
    
}

int isvalid(char* board)
{
    int countx = 0;
    int counto = 0;
    for(int i=0;i<9;i++)
    {
            if(board[i]=='X')
                countx++;
            else
                counto++;
    }
    
    if(countx!=counto && countx!=counto+1)
        return 0;
    else
    {
        int xwin = isWin(board,'X');
        int owin = isWin(board,'O');
        if(xwin && owin)
            return 0;
        else if(owin && countx!=counto)
            return 0;
        else if(xwin && countx!=counto+1)
            return 0;
        return 1;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    char board[9];
	    for(int i=0;i<9;i++)
	    {
	            cin>>board[i];
	    }
	    int res = isvalid(board);
	    if(res) 
	        cout<<"Valid"<<'\n';
	   else
	    cout<<"Invalid"<<'\n';
	}
	return 0;
}

