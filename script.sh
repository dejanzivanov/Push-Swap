clear
make
ARG=`ruby -e 'puts (0..3).to_a.shuffle.join(" ")'`;
clear
#valgrind ./push_swap $ARG
./push_swap $ARG
echo $ARG