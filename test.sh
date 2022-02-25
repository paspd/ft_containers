
clang++ -Wall -Wextra -Werror $1 -g -D TESTED_NAMESPACE="ft" -D TESTED_TYPE=$2 -o test

if [ $3 = "y" ]
then
leaks -atExit -- ./test &> tmp1
else
./test > tmp1
fi

rm -rf test

clang++ -Wall -Wextra -Werror $1 -g -D TESTED_NAMESPACE="std" -D TESTED_TYPE=$2 -o test

if [ $3 = "y" ]
then
leaks -atExit -- ./test &> tmp2
else
./test > tmp2
fi

echo "diff of $1 :" > log
diff -a tmp1 tmp2 >> log

if [ $? = 0 ]
then
echo "diff of $1 :" > log
echo "0 diff" >> log
fi

rm -rf test