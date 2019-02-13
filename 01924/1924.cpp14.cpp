#include <stdio.h>

int main(void) {
    int monthday[13] = {0, 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31};
    int month, date;
    int datesum = 0;
    scanf("%d %d", &month, &date);
    
    for(int i = 1; i < month; i++)
    {
        datesum += monthday[i];
    }
    
    datesum += date;
    //printf("%d", datesum);
    //자 이제 나머지로 요일을 판단해야겠지?
    
    if(datesum % 7 == 1) printf("MON");
    else if(datesum % 7 == 2) printf("TUE");
    else if(datesum % 7 == 3) printf("WED");
    else if(datesum % 7 == 4) printf("THU");
    else if(datesum % 7 == 5) printf("FRI");
    else if(datesum % 7 == 6) printf("SAT");
    else if(datesum % 7 == 0) printf("SUN");
        
}