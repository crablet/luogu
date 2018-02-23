#include <iostream>
#include <algorithm>
#include <array>
#include <cmath>

constexpr int MaxN = 1000 + 5;

// ��ŵ����Ϣ�Ľṹ��(x, y)����ԽǶ�Rad
struct Point
{
    int x, y;
    double Rad;
};

std::array<Point, MaxN> op, p;
std::array<int, MaxN> Color{ 0 };
int n;

// ���������������������OA�Ƿ�������OB����ߣ��Ӷ�ȷ����A�Ƿ��ڵ�B�����
// ��OA * OB >= 0�����A�ڵ�B������OA��OB����
// ��OA * OB < 0�����A�ڵ�B���Ҳ�
// ���������˲�����ʽ����һ��sinx���Ӷ�����ȷ������
// �����https://www.cnblogs.com/rhythmic/p/5727057.html
bool IsLeft(const Point &A, const Point &B)
{
    return A.x * B.y - A.y * B.x >= 0;
}

int Solve()
{
    if (n <= 2)
    {
        return 2;
    }

    // ����һ�����㼸���⣺
    // ��O-p[i]��Ϊ�ָ��ߣ���O-p[j]��Ϊɨ����
    // ��Ҫ��ɨ��ĵ㰴��������
    // �����ж��ٸ�����O-p[i]���
    // Ȼ����ת�ָ��ߣ�����ɨ��
    int Ans = 0;    // ���������ĺڵ�Ͱ׵�ĺͣ������Ϊ�𰸷���
    for (int i = 0; i < n; ++i) // ö�ٻ�׼��op[i]
    {
        int k = 0;  // ɨ���ߵı��
        for (int j = 0; j < n; ++j) // ����op[i]��op[j]���Դ���Ϊɨ����
        {
            if (i != j) //ȷ����Ҫѡ��ͬһ����
            {
                p[k].x = op[j].x - op[i].x; // �൱��delta x
                p[k].y = op[j].y - op[i].y; // �൱��delta y

                                            // ����Ǻڵ㣬�ǾͰ�����Ϊ�׵㣬���ҽ�������ת180��
                if (Color[j])   // ����Ϊ�˷����������Ϊ���ұߵĵ����Ϳ��Ȼ��������ߵİ׵�
                {               // �������ֻҪѡȡ����ߵİ׵㼴��
                    p[k].x = -p[k].x;
                    p[k].y = -p[k].y;
                }

                // ����Ҫע��std::atan��std::atan2��һ����std::atan2�����ȷ����Ϊ�����˸��������
                p[k].Rad = std::atan2(p[k].y, p[k].x);  // �����б�ǣ����еĹ�ʽ��

                ++k;    // ɨ���߱�ż�һ
            }
        }

        // ���㰴�������򣬴�С������
        std::sort(p.begin(), p.begin() + k, [](const Point &A, const Point &B)
        {
            return A.Rad < B.Rad;
        });

        int L = 0, R = 0, cnt = 2;
        while (L < k)   // ö��ÿһ����
        {
            if (R == L) // ��������ʱ�ȶ���һ���㣬�����ȥ
            {
                R = (R + 1) % k;
                ++cnt;
            }

            // �����L�ڵ�R����ߣ��Ǿͼ�һ��Ȼ��ɨ������ת
            // ע�������R�ķ�Χ��[0, k)
            while (R != L && IsLeft(p[L], p[R]))
            {
                R = (R + 1) % k;
                ++cnt;
            }

            --cnt;  // ��ȥ������һ����
            ++L;    // ��ת�ָ���

            Ans = std::max(Ans, cnt);   // ���´�
        }
    }

    return Ans;
}

int main()
{
    while (std::cin >> n && n)
    {
        for (int i = 0; i < n; ++i)
        {
            std::cin >> op[i].x >> op[i].y >> Color[i];
        }

        std::cout << Solve() << std::endl;
    }

    return 0;
}