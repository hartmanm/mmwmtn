/*
Copyright (c) 2023 Michael Neill Hartman. All rights reserved.
mnh_license@proton.me
https://github.com/hartmanm
*/

#include <iostream>
void get_price(char* min_Price,char* max_Price){
uint64_t minPrice=atoll(min_Price);
uint64_t maxPrice=atoll(max_Price);
uint8_t number_of_digits=strlen(max_Price);
uint8_t number_of_nines=0;
char numbers[number_of_digits+1];
uint64_t i=0;
uint8_t flag=0;
while(i<number_of_digits){
if(max_Price[i]=='9') flag=1;
if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
if(flag) numbers[i]='9';
i++;
}
while(!flag){
i=0;
maxPrice--;
sprintf(max_Price,"%lld",maxPrice);
number_of_digits=strlen(max_Price);
while(i<number_of_digits){
if(max_Price[i]=='9') flag=1;
if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
if(flag) numbers[i]='9';
i++;
}
}
numbers[i]='\0';
printf("%s\n",numbers);
while(!flag){
i=0;
maxPrice-=10;
sprintf(max_Price,"%lld",maxPrice);
number_of_digits=strlen(max_Price);
while(i<number_of_digits){
if(max_Price[i]=='9') flag=1;
if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
if(flag) numbers[i]='9';
i++;
}
}
//number_of_nines
numbers[i]='\0';
printf("%s\n",numbers);
}
int main(
int   number_of_parameters,
char* parameters[],
char* environment[]
){
if(number_of_parameters>2) get_price(parameters[1],parameters[2]);
return 0; 
}
/*
g++ mmwmtn.cpp -o mmwmtn
./mmwmtn 20 25
./mmwmtn 460 680
./mmwmtn 1255 2999
./mmwmtn 10 3000000000
./mmwmtn 18696 18702
./mmwmtn 80999 89099
echo "\n\n19\n599\n2999\n2999999999\n18699\n88999"
*/
// case_0 20 25 =25 -> should be 19
// case_1 460 680 =599 not checking all larger possible 9s
// case_2 1255 2999 =2999
// case_3 10 3000000000 =2999999999
// case_4 18696 18702 =18699
// case_5 80999 89099 =88999 too big

// `head -61 mmwmtn.cpp | tail -1`
