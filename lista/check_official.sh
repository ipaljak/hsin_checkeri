#!bin/bash

make check

for f in lista/*.in.*
do
    ./check $f ${f/in/out} ${f/in/out}
done
