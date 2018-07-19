// ����Ҫ��ȷһ�£���������������ÿ�ζ�DFSһ�£��϶���T�����ҵڶ������T�ˣ�����������ô֪����
// Ȼ��������ʵֻ��ҪDFSһ�飬��¼��ÿ���ڵ㱻DFS���ʵ���ʱ�̣�Ȼ���ټ�¼һ��һ���ڵ�����ܷ��ʵ��Ľڵ������������ж��Ƿ����u��k��Ԫ��
#include <iostream>
#include <vector>
#include <array>

constexpr int MaxN = 200000 + 5;

std::array<std::vector<int>, MaxN> G;
std::array<int, MaxN> DFN{ 0 }, Size{ 0 }, Pos{ 0 };

// DFN[x]: �ڵ�x��DFS���ʵ���ʱ��
// Size[x]: �ڵ�x�·��ж��ٸ��ڵ㣨�������Լ���
// Pos[x]: DFS��xʱ�̷��ʵ��Ľڵ���

int Clock = 0;  // DFSʱ��

void DFS(int p)
{
    Size[p] = 1;    // һ��ʼ�ڵ�p�����·��ڵ��ֻ���Լ�һ��
    ++Clock;        // DFS����ʱ�̼�һ
    DFN[p] = Clock; // ��¼�½ڵ�p�����ʵ���ʱ��
    Pos[Clock] = p; // ��¼�¸�ʱ�̷��ʵ����ǽڵ�p

    for (const auto &q : G[p])  // ����p������ֱ����ӵ��ӽڵ�
    {
        DFS(q);
        Size[p] += Size[q];     // p�·��Ľڵ�������p�������ӽڵ��·��Ľڵ���֮��
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

    DFS(1); // �Ӹ��ڵ����һ��DFS

    while (q--)
    {
        int u, k;
        std::cin >> u >> k;
        if (Size[u] < k)    // ����ڵ�u�·������нڵ�����û��k����ô�����ѯ��ʧ�ܵ�
        {
            std::cout << -1 << std::endl;
        }
        else                // ��������u��k - 1���ڵ�ı�ţ���Ϊ����Ҳ��һ��
        {
            std::cout << Pos[DFN[u] + k - 1] << std::endl;
        }
    }

    return 0;
}