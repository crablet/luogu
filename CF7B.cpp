// ����һ��ģ���⣬������һЩСϸ��Ҫע��
// ����������ע��
#include <iostream>
#include <string>
#include <array>

int main()
{
    std::array<int, 100> Arr{ 0 };
    int t, m;
    std::cin >> t >> m;

    int id = 1; // �������Զ�ı�ţ���1��ʼ
    std::string Command;
    while (t--)
    {
        std::cin >> Command;
        if (Command[0] == 'a')  // "alloc"
        {
            int p;
            std::cin >> p;

            int cnt = 0, idx = 0;
            bool OK = false;
            for (int i = 0; i < m; ++i)
            {
                if (!Arr[i])
                {
                    ++cnt;  // ȥ���ж��ٸ�������0
                }
                else
                {
                    cnt = 0;    // �ж��˾���������
                    idx = i + 1;
                }

                if (cnt == p)   // �����⣬�ҵ��˵�һ���ܴ��p����λ�ľ���������
                {
                    OK = true;
                    break;
                }
            }

            if (OK)
            {   // ��idx��ʼͿ������p��
                for (int i = idx; i < idx + p; ++i)
                {
                    Arr[i] = id;
                }

                // ����Ҫ��һ��
                std::cout << id++ << std::endl;
            }
            else
            {
                std::puts("NULL");
            }
        }
        else if (Command[0] == 'e') // "erase"
        {
            int p;
            std::cin >> p;

            if (p > id || p <= 0)   // ɾ�����������Ļ���ɾ��1���µľ�Ϊ�Ƿ�
            {
                std::puts("ILLEGAL_ERASE_ARGUMENT");
            }
            else
            {
                int f = false;
                int i;
                for (i = 0; i < m; ++i)
                {
                    if (Arr[i] == p)    // ȥ��Ҫ��ɾȥ�ĵ�һ�������±�
                    {
                        break;
                    }
                }

                while (Arr[i] == p)
                {
                    Arr[i] = 0; // ���㼴��ɾ��
                    ++i;
                    f = true;   // ���ɾ��������ִ����
                }

                if (!f) // �����һ��ɾ��û�����κβ�������ô���ɾ��Ҳ����Ч��
                {
                    std::puts("ILLEGAL_ERASE_ARGUMENT");
                }
            }
        }
        else   // "defragment"
        {
            int idx = 0;
            for (int i = 0; i < m; ++i)
            {
                if (Arr[i]) // ������㣬������ǰ��
                {
                    Arr[idx++] = Arr[i];
                }
            }
            for (int i = idx; i < m; ++i)   // �����ǲ��ֶ�����
            {
                Arr[i] = 0;
            }
        }
    }

    return 0;
}