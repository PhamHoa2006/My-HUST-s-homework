//C 
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
int main() 
{ 
    long long sum  = 0;
    int countBug = 0;
    
    char* str = (char *)malloc(10000000*sizeof(char));
    scanf("%s",str);
    int length = strlen(str);
    if(str[0]<'0'||str[0]>'9'||str[length-1]<'0'||str[length-1]>'9'){
        printf("NOT_CORRECT");
        return 0;
    }
    for (int i = 0; i<length; i++){
        long long so = 0;
        while (str[i]>='0'&&str[i]<='9'){
            so = so*10 + (str[i]-'0');
            countBug = 0;
            i++;
            if (i >= length) {
                sum += so;
                printf("%lld",so);
                return 0;
            }
            
        }
        if(str[i] == '+'){
            sum += so;
            countBug++;
        } else if (str[i]<'0'||str[i]>'9') {
            printf("NOT_CORRECT");
            return 0;
        }
        if(countBug > 1) {
            printf("NOT_CORRECT");
            return 0;
        }
    }
    
}