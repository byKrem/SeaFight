﻿#include <iostream>;
#include <Windows.h>;
#include <conio.h>;
#include <ctime>;
#include <list>;
using namespace std;

struct Options {
	int FirstMap[12][12] = { 0 };
	int SecondMap[12][12] = { 0 };

	int shipS = 0, 
		shipM = 0,
		shipL = 0,
		shipXL = 0;

	int size = 12;
	const bool isRandomPlace = true;
	int ShipColor = 7;
	int ShipCount1 = 0, ShipCount2 = 0;

};

void SetColor(char symbol, int color) {
	HANDLE _color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(_color, color);
	cout << symbol << " ";
	SetConsoleTextAttribute(_color, 7);
}

void ShowMap(Options options, bool isEnemyMap = false) {
	//int** Map = new int *[12];
	//for (int i = 0; i < 12; i++) Map[i] = new int[12];
	int Map[12][12];
	if (!isEnemyMap) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.FirstMap[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.SecondMap[i][j];
			}
		}
	}
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			if (isEnemyMap) {
				SetColor('~', 9);
			}
			else if (Map[i][j] == 8) {
				SetColor('#', 14);
			}
			else if (Map[i][j] == 2 || Map[i][j] == 9) {
				SetColor('=', 7);
			}
			else if (Map[i][j] == 0 || Map[i][j] == 0) {
				SetColor('~', 9);
			}
			else if (Map[i][j] == 3) {
				SetColor('o', 11);
			}
			else if (Map[i][j] == 4) {
				SetColor('x', 6);
			}
			else if (Map[i][j] == 5) {
				SetColor('X', 4);
			}
		}
		cout << endl;
	}
}


void Rotate(int Map[12][12]) {
	
}

void RandomShip(Options& options, bool isFirstMap = true) {
	int Map[12][12];
	if (isFirstMap) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.FirstMap[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.SecondMap[i][j];
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (options.shipXL != 1) {
			bool isStop = false;
			for (; !isStop;) {
				int X = rand() % 6 + 3;
				int Y = rand() % 6 + 3;
				switch (rand() % 4 + 1) {
				case 1:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X + o][Y] = 2;
							Map[X + o][Y - 1] = 8;
							Map[X + o][Y + 1] = 8;
							if (o == 3) {
								Map[X + o + 1][Y] = 8;
								Map[X + o + 1][Y - 1] = 8;
								Map[X + o + 1][Y + 1] = 8;
								Map[X - 1][Y] = 8;
								Map[X - 1][Y - 1] = 8;
								Map[X - 1][Y + 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 2:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X - o][Y] = 2;
							Map[X - o][Y - 1] = 8;
							Map[X - o][Y + 1] = 8;
							if (o == 3) {
								Map[X - o - 1][Y] = 8;
								Map[X - o - 1][Y - 1] = 8;
								Map[X - o - 1][Y + 1] = 8;
								Map[X + 1][Y] = 8;
								Map[X + 1][Y - 1] = 8;
								Map[X + 1][Y + 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 3:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X][Y + o] = 2;
							Map[X - 1][Y + o] = 8;
							Map[X + 1][Y + o] = 8;
							if (o == 3) {
								Map[X][Y + o + 1] = 8;
								Map[X - 1][Y + o + 1] = 8;
								Map[X + 1][Y + o + 1] = 8;
								Map[X][Y - 1] = 8;
								Map[X - 1][Y - 1] = 8;
								Map[X + 1][Y - 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 4:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X][Y - o] = 2;
							Map[X - 1][Y - o] = 8;
							Map[X + 1][Y - o] = 8;
							if (o == 3) {
								Map[X][Y - o - 1] = 8;
								Map[X - 1][Y - o - 1] = 8;
								Map[X + 1][Y - o - 1] = 8;
								Map[X][Y + 1] = 8;
								Map[X - 1][Y + 1] = 8;
								Map[X + 1][Y + 1] = 8;
							}
						}
						isStop = true;
					}
					break;
				}
			}
			options.shipXL++;
		}
		if (options.shipL != 2) {
			bool isStop = false;
			for (; !isStop;) {
				int X = rand() % 6 + 3;
				int Y = rand() % 6 + 3;
				switch (rand() % 4 + 1) {
				case 1:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X + o][Y] = 2;
							Map[X + o][Y - 1] = 8;
							Map[X + o][Y + 1] = 8;
							if (o == 3) {
								Map[X + o + 1][Y] = 8;
								Map[X + o + 1][Y - 1] = 8;
								Map[X + o + 1][Y + 1] = 8;
								Map[X - 1][Y] = 8;
								Map[X - 1][Y - 1] = 8;
								Map[X - 1][Y + 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 2:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X - o][Y] = 2;
							Map[X - o][Y - 1] = 8;
							Map[X - o][Y + 1] = 8;
							if (o == 3) {
								Map[X - o - 1][Y] = 8;
								Map[X - o - 1][Y - 1] = 8;
								Map[X - o - 1][Y + 1] = 8;
								Map[X + 1][Y] = 8;
								Map[X + 1][Y - 1] = 8;
								Map[X + 1][Y + 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 3:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X][Y + o] = 2;
							Map[X - 1][Y + o] = 8;
							Map[X + 1][Y + o] = 8;
							if (o == 3) {
								Map[X][Y + o + 1] = 8;
								Map[X - 1][Y + o + 1] = 8;
								Map[X + 1][Y + o + 1] = 8;
								Map[X][Y - 1] = 8;
								Map[X - 1][Y - 1] = 8;
								Map[X + 1][Y - 1] = 8;
							}
						}
						isStop = true;
						break;
					}
				case 4:
					if (X >= 0 + 3 && X <= 12 - 3 && Y >= 0 + 3 && Y <= 12 - 3) {
						for (int o = 0; o < 4; o++) {
							Map[X][Y - o] = 2;
							Map[X - 1][Y - o] = 8;
							Map[X + 1][Y - o] = 8;
							if (o == 3) {
								Map[X][Y - o - 1] = 8;
								Map[X - 1][Y - o - 1] = 8;
								Map[X + 1][Y - o - 1] = 8;
								Map[X][Y + 1] = 8;
								Map[X - 1][Y + 1] = 8;
								Map[X + 1][Y + 1] = 8;
							}
						}
						isStop = true;
					}
					break;
				}
			}
			options.shipL++;
		}
		if (options.shipM != 3) {

		}
		if (options.shipS != 4) {

		}
	}
	if (isFirstMap) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				options.FirstMap[i][j] = Map[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				options.SecondMap[i][j] = Map[i][j];
			}
		}
	}
}

