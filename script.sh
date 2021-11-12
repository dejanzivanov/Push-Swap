clear
make
ARG=`ruby -e 'puts (0..3).to_a.shuffle.join(" ")'`;
clear
./push_swap $ARG