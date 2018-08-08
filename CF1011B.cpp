// ˼·����Ԥ����һ��ÿһ�����������˶��ٴΣ�Ȼ��ö�ٺϷ�������
#include <iostream>
#include <unordered_map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    if (n > m)  // ɮ�����٣�����һ�춼�߲���
    {
        std::cout << 0 << std::endl;
    }
    else if (n == m)    // �պ���ȣ�һ��һ�ڣ�һ�����
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::unordered_map<int, int> Map;
        for (int i = 0; i < m; ++i) // ͳ��ÿ�����������˶��ٴ�
        {
            int t;
            std::cin >> t;
            ++Map[t];
        }

        for (int k = m / n; k >= 1; --k)    // ö�ٺϷ���������k���������������ֻ����(m / n)��
        {
            int Tol = 0;
            for (const auto &r : Map)
            {
                Tol += r.second / k;
            }

            if (Tol >= n)   // һ������һ���Ϸ��ľ��˳�����Ϊ�����ǴӸ����ö�ٵ�
            {
                std::cout << k << std::endl;

                break;
            }
        }
    }

    return 0;
}