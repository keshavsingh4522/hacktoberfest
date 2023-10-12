string[] fraudulentIDArray = new string[4];

fraudulentIDArray[0] = "sayaInginMakan";
fraudulentIDArray[1] = "sayaInginTidur";
fraudulentIDArray[2] = "sayaInginBerak";
fraudulentIDArray[3] = "sayaInginSukses";

for (int i = 0; i < fraudulentIDArray.Length; i++ ) {
    Console.WriteLine($"Nilai Array Index ke {i} adalah : {fraudulentIDArray[i]}");
}

// new array initialize inside the variable

string[] anyarArray = {"Satu", "Dua", "Tiga", "Empat"};

foreach (string anyar in anyarArray)
{
    Console.WriteLine(anyar);
}
Console.WriteLine(fraudulentIDArray.Length);

// foreach
int totalSales = 0;
int keBerapa = 0;
int[] salesThisMonth = {100, 72, 323, 500};
foreach (var october in salesThisMonth )
{
    totalSales += october;
    Console.WriteLine(october);
    keBerapa++;
}

Console.WriteLine($"Jumlah Penjualan total pada hari {keBerapa} bulan Oktober adalah {totalSales} buah");