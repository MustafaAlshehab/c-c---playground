#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Strata core performance optimization - RS spikes on qml/qt alternative graph - Hello Strata improvements";
    
    printf("String before removing spaces: %s\n", s);
    printf("String size before removing spaces: %ld\n", strlen(s));
    
    int i = 0, j = 0;
    while ( i < strlen(s) ) {
        if ( s[i] == ' ' ) {
            i++;
            continue;
        }
        if ( i != j ) {
            s[j] = s[i];
        }
        i++;
        j++;
    }

    if ( i != j ) {
        s[j] = '\0';
    }

    printf("String after removing spaces: %s\n", s);
    printf("String size after removing spaces: %ld\n", strlen(s));
    
    return 0;
}


