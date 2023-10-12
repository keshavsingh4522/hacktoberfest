// // Inisialisasi random dengan membuat instance
// Random dadu = new Random();

// int roll1 = dadu.Next(1, 7);
// int roll2 = dadu.Next(1, 7);
// int roll3 = dadu.Next(1, 7);

// int total = roll1 + roll2 + roll3;

// if (roll1 == roll2 || roll2 == roll3 || roll1 == roll3) {
//     if (roll1 == roll2 && roll2 == roll3)
//     {
//         Console.WriteLine("You Got a Plus +6 points into your rolls");
//         total +=6;
//     } else
//     {
//         Console.WriteLine("You got a double same so you got a twice point ");
//         total += 2;
//     }
// }
// Console.WriteLine($"Roll anda adalah {roll1} + {roll2} + {roll3} = {total}");
// if (total >= 16)
// {
//     Console.WriteLine("You got a universe");
// } 
// else if (total >10) {
//     Console.WriteLine("You got a mountain");
// }
// else if(total >6) {
//     Console.WriteLine("You got a mustache");
// }
// else
// {
//     Console.WriteLine("You fuck");
// }

Random acak = new Random();

Console.WriteLine(acak.Next(1, 5));