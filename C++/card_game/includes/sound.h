#include<iostream>
#include<windows.h>
using namespace std;

class SoundEmitter{
    string filePath;

public:
    void GameStartSound();
    void GameOverSound();
    void WinSound();
    void LoseSound();
}