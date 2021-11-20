make fclean
clear
make
ARG=`ruby -e 'puts (0..99).to_a.shuffle.join(" ")'`;
# $>ARG="<100 random values>"
# ARG="<100 random values>"; ./push_swap $ARG
clear
#valgrind ./push_swap $ARG
#./push_swap $ARG
./push_swap $ARG | wc -l
# ./push_swap $ARG | ./checker_linux $ARG

# echo $ARG
