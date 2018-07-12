/*******************************************************************************
功    能：动态规划-混合多种背包问题
创建时间： 2018-07-06
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

// /************************************************************
//  * 函 数 名：int MixPack(int v[], int w[], int t[], int n, int V)
//  * 函数功能：动态规划求解最大价值和分配方案
//  * 函数参数：v-价值，w-重量，t-每件物品最大个数，n-物品种类，V-背包容量
//  * 返 回 值：最大价值
//  * 作    者：Elvan
//  * 创建日期：2018-07-12
//  * **********************************************************/
// int MixPack(int v[], int w[], int t[], int n, int V)
// {
//     //初始化
//     for (int j = 0; j <= V; j++)
//         f[0][j] = 0;
//     //求解最优解
//     for (int i = 1; i <= n; i++)
//     {
//         //完全背包问题
//         if (t[i - 1] == -1)
//         {
//             for (int j = w[i - 1]; j <= V; j++)
//                 f[i][j] = max(f[i - 1][j], f[i][j - w[i - 1]] + v[i - 1]);
//         }
//         //0-1背包或者多重背包
//         else
//         {
//             for (int j = w[i - 1]; j <= V; j++)
//             {
//                 //第i个物品的最大可能数量
//                 int count = min(t[i - 1], j / w[i - 1]);
//                 int tmp = 0;
//                 for (int k = 0; k <= count; k++)
//                 {
//                     if (f[i - 1][j - w[i - 1] * k] + v[i - 1] * k > tmp)
//                         tmp = f[i - 1][j - w[i - 1] * k] + v[i - 1] * k;
//                 }
//                 f[i][j] = max(f[i - 1][j], tmp);
//             }
//         }
//     }

//     int c = V;
//     int x[n]; //分配状态
//     for (int i = n; i >= 1; i--)
//     {
//         int tmp;
//         //如果为-1，表示可以取多个而不是-1
//         if (t[i - 1] == -1)
//             tmp = c / w[i - 1];
//         else
//             tmp = min(c / w[i - 1], t[i - 1]);

//         for (int j = 0; j <= tmp; j++)
//         {
//             if (f[i][c] == f[i - 1][c - j * w[i - 1]] + j * v[i - 1])
//             {
//                 x[i - 1] = j;
//                 c -= j * w[i - 1];
//                 break;
//             }
//             else
//             {
//                 x[i - 1] = 0;
//             }
//         }
//     }

//     //打印最终结果
//     cout << "二维数组规划-最大价值为：" << f[n][V] << endl;
//     cout << "分配状态为：";
//     for (int i = 0; i < n; i++)
//     {
//         cout << x[i] << " ";
//     }
//     cout << endl;
//     return f[n][V];
// }

/************************************************************
 * 函 数 名：int MixPack2(int v[],int w[],int t[],int n,int V)
 * 函数功能：动态规划求解最大价值
 * 函数参数：v-价值，w-重量，t-每件物品最大个数，n-物品种类，V-背包容量
 * 返 回 值：最大价值
 * 作    者：Elvan
 * 创建日期：2018-07-12
 * **********************************************************/
int MixPack2(int v[], int w[], int t[], int n, int V)
{
    for (int i = 1; i <= V; i++)
    {
        dp[i] = 0;
    }
    //求解最优解
    for (int i = 1; i <= n; i++)
    {
        //完全背包问题
        if (t[i - 1] == -1)
        {
            for (int j = w[i - 1]; j <= V; j++)
            {
                dp[j] = max(dp[j], dp[j - w[i - 1]] + v[i - 1]);
            }
        }
        //0-1背包或者多重背包问题
        else
        {
            for (int j = V; j >= w[i - 1]; j--)
            {
                int count = min(t[i - 1], j / w[i - 1]);
                int tmp = 0;
                for (int k = 0; k <= count; k++)
                {
                    if (dp[j - w[i - 1] * k] + v[i - 1] * k > tmp)
                        tmp = dp[j - w[i - 1] * k] + v[i - 1] * k;
                }
                dp[j] = max(dp[j], tmp);
            }
        }
    }
    //打印最终结果
    cout << "一维数组规划-最大价值为：" << dp[V] << endl;
    return dp[V];
}

int main(int argc, char const *argv[])
{
    int v[3] = {1, 3, 5};
    int w[3] = {2, 3, 4};
    int t[3] = {-1, 1, 4}; //若为-1，则表示可以放无限件
    int n = 3;             //物体个数
    int V = 10;            //背包最大容量

    //int max = MixPack(v, w, t, n, V);   //经典
    int max2 = MixPack2(v, w, t, n, V); //优化
    return 0;
}
