#include "libraries.h"
#include "prototipes.h"
#include "enum.h"
#include "Structs.h"

bool music_status = 1;
bool correct_word = 0;
bool wave_reflected = 0;
bool redwave = 0;
bool gameon = 1;
int credits = 100;
int length = 3;
int side = 0;
int mode = 0;
int seconds = 10;
int defalt_record = 0;
int legacy_record = 0;
int typewriter_record = 0;
int x_coordinats[10]{ 0 };
char word[10]{ 0 };
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
QuestsStatistic Quest;
Items CurrentItems;

int main()
{
	srand(time(0));
	system("title Push"); // для названия консоли
	SetConsoleTextAttribute(h, Green);
	MainMenu();
}
void Default()
{
	mode = 1;
	side = rand() % 4;
	length = 3;
	system("title Default");
	int score = 0;
	int i = 0;
	ShowField();
	WordGeneration(length);
	gameon = 1;
	do
	{
		if (score == 0)
		{
			//CreateThread(0, 0, Time, 0, 0, 0);
			//CreateThread(0, 0, Waves, 0, 0, 0);
		}
		if (correct_word)
		{
			ShowField();
			WordGeneration(length);
			correct_word = 0;
		}
		for (; true; i++)
		{
			if (score >= 10000)
			{
				length = 10;
			}
			else if (score >= 9000)
			{
				length = 9;
			}
			else if (score >= 8000)
			{
				length = 8;
			}
			else if (score >= 7000)
			{
				length = 7;
			}
			else if (score >= 6000)
			{
				length = 6;
			}
			else if (score >= 5000)
			{
				length = 5;
			}
			else if (score >= 3000)
			{
				length = 4;
			}
			if (rand() % 2 == 0)
			{
				ButtonPress(1, 0, score, length);
				if (correct_word)	
					break;
			}
			else
			{
				ButtonPress(0, 0, score, length);
				if (correct_word)
					break;
			}
		}
	} while (true);
}
void Legacy()
{
	mode = 2;
	length = 3;
	system("title Legacy");
	int score = 0;
	ShowField();
	WordGeneration(length);
	gameon = 1;
	do
	{
		if (score == 0)
		{
			//CreateThread(0, 0, Timer, 0, 0, 0);
			//CreateThread(0, 0, Waves, 0, 0, 0);
		}
		if (correct_word)
		{
			ShowField();
			WordGeneration(length);
			side = rand() % 4;
			correct_word = 0;
		}
		if (score >= 10000)
		{
			length = 10;
		}
		else if (score >= 9000)
		{
			length = 9;
		}
		else if (score >= 8000)
		{
			length = 8;
		}
		else if (score >= 7000)
		{
			length = 7;
		}
		else if (score >= 6000)
		{
			length = 6;
		}
		else if (score >= 5000)
		{
			length = 5;
		}
		else if (score >= 3000)
		{
			length = 4;
		}
		ButtonPress(0, 0, score, length);
	} while (true);
}
void TypeWriter()
{
	mode = 3;
	length = 5;
	system("title TypeWriter");
	int score = 0;
	int i = 0;
	ShowField();
	WordGeneration(length);
	gameon = 1;
	//CreateThread(0, 0, Timer, 0, 0, 0);
	do
	{
		for (; true; i++)
		{
			if (score == 0)
			{
				//CreateThread(0, 0, Timer, 0, 0, 0);
			}
			if (correct_word)
			{
				ShowField();
				WordGeneration(length);
				correct_word = 0;
			}
			if (score >= 10000)
			{
				length = 10;
			}
			else if (score >= 8000)
			{
				length = 9;
			}
			else if (score >= 6000)
			{
				length = 8;
			}
			else if (score >= 4000)
			{
				length = 7;
			}
			else if (score >= 2000)
			{
				length = 6;
			}
			if (rand() % 2 == 0)
			{
				ButtonPress(1, 0, score, length);
				if (correct_word)
					break;
			}
			else
			{
				ButtonPress(0, 0, score, length);
				if (correct_word)
					break;
			}
		}
	} while (true);
	
}
void NewQuest(bool permision)
{
	system("cls");
	system("title Your Quest");
	system("mode con cols=120 lines=20");
	COORD coord;
	coord.X = 30;
	coord.Y = 5;
	SetCursor(coord, coord.X, coord.Y);
	if (permision)
	{
		Quest = { 0 };
		Quest.quest_number = rand() % 5;
	}
	else
	{
		cout << "Do you want to use one of your skipper and skip this quest?";
		coord.Y += 2;
		SetCursor(coord, coord.X, coord.Y);
		cout << "\t\tEnter\tEsc";
		int key = 0;
		do
		{
			key = _getch();
		} while (key != ESC && key != ENTER);
		if (key == ENTER)
		{
			if (CurrentItems.skippers == 0)
			{
				MessageBox(0, L"You need to complete your quest or buy skipper", L"Error", MB_OK);
			}
			else
			{
				permision = 1;
				Quest = { 0 };
				Quest.quest_number = rand() % 5;
			}
		}
	}
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	switch (Quest.quest_number)
	{
	case 0:
		if (permision)
		{
			Quest.goal = rand() % 10000 + 1500;
		}
		cout << "Your need to score " << Quest.goal << " in the Defalt";
		break;
	case 1:
		if (permision)
		{
			Quest.goal = rand() % 10000 + 1500;
		}
		cout << "Your need to score " << Quest.goal << " in the Legasy";
		break;
	case 2:
		if (permision)
		{
			Quest.goal = rand() % 10000 + 1500;
		}
		cout << "Your need to score " << Quest.goal << " in the TypeWriter";
		break;
	case 3:
		if (permision)
		{
			Quest.goal = rand() % 300 + 50;
		}
		cout << "Your need to reflect " << Quest.goal << " wawes in the any mode with wawes";
		break;
	case 4:
		if (permision)
		{
			Quest.goal = rand() % 100 + 10;
		}
		cout << "Your need to reflect " << Quest.goal << " in the any mode";
		break;
	default:
		cout << "Error -1";
		exit(0);
		break;
	}
	int key = 0;
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "Press enter to exit";
	do
	{
		key = _getch();
	} while (key != ESC && key != ENTER);
	permision = 0;
	MainMenu();
}
DWORD WINAPI Timer(void* p)
{
	bool defeat = 1;
	COORD coord;
	coord.X = 50;
	while (true)
	{
		do
		{
			this_thread::sleep_for(chrono::milliseconds(1000));
		} while (gameon == 0);
		for (int i = 0, counter = 0; i < 150 && gameon; i++)
		{
			coord.X++;
			coord.Y = 21;
			for (int j = 0; j < 20 && gameon; j++)
			{
				SetCursor(coord, coord.X, coord.Y);
				SetConsoleTextAttribute(h, Red);
				if (coord.Y != 30 || coord.X != x_coordinats[counter])
				{
					cout << (char)219;
				}
				else
				{
					counter++;
				}
				if (gameon == 0)
				{
					break;
				}
				coord.Y++;
			}
			this_thread::sleep_for(chrono::milliseconds(50));
			if (correct_word)
			{
				coord.X = 50;
				for (int i = 0, counter = 0; i < 150 && gameon; i++)
				{
					coord.X++;
					coord.Y = 21;
					for (int j = 0; j < 20 && gameon; j++)
					{
						SetCursor(coord, coord.X, coord.Y);
						SetConsoleTextAttribute(h, Black);
						cout << (char)219;
						coord.Y++;
					}
				}
				defeat = 0;
				break;
			}
		}
		if (defeat)
		{
			gameon = 0;
		}
	}
	return 0;
}
DWORD WINAPI Waves(void* p)
{
	COORD coord;
	do
	{
		do
		{
			if (rand() % 2 == 0)
			{
				redwave = 1;
			}
			else
			{
				redwave = 0;
			}
			if (side == 0)
			{
				for (int black = 0; black < 2 && gameon; black++)
				{
					coord.X = 0;
					coord.Y = 0;
					for (int i = 0; i < 20 && gameon; i++)
					{
						if (wave_reflected)
						{
							break;
						}
						for (int j = 0; j <= 250 && gameon; j++)
						{
							if (redwave)
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, Red);
								}
							}
							else
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, DarkGreen);
								}
							}
							if (coord.Y != 1 && coord.Y != 3 && coord.X >= 3 && coord.X <= 35)
							{
								cout << (char)219;
							}
							coord.X++;
							SetCursor(coord, coord.X, coord.Y);
						}
						this_thread::sleep_for(chrono::milliseconds(50));
						coord.Y++;
						coord.X = 0;
						SetCursor(coord, coord.X, coord.Y);
					}
				}
			}
			else if (side == 3)
			{
				for (int black = 0; black < 2 && gameon; black++)
				{
					coord.X = 0;
					coord.Y = 0;
					for (int i = 0; i <= 60 && gameon; i++)
					{
						if (wave_reflected)
						{
							break;
						}
						for (int j = 0; j < 150 && gameon; j++)
						{
							if (redwave)
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, Red);
								}
							}
							else
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, DarkGreen);
								}
							}
							if (coord.Y != 1 && coord.Y != 3 && coord.X >= 3 && coord.X <= 35)
							{
								cout << (char)219;
							}
							this_thread::sleep_for(chrono::milliseconds(50));
							coord.Y++;
							SetCursor(coord, coord.X, coord.Y);
						}
						coord.X++;
						coord.Y = 0;
						SetCursor(coord, coord.X, coord.Y);
					}
				}
			}
			else if (side == 1)
			{
				for (int black = 0; black < 2 && gameon; black++)
				{
					coord.X = 250;
					coord.Y = 60;
					for (int i = 250; i > 200 && gameon; i--)
					{
						if (wave_reflected)
						{
							break;
						}
						for (int j = 60; j >= 0 && gameon; j--)
						{
							if (redwave)
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, Red);
								}
							}
							else
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, DarkGreen);
								}
							}
							cout << (char)219;
							coord.Y--;
							SetCursor(coord, coord.X, coord.Y);
						}
						this_thread::sleep_for(chrono::milliseconds(50));
						coord.X--;
						coord.Y = 60;
						SetCursor(coord, coord.X, coord.Y);
					}
				}
			}
			else if (side == 2)
			{
				for (int black = 0; black < 2 && gameon; black++)
				{
					coord.X = 250;
					coord.Y = 60;
					for (int i = 60; i > 40 && gameon; i--)
					{
						if (wave_reflected)
						{
							break;
						}
						for (int j = 250; j >= 0 && gameon; j--)
						{
							if (redwave)
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, Red);
								}
							}
							else
							{
								if (black == 1)
								{
									SetConsoleTextAttribute(h, Black);
								}
								else
								{
									SetConsoleTextAttribute(h, DarkGreen);
								}
							}
							cout << (char)219;
							coord.X--;
							SetCursor(coord, coord.X, coord.Y);
						}
						this_thread::sleep_for(chrono::milliseconds(50));
						coord.Y--;
						coord.X = 250;
						SetCursor(coord, coord.X, coord.Y);
					}
				}
			}
			if (wave_reflected == 0)
			{
				gameon = 0;
			}
			wave_reflected = 0;
		} while (gameon);
	} while (gameon == 0);
	if (gameon)
	{
		ExitThread(GetExitCodeThread(Waves, 0));
	}
	return 0;
}
void ButtonPress(bool reverse, bool waves, int& score, int& size)
{
	COORD coord;
	int key = 0;
	if (gameon)
	{
		if (reverse)
		{
			coord.X = 125;
			coord.Y = 18;
			SetCursor(coord, coord.X, coord.Y);
			SetConsoleTextAttribute(h, Red);
			cout << "REVERSE";
			for (int i = size - 1; i >= 0; i--)
			{
				coord.X = 5;
				coord.Y = 1;
				SetCursor(coord, coord.X, coord.Y);
				switch (Quest.quest_number)
				{
				case 0:
					cout << "Your need to score " << Quest.goal << " in the Defalt";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.defalt_score << "\\" << Quest.goal;
					break;
				case 1:
					cout << "Your need to score " << Quest.goal << " in the Legasy";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.legacy_score << "\\" << Quest.goal;
					break;
				case 2:
					cout << "Your need to score " << Quest.goal << " in the TypeWriter";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.typewriter_score << "\\" << Quest.goal;
					break;
				case 3:
					cout << "Your need to reflect " << Quest.goal << " wawes in the any mode with wawes";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.waves_count << "\\" << Quest.goal;
					break;
				case 4:
					cout << "Your need to reflect " << Quest.goal << " in the any mode";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					if (Quest.defalt_score > Quest.legacy_score && Quest.defalt_score > Quest.typewriter_score)
					{
						cout << "Current progress:" << Quest.defalt_score << "\\" << Quest.goal;
					}
					else if (Quest.legacy_score > Quest.defalt_score && Quest.legacy_score > Quest.typewriter_score)
					{
						cout << "Current progress:" << Quest.legacy_score << "\\" << Quest.goal;
					}
					else if (Quest.typewriter_score > Quest.legacy_score && Quest.typewriter_score > Quest.defalt_score)
					{
						cout << "Current progress:" << Quest.typewriter_score << "\\" << Quest.goal;
					}
					break;
				default:
					break;
				}
				key = _getch();
				if (gameon)
				{
					if (key == (int)word[i] || key == (int)word[i] + 32 || key == (int)word[i] - 32)
					{
						coord.X = x_coordinats[i];
						coord.Y = 30;
						SetCursor(coord, coord.X, coord.Y);
						SetConsoleTextAttribute(h, BlueOnRed);
						cout << word[i];
						SetConsoleTextAttribute(h, Green);
						score += rand() % 100;
						if (mode == 3)
						{
							Quest.typewriter_score = score;
						}
						else if (mode == 2)
						{
							Quest.legacy_score = score;
						}
						else if (mode == 1)
						{
							Quest.defalt_score = score;
						}
					}
					else
					{
						if (waves)
						{
							if (key == 224 && redwave == 0)
							{
								key = _getch();
								if (side == 0 && key == UP)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 1 && key == RIGHT)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 2 && key == DOWN)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 3 && key == LEFT)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else
								{
									gameon = 0;
									Defeat();
								}
								if (mode == 3)
								{
									Quest.typewriter_score = score;
								}
								else if (mode == 2)
								{
									Quest.legacy_score = score;
								}
								else if (mode == 1)
								{
									Quest.defalt_score = score;
								}
							}
							else
							{
								gameon = 0;
								Defeat();
							}
						}
						else
						{
							gameon = 0;
							Defeat();
						}
					}
				}
				else
				{
					Defeat();
				}
			}
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				coord.X = 5;
				coord.Y = 1;
				SetCursor(coord, coord.X, coord.Y);
				switch (Quest.quest_number)
				{
				case 0:
					cout << "Your need to score " << Quest.goal << " in the Defalt";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.defalt_score << "\\" << Quest.goal;
					break;
				case 1:
					cout << "Your need to score " << Quest.goal << " in the Legasy";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.legacy_score << "\\" << Quest.goal;
					break;
				case 2:
					cout << "Your need to score " << Quest.goal << " in the TypeWriter";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.typewriter_score << "\\" << Quest.goal;
					break;
				case 3:
					cout << "Your need to reflect " << Quest.goal << " wawes in the any mode with wawes";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					cout << "Current progress:" << Quest.waves_count << "\\" << Quest.goal;
					break;
				case 4:
					cout << "Your need to reflect " << Quest.goal << " in the any mode";
					coord.Y = 3;
					SetCursor(coord, coord.X, coord.Y);
					if (Quest.defalt_score > Quest.legacy_score && Quest.defalt_score > Quest.typewriter_score)
					{
						cout << "Current progress:" << Quest.defalt_score << "\\" << Quest.goal;
					}
					else if (Quest.legacy_score > Quest.defalt_score && Quest.legacy_score > Quest.typewriter_score)
					{
						cout << "Current progress:" << Quest.legacy_score << "\\" << Quest.goal;
					}
					else if (Quest.typewriter_score > Quest.legacy_score && Quest.typewriter_score > Quest.defalt_score)
					{
						cout << "Current progress:" << Quest.typewriter_score << "\\" << Quest.goal;
					}
					break;
				default:
					break;
				}
				key = _getch();
				if (gameon)
				{
					if (key == (int)word[i] || key == (int)word[i] + 32 || key == (int)word[i] - 32)
					{
						coord.X = x_coordinats[i];
						coord.Y = 30;
						SetCursor(coord, coord.X, coord.Y);
						SetConsoleTextAttribute(h, BlueOnRed);
						cout << word[i];
						SetConsoleTextAttribute(h, Green);
						score += rand() % 100;
						if (mode == 3)
						{
							Quest.typewriter_score = score;
						}
						else if (mode == 2)
						{
							Quest.legacy_score = score;
						}
						else if (mode == 1)
						{
							Quest.defalt_score = score;
						}
					}
					else
					{
						if (waves)
						{
							if (key == 224 && redwave == 0)
							{
								key = _getch();
								if (side == 0 && key == UP)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 1 && key == RIGHT)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 2 && key == DOWN)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else if (side == 3 && key == LEFT)
								{
									wave_reflected = 1;
									score += rand() % 25;
								}
								else
								{
									gameon = 0;
									Defeat();
								}
								if (mode == 3)
								{
									Quest.typewriter_score = score;
								}
								else if (mode == 2)
								{
									Quest.legacy_score = score;
								}
								else if (mode == 1)
								{
									Quest.defalt_score = score;
								}
							}
							else
							{
								gameon = 0;
								Defeat();
							}
						}
						else
						{
							gameon = 0;
							Defeat();
						}
					}
				}
				else
				{
					Defeat();
				}
			}
		}
		correct_word = 1;
	}
	else
	{
		Defeat();
	}
}
void Defeat()
{
	system("cls");
	system("title Your Lose");
	system("mode con cols=120 lines=20");
	COORD coord;
	coord.X = 30;
	coord.Y = 5;
	SetCursor(coord, coord.X, coord.Y);
	cout << "Try do this faster next time";
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	if (mode == 1)
	{
		cout << "You have scored in defalt mode " << Quest.defalt_score << " points";
		if (Quest.defalt_score > defalt_record)
		{
			defalt_record = Quest.defalt_score;
			coord.Y += 2;
			SetCursor(coord, coord.X, coord.Y);
			cout << "It's you new record!";
		}
	}
	else if (mode == 2)
	{
		cout << "You have scored in legacy mode " << Quest.legacy_score << " points";
		if (Quest.legacy_score > legacy_record)
		{
			legacy_record = Quest.legacy_score;
			coord.Y += 2;
			SetCursor(coord, coord.X, coord.Y);
			cout << "It's you new record!";
		}
	}
	else if (mode == 3)
	{
		cout << "You have scored in typewriter mode " << Quest.typewriter_score << " points";
		if (Quest.typewriter_score > typewriter_record)
		{
			typewriter_record = Quest.typewriter_score;
			coord.Y += 2;
			SetCursor(coord, coord.X, coord.Y);
			cout << "It's you new record!";
		}
	}
	if (CurrentItems.protection > 0)
	{
		coord.Y += 2;
		SetCursor(coord, coord.X, coord.Y);
		cout << "You have protection would you like to use it to save your score for quest?";
		coord.Y += 2;
		SetCursor(coord, coord.X, coord.Y);
		cout << "\t\tEnter\tEsc";
		int key = 0;
		do
		{
			key = _getch();
		} while (key != ESC && key != ENTER);
		if (key == ENTER)
		{
			MessageBox(0, L"You have use your item your score have been saved for one more game", L"Error", MB_OK);
			if (mode == 1)
			{
				Default();
			}
			else if (mode == 2)
			{
				Legacy();
			}
			else if (mode == 3)
			{
				TypeWriter();
			}
		}
		else if (key == ESC)
		{
			Quest = { 0 };
			MainMenu();
		}
	}
	else
	{
		Sleep(3000);
		MainMenu();
	}
}
void Shop() {
	system("cls");
	system("title Shop");
	system("mode con cols=120 lines=60");
	COORD coord;
	coord.X = 5;
	coord.Y = 3;
	SetCursor(coord, coord.X, coord.Y);
	cout << "───────────────██████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──────────█████████████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──────█████████───████████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "─────████─────────█████████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──█████───────────████████████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "█████─────────────██████████████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒───────────────████████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒────────▒██████████████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─────────██────────████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒──────────██──────█████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒───────────██────██████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒────────────█────██████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█▒─────────██──███████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█████▒─────██──███████████▒███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█───▒████████──████████▒───███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█──────────────────────────███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█──────────────────────────███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█───▒████████──████████▒───███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒─█████▒─────▒█──███████████▒███▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒────────────██──███████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "██▒───────────▒█────██████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "─██▒──────────█──────████████████▒█";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "─██▒─────────██──────███████████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──██▒───────██────────█████████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "───██▒────────██────██████████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "────███─────────█████████████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "─────███▒────────███████████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──────████▒───────████████▒███";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "────────████▒─────██████▒███";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──────────████▒───█████▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "────────────████▒─███▒██";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "──────────────█████████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "────────────────█████";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "─────────────────███";
	coord.Y += 3;
	SetCursor(coord, coord.X, coord.Y);
	cout << "Shield that can save you once at game in one mode";
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tCost - 100";
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tIn inventory - " << CurrentItems.protection;
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tTo buy press P";
	coord.X += 45;
	coord.Y = 3;
	SetCursor(coord, coord.X, coord.Y);
	cout << "______________________$$$$$$$$$$____________________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "_____________________$$___$$_$$$____________________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "______________________$$$____$$$____________________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "______________________$$$$$$$$$_____________________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "_______$$$$$$$$$$$$___$$_____$$___$$$$$$$$$$$$______";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "_____$$$____$$_____$$$__$$$$$__$$$______$____$$$____";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "_____$__$$$$$$$$$$$__$$__$$$__$$___$$$$$$$$$$__$$___";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____$$__$$$$$$$$$$$$$__$_____$___$$$$$$$$$$$$$__$___";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____$$__$$$$$$$$$$$$$$__$$__$__$$$$$$$$$$$$$$___$___";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "_____$$__$$$$$$$$$$$$$$__$$$__$$$$$$$$$$$$$$___$$___";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "______$$___$$$$$_________$$$_________$$$$$$__$$_____";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "________$$$______$$$$$$$$$$$$$$$$$$$$______$$_______";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "___________$$$$$$$$$$$$$_____$$$$$$$$$$$$$__________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________$$_$$$$$$$$$$___$$$$$$$$$$_$$___________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________$$_$$$$$$___________$$$$$$__$$__________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________$$___________$$$___________$$$__________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________$$_$$$$$$$$$$$$$$$$$$$$$$$_$$$__________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________$$$$$$$$$$$$$$$$$$$$$$$$$$$$$___________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "______________$$$$$$$$$$$$$$$$$$$$$$$$$_____________";
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << "____________________________________________________";
	coord.Y += 3;
	SetCursor(coord, coord.X, coord.Y);
	cout << "Skipper that can change your current quest";
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tCost - 10";
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tIn inventory - " << CurrentItems.skippers;
	coord.Y += 2;
	SetCursor(coord, coord.X, coord.Y);
	cout << "\tTo buy press S";
	coord.X = 80;
	coord.Y = 40;
	SetCursor(coord, coord.X, coord.Y);
	cout << "Credits - " << credits;
	int key = 0;
	do
	{
		key = _getch();
	} while (key != ESC && key != P && key != S);
	if (key == P)
	{
		if (credits >= 100)
		{
			credits -= 100;
			CurrentItems.protection++;
			MessageBox(0, L"Thank you for your purchase you bought 1 shield", L"Purchase", MB_OK);
			MainMenu();
		}
		else
		{
			MessageBox(0, L"You haven't eniught credits to buy this", L"Error", MB_OK);
			MainMenu();
		}
	}
	else if (key == S)
	{
		if (credits >= 10)
		{
			credits -= 10;
			CurrentItems.skippers++;
			MessageBox(0, L"Thank you for your purchase you bought 1 skipper", L"Purchase", MB_OK);
			MainMenu();
		}
		else
		{
			MessageBox(0, L"You haven't eniught credits to buy this", L"Error", MB_OK);
			MainMenu();
		}
	}
	else if (key == ESC)
	{
		MainMenu();
	}
}
void ShowField()
{
	system("cls");
	COORD coord;
	coord.X = 50;
	coord.Y = 20;
	SetCursor(coord, coord.X, coord.Y);
	SetConsoleTextAttribute(h, Green);
	cout << (char)218;
	for (int i = 0; i < 150; i++)
	{
		coord.X++;
		SetCursor(coord, coord.X, coord.Y);
		cout << (char)196;
	}
	cout << (char)191;
	coord.X++;
	for (int i = 0; i < 20; i++)
	{
		coord.Y++;
		SetCursor(coord, coord.X, coord.Y);
		cout << (char)179;
	}
	coord.Y++;
	SetCursor(coord, coord.X, coord.Y);
	cout << (char)217;
	for (int i = 0; i < 150; i++)
	{
		coord.X--;
		SetCursor(coord, coord.X, coord.Y);
		cout << (char)196;
	}
	coord.X--;
	SetCursor(coord, coord.X, coord.Y);
	cout << (char)192;
	for (int i = 0; i < 20; i++)
	{
		coord.Y--;
		SetCursor(coord, coord.X, coord.Y);
		cout << (char)179;
	}
}
void WordGeneration(int size)
{
	SetConsoleTextAttribute(h, GreenOnRed);
	char letters[26]{ Q, W, E, R, T, Y, U, I, O, P, A, S, D, F, G, H, J, K, L, Z, X, C, V, B, N, M};
	for (int i = 0; i < size; i++)
	{
		word[i] = letters[rand() % 26];
	}
	COORD coord;
	coord.X = 70;
	coord.Y = 30;
	SetCursor(coord, coord.X, coord.Y);
	int step = 50;
	if (size >= 9)
	{
		step = 12;
	}
	else if (size >= 7)
	{
		step = 18;
	}
	else if (size >= 5)
	{
		step = 26;
	}
	else if (size >= 3)
	{
		step = 56;
	}
	for (int i = 0; i < size; i++)
	{
		x_coordinats[i] = coord.X;
		cout << word[i];
		coord.X += step;
		SetCursor(coord, coord.X, coord.Y);
	}
	SetConsoleTextAttribute(h, Green);
}
void Music(int music)
{
	if (music_status)
	{
		if (music == 1)
		{
			PlaySound(TEXT("1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else if (music == 2)
		{
			PlaySound(TEXT("2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else if (music == 3)
		{
			PlaySound(TEXT("3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
		else if (music == 4)
		{
			PlaySound(TEXT("4.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		}
	}
	else
	{
		PlaySound(NULL, 0, 0);
	}
}
void MainMenu()
{
	COORD coord;
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_WINDOWED_MODE, &coord);
	system("cls");
	system("mode con cols=80 lines=50");
	const int items_count = 8;
	string menu_items[items_count] = { "DEFAULT","LEGACY","TYPEWRITER","NEW QUEST", "SHOP", "MUSIC ON\\OFF", "AUTOR", "EXIT" };

	int startX = 35;
	int startY = 10;
	int margin = 5;

	COORD position = { startX, startY };
	for (auto item : menu_items)
	{
		SetConsoleTextAttribute(h, DarkGreen);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += margin;
	}

	int current_item = 0; // new game
	SetConsoleTextAttribute(h, Green);
	position.Y = startY + current_item * margin;
	SetConsoleCursorPosition(h, position);
	cout << menu_items[current_item];

	int code;
	while (true)
	{
		code = _getch();
		if (code == 224)
			code = _getch();

		SetConsoleTextAttribute(h, DarkGreen);
		position.Y = startY + current_item * margin;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) // down arrow
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // up arrow
		{
			current_item--;
		}
		else if (code == ENTER)
		{
			switch (current_item)
			{
			case 0:
				SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
				Default();
				break;
			case 1:
				SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
				Legacy();
				break;
			case 2:
				SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, &coord);
				TypeWriter();
				break;
			case 3:
				if (Quest.quest_number == -2)
				{
					NewQuest(1);
				}
				else
				{
					NewQuest(0);
				}
				break;
			case 4:
				Shop();
				break;
			case 5:
				if (music_status == 1)
				{
					music_status = 0;
				}
				else
				{
					music_status = 1;
				}
				Music(0);
				break;
			case 6:
				AboutAuthor();
				break;
			default:
				exit(0);
				break;
			}
		}

		SetConsoleTextAttribute(h, Green);
		position.Y = startY + current_item * margin;
		SetConsoleCursorPosition(h, position);
		cout << menu_items[current_item];

	}
}
void AboutAuthor()
{
	system("cls");
	system("title About Autor");
	system("mode con cols=60 lines=20");
	const int items_count = 2; //всего кнопок
	string menu_items[items_count] = { "Stepa","Back to main menu" }; //массив кнопок
	int startX = 20; //координата по иксу
	int startY = 8; //координата по игрику
	int margin = 2; //для расстояния
	COORD Position = { startX , startY };
	COORD Hello;
	Hello.Y = 8; // 3
	Hello.X = 20;

	SetConsoleTextAttribute(h, DarkGreen);
	SetConsoleCursorPosition(h, Hello);

	for (auto item : menu_items) // ф-ия перебора элементов нашего массива с названиями кнопок
	{
		SetConsoleTextAttribute(h, Yellow);
		SetConsoleCursorPosition(h, Position);
		cout << item; //вывод наших всееех кнопок
		Position.Y += margin; //позиция по игрику(строки на нужное кол-во вниз)
	}

	int current_item = 0; //для кнопок, чтоб окрасить в фиол
	SetConsoleTextAttribute(h, DarkGreen);
	Position.Y = startY + current_item * margin;  // возвращает на первый элемент -> new game
	SetConsoleCursorPosition(h, Position);
	cout << menu_items[current_item]; // выводит -> new game

	int code; //перемннная для хранения клавишей, которые мы нажали

	while (true) //пока не выйдем
	{
		code = _getch(); //для нажатия кнопок
		if (code == 224) //для стрелок
			code = _getch(); //повторное присвоение

		SetConsoleTextAttribute(h, Yellow);
		Position.Y = startY + current_item * margin;
		SetConsoleCursorPosition(h, Position);
		cout << menu_items[current_item];

		if ((code == DOWN || code == RIGHT) && current_item < items_count - 1) // стрелочка вниз
		{
			current_item++;
		}
		else if ((code == UP || code == LEFT) && current_item > 0) // стрелочка вверх
		{
			current_item--;
		}
		else if (code == ENTER) // если пользователь нажал клавишу Enter, тобиж выбрал нужный пункт
		{
			switch (current_item) //какую кнопку выбрал
			{
			case 0: //если 0 (1 элемент массива)
				Stepa();
				break; // для того, чтобы не сделало след. пункт
			case 1: //если 2 (3 элемент массива)
				MainMenu(); //возвращаемся в главное меню
				break;
			default:
				exit(0);
				break;
			}
		}

		SetConsoleTextAttribute(h, DarkGreen);
		Position.Y = startY + current_item * margin;
		SetConsoleCursorPosition(h, Position);
		cout << menu_items[current_item];

	}



	margin = 5;
	Position.Y += margin;
	SetConsoleCursorPosition(h, Position);
	cout << "To exit press Enter";


}
void Stepa() {

	system("cls");
	int code;// для клавиши enter
	COORD position;//позиции текста
	position.X = 20;
	position.Y = 5;
	int margin = 2;// расстояние между текстом

	const int items_count = 3;
	string discript_items[items_count] = { "My Name is Stepa","I'm 17","I'm a programmer" };//массив текста

	for (auto item : discript_items) // ф-ия перебора элементов нашего массива тобиж строчек текста
	{
		SetConsoleTextAttribute(h, Yellow);
		SetConsoleCursorPosition(h, position);
		cout << item;
		position.Y += margin;
	}
	position.Y += margin;

	SetConsoleTextAttribute(h, DarkGreen);
	SetConsoleCursorPosition(h, position);
	cout << "To go back press Enter...";
	code = _getch();
	if (code == ENTER) // если пользователь нажал ентер
		AboutAuthor();//возвращаемся в меню авторов
	else   // а вот не нажал ентер 
		Stepa();//вызываем саму себя 


	Sleep(INFINITE);
}
void SetCursor(COORD& position, int x, int y) {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	position.X = x; // координата позиции
	position.Y = y; // координата позиции
	SetConsoleCursorPosition(h, position);
} 