#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

int NumS, NumF, S[20][200],t, threshold, r=0, k=0, latency, b=1, w=0;
float a;
queue <int> q[20];
const int tmax = 200, C=10;

struct fog{
    int n[20];
    int workingTime[20];
}F;

int factorial(int n) //tinh giai thua cua n
{
    int i,gt=1;
    for(i=1;i<n+1;i++) gt=gt*i;
    return gt;
}

double poisson(int i,int j)
{
    double p;
    p=exp(-i)*pow(i,j)/factorial(j);
    return p;
}

void generateW(int m) //sinh cong viec cho S[m]
{
    int i=1,j=1;
    double h=0;
    do
    {
        h=0;
        a=(double)rand()/RAND_MAX;
        for(j=1;j<31;j++)              //gia tri w duoc sinh ra o S[m] tai thoi diem b
            if((a>=h) && (a<h+poisson(i,j)))
            {
                S[m][b]=j;
                break;
            }
            else h+=poisson(i,j);
        a=(double)rand()/RAND_MAX;
        for(i=1;i<=tmax;i++)                  //thoi gian sinh w tiep theo
            if ((a>=1-exp(-i+1)) && (a<1-exp(-i))) //exponential distribution
            {
                b=b+i;
                break;
            }
    } while(b<=tmax);
    b=1;
}

void randomchoice(int t)
{
    for(int i=1; i<=NumS; i++)
    {
        int m;
        m = rand()% NumF+1;
        if((F.n[m]+S[i][t]<=C) && (10*abs(m-i)+10+10*(F.n[m]+S[i][t])<=threshold))
            q[m].push(S[i][t]);
        else
            r+=S[i][t];
        if(F.workingTime[m]==0){
            F.n[m]=q[m].front();
            F.workingTime[m]=q[m].front();
            q[m].pop();
        }
    }
}

void maxcpc(int t)                  //chon F[i] be nhat trong thoi diem t
{
    int m=1;
    for(int i=1; i<=NumS; i++)
    {
        for(int j=2; j<=NumF; j++)
            if(F.n[m]>F.n[j]) m=j;
        if((F.n[m]+S[i][t]<=C) && (10*abs(m-i)+10+10*(F.n[m]+S[i][t])<=threshold))
            q[m].push(S[i][t]);
        else
            r+=S[i][t];
        if(F.workingTime[m]==0){
            F.n[m]=q[m].front();
            F.workingTime[m]=q[m].front();
            q[m].pop();
        }
        m=1;
    }
}

void lowltc(int t)   //chon F[j] co do tre nho nhat trong thoi diem t
{
    int m=1;
    for(int i=1; i<=NumS; i++)
    {
        for(int j=2; j<=NumF; j++)
            if((abs(m-i)+F.n[m]+S[i][t]) > (abs(j-i)+F.n[j]+S[i][t])) m=j;
        if((F.n[m]+S[i][t]<=C) && (10*abs(m-i)+10+10*(F.n[m]+S[i][t])<=threshold))
            q[m].push(S[i][t]);
        else
            r+=S[i][t];
        if(F.workingTime[m]==0){
            F.n[m]=q[m].front();
            F.workingTime[m]=q[m].front();
            q[m].pop();
        }
        m=1;
    }
}

void solve() {
    NumS = 10;
    NumF = 10;
    threshold = 30 + rand() % 170;
    for(int d=1; d<=NumS; d++)
    {
        for(int j=1;j<=tmax;j++) S[d][j]=0;
        generateW(d);
        for(int j=1;j<=tmax;j++)
        {
            k+=S[d][j];
        }
    }
    for(int i=1; i<=NumF; i++)
    {
        F.n[i]=0;
    }
    for(t=1; t<=tmax; t++)
    {
        randomchoice(t);
        for(int j=1; j<=NumF; j++)
            if(F.workingTime[j]>0) F.workingTime[j]-- ;
    }
    double a1 = double(r) / double(k);
//    cout<<"\n random: "<<(double)r/k;
    r=0;
    for(t=1; t<=tmax; t++)
    {
        maxcpc(t);
        for(int j=1; j<=NumF; j++)
            if(F.workingTime[j]>0) F.workingTime[j]-- ;
    }
    double a2 = double(r) / double(k);
//    cout<<"\n maxcapacity: "<<(double)r/k;
    r=0;
    for(t=1; t<=tmax; t++)
    {
        lowltc(t);
        for(int j=1; j<=NumF; j++)
            if(F.workingTime[j]>0) F.workingTime[j]-=1 ;
    }
    double a3 = double(r) / double(k);
//    cout<<"\n lowlatency: "<<(double)r/k;
  //  const double eps = 1e-4;
    if (/*abs(a1 - a2) <= eps &&*/ a1 > a3 && a2 > a3 && abs(a2 - a3) >= 0.1 ) {
      for (int i = 1; i <= NumS; i++) {
        for (int j = 1; j <= tmax; j++) {
          cout << S[i][j] << " ";
        }
        cout << endl;
      }
      cout << NumF << " " << NumS << " " << threshold << endl;
      cout << "random: " << a1 << endl;
      cout << "max capacity: " << a2 << endl;
      cout << "lowest latency: " << a3 << endl;
      cout << "----------------------" << endl;
    }
}

void reset() {
  NumS = 10, NumF = 10;
  memset(S, 0, sizeof S);
  memset(F.n, 0, sizeof F.n);
  t = 0, threshold = 0, r=0, k=0, latency = 0, b=1, w=0;
  a = 0;
}

int main()
{
  freopen("output.txt", "w", stdout);
  srand(time(NULL));
  cout << fixed << setprecision(10);
  for (int tt = 1; tt <= 1000; tt++) {
    reset();
    solve();
  }
  return 0;
}
