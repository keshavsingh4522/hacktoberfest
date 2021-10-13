using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

namespace CSharp_Shell
{

    public static class Program 
    {
        public static void Main() 
        {
	//Program writes a Fibonacci sequence the size of the input number.
        int seq1 = 0;
        int seq2 = 1;
        int aux = 0;
        Console.Write("Type a value:");
        int num = int.Parse(Console.ReadLine());
        for(int cont = 0; cont <= num; cont++)
        {
         aux = seq1 + seq2;
         seq2 = seq1;
         seq1 = aux;
         Console.WriteLine(aux);
        }
        Console.ReadLine();
        }
    }
}