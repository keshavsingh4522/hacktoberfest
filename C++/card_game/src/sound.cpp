#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

int main()
{
 system("start sound.mp3");
// std::cout<<"Sound playing... enjoy....!!!";
// PlaySound(TEXT("./../assets/fail.wav"), NULL, SND_SYNC);
    
    system("pause");
    return 0;
}
