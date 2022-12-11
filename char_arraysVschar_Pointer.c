/*******************************************************************************
*
* Program: Char Array String Vs. Poointer To String Literal
*
* Description: The difference between a string stored in a char array compared
* to a pointer to a string literal in C.  i.e. the difference between
* char s[] = "string"; vs char *s = "string";
*
*
* Author: Manoj Verma
*******************************************************************************/

#include <stdio.h>

int main()
{
  // String literals like "abcdef" exist in some place in memory, where
  // exactly is not defined by the C standard.  We can use string literals to
  // initialize a char array to store a string, as we do here.  The char array
  // s1 will be 7 chars long (due to the extra null terminator), and it will
  // be in a place in memory called the stack where we know it is possible
  // to modify the values that are stored there.
  char s1[] = "abcdef";

  // Change the first char of the char array s1
  s1[0] = 'X';

  // Output the modified s1 string which should now be Xbcdef
  printf("s1: %s\n", s1);

  // The string literal "abcdef" will exist *somewhere* in-memory during our
  // program's execution (again we don't exactly know where as it is not
  // defined by the C standard and is up to the compiler).  And s2 is a
  // pointer to the first char of this string literal (which is terminated
  // with a null terminator character).
  const char *s2 = "abcdef";

  // Because we've made s2 a pointer to a const char above, the compiler will
  // flag an attempt (like below) to modify what s2 is pointing to as an error.
  // If we did not user the const keyword when declaring s2, the compiler
  // would allow the below statement to be compiled without error.  But we
  // will almost certainly get a runtime error as a result because the
  // modification of a string literal is "undefined" by the C standard.  This
  // does not strictly speaking mean it is not allowed, but as a practical
  // matter the compiler will not support this and we will get a runtime
  // error related to memory acces.  As a result, if we're going to have a
  // pointer to a string literal, we should make sure it's a const char
  // pointer so that we don't accidentally attempt to modify the string.
  // s2[0] = 'X';

  // The char array s1 is like a constant pointer, so we can't increment
  // s1 to have it point to the next element in the array.
  // s1++;

  // s2 is a non-const pointer, so we actually CAN increment s2 to have it
  // point to the next char in the string literal.  Note that s2 is a pointer
  // to a const char, NOT a 'const pointer', there is a difference.
  s2++;

  // Output s2 and we'll get bcdef as s2 has been set to point to the next
  // char in the string literal (i.e. the char 'b' onwards)
  printf("s2: %s\n", s2);

  // We cannot assign a string to s1, we would need to use something like
  // strcpy() in the string.h library to change the string stored in s1
  // s1 = "new string";

  // We actually CAN assign a string literal to s2 because what will happen
  // is that "new string" will be a new string literal in memory, and s2
  // will be changed to point to THIS string literal now.
  s2 = "new string";

  // If we output s2 now we'll get "new string"
  printf("s2: %s\n", s2);

  // If we use the sizeof operator with s1 and s2, we'll get 7 bytes for s1
  // because it stores 7 chars of 1 byte each.  These 7 chars are stored on
  // the stack.  But with s2 we'll get 8 bytes because s2 is REALLY just a
  // pointer on the stack and sizeof will give us the size of that pointer
  // NOT the size of the string literal that it points to.
  printf("sizeof(s1): %zu\n", sizeof(s1));
  printf("sizeof(s2): %zu\n", sizeof(s2));

  return 0;
}



/*
Good video, but I like to also add that    char msg[] ="hello"; 
is just shorthand  for
char msg[] ={'h', 'e', 'l', 'l', 'o', '\0'};
There are no such things as strings
in C.      Only char arrays  or
character arrays.  And the address of  first character of the  char array is 
fixed ,  it is a constant pointer,    &msg[0] and  msg mean the same thing.  And msg and
msg + 0 is also the same , you can't change the  base address of the array, it is suck in memory.  It makes
sense , lets say you had this :
char s[]="car";
then decided to change it to
s =
"abcdefghijklmnopqrstuvwxyz123456789134566778889abcdefghijklmnopqrstuvwxyz"  ;
The compiler would have to find a  large amount of memory for this new change  in size.
And there might not be enough memory for this new  sudden change in size.   Therefore  a array's 
starting address being fixed is a good safeguard.  
   Therefore the base address of any
array in C  is fixed, it is a constant.  
   This applys to all arrays in  C , for example:  
int a[]={1,2,3};
int b[={4,5,6};
you can't do this
a= b;       // same as a= &b[0] ;
because you are changing the starting or base address of the integer array called a .  The address of a is fixed, and will remain fixed for the entire program.
But I can do this ,  
int *p = a;  //  int *p =&a[0];
then later I can change the int pointer to point to array b
p = b;     //   because  p is a 
pointer variable that can  point to any variable or  any array as long as it has the same data type , as the variable or array , that it is pointing,  or  refering to.    Pointer variables  can point to any variable of the same type.  Again as I said earlier ,  char arrays or C-strings are  character arrays only  , there is no such thing as a string in C ,  they are not  String objects like Java ,  or String objects like C++ or C#  .
*/