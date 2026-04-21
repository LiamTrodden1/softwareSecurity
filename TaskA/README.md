## Task A: Vulnerability Discovery and Remediation
# Buffer Overflow 
A buffer overflow occurs when memory is exceeded causing the data to overflow into nearby memory locations. 

This code contains a function to login with 2 variables. The temp variable holds an integer value. The sole purpose of this variable is to see if a buffer overflow has occured from the users password input. The password is the users input that will be checked to see if it is correct so they can log in. 

To cause a buffer overflow, the users password input must exceed the designated length of 8 characters. If a buffer overflow occurs the memory will leak causing the temp variable to change its value.

To Test this exploit:
1. Type into terminal "g++ bufferOverflow.cpp -o bufferOverflow" to compile
2. Type into terminal "./bufferOverflow" to run
3. Type a string longer than 8 characters e.g. "TESTTESTTEST"
4. Observe that the temporary integer has changed its value from 1 to another integer.

To fix this issue, instead of using a char data type i have used a string datatype. String datatypes are dynamic and are stored in the heap rather than the stack like char datatypes. this means the size of the memory resizes depending on the string data type input. This prevents a buffer overflow as the available space for the input far exceeds a feesible input to overflow the buffer.

To Test this Fix:
1. Type into terminal "g++ bufferOverflowFix.cpp -o bufferOverflowFix" to compile
2. Type into terminal "./bufferOverflowFix" to run
3. Type a string longer than 8 characters e.g. "TESTTESTTEST"
4. Observe that the temporary integer has changed its value from 1 to another integer.


# Use After Free
Use after Free memory flaws occur when a pointer is not properly nullified. This means that after the pointer has been freed, it can still still be used to read or write data that it shouldn't have access to.

In this function, a pointer is assigned to the value 1234. The pointer is then deleted but not nullified.

When the pointer is now viewed, it now has access to different values it shouldn't be able to see. As you can see when the pointer is printed in the terminal it points to a value that is not 1234.

To test this flaw:
1. Type into terminal "g++ useAfterFree.cpp -o useAfterFree" to compile
2. Type into terminal "./useAfterFree" to run

To fix this issue, after using freeing the pointer, it is set to the value of a null pointer so it can no longer be used. As you can see nothing is printed now.

To test this fix:
1. Type into terminal "g++ useAfterFreeFix.cpp -o useAfterFreeFix" to compile
2. Type into terminal "./useAfterFreeFix" to run
