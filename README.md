CIS*4650 - Assignment 1
James Wadsworth
0813414




Description
--------------------------
Program to parse through an SGML (Standard Generalized
Markup Language), looking for specific tags and matching
open tags with closed tags.

getToken() function written by Fei Song.


Running the Program
--------------------------
cd into 'wadsworj_a1'
enter 'make'
enter ./scanner < [input_file] > [output_file]

Folder Structure
--------------------------
    ./src           > source files
    ./include       > header files
    ./obj           > objects (.o) files
    ./test_suite    > in progress test suite




Tests
--------------------------
Development was done based on tests. Not exactly unit
tests unfortunatly, but the program was modified every time
a new test was added. Here are the first 4, more were added
as development went on.

I began implementing a Test Suite, which would have automatically
run each test after every change to the program. This can be found
in the folder 'test_suite'. I realized time would not allow this to
be implemented for this assignment, but hopefully for future
assignments.


1. Open/Closed tag
    Test that program can accept an open and closed tag

<TEXT>
</TEXT>

2. Nested Open/Closed tags

<TEXT>
    <TEX>
    </TEX>
</TEXT>

3. Test for unmatched tags
    Program should print an error to user

<TEXT>
</TEX>

4.  Test for case-insensitivity
<TEXT>
</text>


5.  Test against provided example file
        Output should match sample output