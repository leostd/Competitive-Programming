#include <stdlib.h>
#include <stdio.h>



int main()
{
    int chs1[26], chs2[26], chs3[26];
    int t, i;
    char c;
    scanf("%d\n", &t);
    while(t--)
    {
        char str1[102], str2[102];
        i = 0;
        while (c = getchar(), c != '\n' && c != EOF)
            str1[i++] = c;
        str1[i] = '\0';
        i = 0;
        while (c = getchar(), c != '\n' && c != EOF)
            str2[i++] = c;
        str2[i] = '\0';
        int chs1[26] = {0}, chs2[26] = {0}, chs3[26] = {0};
        int i = 0, flag = 0;
        while(str1[i] != '\0')
        {
            if (str1[i] >= 'A' && str1[i] <= 'Z')
                chs1[str1[i] - 65]++;
            else if (str1[i] >= 'a' && str1[i] <= 'z')
                chs1[str1[i] - 97]++;
            i++;
        }
        i = 0;
        while(str2[i] != '\0')
        {
            if (str2[i] >= 'A' && str2[i] <= 'Z')
                chs2[str2[i] - 65]++;
            else if (str2[i] >= 'a' && str2[i] <= 'z')
                chs2[str2[i] - 97]++;
            i++;
        }
        
        for (int i = 0; i < 26; i++)
        {
            if (!flag)
            {
                if (chs1[i] < chs2[i])
                {
                    flag = 1;
                    chs3[i] = chs2[i] - chs1[i];
                }
                else if (chs1[i] > chs2[i])
                {
                    flag = 2;
                    chs3[i] = chs1[i] - chs2[i];
                }
            }
            else if (flag == 1)
            {
                if (chs1[i] > chs2[i] )
                {
                    flag = 3;
                    break;
                }
                else
                    chs3[i] = chs2[i] - chs1[i];
            }
            else if (flag == 2)
            {
                if (chs1[i] < chs2[i])
                {
                    flag = 3;
                    break;
                }
                else
                    chs3[i] = chs1[i] - chs2[i];
            }
        }

        if (flag == 1 || flag == 2)
        {
            int odds = 0, lodd;
            for (int i = 0; i < 26; i++)
            {
                if (chs3[i] % 2 > 0)
                {
                    odds++;
                    lodd = i;
                    chs3[i]--;
                }
            }
            if (odds > 1)
                flag = 3;
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    for(int j = 0; j < chs3[i]/2; j++)
                        printf("%c", i+97);
                }
                if (odds == 1)
                    printf("%c", lodd+97);
                for (int i = 25; i >= 0; i--)
                {
                    for (int j = 0; j < chs3[i]/2; j++)
                        printf("%c", i+97);
                }
                printf("\n");
            }
            
        }

        if (!flag)
            printf("YES\n");
        else if (flag == 3)
            printf("NO LUCK\n");
    }
    return 0;
}