bool PlaceShip(Options& options, int D = 1, bool isFirstMap = true) {
	bool isStop = false;
	int Map[12][12];
	if (isFirstMap) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.FirstMap[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				Map[i][j] = options.SecondMap[i][j];
			}
		}
	}
	const int C = 4;
	int cord[C][2];
	for (int x = 0, count = 0; x < 12; x++) {
		for (int y = 0; y < 12; y++) {
			if (Map[y][x] == 9) {
				cord[count][0] = x;
				cord[count][1] = y;
				count++;
				if (count == C-1) {
					break;
				}
			}
			else {
			}
		}
		if (count == C-1) {
			break;
		}
	}
	while (!isStop) {
		switch (_getch())
		{
			case 'A':
			case 'a':
			case 75:
				if (Map[cord[C-1][1]][cord[C-1][0] - 1] != 1 && Map[cord[0][1]][cord[0][0] - 1] != 1) {
					for (int i = 0; i < C; i++) {
						Map[cord[i][1]][cord[i][0]] = 0;
						cord[i][0]--;
						Map[cord[i][1]][cord[i][0]] = 9;
					}
				}
				isStop = true;
				break;
			case 'D':
			case 'd':
			case 77:
				if (Map[cord[C-1][1]][cord[C-1][0] + 1] != 1 && Map[cord[0][1]][cord[0][0] + 1] != 1) {
					for (int i = C-1; i >= 0; i--) {
						Map[cord[i][1]][cord[i][0]] = 0;
						cord[i][0]++;
						Map[cord[i][1]][cord[i][0]] = 9;
					}
				}
				isStop = true;
				break;
			case 'S':
			case 's':
			case 80:
				if (Map[cord[C-1][1]+1][cord[C-1][0]] != 1 && Map[cord[0][1]+1][cord[0][0]] != 1) {
					for (int i = C-1; i >= 0; i--) {
						Map[cord[i][1]][cord[i][0]] = 0;
						cord[i][1]++;
						Map[cord[i][1]][cord[i][0]] = 9;
					}
				}
				isStop = true;
				break;
			case 'W':
			case 'w':
			case 72:
				if (Map[cord[C-1][1] - 1][cord[C-1][0]] != 1 && Map[cord[0][1] - 1][cord[0][0]] != 1) {
					for (int i = 0; i < C; i++) {
						Map[cord[i][1]][cord[i][0]] = 0;
						cord[i][1]--;
						Map[cord[i][1]][cord[i][0]] = 9;
					}
				}
				isStop = true;
				break;
			case 'E':
			case 'e':
			case 'Q':
			case 'q':
				if (true) {
					int	bufferArray[4][4];
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
 							bufferArray[i][j] = Map[cord[i][0]][cord[j][1] + j / 2];
						}
					}
					int buf[4][4];
					for (int i = 0; i < 4; i++){
						Map[cord[i][1]][cord[i][0]] = 0;
						for (int j = 0; j < 4; j++) {
							buf[j][i] = bufferArray[i][j];
						}
					}
					for (int i = 0; i < 4; i++) {
						for (int j = 0; j < 4; j++) {
							if (buf[i][j] == 9) {
								Map[cord[i][1]+i][cord[j][0]+j] = buf[i][j];
							}
						}
					}
				}
				isStop = true;
				break;
			case 13: // ENTER
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 4; j++) {
						if (Map[i][j] == 9) {
							Map[i][j] = 2;
						}
					}
				}
				return true;
				isStop = true;
				break;
		}
	}
	if (isFirstMap) {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				options.FirstMap[i][j] = Map[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 12; j++) {
				options.SecondMap[i][j] = Map[i][j];
			}
		}
	}
	return false;
}

