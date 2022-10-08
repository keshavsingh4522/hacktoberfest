
/*
1) Input Functions

Function	Definition
getline()	This function is used to store a stream of characters as entered by the user in the object memory.
push_back()	This function is used to input a character at the end of the string.
pop_back()	Introduced from C++11(for strings), this function is used to delete the last character from the string. 

2) Capacity Functions
Function	    Definition
capacity()	    This function returns the capacity allocated to the string, which can be equal to or more than the size of the string. 
                Additional space is allocated so that when the new characters are added to the string, the operations can be done 
                efficiently.
resize()	    This function changes the size of the string, the size can be increased or decreased.
length()	    This function finds the length of the string.
shrink_to_fit()	This function decreases the capacity of the string and makes it equal to the minimum capacity of the string. This 
                operation is useful to save additional memory if we are sure that no further addition of characters has to be made.

3) Iterator Functions
Function	Definition
begin()	This function returns an iterator to the beginning of the string.
end()	This function returns an iterator to the end of the string.
rbegin()	This function returns a reverse iterator pointing at the end of the string.
rend()	This function returns a reverse iterator pointing at beginning of the string.

4) Manipulating Functions:

Function	Definition
copy(“char array”, len, pos) 	This function copies the substring in the target character array 
mentioned in its arguments. It takes 3 arguments, target char array, length to be copied, and starting 
position in the string to start copying.
swap()	This function swaps one string with other.

strrchr() function 
In C++, strrchr() is a predefined function used for string handling. cstring is the header file required for string functions.
This function returns a pointer to the last occurrence of a character in a string. 
Syntax : char *strrchr(const char *str, int c)
Given a string in C++, we need to find the last occurrence of a character, let’s say ‘a’.
Input : string = 'This is a string'
Output :9
Input :string = 'My name is Ayush'
Output :12

*/
