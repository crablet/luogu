// ��һ�����������ƶ�̬�滮��˼��
// ö��ÿһ�ֺϷ��������Ȼ��ͳ�Ƹ��ʺ�
// ��һ�¼��仯������������������
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <map>

std::map<std::vector<int>, double> d;
std::array<std::array<std::string, 4>, 9> Card;

// cnt���Ƶ����
// c��һ������c����
double DP(std::vector<int> &cnt, int c)
{
    if (c == 0)
    {
        return 1.0;
    }

    if (d.count(cnt) != 0)  // ���仯����
    {
        return d[cnt];
    }

    double Sum = 0.0;
    int Tot = 0;
    for (int i = 0; i < 9; ++i) // ö��ÿһ����
    {
        if (cnt[i] > 0) // �����ʣ����
        {
            for (int j = i + 1; j < 9; ++j)
            {
                if (cnt[j] > 0)
                {
                    // �ǾͱȽ�һ�¶Ѷ������Ƿ���ֵһ��
                    // ȡ����ĸ�ͺ��ˣ������[0]
                    if (Card[i][cnt[i] - 1][0] == Card[j][cnt[j] - 1][0])
                    {
                        ++Tot;  // ͳ��ȡ�˶��ٴ�
                        --cnt[i];   // ����
                        --cnt[j];

                        Sum += DP(cnt, c - 2);  // ͳ�Ƹ���

                        ++cnt[i];   // �Ż�ȥ������
                        ++cnt[j];
                    }
                }
            }
        }
    }

    if (Tot == 0)
    {
        return d[cnt] = 0;  // ���仯
    }
    else
    {
        return d[cnt] = Sum / Tot;  // ���仯
    }
}

bool Read()
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (!(std::cin >> Card[i][j]))
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    while (Read())
    {
        // cnt[i]��ʾ��i�������滹ʣ�¶�����
        // ��ʼʱΪ9���ƣ�ÿ��4��
        std::vector<int> cnt(9, 4);
        d.clear();
        std::printf("%.6lf\n", DP(cnt, 36));
    }

    return 0;
}