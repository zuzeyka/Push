#pragma once
void Default();
void Legacy();
void TypeWriter();
void NewQuest(bool permision);
void Shop();
DWORD WINAPI Timer(void* param);
void Defeat();
DWORD WINAPI Waves(void* p);
void ShowField();
void WordGeneration(int mode);
void ButtonPress(bool reverse, bool waves, int& score, int& size);
void Music(int music);
void MainMenu();
void AboutAuthor();
void Stepa();
void SetCursor(COORD& position, int x, int y);