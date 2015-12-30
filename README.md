# Enigma Implementation

This is a complete implementation of an Enigma encryption machine. It works exactly like a World War II Enigma machine, and it should be compatible with a real-world machine.

### How to compile it ?

Write these commands in a console :  
`git clone https://github.com/paly2/Enigma.git`  
`cd Enigma`  
`g++ *.cpp -o enigma`  

### How to use it ?

To run the program, go in the program directory and write :  
`./enigma rotors/I rotors/II reflectors/A`  
Of course, you can change the rotors and the reflectors files. This is just an example.

Then, the program asks you the rotors initial settings. Please give three capital letters and press enter, no more, no less.  
Next, it asks you the plugboard wiring. Please give six capital letters and press enter, them will be paired.  

You can now write your message.

### How to change the rotors and the plugboard wirings numbers ?

By default, there are three rotors. If you want to change this value, you can change the sixth line of the `rotors.h` file. For example, if you want a 4-rotors Enigma, replace this line by :  
`#define ROTORS_NUMBER 6`

By default, there are 6 plugboard wiring. If you want to change this value, you can change the fourth line of the `plugboard.h`. Please always write an even number. For example, if you want to have 10 wirings (so 5 cables), replace this line by :  
`#define PLUGBOARD_WIRING_NUMBER 10`

To test the changes, you must compile again the program.
