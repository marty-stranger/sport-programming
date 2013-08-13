#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char s[5000+1]; scanf("%s", s);
    int sn = strlen(s);

    char t[5000+1]; scanf("%s", t);
    int tn = strlen(t);

    char ans[5000+1];
    bool ff = false;
    for (int i = 0; i <= tn; i++) {
        int cs[200] = {0};
        for (char *c = s; *c != 0; c++)
            cs[*c]++;

        char r[5000+1];

        bool f = true;
        for (int j = 0; j < i; j++)
            if (cs[t[j]] == 0) {
                f = false;
                break;
            } else {
                cs[t[j]]--;
                r[j] = t[j];
            }

        if (!f)
            continue;

        char ch;
        if (i < tn)
            ch = t[i]+1;
        else
            ch = 'a';

        while (ch <= 'z' && cs[ch] == 0)
            ch++;

        if (ch > 'z')
            continue;

        cs[ch]--;
        r[i] = ch;

        int j = i+1;
        for (char ch = 'a'; ch <= 'z'; ch++)
            while (cs[ch] != 0) {
                r[j] = ch;
                cs[ch]--;
                j++;
            }

        r[j] = 0;

        if (!ff || strcmp(r, ans) < 0) {
            ff = true;
            strcpy(ans, r);
        }
    }

    if (!ff)
        puts("-1");
    else
        puts(ans);

    return 0;
}
