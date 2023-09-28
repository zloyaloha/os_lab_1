#!/bin/bash
cd ../src/build
cat ../../test/test1.txt | ./parent.out > ../../test/res1.txt
cat ../../test/test2.txt | ./parent.out > ../../test/res2.txt
cat ../../test/test3.txt | ./parent.out > ../../test/res3.txt
cat ../../test/test4.txt | ./parent.out > ../../test/res4.txt
cd ../../test


echo "_____________________________"
echo RESULT:; cat res1.txt; echo -e "\n"
echo EXPECT:; cat good_res1.txt; echo -e "\n"
if diff res1.txt good_res1.txt
then 
echo test1 confirmed
else echo NOT OK
fi
echo "_____________________________"

echo "_____________________________"
echo RESULT:; cat res2.txt; echo -e "\n"
echo EXPECT:; cat good_res2.txt; echo -e "\n"
if diff res2.txt good_res2.txt
then 
echo test2 confirmed
else echo NOT OK
fi
echo "_____________________________"

echo "_____________________________"
echo RESULT:; cat res3.txt; echo -e "\n"
echo EXPECT:; cat good_res3.txt; echo -e "\n"
if diff res3.txt good_res3.txt
then 
echo test3 confirmed
else echo NOT OK
fi
echo "_____________________________"

echo "_____________________________"
echo RESULT:; cat res4.txt; echo -e "\n"
echo EXPECT:; cat good_res4.txt; echo -e "\n"
if diff res4.txt good_res4.txt
then 
echo test4 confirmed
else echo NOT OK
fi
echo "_____________________________"