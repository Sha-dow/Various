#!/bin/bash

# bash trap command
trap bashtrap INT

found=0

start_time=$(date +%s)

# bash trap function is executed when CTRL-C is pressed:
# bash prints message => Executing bash trap subrutine !
bashtrap()
{
	echo
    echo "CTRL+C Detected !...Terminating program!"
    sleep 1
    clear
    exit 1
}

echo "============================"
echo "ImageHandler.sh"
echo "============================"
echo "Executed:"
echo `date` 
echo "----------------------------"
echo -e "Insert filename: \c"
read filename
echo "File to write: $filename"
echo
echo "Set tileformat to image"
echo "format: [columns]x[rows]"
echo "rows is not mandatory parameter,"
echo "script can count the correct number."
echo -e "Tileformat:"
read tileformat
echo "Generating $tileformat tiles."
echo

#finding imagefiles...
echo "Finding .jpeg .png and .gif files from folder: "
echo "$PWD"

echo "============================"
echo "Listing files:"
echo

# bash for loop
for f in $( ls ./ ); do
	if [[ $f = *.png || $f = *.gif || $f = *.jpeg || $f = *.jpg ]]; then
		found=1
	fi
done 

if [ $found ]; then
	convert * \
     -print "Found %n imagefiles\n" \
     -print "\n" \
     -format "- %f size: %G" -identify \
     -print "\n" \
     null:
else
	echo "No image files found."
	echo "ABORTING"
	sleep 1
	exit 1
fi

echo "Press Y to start operation, anything else to abort"
read proceed
if [ $proceed = "Y" ] || [ $proceed = "y" ]; then
	#statements
	echo "Starting..."
	sleep 1
	clear
else
	echo "ABORTING..."
	sleep 1
	clear
	exit 1
fi

echo "OPERATION IN PROGRESS..."
echo "------------------------"

#convert *.png *.jpeg *.jpg *.gif +append $filename
montage *.png *.jpg *.jpeg *.gif -tile $tileformat $filename 

echo "READY"
echo "Generated file info: "
echo "====================="
identify $filename
echo 
echo "Execution time:"
finish_time=$(date +%s)
echo "$((finish_time - start_time)) secs."
echo
echo "ABORTING..."
display $filename
exit 0



