#include <iostream>
#include <algorithm>
#include <array>

using ll = long long;

constexpr int MaxN = 4000 + 5;
int n, c;
std::array<int, MaxN> A{ 0 }, B{ 0 }, C{ 0 }, D{ 0 };
std::array<int, MaxN * MaxN> Sums{ 0 }; // ���A[i]��B[j]������ӵĺ�

int main()
{
    int T;
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> A[i] >> B[i] >> C[i] >> D[i];
        }

        // ��һ���˼·ʮ��ֱ�ף�
        // ���ǰ�ÿһ��(A[i] + B[j])����϶��������
        // Ȼ�����Sums[]�У�
        // ���Ŷ�Sums[]����
        // Ȼ��Ѱ��ÿһ��(-C[i] - D[j])��Sums[]�г����˶��ٴΣ�����Щ��������������
        // ��Ӻ�Ľ�����Ǵ�

        c = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                Sums[c++] = A[i] + B[j];    // A[i]��B[j]�������
            }
        }
        std::sort(Sums.begin(), Sums.begin() + c); // ����Ϊ�˺�����ַ���

        ll cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // ��ʵ��������Sums[]���ж��ٸ�������(-C[i] - D[j])��Ȼ�������
                cnt += std::upper_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j])
                     - std::lower_bound(Sums.cbegin(), Sums.cbegin() + c, -C[i] - D[j]);
            }
        }

        std::cout << cnt << std::endl;

        if (T)
        {
            std::putchar('\n');
        }
    }

    return 0;
}