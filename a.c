#include <stdio.h>
void init(char **s)
{
char *a[] = {"Stay", "Safe", "From", "Covid"};
for (int i = 0; i < 4; i++)
s[i] = a[i];
}
 int main()
 {
 char *s[4];
 init(s);
 for (int i = 0; i < 4; i++)
 printf("%s\n", s[i]);
 return 0;
 }
