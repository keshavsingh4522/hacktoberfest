#include <bits/stdc++.h>

using namespace std;
vector<string> split_string(string);
// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
std::string st;
int d1 = 0;
int d2 = 0;
if(x>z)
{
d1 = x-z;
}else
{
d1 = z-x;
}
if(y>z)
{
d2 = y-z;
}else
{
d2 = z-y;
}
if(d1<d2)
{
st="Cat A";
}
else if(d2<d1)
{
st= "Cat B";
}
else
{
st= "Mouse C";
}
return st;
}
int main()
{
ofstream fout(getenv("OUTPUT_PATH"));
int q;
cin >> q;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
for (int q_itr = 0; q_itr < q; q_itr++) {
string xyz_temp;
getline(cin, xyz_temp);
vector<string> xyz = split_string(xyz_temp);
int x = stoi(xyz[0]);
int y = stoi(xyz[1]);
int z = stoi(xyz[2]);
string result = catAndMouse(x, y, z);
fout << result << "\n";
}
fout.close();
return 0;
}
vector<string> split_string(string input_string) {
string::iterator new_end = unique(input_string.begin(),
input_string.end(), [] (const char &x, const char &y) {
return x == y and x == ' ';
});
input_string.erase(new_end, input_string.end());
while (input_string[input_string.length() - 1] == ' ') {
input_string.pop_back();
}
vector<string> splits;
char delimiter = ' ';
size_t i = 0;
size_t pos = input_string.find(delimiter);
while (pos != string::npos) {
splits.push_back(input_string.substr(i, pos - i));
i = pos + 1;
pos = input_string.find(delimiter, i);
}
splits.push_back(input_string.substr(i, min(pos,
input_string.length()) - i + 1));
return splits;
}
