## SimpleDraw Reference design

Author: HBF

Date: 2022-09-19

## What's about

This is a reference design to A2Q3 SimpleDraw program. You are allowed to design and implement your SimpleDraw program based on this reference design. 

Even though we use C++ file extension convention, the program is actually a C program. That means you compile it using the MinGW C compiler. 

## Working plan

The SimpleDraw sounds simple, but it is not a simple program. I that you assignn 10 hours to write the program, and write and make progress step by step as follows. 

1. Try the provided execugtable sample program, to see what your SimpleDraw should look like at runtime. Import the SimpleDraw_reference_design.zip into Eclipse to as existing archive project. Understand the program design by reading the simpledraw.cpp, *.hpp and *.cpp files.  
2. Create your SimpleDraw project with the similar files like the reference design. Add menu to the your program, so that your SimpleDraw program has the menu structure like the sample program.       
3. Implement the insert function so that you can insert an object into the object list.  
4. Work on the mouseActionFcn function so that you can draw a rectangle by clicking two corner points and insert into the object list. Work on the mouseMotionFcn function, so that it shows the intermediate rectangle when dragging the mouse. Work on menu functions for styles: fill colors, stroke colors and width. 
5. Do the above with circle drawing using midpoint algorithm and make it work for both outline and fill circle drawing. Refer to lecture notes for the Midpoing alogrithm. 
6. Work on edit functions: select, delete, move to front, move to back, move around. 
7. Implement SVG save/open functions. 
8. Write Bitmap export function. 
9. Create a Circle&Square artwork. 

