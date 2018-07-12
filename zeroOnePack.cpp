/*******************************************************************************
功    能：动态规划-经典0-1背包问题
创建时间： 2018-07-03
作    者：Elvan
修改时间：
作    者：
********************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX = 100;
int f[MAX][MAX]; //存储最优解
int dp[MAX];     //存储最优解

/************************************************************
 * 函 数 名：int ZeroOnePack(int v[], int w[], int n, int V)
 * 函数功能：动态规划求解最大价值和分配方案
 * 函数参数：v-价值，w-重量，n-物品种类，V-背包容量
 * 返 回 值：最大价值
 * 作    者：Elvan
 * 创建日期：2018-07-12
 * **********************************************************/
int ZeroOnePack(int v[], int w[], int n, int V)
{
    //初始化
    for (int j = 1; j <= V; j++)
        f[0][j] = 0;

    //求解最优解
    for (int i = 1; i <= n; i++)
    {
        for (int j = w[i - 1]; j <= V; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }

    int c = V;
    int x[n]; //分配状态
    for (int i = n; i >= 1; i--)
    {
        if (f[i][c] == f[i - 1][c])
            x[i - 1] = 0;
        else
        {
            x[i - 1] = 1;
            c -= w[i - 1];
        }
    }

    //打印最终结果
    cout << "二维数组规划-最大价值为：" << f[n][V] << endl;
    cout << "分配状态为：";
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
    return f[n][V];
}

/************************************************************
 * 函 数 名：int ZeroOnePack(int v[], int w[], int n, int V)
 * 函数功能：动态规划求解最大价值
 * 函数参数：v-价值，w-重量，n-物品种类，V-背包容量
 * 返 回 值：最大价值
 * 作    者：Elvan
 * 创建日期：2018-07-12
 * **********************************************************/
int ZeroOnePack2(int v[], int w[], int n, int V)
{
    for (int i = 1; i <= V; i++)
    {
        dp[i] = 0;
    }

    //求解最优解
    for (int i = 1; i <= n; i++)
    {
        for (int j = V; j >= w[i - 1]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
        }
    }
    //打印最终结果
    cout << "一位数组规划-最大价值为：" << dp[V] << endl;
    return dp[V];
}

int main(int argc, char const *argv[])
{
    int v[5] = {6, 3, 5, 4, 6};
    int w[5] = {2, 2, 6, 5, 4};
    int n = 5;  //物体个数
    int V = 10; //背包最大容量

    ZeroOnePack(v, w, n, V);  //经典
    ZeroOnePack2(v, w, n, V); //优化之后
    return 0;
}
