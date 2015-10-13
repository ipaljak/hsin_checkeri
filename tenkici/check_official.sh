#!bin/bash

make check

for f in primjeri/*in*
do
    ./check $f ${f/in/out} ${f/in/out}
done
