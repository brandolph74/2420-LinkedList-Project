# String Library Part 1

C++ has two common ways to represent strings, the string class or a char buffer
(commonly called c-strings).
The string class actually stores strings using a char buffer but takes care of
all of the underlying memory management.
It also provides several methods for working with and manipulating strings.
We will be creating are own string class which will call DynamicString.
DynamicString will store the string using a dynamically-sized character array.
The last byte of the string should always by the null character '\0' so the
char buffer is compatible with standard c/c++ code.
This lets the code detect the end of the string by detecting the null character.
When implementing the DynamicString class you are **not allowed** to use the
string header file, cstring header file or C++ strings.

## Goals:
The purpose of this project is to review topics covered in CS 1410 especially
classes, arrays, pointers, loops, and operator overloading.
This assignment will also introduce the tools and methodologies we will be using
throughout the rest of the semester.

## Requirements:

Implement the following string methods

+ DynamicString() //Constructs an empty string. Allocating enough memory to store the null character
+ DynamicString(const char* str) //Constructs a string by copying the characters from the char array str to this object.  You should dynamically allocate enough memory for the entire string.
+ int len() const //returns the length of this string (i.e. the number of characters in the array not including the null char)
+ const char* c_str() const // returns a pointer to the underlying char array
+ char char_at(int position) const // returns the char at the specified position
+ char& operator[](int position) // returns the char at the specified position
+ bool startsWith(const DynamicString& other) const //True if other is a prefix of this string
+ bool endsWith(const DynamicString& other) const //True if other is a suffix of this string
+ int compare(const DynamicString& other) const // negative if this is smaller than other, 0 if this is equal to other, positive if this is larger than other
+ int iCompare(const DynamicString& other) const // same as compare but is case-insensetive
+ DynamicString& toLower() // converts the string to lowercase
+ DynamicString& toUpper() // converts the string to uppercase
+ DynamicString& replace(char old, char new) //replace all instances of old with new
+ int find(char needle, int start=0) const //return the first index of the specified char or -1 if the char is not found starting from index start.
+ int reverseFind(char needle, int start) const //return the right-most index (less than or equal to start) of the specified char or -1 if the char is not found.


Helpful C++ library methods:

+ tolower
+ toupper
+ out_of_range


## Tips and suggestions:
- C-strings always end with the null character. So should your DynamicString.
- Get started early.
- Look at the driver file. Just because you will not be making changes to that code, you should still understand what it is doing. The tests are examples of expected results for each of the different methods. If you want to know what concat is supposed to do, look at the input and expected output.
- Read the comments in the header files.  They describe what each method is meant to do.
- Work on one thing at a time and compile and commit early and often.  For example, implement the len method, compile it, test it, commit it.  The more often you compile and test the easier it will be to pinpoint errors.
- Use the debugger.  When you are getting unexpected results, set a breakpoint and trace exactly what is happening in the code.
- Ask for help.  Use the tutors, canvas dicussion boards and me.  Be detailed and descriptive of what problem you are having and how you have tried to solve it. When you ask me for help make sure your latest code is in your git repository.
