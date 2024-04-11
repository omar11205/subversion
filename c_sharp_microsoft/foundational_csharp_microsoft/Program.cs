// See https://aka.ms/new-console-template for more information
Console.WriteLine("Hello, World!");
// not allowed Console.WriteLine('Hello World'), use "" instead '' that are for character literals 'a', 'b' etc

// allowed printing integers Console.WriteLine(123);
Console.WriteLine(123);

// to create a float literal decimal, put at the end the word 'F' <- literal sufix 
Console.WriteLine(0.2F);

//the compiler automatically assing a double data type to a decimal number like 1.234
Console.WriteLine(1.234);

//to work with a literal decimal add the literal sufix 'm'
Console.WriteLine(12.39816m);

//managing boleans in lowercase true or false
Console.WriteLine(true);

//STATIC TYPING!!!

//variable declaration and initialization 
string firstName = "Omar";
Console.WriteLine(firstName);

bool isTrue = true;
Console.WriteLine(isTrue);

int evenNumber = 2;
Console.WriteLine(evenNumber);

double decimalDouble = 1.222D;
Console.WriteLine(decimalDouble);

char ASCIIA = 'A';
Console.WriteLine(ASCIIA);

float floatDecimal = 1.3333F;
Console.WriteLine(floatDecimal);

// DINAMIC TYPING!!

// Implicitly-typed variables must be initialized
// var message; is not valid

var message = "Hello C#!";
Console.WriteLine(message);




