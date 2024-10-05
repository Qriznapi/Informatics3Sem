#include <stdio.h>

void set_characters(const char* begin, const char* end, char c)
{
    for (char* p = begin; p < end; p += 1){
        *p = c;
    }
}

int main66()
{
    char s[] = "Sapere Aude";
    set_characters(&s[2], &s[8], 'b');
    printf("%s\n", s);
    set_characters(s, &s[4], 'a');
    printf("%s\n", s);
}
