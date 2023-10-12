// Mencari user yang memiliki nama berawalan B

// create array username
string[] username = {"B123","C234","A345","C15","B177","G3003","C235","B179"};

// cetak value atu atu
foreach (var user in username) {
    // Console.WriteLine(user);
    if (user.StartsWith("B"))
    {
        Console.WriteLine(user);
        // username.
    }
}


string supplierName = "Jaja Miharja";
int purchasedStock = 4;
// Barang terbeli
// int soldStock = 3;
// Console.WriteLine($"This sold product is around {soldStock} pcs");
Console.WriteLine($"The stock is {purchasedStock}");