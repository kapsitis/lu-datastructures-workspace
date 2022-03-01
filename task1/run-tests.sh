#!/bin/bash

#echo "Pull the submitted files from GitHub" (something like this):
#git clone git@github.com:username/ds-workspace-username.git

#######################################################
## Run tests in task1 directory.                     ##
#######################################################

# Remove GRADES file (will append to it later on)
rm -f GRADES-TASK1.txt

cd task1
rm -fr build

# There are 5 testcases (tests with their expected results)
# declare -a tsts=( "1" "2" "3" "4" "5")
declare -a tsts=("1")

echo "Compiling..."

mkdir build

make all
cd build

# If executable exists:
if [ -f "task1" ]
then
  for i in "${tsts[@]}"
  do
    echo "----- input${i}.txt -----"
    cp ../input${i}.txt task1.in
    # Run the test on input${i}.txt
    timeout 1 ./task1
    if [ $? == "0" ]
    then      
      # wait until output file exists
      until [ -f w ]
      do 
        sleep 1
      done
      cp task1.out ../output${i}.txt 
      # Add one extra newline at the end of the file
      echo >> ../output${i}.txt
      # Ignore case (-i), ignore extra whitespace (-w), ignore blank lines (-B).
      diff -i -w -B ../output${i}.txt ../expected${i}.txt
      # If the diff command found that two files are the same
      if [ $? == "0" ]
      then
        echo "Test${i}: PASS" >> ../GRADES-TASK1.txt
      else
        echo "Test${i}: FAIL" >> ../GRADES-TASK1.txt
      fi
    else
      echo "Test${i}: CRASH" >> ../../GRADES-TASK1.txt
    fi        
  done
else 
  # Executable circlist_main not built.
  echo "task1 did not build"
  for i in "${tsts[@]}"
  do
    echo "Test${i}: BUILDISSUE" >> ../../GRADES-TASK1.txt
  done
fi
echo "------------------------"

echo "Cleaning up..."
# cd ..
# make clean
echo "Done!"


