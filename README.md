# CS 210 Project Three: Corner Grocer Item-Tracking Program



## Project Summary



For this project, I built an item-tracking program for a fictional grocery store called the Corner Grocer. The store needed a way to analyze their daily sales records to see how often each item was being purchased. The program reads through a text file that lists every item bought throughout the day and gives the store four ways to view that data: searching for a specific item, seeing a full frequency list, viewing a histogram, and exiting the program. The goal was to help the store make smarter decisions about how to arrange their produce section based on what customers buy most.



## What I Did Particularly Well



I think I did a good job keeping the code organized and easy to follow. I split everything into separate files ? a header file, an implementation file, and a main file ? so each part of the program had a clear purpose. I also made sure to add comments throughout the code explaining what each section does, which makes it easier for someone else (or myself later) to read and understand. Using a map to store the item data worked really well because it kept everything sorted automatically and made lookups fast.



## Where I Could Enhance My Code



There are a few areas where I could improve the program in the future. Right now, the item search in Menu Option 1 is case-sensitive, so typing "potatoes" instead of "Potatoes" would return zero results. I could fix this by converting the user's input to match the format in the file before searching. I could also add more detailed error handling for situations like a missing or corrupted input file. Another improvement would be letting the user load a different input file without restarting the program, which would make it more flexible for real-world use.



## Most Challenging Parts



The trickiest part for me was making sure the input validation worked correctly. I wanted the program to handle situations where a user types a letter instead of a number without crashing, and getting the cin error-clearing logic right took some extra thought. I worked through it by testing different inputs and looking at how other C++ programs handle bad input. Going forward, I plan to lean more on C++ documentation and peer resources when I run into problems like this, since they helped me understand the logic more clearly.



## Transferable Skills



Several things I learned in this project will carry over to future coursework. Working with file input and output is something that comes up in almost every real program, so getting comfortable with that was valuable. I also got more practice designing a class with public and private sections, which is a core concept in C++ and most other programming languages. Writing clean, commented code is another habit I want to keep building on, since it makes collaboration and future edits much easier.



## Making the Program Maintainable, Readable, and Adaptable



I tried to make the program easy to maintain by giving everything clear, descriptive names ? for example, the method that prints the histogram is called PrintHistogram(), so there is no guessing what it does. I used in-line comments throughout to explain the purpose of each block of code. The class structure also makes the program adaptable, because if the store wanted to add a new feature ? like searching by frequency range ? I could add a new method to the class without rewriting the rest of the program.
