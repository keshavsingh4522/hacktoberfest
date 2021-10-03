using System;
using System.Linq;

string NumberToCharacters(double number) 
	=> string.Join(" ", number.ToString().Select(x => x switch {
		'-' => "minus",
		'0' => "zero",
		'1' => "one",
		'2' => "two",
		'3' => "three",
		'4' => "four",
		'5' => "five",
		'6' => "six",
		'7' => "seven",
		'8' => "eight",
		'9' => "nine",
		'.' => "comma",
		_ => ""
	}));

var randomNumber = (new Random().NextDouble() - 0.5) * int.MaxValue * 2f / short.MaxValue;
Console.WriteLine($"{randomNumber} => {NumberToCharacters(randomNumber)}");