#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decoder(char *s)
{
    char *res = calloc(1000000, sizeof(char));
    int ri = 0;
    int nums[5000] = {0}, ni = 0;
    int l[5000] = {0}, li = 0;

    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            ni++;
            l[li++] = ri;
        }
        else if (s[i] == ')')
        {
            int temp = ri;
            while (nums[ni - 1] > 1)
            {
                for (int j = l[li - 1]; j < temp; j++)
                {
                    res[ri++] = res[j];
                }
                nums[ni - 1]--;
            }
            nums[--ni] = 0;
            li--;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            nums[ni] *= 10;
            nums[ni] += s[i] - '0';
        }
        else
        {
            res[ri++] = s[i];
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        char s[65536];
        scanf("%[^\n]%*c", s);
        char *res = decoder(s);
        printf("%s\n", res);
    }
    return 0;
}