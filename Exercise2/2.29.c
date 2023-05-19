//balancing parentheses
#include <stdio.h>

int main()
{
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < n; i++)
    {
        int len;
        scanf("%d\n", &len);

		

        char s[200];
        if (len > 0)
            scanf("%[^\n]%*c", s);
        int l = 0;
        int r = 0;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
                r++;
            else if (r > 0)
                r--;
            else
                l++;
        }
        printf("%d\n", l + r);
		
    }
    return 0;
}