void PlayerMove(Options& options) {
	cout << "Ваша ход!";
	ShowMap(options);
	char hitX; int hitY;
	cout << "Куда вы хотите ударить?"; cin >> hitX; cin >> hitY;
}

void BotMove(Options& options) {
	srand(time(0));
	int i1 = rand() % 10 + 1,
		i2 = rand() % 10 + 1;
	if (options.FirstMap[i1][i2] == 0) {
		options.FirstMap[i1][i2] = 3;
	}
	else if (options.FirstMap[i1][i2] == 2) {
		options.FirstMap[i1][i2] = 4;
	}

	cout << endl << "Противник ударил по координатам: " << endl << "[X]: " << i1 << endl << "[Y]: " << i2;


}

void SinglePlayer() {
	Options options;
	cout << "\n\n\t\t\t\t\tВы выбрали режим одиночной игры\n\n";
	for (int i = 0; i < 100 ; i++) {
		system("cls");
		ShowMap(options);
		cout << "\nОсталось кораблей"
			<< "\nXL - " << options.shipXL
			<< "\nL  - " << options.shipL
			<< "\nM  - " << options.shipM
			<< "\nS  - " << options.shipS;
		BotMove(options);
		if (options.isRandomPlace) {
			RandomShip(options);
		}
		else {
			PlaceShip(options);
		}
	}

}

void MultiPlayer() {
	cout << "Вы выбрали режим многопользовательской игры";
}

void Settings() {
	cout << "Вы зашли в настройки";
}

void Exit() {
	system("cls");
	cout << "Выход из игры...\n";
	exit(0);
}

void ShowMenu() {
	system("cls");
	cout << "\n\n\t\t\t\t\tДобро пожаловать в 'Морской бой'!\n\n"
		"\t\t\t[1]. Одиночная игра\n"
		"\t\t\t[2]. Многопользовательская игра\n"
		"\t\t\t[3]. Настройки\n"
		"\t\t\t[4]. Выход\n";
	int MainMenuOption;
	cout << "\n\t\t\t[?] - "; cin >> MainMenuOption;
	switch (MainMenuOption)
	{
	case 1:
		SinglePlayer();
		break;
	case 2:
		MultiPlayer();
		break;
	case 3:
		Settings();
		break;
	case 4:
		Exit();
		break;
	default:
		break;
	}
}

int main() {
	setlocale(0, "");
	Options options;
	do {
		ShowMenu();
	} while (options.ShipCount1 != 0 && options.ShipCount2 != 0);
}
