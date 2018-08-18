// ��Ϊ���ǿ���ͨ���˷ѵ�һЩ"()"�����ﵽ��Ŀ��˵��Ҫ��Ŀǰ��Ŀ��������ȥ�˷�
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    if (n == k) // ����������еĳ��Ⱥ�ԭ������ȣ���ֱ�����������������е�
    {
        std::cout << s << std::endl;
    }
    else
    {
        int Delta = n - k;  // ����Ҫ�˷Ѷ��ٸ�"()"��

        std::string Ans;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '(')    // ����������ֱ���õ�
            {
                Ans.push_back('(');
            }
            else    // ����������Ҫ���������
            {
                if (Delta != 0) // ����Ҫ�˷ѵ�����
                {
                    Ans.pop_back(); // �˵�һ������
                    Delta -= 2;     // ��Ϊ�˷�һ�λ�������
                }
                else    // û��Ҫ�˷ѵ������ˣ�����ֱ�Ӽ�����������
                {
                    Ans.push_back(')');
                }
            }
        }
        std::cout << Ans << std::endl;
    }

    return 0;
}