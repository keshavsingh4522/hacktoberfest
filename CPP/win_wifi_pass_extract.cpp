#include <iostream>
#include <fstream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <istream>
#include <cstdlib>
#include <vector>
#include <regex>
#include <algorithm>
#include <iterator>
using namespace std;

string exec(const char* cmd) {
	array<char, 128> buffer;
	string result;
	unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

int main() {
	fstream wifienumfile;
	string wifienumRSLT,wifienumlines,wifienumwifiname,wifienumcmd,wifienumwifiprofiles;
	vector <string> wifienumwifis;
	regex wifienumreplace0("    All User Profile     : ");
	string wifienumreplace1 = "-\n";
	wifienumfile.open("WifiExtractorRSLT.txt", fstream::in | fstream::out | fstream::trunc);
	wifienumwifiprofiles = exec("netsh WLAN show profiles");
	while (wifienumwifiprofiles.find(wifienumreplace1) != string::npos)
	{
		wifienumwifiprofiles.erase(0,wifienumwifiprofiles.find(wifienumreplace1)+2);
	}
	wifienumwifiprofiles = regex_replace(wifienumwifiprofiles,wifienumreplace0, "");
	ofstream wifienumfile1("wifis.txt");
	wifienumfile1 << wifienumwifiprofiles;
	wifienumfile1.close();
	ifstream wifienumfile1i("wifis.txt");
	while(getline(wifienumfile1i, wifienumlines, '\n'))
	{
		wifienumwifis.push_back(wifienumlines);
	}
	wifienumfile1i.close();
	for (string wifienumwifiname : wifienumwifis) {
		wifienumcmd = "netsh WLAN show profile \"" + wifienumwifiname + "\" key=clear";
		const char* wifienumc = wifienumcmd.c_str();
		if (wifienumwifiname == "")
		{
			break;
		}
		wifienumRSLT += exec(wifienumc);
	}
	wifienumfile << wifienumRSLT;
	wifienumfile.close();
}
