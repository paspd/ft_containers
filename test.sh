if [ $2 = "out" ]
then
clang++ -Wall -Wextra -Werror $1 -g -D TESTED_NAMESPACE="ft" -o test
./test > log
else
clang++ -Wall -Wextra -Werror $1 -g -D TESTED_NAMESPACE="ft" -o test
./test > tmp1
clang++ -Wall -Wextra -Werror $1 -g -D TESTED_NAMESPACE="std" -o test
./test > tmp2
diff tmp1 tmp2 > log
if [ $? = 0 ]
then
echo "0 diff" > log
fi
fi
rm -rf tmp1 tmp2 test