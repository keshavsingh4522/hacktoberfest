      Python With me
Python tutorial provides basic and advanced concepts of Python. Our Python tutorial is designed for beginners and professionals.

Python is a simple, general purpose, high level, and object-oriented programming language.

Python is an interpreted scripting language also. Guido Van Rossum is known as the founder of Python programming.
  
 What is Python
 
 Python is a general purpose, dynamic, high-level, and interpreted programming language. It supports Object Oriented programming approach to develop applications. It is simple and easy to learn and provides lots of high-level data structures.

Python is easy to learn yet powerful and versatile scripting language, which makes it attractive for Application Development.

Python's syntax and dynamic typing with its interpreted nature make it an ideal language for scripting and rapid application development.

Python supports multiple programming pattern, including object-oriented, imperative, and functional or procedural programming styles.

Python is not intended to work in a particular area, such as web programming. That is why it is known as multipurpose programming language because it can be used with web, enterprise, 3D CAD, etc.

We don't need to use data types to declare variable because it is dynamically typed so we can write a=10 to assign an integer value in an integer variable.

Python makes the development and debugging fast because there is no compilation step included in Python development, and edit-test-debug cycle is very fast.
  
  Python 2 vs. Python 3
  
  In most of the programming languages, whenever a new version releases, it supports the features and syntax of the existing version of the language, therefore, it is easier for the projects to switch in the newer version. However, in the case of Python, the two versions Python 2 and Python 3 are very much different from each other.
    
  #A list of differences between Python 2 and Python 3 are given below:

1. Python 2 uses print as a statement and used as print "something" to print some string on the console. On the other hand, Python 3 uses print as a function and used as print("something") to print something on the console.
2. Python 2 uses the function raw_input() to accept the user's input. It returns the string representing the value, which is typed by the user. To convert it into the integer, we need to use the int() function in Python. On the other hand, Python 3 uses input() function which automatically interpreted the type of input entered by the user. However, we can cast this value to any type by using primitive functions (int(), str(), etc.).
3. In Python 2, the implicit string type is ASCII, whereas, in Python 3, the implicit string type is Unicode.
4.Python 3 doesn't contain the xrange() function of Python 2. The xrange() is the variant of range() function which returns a xrange object that works similar to Java iterator. The range() returns a list for example the function range(0,3) contains 0, 1, 2.
5.There is also a small change made in Exception handling in Python 3. It defines a keyword as which is necessary to be used. We will discuss it in Exception handling section of Python programming tutorial.
  
  Python History
Python was invented by Guido van Rossum in 1991 at CWI in Netherland. The idea of Python programming language has taken from the ABC programming language or we can say that ABC is a predecessor of Python language.

There is also a fact behind the choosing name Python. Guido van Rossum was a fan of the popular BBC comedy show of that time, "Monty Python's Flying Circus". So he decided to pick the name Python for his newly created programming language.

Python has the vast community across the world and releases its version within the short period.
  
    Why learn Python?
  Python provides many useful features to the programmer. These features make it most popular and widely used language. We have listed below few-essential feature of Python.
  
>Easy to use and Learn
>Expressive Language
>Interpreted Language
>Object-Oriented Language
>Open Source Language
>Extensible
>Learn Standard Library
>GUI Programming Support
>Integrated
>Embeddable
>Dynamic Memory Allocation
>Wide Range of Libraries and Frameworks

         Where is Python used?
  Python is a general-purpose, popular programming language and it is used in almost every technical field. The various areas of Python use are given below.

>Data Science
>Date Mining
>Desktop Applications
>Console-based Applications
>Mobile Applications
>Software Development
>Artificial Intelligence
>Web Applications
>Enterprise Applications
>3D CAD Applications
>Machine Learning
>Computer Vision or Image Processing Applications.
  
  Python Basic Syntax
There is no use of curly braces or semicolon in Python programming language. It is English-like language. But Python uses the indentation to define a block of code. Indentation is nothing but adding whitespace before the statement when it is needed. For example -
  def func():  
       statement 1  
       statement 2  
       …………………  
       …………………  
         statement N  
         In the above example, the statements that are same level to right belong to the function. Generally, we can use four whitespaces to define indentation.
         Python First Program
Unlike the other programming languages, Python provides the facility to execute the code using few lines. For example - Suppose we want to print the "Hello World" program in Java; it will take three lines to print it.
  public class HelloWorld {  
 public static void main(String[] args){  
// Prints "Hello, World" to the terminal window.  
  System.out.println("Hello World");  
 }  
 } 
On the other hand, we can do this using one statement in Python
print("Hello World")  
  Both programs will print the same result, but it takes only one statement without using a semicolon or curly braces in Python.
  Python Popular Frameworks and Libraries
Python has wide range of libraries and frameworks widely used in various fields such as machine learning, artificial intelligence, web applications, etc. We define some popular frameworks and libraries of Python as follows.

>Web development (Server-side) - Django Flask, Pyramid, CherryPy
>GUIs based applications - Tk, PyGTK, PyQt, PyJs, etc.
>Machine Learning - TensorFlow, PyTorch, Scikit-learn, Matplotlib, Scipy, etc.
>Mathematics - Numpy, Pandas, etc.
  Python print() Function
The print() function displays the given object to the standard output device (screen) or to the text stream file.

Unlike the other programming languages, Python print() function is most unique and versatile function.

The syntax of print() function is given below.
  print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)  
  
 Let's explain its parameters one by one.

>objects - An object is nothing but a statement that to be printed. The * sign represents that there can be multiple statements.
>sep - The sep parameter separates the print values. Default values is ' '.
>end - The end is printed at last in the statement.
>file - It must be an object with a write(string) method.
>flush - The stream or file is forcibly flushed if it is true. By default, its value is false.
Let's understand the following example.
      Example - 1: Return a value
 print("Welcome to Manish.")  
  
a = 10  
# Two objects are passed in print() function  
print("a =", a)  
  
b = a  
# Three objects are passed in print function  
print('a =', a, '= b')  
   OutPut:
Welcome to Manish.
a = 10
a = 10 = b
As we can see in the above output, the multiple objects can be printed in the single print() statement. We just need to use comma (,) to separate with each other.
  
  Example - 2: Using sep and end argument
  a = 10  
print("a =", a, sep='dddd', end='\n\n\n')  
print("a =", a, sep='0', end='$$$$$')  
 Output:
a =dddd10

a =010$$$$$

In the first print() statement, we use the sep and end arguments. The given object is printed just after the sep values. The value of end parameter printed at the last of given object. As we can see that, the second print() function printed the result after the three black lines.
  Taking Input to the User
Python provides the input() function which is used to take input from the user. Let's understand the following example.

Example -
  name = input("Enter a name of student:")  
print("The student name is: ", name)  
  Output:

Enter a name of student: Manish
The student name is:   Manish
By default, the input() function takes the string input but what if we want to take other data types as an input.

If we want to take input as an integer number, we need to typecast the input() function into an integer.

For example -

Example -

a  = int(input("Enter first number: "))  
b = int(input("Enter second number: "))  
  
print(a+b)  
  Output:

Enter first number: 50
Enter second number: 100
150
  We can take any type of values using input() function.
  


