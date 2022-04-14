//adder 'emulation'
#include<stdio.h>
#include<stdlib.h>
//function returning adder value
int sum1(int a1, int a2, int a3){
    if((a1 == 1) && (a2 == 1) && (a3 == 0)){
        return 0;
    }
    else if(a1 == 1 && a2 == 1 && a3 == 1){
        return 1;
    }
    else if((a1 == 1 && a2 == 0 && a3 == 1) || 
    (a1 == 0 && a2 == 1 && a3 == 1)){
        return 0;
    }
    else if((a1 > a2) && a3 == 0){
        return 1;
    }
    else if((a1 < a2) && a3 == 0){
        return 1;
    }
    else if(a1 == 0 && a2 == 0 && a3 == 1){
        return 1;
    }
    else if(a1 == 0 && a2 == 0){
        return 0;
    }

}



int main(void){
    //question
    int bit;
    printf("How many bits?:\n");
    scanf("%i",&bit);
    printf("Adder: %i-bit\n",bit);
    printf("Add first value:\n");
    int a1[bit];
    for (int i = 0; i < bit; i++){
        scanf("%i",&a1[i]);
    }
    printf("Add second value\n");
    int a2[bit];
    for (int i = 0; i < bit; i++){
        scanf("%i",&a2[i]);
    }
    //summation
    int a3[bit];
    int a4[bit + 1];
    a4[-1]=0;
    for (int i = 0; i < bit + 1; i++)a4[i] = 0;
    
    for(int k = 0;k < bit;k++){
        a3[k] = sum1(a1[k],a2[k],a4[k-1]);
        if((a1[k] == 1 && a2[k] == 1) || 
        (a1[k] == 1 && a2[k] == 1 && a4[k-1] == 1) ||
        (a1[k] == 1 && a2[k] == 0 && a4[k-1] == 1) ||
        (a1[k] == 0 && a2[k] == 1 && a4[k-1] == 1)){
            a4[k] = 1;
    }
    }
    for (int i = 0; i < bit; i++){
        printf("%i",a3[i]);
    }
    printf("\n");
    

    return 0;
}