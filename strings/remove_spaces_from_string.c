#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Strata core performance optimization - RS spikes on qml/qt alternative graph";
    
    printf("String before removing spaces: %s\n", s);
    printf("String length before removing spaces: %ld\n", strlen(s));
    
    int i = 0, j = 0;
    while ( i < strlen(s) ) {
        if (s[i] != ' ') {
            s[j] = s[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';
    
    printf("String after removing spaces: %s\n", s);
    printf("String length after removing spaces: %ld\n", strlen(s));
    
    return 0;
}


