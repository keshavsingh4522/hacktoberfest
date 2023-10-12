Random shuffle = new Random();

// int daysUntilExpired1 = shuffle.Next(1, 20);
// int daysUntilExpired2 = shuffle.Next(1, 20);
int discountPercentage = 0;


string[] namaPelanggan = {"Icann", "Dandy", "Gabriel"};

for (int i = 0; i < namaPelanggan.Length; i++)
{
    int daysUntilExpired = shuffle.Next(1, 10);
    Console.WriteLine($"{namaPelanggan[i]} {daysUntilExpired}");
// if users subscription expired in 15 days
if (daysUntilExpired >= 5 && daysUntilExpired <= 10) {
    Console.WriteLine("Youre subscription will expired in each days, Renew Now !");
    Console.WriteLine($"You have {daysUntilExpired} days remaining");
} else if(daysUntilExpired <= 5) {
    Console.WriteLine($"Your subscription expires in {daysUntilExpired} days\n");
    discountPercentage = 20;
    Console.WriteLine($"Save your money with {discountPercentage}%");
} else if(daysUntilExpired <= 1 ) {
    Console.WriteLine($@"You just have a {daysUntilExpired}       dont forget to renew it");
    discountPercentage = 10;
    Console.WriteLine($"Save your money with {discountPercentage}%");
} else {
    Console.WriteLine("Your subscription has expired.");
}
}
