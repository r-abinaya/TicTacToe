#include<iostream>
using namespace std;
int checkFinish(string C,char P[3][3]);
void print(char arr[3][3]);
int main()
{
    string p1,p2;
    cout<<"Enter Player name for symbol X:";
    cin>>p1;
    cout<<endl;
    cout<<"Enter player name for symbol O:";
    RENAME:
    cin>>p2;
    if(p1==p2){
        cout<<"enter different name for player 2 for symbol O:";
        goto RENAME;
    }
    cout<<"player name for symbol X:"<<p1;
    cout<<"player name for symbol O:"<<p2;
    int a[4][9]={{1,2,3,4,5,6,7,8,9},{0,0,0,1,1,1,2,2,2},{0,1,2,0,1,2,0,1,2},{0}};
    char p[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char set;
    string name;
    bool finish=false;
    cout<<endl;
    print(p);

    for(int i=0;i<9&&finish!=1;i++)
    {
        REENTER:
        if(i%2==0)
        {
            cout<<"\n"<<p1<<" Enter Position to Insert X : ";
            set='X';
            name=p1;
        }
        else
        {
            cout<<"\n"<<p2<<" Enter Position to Insert O : ";
            set='O';
            name=p2;
        }
        int pos;
        char cpos;
        cin>>cpos;
        pos=cpos-48;
        if((pos>0&&pos<10)&&!(a[3][pos-1]))
        {
            p[(a[1][pos-1])][(a[2][pos-1])]=set;
            a[3][pos-1]=1;
        }
        else
        {
            cout<<"\nInvalid Position! Re-Enter\n";
            goto REENTER;
        }
        print(p);
        cout<<"\n";
        if(i>3)
        {
            finish=checkFinish(name,p);
        }
    }
    if(finish==0)
    {
        cout<<"\nGame Tied !";
    }

return 0;
}

void print(char arr[3][3]){
      cout<<"\n-------------";
      for(int i=0;i<3;i++)
      {
          cout<<"\n";
          for(int j=0;j<3;j++)
          {
              cout<<"| "<<arr[i][j]<<" ";
          }
        cout<<"|\n-------------";
      }

}


int checkFinish(string C,char P[3][3])
{
    for(int i=0;i<3;i++)
    {
        if((P[i][0]==P[i][1])&&(P[i][0]==P[i][2]))    //checks for horizontal match
        {
            cout<<"\n"<<C<<" Won the Game !";
            return 1;                                 //return 1 to finish to show that game is finished
        }
        if((P[0][i]==P[1][i])&&(P[0][i]==P[2][i]))    //checks for vertical match
        {
            cout<<"\n"<<C<<" Won the Game !";
            return 1;                                 //return 1 to finish to show that game is finished
        }
    }
    if((P[0][0]==P[1][1])&&(P[1][1]==P[2][2]))        //checks for 1st diagnol match
    {
        cout<<"\n"<<C<<" Won the Game !";
        return 1;                                     //return 1 to finish to show that game is finished
    }
    if((P[2][0]==P[1][1])&&(P[1][1]==P[0][2]))        //checks for 2nd diagonal match
    {
        cout<<"\n"<<C<<" Won the Game !";
        return 1;                                     //return 1 to finish to show that game is finished
    }
    return 0;
}
