// reversing string from variabel

string text = "Ketika cinta bersemi diantara kita";
// convert to char, save the value inside arrayyyahhh
char[] eachOf = text.ToCharArray();
int amountOfA = 0;
// Count amount of "a" inside the variable or text

foreach (char alphabet in eachOf)
{
    if (alphabet == 'a')
    {
        amountOfA++;
    }
}

Console.WriteLine($"The amount of \"A\" inside the text is : {amountOfA} pieces");