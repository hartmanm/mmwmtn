/*
Copyright (c) 2023 Michael Neill Hartman. All rights reserved.
mnh_license@proton.me
https://github.com/hartmanm
*/

#include <iostream>
#include <cstring>

// min max with max trailing nines

// uint8_t match(char char_ptr){
// if(char_ptr=='9') return 9;
// if(char_ptr=='9') return 9;

// }

uint8_t get_price(char* min_Price,char* max_Price){
uint8_t number_of_digits=strlen(max_Price);
char numbers[number_of_digits+1];


if(number_of_digits==1){
numbers[0]=max_Price[0];
numbers[number_of_digits]='\0';
printf("numbers:\n%s\n\n",numbers);
return 0;
}

uint8_t maxPrice_digit=0;
if(number_of_digits==2){
if(min_Price[0]==max_Price[0]){
numbers[0]=max_Price[0];
numbers[1]=max_Price[1];
numbers[number_of_digits]='\0';
printf("numbers:\n%s\n\n",numbers);
return 0;
}
if(min_Price[0]!=max_Price[0]){
maxPrice_digit=uint8_t(max_Price[0]);
if(maxPrice_digit>1){
maxPrice_digit--;
if(maxPrice_digit>1){
printf("maxPrice_digit=%d\n",maxPrice_digit);
numbers[0]=(char)maxPrice_digit; 
numbers[1]='9';
numbers[number_of_digits]='\0';
printf("numbers:\n%s\n\n",numbers);
return 0;
}
}
else printf("todo\n");
}
}







// if(number_of_digits==3){
// if(min_Price[0]==max_Price[0]){
// numbers[0]=max_Price[0];
// numbers[1]=max_Price[1];
// numbers[number_of_digits]='\0';
// printf("numbers:\n%s\n\n",numbers);
// return 0;
// }
// if(min_Price[0]!=max_Price[0]){
// maxPrice_digit=uint8_t(max_Price[0]);
// if(maxPrice_digit>1){
// maxPrice_digit--;
// if(maxPrice_digit>1){
// printf("maxPrice_digit=%d\n",maxPrice_digit);
// numbers[0]=(char)maxPrice_digit; 
// numbers[1]='9';
// numbers[number_of_digits]='\0';
// printf("numbers:\n%s\n\n",numbers);
// return 0;
// }
// }
// else printf("todo\n");
// }
//}



// acc process 3 digits

// process leading match

// slide to end of leading match

// use acc

// 2 digit look ahead


uint64_t i=0;
uint64_t minPrice=atoll(min_Price);
uint64_t maxPrice=atoll(max_Price);
maxPrice_digit=0;

// u_int8_t max_number_of_ending_nines=0;
// if(maxPrice<15999){

// while(minPrice<maxPrice){


// minPrice++;
// }

// }





uint8_t flag=0;

//char* maxPrice_char=NULL;

// generate non_nine_mapping
uint8_t max_index=0;
uint8_t contains_nine=0;
uint8_t non_nine_mapping[number_of_digits];
memset(non_nine_mapping,0,number_of_digits);
while(i<number_of_digits){
if(max_Price[i]!='9'){
non_nine_mapping[i]=1; 
if((i>0)&&(non_nine_mapping[i-1]==0)) max_index=i-1;
}
if(max_Price[i]=='9') contains_nine=1;
printf(" %d ",non_nine_mapping[i]);
i++;
}
printf("max_index %d\nnumber_of_digits %d\ncontains_nine %d\n",max_index,number_of_digits,contains_nine);
//uint8_t contains_nine=0;
//if(max_index<number_of_digits) contains_nine=1;

printf("min %s\nmax %s\n",min_Price,max_Price);

// identify leading pattern match
uint8_t ended=0;
uint8_t leading_match_index=0;
i=0;
while(i<number_of_digits){
if(min_Price[i]==max_Price[i]&&ended==0) leading_match_index++;
if(min_Price[i]!=max_Price[i]) ended=1;
// if(ended){
// printf("i %lld\n",i);
// printf("%c\n",max_Price[i]);
// }
i++;
}
printf("leading_match_index %d\n",leading_match_index);
// while(i<number_of_digits){
// printf("i %lld",i);
// printf("%c",max_Price[i]);
// }
printf("\n");
i=0;
if(leading_match_index+1==number_of_digits){
while(i<number_of_digits){
numbers[i]=max_Price[i];
i++;
}
numbers[i]='\0';
printf("numbers:\n%s\n\n",numbers);
return 0;
}

// check for 9
// if !9 decrement current index -> all 9s
// if 9 increment current index

u_int8_t done=0;
i=leading_match_index;

if(maxPrice_digit==0){
numbers[i-1]='0';
maxPrice_digit=uint8_t(max_Price[i]);
maxPrice_digit--;
printf("maxPrice_digit=%d\n",maxPrice_digit);
numbers[i]=(char)maxPrice_digit; 
i++;

while(i<number_of_digits){
numbers[i]='9';
i++;
}
numbers[i]='\0';
done=1;
}



if(contains_nine==0){
printf("decrement_leading_digit\n");
maxPrice_digit=uint8_t(max_Price[i]);
maxPrice_digit--;
if(maxPrice_digit>1){
printf("maxPrice_digit=%d\n",maxPrice_digit);
numbers[i]=(char)maxPrice_digit; 
i++;

while(i<number_of_digits){
numbers[i]='9';
i++;
}
numbers[i]='\0';
done=1;
}


// 18699 //  18696 18702
// if(maxPrice_digit==1){
// printf("maxPrice_digit=%d\n",maxPrice_digit);
// numbers[i]=(char)maxPrice_digit; 
// i++;
// while(i<number_of_digits){
// numbers[i]='9';
// i++;
// }
// }
if(done==0) printf("todo\n");

}




if(i==0){
i=leading_match_index;
char maxPrice_char='0';
while(i<number_of_digits){
maxPrice_digit=0;
if(max_Price[i]=='9') numbers[i]='9';
if(max_Price[i]!='9'){
if(max_Price[i+1]=='9') numbers[i]=max_Price[i];
if(max_Price[i+1]!='9'){
//memcpy(maxPrice_char,(char*)max_Price[i],1);
//maxPrice_char=(char*)max_Price[i];
printf("max_Price[i]=%c\n",max_Price[i]);
maxPrice_digit=uint8_t(max_Price[i]);
maxPrice_digit--;
printf("maxPrice_digit=%c\n",(char)maxPrice_digit+1);
numbers[i]=(char)maxPrice_digit+1;
printf("numbers[i]=%c\n",numbers[i]);
//sprintf(maxPrice_char,"%c",maxPrice_digit);
//numbers[i]=maxPrice_char;
}
printf("max_Price[i+1]!='9'  %c\n",numbers[i]);
}
printf("i=%lld  %s\n",i,numbers);
i++;
}
//numbers[i]='\0';
//printf("init %s\n",numbers);

}

// while(i<number_of_digits){
// if(max_Price[i]=='9') flag=1;
// if((max_Price[i]!='9')&&(!flag)) numbers[i]=max_Price[i];
// if(flag) numbers[i]='9';
// i++;
// }
// while(!flag){
// i=0;
// maxPrice--;
// sprintf(max_Price,"%llu",maxPrice);
// number_of_digits=strlen(max_Price);
// while(i<number_of_digits){
// if(max_Price[i]=='9') flag=1;
// if((max_Price[i]!='9')&&(!flag)){
// //max_Price[i];
// numbers[i]=max_Price[i];
// }
// if(flag) numbers[i]='9';
// i++;
// }
// }
// numbers[i]='\0';
// printf("init %s\n",numbers);

// uint8_t max_index=0;
// uint64_t max_index_digit=0;
// uint64_t next_max_index_digit=0;

// uint8_t non_nine_mapping[number_of_digits];
// memset(non_nine_mapping,0,number_of_digits);
// i=0;
// // generate non_nine_mapping
// while(i<number_of_digits){
// if(max_Price[i]!='9'){
// non_nine_mapping[i]=1; 
// if((i>0)&&(non_nine_mapping[i-1]==0)) max_index=i-1;
// }
// printf(" %d ",non_nine_mapping[i]);
// i++;
// }
// printf("\n%d max_index\n",max_index);

// printf(" -max_Price[max_index] %c -\n",max_Price[max_index]);
// //while(!flag){
// if(max_index>0){
// i=max_index;
// max_index_digit=atoll((const char*)max_Price[i]);
// max_index_digit--;

// printf("here %llu",max_index_digit);
// max_Price[i]=(char)max_index_digit;
// while(i+1<number_of_digits){
// if(flag && max_index==0) numbers[i]='9';
// if(max_index>0){
// next_max_index_digit=atoll((const char*)max_Price[max_index+1]);
// if((int)next_max_index_digit<9) max_Price[max_index+1]=(char)next_max_index_digit;
// max_index--;
// }
// printf(" next_max_index_digit - %llu -\n",next_max_index_digit);
// printf(" - %s -\n",max_Price);
// i++;
// }
// }
// printf(" - %s -\n",max_Price);



numbers[i]='\0';
printf("numbers:\n%s\n\n",numbers);
//printf("\n19\n599\n2999\n2999999999\n18699\n88999\n");
return 9;
}
int main(
int   number_of_parameters,
char* parameters[],
char* environment[]
){
if(number_of_parameters>2) get_price(parameters[1],parameters[2]);
return 0; 
}

// cd /Users/`whoami`/c; g++ mmwmtn.cpp -o mmwmtn

// cd /Users/`whoami`/c; g++ mmwmtn.cpp -o mmwmtn; ./mmwmtn 20 25; ./mmwmtn 460 680; ./mmwmtn 1255 2999; ./mmwmtn 10 3000000000; ./mmwmtn 18696 18702; ./mmwmtn 80999 89099; echo "\n\n19\n599\n2999\n2999999999\n18699\n88999"

// case_0 20 25 =25 need to consider min bounding
// case_1 460 680 =599 not checking all larger possible 9s
// case_2 1255 2999 =2999
// case_3 10 3000000000 =2999999999
// case_4 18696 18702 =18699
// case_5 80999 89099 =88999 too big


















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

