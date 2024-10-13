#!/bin/bash

gcc mmwmtn.c -o mmwmtn
sep(){
echo "------------------"
}
./mmwmtn 20 25
echo -e "19"
sep
./mmwmtn 460 680
echo -e "599"
sep
./mmwmtn 1255 2999
echo -e "2999"
sep
./mmwmtn 10 3000000000
echo -e "2999999999"
sep
./mmwmtn 18696 18702
echo -e "18699"
sep
./mmwmtn 80999 89099
echo -e "88999"
sep
