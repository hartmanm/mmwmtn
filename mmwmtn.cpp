#include <iostream>
//#include <bits/stdc++.h>
//#include <ctype.h>
// int price 
// int minPrice
// int maxPrice
// 3000000000
// >= minPrice
// <= maxPrice
// int number_of_trailing_nines
// api set minPrice,maxPrice 
//int price 
//int minPrice
//int maxPrice
//3000000000
//unsigned int j=0;
//unsigned int z=0;
// if(max_Price[0]!='9'){
// i++;
// numbers[0]=max_Price[0];
// //memcpy(numbers,max_Price,1);
// //printf("%s in\n",numbers);
// //number_of_digits--;
// }
//>= minPrice
//<= maxPrice
//printf("%c\n",max_Price[0]);
// for(j=number_of_digits;j>0;j--){
// z==atol(max_Price);
// }
// //printf("%d i\n",i);
// while(i<number_of_digits)
// {
// numbers[i]='9';
// i++;
// }
// char* number=NULL;
// char numbers[12];
// int number_of_trailing_nines=0;
// for(i=maxPrice;i>0;i--){
// }
// number_of_digits
// for(i=minPrice;i<=maxPrice;i++){
// while(max_Price[strlen(max_Price)]==9)
//     //number=NULL;
// if(i==9)number_of_trailing_nines=1;
// // if(i>9){
// // if(i==9)number_of_trailing_nines=1;
// // };
// if(i>=99){
// //if(i==99)number_of_trailing_nines=2;
// // 2999
// sprintf(numbers[0],"%ld",i);
// //printf()
// if(i-90==9)number_of_trailing_nines=2;
// };
// if(i>999){};
// if(i>9999){};
// if(i>99999){};
// if(i>999999){};
// if(i>9999999){};
// if(i>99999999){};
// if(i>999999999){};
// if(i>9999999999){};
// number_of_trailing_nines
// }
// //api set minPrice,maxPrice 
// //std::cout<< best << std::endl;


// min max with max trailing nines

// mmwmtn.cpp

// case_0 20 25 =25 -> should be 19
// case_1 460 680 =599 not checking all larger possible 9s
// case_2 1255 2999 =2999
// case_3 10 3000000000 =2999999999
// case_4 18696 18702 =18699
// case_5 80999 89099 =88999 too big

void get_price(char* min_Price,char* max_Price){
uint64_t minPrice=atoll(min_Price);
uint64_t maxPrice=atoll(max_Price);
uint8_t number_of_digits=strlen(max_Price);
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
//numbers[i]='\0';
//printf("%s\n",numbers);

//uint8_t number_of_nines=0;
uint8_t max_index=0;
uint8_t max_index_digit=0;

uint8_t non_nine_mapping[number_of_digits];
memset(non_nine_mapping,0,number_of_digits);
i=0;
// generate non_nine_mapping
while(i<number_of_digits){
//if(max_Price[i]=='9') non_nine_mapping[i]=0;
if(max_Price[i]!='9'){
non_nine_mapping[i]=1; 
//number_of_nines++;
if((i>0)&&(non_nine_mapping[i-1]==0)) max_index=i-1;
}
printf(" %d ",non_nine_mapping[i]);
i++;
}
printf("\n%d max_index\n",max_index);


//while(!flag){
if(max_index>0){
i=max_index;
max_index_digit=atoi((const char*)max_Price[i]);
max_index_digit--;
//char* here=nullptr;
//sprintf(here,"%d",max_index_digit);
max_Price[i]=(char)max_index_digit;
while(i+1<number_of_digits){
if(flag) numbers[i]='9';
i++;
}
}




// scan from left

// max_Price[i]!='9'
// sprintf(max_Price,"%lld",maxPrice);
// number_of_digits=strlen(max_Price);


// while(!flag){
// i=0;
// maxPrice-=10;
// sprintf(max_Price,"%lld",maxPrice);
// number_of_digits=strlen(max_Price);
// while(i<number_of_digits){
// if(max_Price[i]=='9') flag=1;
// if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
// if(flag) numbers[i]='9';
// i++;
// }
// }




// while(number_of_nines-1){

// maxPrice-=10;
// sprintf(max_Price,"%lld",maxPrice);
// number_of_digits=strlen(max_Price);
// while(i<number_of_digits){
// if(max_Price[i]=='9') flag=1;
// if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
// if(flag) numbers[i]='9';
// i++;
// }
// }
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

// g++ mmwmtn.cpp -o mmwmtn

// g++ mmwmtn.cpp -o mmwmtn; ./mmwmtn 20 25; ./mmwmtn 460 680; ./mmwmtn 1255 2999; ./mmwmtn 10 3000000000; ./mmwmtn 18696 18702; ./mmwmtn 80999 89099; echo "\n\n19\n599\n2999\n2999999999\n18699\n88999"

// case_0 20 25 =25 need to consider min
// case_1 460 680 =599 not checking all larger possible 9s
// case_2 1255 2999 =2999
// case_3 10 3000000000 =2999999999
// case_4 18696 18702 =18699
// case_5 80999 89099 =88999 too big
