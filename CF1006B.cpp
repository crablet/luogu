// ���ȣ������ܹ۲쵽��һ��Ҫ�����������������ǰk�����֮��
// ͨ�������������ҳ�ǰk�����
// Ȼ�����ǰ���ǰk�������λ���ҳ���������������Ϊ����ָ�����
// ע��ͷβ�Ĳ�������ͷ�Ǹ�0��β���Ǹ�n
#include <iostream>
#include <vector>
#include <algorithm>

class Pair
{
public:
    int Key, Pos;   // ����Posλ�ϵ���ΪKey

    Pair() = default;
    Pair(int k, int p)
        : Key(k), Pos(p)
    {
    }

    bool operator<(const Pair &rhs) const noexcept
    {
        return Key > rhs.Key || (Key == rhs.Key && Pos < rhs.Pos);
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<Pair> Vec(n);
    for (int i = 0; i < n; ++i)
    {
        int t;
        std::cin >> t;
        Vec[i] = Pair(t, i + 1);
    }
    std::sort(Vec.begin(), Vec.end());

    int Ans = 0;    // ǰk�����֮��
    for (int i = 0; i < k; ++i)
    {
        Ans += Vec[i].Key;
    }
    std::cout << Ans << std::endl;

    std::vector<int> Arr(k);
    for (int i = 0; i < k; ++i)
    {
        Arr[i] = Vec[i].Pos;
    }
    std::sort(Arr.begin(), Arr.end());

    int Last = 0;   // ��ͷ�Ǹ�0
    for (int i = 0; i < k - 1; ++i)
    {
        std::cout << Arr[i] - Last << ' ';  // �м��ֱ�������������
        Last = Arr[i];
    }
    std::cout << n - Last << std::endl; // β���Ǹ�n

    return 0;
}