# intal
An intal is a nonnegative integer of arbitrary length, supporting upto 1000 digits.  
The integer is stored as a null-terminated string of ASCII characters.  
An intal is represented as a string of decimal digits(0-9) that are stored in the big endian format. It doesn't support  
decimal points.  
It is different from an integer in the sense that an integer is represented as a number of 4 bytes for integers of type int[range=(2,147,483,648 to 2,147,483,647)] and 8 bytes for integer of type long int[range=(-9223372036854775808 to 9223372036854775807)].  
An intal on the other hand is an integer represented as string of 1000 bytes but can support upto 1000 digits. But an intal cannot take up the role of float types.  
Intals can be used in scientific calculations. It can also be used in astronomical calculations which require dealing with huge numbers.  
