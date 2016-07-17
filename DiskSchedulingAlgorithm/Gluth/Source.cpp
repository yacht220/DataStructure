#include <iostream>
#include <fstream>

using namespace std;
const int largediskclinder = 1200;
const int maxInt = 2147483647;
int diskinfo[largediskclinder];
int dp[largediskclinder][largediskclinder];

int disksectord(int x, int y)
{
    if (diskinfo[x] < diskinfo[y])
    {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    int d = diskinfo[x] - diskinfo[y];
    if (d > 180) d = 360 - d;
    return d;
}

int min(int x, int y)
{
    return x > y ? y : x;
}

void compute(int num)
{
    dp[1][0] = disksectord(1, 0);
    int i, j;
    for (i = 2; i <= num; i++)
    {
        dp[i][i - 1] = maxInt;
        for (j = 0; j < i-1; j++)
        {
            dp[i][j] = dp[i - 1][j] + disksectord(i, i - 1);
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + disksectord(i, j));
            
        }
    }
}

int main(int argc, char** argv)
{
    ifstream myfile;
    myfile.open(argv[1]);
    int num;

    
    myfile >> num;
    //cout << num << endl;
    int x, y;
    int largenum = 0;
    int s = num;
    diskinfo[0] = 0;
    int i = 1;
    while (num != 0)
    {
        myfile >> x >> y;
        //cout << x << " " << y << endl;
        diskinfo[i++] = y;
        num--;
    }
    compute(s);
    int re = maxInt;
    int simple = 0;
    for (i = 0; i < s; i++)
    {
        re = min(re, dp[s][i] + disksectord(s, i));
        simple += disksectord(i, i+1);
    }

    re += 800 * x + s * 10;
    cout << re << endl;
    simple += 400 * x + s * 10;
    cout << simple << endl;
    myfile.close();
    //system("pause");
    return 0;
}
