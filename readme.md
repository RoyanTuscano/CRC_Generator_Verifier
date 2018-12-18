The goal of this lab exercise is to implement an error-detection mechanism using the standard CRC algorithm
described in the text. Write two programs, generator and verifier. The generator program reads from standard
input (or a file) a line of ASCII text containing an n-bit message consisting of a string of 0s and 1s. The second
line is the k-bit polynomial, also in ASCII. It outputs to standard output (or a file) a line of ASCII text withn + k
0s and 1s representing the message to be transmitted. Then it also outputs the polynomial, just as it read it in.
The verifier program reads in the output of the generator program and outputs a message indicating whether it
is correct or not. Finally, write a program, alter, that takes the outputs of the generator program, inverts 1 bit on
the first line depending on its argument (the bit number/position, counting from the leftmost bit as 1) but copies
the second line correctly. By running generator on the input file and polynomial, and then run verifier on the
output of generator, you should see that the message is correct, but by running generator on the input file and
polynomial, and then alter arg on the output of generator, and run verifier again, you should get the error message.

Use makefile to generate code


Running the code:
1.use make statement to create all the executables
2.input the message in the input.txt file
3.output message can be seen in output.txt file
4.General commands to the run the programms'
./generator
./generator | ./verifier 
./generator | ./alter 2 | ./verifier 

The logic of implementation

generator.cpp:

the generator.cpp uses a read file command to read input. The data is stored in char array and can be accessed individually
hence two array are created for polynomial and message

paddging is added to the input message to create a new message that will be trasmiited. An function is created to divide the message 
with the polynomial. The remainder array is also created that stores thos value. We than add the remainder bits to the message bits by creating new array.

hence we get output message
we write output message and the polynomial message to output.txt and also pass it as stdoutput

verifier.cpp:

Similar to generator. We dont add paddign bits just perform the division and checjk whether evvery char vyte of remainder is zero


alter.cpp:

we take the argument from command line. convert to int. the int value is inserted into char to change the message bit and the same is std out to the terminal

