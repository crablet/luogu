// 首先要明确一下，如果按照题意里的每次都DFS一下，肯定会T，而且第二个点就T了，别问我是怎么知道的
// 然后，我们其实只需要DFS一遍，记录下每个节点被DFS访问到的时刻，然后再记录一下一个节点后面能访问到的节点总数，用以判断是否存在u后k个元素
#include <iostream>
#include <vector>
#include <array>

constexpr int MaxN = 200000 + 5;

std::array<std::vector<int>, MaxN> G;
std::array<int, MaxN> DFN{ 0 }, Size{ 0 }, Pos{ 0 };

// DFN[x]: 节点x被DFS访问到的时刻
// Size[x]: 节点x下方有多少个节点（包括它自己）
// Pos[x]: DFS在x时刻访问到的节点编号

int Clock = 0;  // DFS时钟

void DFS(int p)
{
    Size[p] = 1;    // 一开始节点p及其下方节点就只有自己一个
    ++Clock;        // DFS访问时刻加一
    DFN[p] = Clock; // 记录下节点p被访问到的时刻
    Pos[Clock] = p; // 记录下该时刻访问到的是节点p

    for (const auto &q : G[p])  // 遍历p的所有直接相接的子节点
    {
        DFS(q);
        Size[p] += Size[q];     // p下方的节点数等于p的所有子节点下方的节点数之和
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    for (int i = 2; i <= n; ++i)
    {
        int p;
        std::cin >> p;
        G[p].push_back(i);
    }

    DFS(1); // 从根节点进行一遍DFS

    while (q--)
    {
        int u, k;
        std::cin >> u >> k;
        if (Size[u] < k)    // 如果节点u下方的所有节点数都没有k大，那么这个查询是失败的
        {
            std::cout << -1 << std::endl;
        }
        else                // 否则计算出u后k - 1个节点的编号，因为自身也算一个
        {
            std::cout << Pos[DFN[u] + k - 1] << std::endl;
        }
    }

    return 0;
}