// �������˽�һ��λ�����һЩ����������
// &����ʾһ��Ԫ���Ƿ������������
// |����ʾ�����Ԫ�ؼ������������
// ^����ʾ�����Ԫ�ش����������ɾ��
// Ȼ�����Ǿ��ö���������ÿһλ��ʾһ����Ŀ��״̬
// �����Ǽ򵥵�dp���ѵ����ڶԸ�����Ŀ״̬�ı��
// ��������ע��
#include <iostream>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <string>

constexpr int MaxN = 100 + 20 + 5;
constexpr int MaxS = 8;
constexpr int INF = 1000000000;

int m, n, s, c[MaxN], st[MaxN], d[MaxN][1 << MaxS][1 << MaxS];

// dp(i, s0, s1, s2)��ʾ��
// �Ѿ�������ǰi���ˣ���ʣs0��û�˻�Ŀ�Ŀ��s1��һ�˻�Ŀ�Ŀ��s2���������ϻ�Ŀ�Ŀ
int dp(int i, int s0, int s1, int s2)
{
    if (i == m + n) // ���������е�����
    {   // ���s2��û���Ļ����Ǿ�˵��������������
        return s2 == (1 << s) - 1 ? 0 : INF;
    }

    int &Ans = d[i][s1][s2];
    if (Ans >= 0)   // ���仯���������֣���Ϊû���ѹ���ʱ����-1
    {
        return Ans;
    }

    Ans = INF;  // û���ѹ������ȳ�ʼ��һ�£���ΪINF
    if (i >= m)
    {
        // �ڿ�ѡ�������ȴ��ѡi���������ѡi�Ľ�����ȴ�������ѡi�ĵĽ���Ƚϡ�
        Ans = dp(i + 1, s0, s1, s2);
    }

    // ������ѡi�������
    // m0����st[i]��û�˻�ģ���i���
    // m1����st[i]��ֻ��һ���˻�ģ�iҲ���
    int m0 = st[i] & s0, m1 = st[i] & s1;
    s0 ^= m0;   // ��s0��������Щi���
    s1 = (s1 ^ m1) | m0;    // ���Ѿ���һ���˻�ļ��������ȥi��ģ�
                            // ��Ϊ�����Ļ����������˻���
                            // Ȼ���ټ���i���еĻ�ģ��ͳ����µ�һ�˻�ļ���
    s2 |= m1;   // ��s2�м���m1����ʾ�����������˻������ô��
    Ans = std::min(Ans, c[i] + dp(i + 1, s0, s1, s2));  // ����ѡi���ǲ�ѡi��

    return Ans;
}

int main()
{
    int x;
    std::string Line;
    while (std::getline(std::cin, Line))
    {
        std::stringstream ss(Line);
        ss >> s >> m >> n;  // ��s����Ŀ��m����ְ��n��ӦƸ
        if (s == 0)
        {
            break;
        }

        for (int i = 0; i < m + n; ++i)
        {
            std::getline(std::cin, Line);
            std::stringstream ss(Line);
            ss >> c[i]; // ��i������Ҫ�Ĺ���
            st[i] = 0;  // ���̵ܽĿ�Ŀ����Ϊ��
            while (ss >> x)
            {
                st[i] |= (1 << (x - 1));    // ��ӽ�ȥ�����̵ܽĿ�Ŀ��������
            }                               // ��һ����Ϊ�����еı�Ŵ�1��ʼ
        }

        std::memset(d, -1, sizeof(d));  // ��ʾ��û�б��ѹ�
        std::cout << dp(0, (1 << s) - 1, 0, 0) << std::endl;
    }             // ��ʼ��ʱ���п�Ŀ��û�˽̣���0�ſ�ʼ��

    return 0;
}