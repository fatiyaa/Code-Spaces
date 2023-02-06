#include <stdio.h>
#include <string.h>
#include <math.h>
int from_base, to_base, temp[100], num_base[100];
char in_num[100], out_num[100];
int y, basisten=0;

//convert to number base ten
int ten(int digit[100]){
    for (int i=0; i<strlen(in_num); i++) basisten+= digit[i]*pow(from_base,(strlen(in_num)-1-i));
    return basisten;
}

// convert to base requested
void conv(int x){
    for (int i=0; x>0; i++){
        num_base[i]=x%to_base;
        x/=to_base;
        y=i+1;
    }
    for(int i=0; i<y; i++){
        if (num_base[i]<=9) num_base[i]= num_base[i]+48;
        else if (num_base[i]>9) num_base[i]=num_base[i]+55;
    }
    for(int i=y; i>=0; i--){
        out_num[i]=num_base[i];
        printf("%c", out_num[i]);
    }
}

int main(){
    printf("Input Number : ");
    scanf("%s", in_num);
    printf("Input Number Base : ");
    scanf("%d", &from_base);
    printf("Convert to Base : ");
    scanf("%d", &to_base);
    // convert string input number to integer using ascii
    for (int i=0; i<strlen(in_num); i++){
        if (in_num[i]>= 'A') temp[i]=in_num[i]-55;
        else if (in_num[i]>='0') temp[i]=in_num[i]-48;
    }

    if (to_base==10)printf("Converted Number : %d", ten(temp));
    else {
        printf("Converted Number : ");
        conv(ten(temp));
    }
    return 0;
}