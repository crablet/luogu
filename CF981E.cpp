// dp�⣬��⿴���뼰�ҵ�ע�ͣ�ϣ���ܶԴ����������
#include <iostream>
#include <array>
#include <tuple>
#include <algorithm>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<std::tuple<int, int, int>> Q;   // �˵��<l, r, x>�ļ���
    for (int i = 0; i < q; ++i)
    {
        int l, r, x;
        std::cin >> l >> r >> x;
        Q.push_back({ l, r, x });
    }
    std::sort(Q.begin(), Q.end(), [](const auto &l, const auto &r) // ���Ҷ˵��С�����������
    {
        return std::get<1>(l) < std::get<1>(r);
    });

    constexpr int MaxN = 10000 + 5;
    std::array<int, MaxN> dp{ 0 };

    // dp[i]��ʾ����i�ܹ��ﵽ�����ұߵĶ˵�λ�ã��������i�޷�ȡ����Ϊ0
    // ��ʼ״̬��dp[0] = n����Ϊһ��ʼȫ��0��0������ܴﵽ���ҵĶ˵�n
    dp[0] = n;
    for (int i = 0; i < q; ++i) // ����֮�����ÿһ������
    {
        const auto &[l, r, x] = Q[i];

        for (int j = n; j >= x; --j)    // ���ڲ��ܳ���n�����Դ�n����ѭ���������׵�ʱ��j - x����С���㣬����½���x
        {
            if (dp[j - x] >= l) // �����˵�С��j - x���ڵ�����λ�ã�˵��j - x�п��ܱ�������ϵ�x���¡�Ȼ�����������ָ��·�ʽ��
            {
                if (dp[j - x] <= r) // �����ǰ�����ܹ�����j - x���ڵ����Ҷ˵㣬˵��j - x���Ա�����Ϊj����ô�Ϳ�һ�¸���֮���Ƿ�������j�����Ҷ�
                {
                    dp[j] = std::max(dp[j], dp[j - x]);
                }
                else // �����ǰ���䲻�ܰ���j - x���ǾͿ����ܲ��ܸ���x��λ�ã�����r�԰���С������������ֱ�Ӹ�ֵr�����ˣ����ǵ�����
                {
                    dp[x] = r;
                }
            }
        }
    }

    int Ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i])  // ͳ���ܴﵽ�������ж��ٸ�����Ϊ����ԭ�ȵ�Լ�����޷�ȡ�õ������Ҷ˵㱻��Ϊ��0
        {
            ++Ans;
        }
    }

    // ���������
    std::cout << Ans << std::endl;
    for (int i = 1; i <= n; ++i)
    {
        if (dp[i])
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;

    return 0;
}