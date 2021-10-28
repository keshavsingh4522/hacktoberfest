//the syntax of opening a file.

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ofstream file;
  file.open ("example.txt");
  return 0;
}

//the syntax to open the file for both reading and writing purposes

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  fstream file;
  file.open ("example.txt", ios::out | ios::in );
  return 0;
}


//C++ automatically close and release all the allocated memory. Syntax to close a file.

#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ofstream file;
  file.open ("example.txt");
  file.close();
  return 0;
}

//Syntax for reading and writing on a file

#include <iostream>
#include <fstream>

using namespace std;

int main(){

  char text[200];

  fstream file;
  file.open ("example.txt", ios::out | ios::in );

  cout << "Write text to be written on file." << endl;
  cin.getline(text, sizeof(text));

  // Writing on file
  file << text << endl;

  // Reding from file
  file >> text;
  cout << text << endl;

  //closing the file
  file.close();
  return 0;
}