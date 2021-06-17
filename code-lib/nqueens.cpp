#include <iostream>
#define Q 4 
using namespace std;

bool check(int board[Q][Q],int row ,int col)
{
    int i,j;
    for(i=0;i<col;i++)
    {
    if(board[row][i]) 
    return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--) 
    {
    if(board[i][j])
    return false;
    }
    for(i=row,j=col;j>=0 && i<Q ;i++,j--) 
    {
    if(board[i][j])
    return false;
    }
return true;
}
bool placement(int board[Q][Q],int col)
{
if(col>=Q) 
{
return true;
}
for(int i=0;i<Q;i++)  
{
    if(check(board,i,col)) 
    {
    board[i][col]=1;
    if(placement(board,col+1)) 
    return true;
    board[i][col]=0;
    }

}
return false;
}
void displayboard(int board[Q][Q])
{
for(int i=0;i<Q;i++)
{
    for(int j=0;j<Q;j++)
    cout<<board[i][j];
    cout<<endl;
}
}
bool solve()
{
int board[Q][Q] = {0};
if(placement(board,0)==false) 
{
    cout<<"No possible solution"<<endl;
    return false;
}
displayboard(board);  
return true;
}
int main()
{
solve();
return 0;
}