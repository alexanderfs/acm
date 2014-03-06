#include <iostream>
#include <fstream>
#include <cstring>
#define MAXN 160
using namespace std;
int G[MAXN][MAXN],n,m,sum,maxlen;
const int move[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{1,-1},{-1,1}};
bool vis[MAXN][MAXN],flag;
void dfs(int x,int y)
{
    vis[x][y]=true;
    int px,py;
    sum++;
    if(x==0 || y==0 || x==2*n-1 || y==2*m-1) flag=true;
    for(int i=0;i<8;++i)
    {
        px=x+move[i][0];
        py=y+move[i][1];
        if(px>=0 && px<2*n && py>=0 && py<2*m && G[px][py]!=1 && !vis[px][py])
        {
            if(i<4) dfs(px,py);
            else
            {
                if(i==4 && G[x-1][y]==1 && G[x][y-1]==1)
                {
                    if((G[x-1][y-2]==1 && G[x][y+1]==1 && (x&1) && !(y&1)) ||
                       (G[x-2][y-1]==1 && G[x+1][y]==1 && !(x&1) && (y&1)))
                    {
                        dfs(px,py);
                    }
                }
                if(i==5 && G[x][y+1]==1 && G[x+1][y]==1)
                {
                    if((G[x+1][y+2]==1 && G[x][y-1]==1 && !(x&1) && (y&1)) ||
                       (G[x-1][y]==1 && G[x+2][y+1]==1 && (x&1) && !(y&1)))
                    {
                        dfs(px,py);
                    }
                }
                if(i==6 && G[x][y-1]==1 && G[x+1][y]==1)
                {
                    if((G[x-1][y]==1 && G[x+2][y-1]==1 && (x&1) && (y&1)) ||
                       (G[x][y+1]==1 && G[x+1][y-2]==1 && !(x&1) && !(y&1)))
                    {
                        dfs(px,py);
                    }
                }
                if(i==7 && G[x-1][y]==1 && G[x][y+1]==1)
                {
                    if((G[x][y-1]==1 && G[x-1][y+2]==1 && (x&1) && (y&1)) ||
                       (G[x+1][y]==1 && G[x-2][y+1]==1 && !(x&1) && !(y&1)))
                    {
                        dfs(px,py);
                    }
                }
            }
        }
    }
}
void solve()
{
    sum=0; maxlen=0;
    int cnt=0;
    for(int i=0;i<2*n;++i)
    {
        for(int j=0;j<2*m;++j)
        {
            if(G[i][j]==0 && !vis[i][j])
            {
                sum=0;
                flag=false;
                dfs(i,j);
                if(!flag)
                {
                    //cout<<sum<<" ";
                    if(maxlen<sum) maxlen=sum;
                    sum=0;
                    cnt++;
                }
            }
        }
    }
    if(cnt) cout<<cnt<<" Cycles; the longest has length "<<maxlen<<"."<<endl;
    else cout<<"There are no cycles."<<endl;
}
void read_input()
{
    char s[80];
    memset(G,0,sizeof(G));
    memset(vis,false,sizeof(vis));
    for(int i=0;i<2*n;i+=2)
    {
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='\\') G[i][j*2]=G[i+1][2*j+1]=1;
            else G[i][2*j+1]=G[i+1][2*j]=1;
        }
    }
}
//void out_put()
//{
//    for(int i=0;i<2*n;++i)
//    {
//        for(int j=0;j<2*m;++j)
//        {
//            if(G[i][j]) cout<<"1";
//            else cout<<"0";
//        }
//        cout<<endl;
//    }
//    cout<<endl;
//}
int main()
{
	ifstream in("test_input.txt");
	cin.rdbuf(in.rdbuf());
    int T=1;
    while(cin>>m>>n)
    {
        if(m+n==0) break;
        cout<<"Maze #"<<T++<<":"<<endl;
        read_input();
        solve();
        cout<<endl;
        //out_put();
    }
    return 0;
}