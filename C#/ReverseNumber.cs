using System;
using System.Linq;

int ReverseNumber(int number) => int.Parse(string.Join("", number.ToString().Reverse()));

var random = new Random();
var randomNumber = random.Next() % 1000;

Console.WriteLine($"{randomNumber} => {ReverseNumber(randomNumber)}");