#include <fcntl.h>
#include <iostream>
#include <windows.h>

using namespace std;

// signs
//**********************************************************************************
#define BOMB '*'
#define FLAG '@'
#define UNKNOWN '?'
#define my_null 'a'
//**********************************************************************************
#define CLEAR system("cls")
#define INVALID cout << R << "***invalid input please try again***\n";
#define LOADING "Loading Please wait ...\n (this might take several seconds based on your game start)"
#define STARSPACE "***********************************************************************************\n"
#define STOP wprintf(L"")
#define ENTER wprintf(L"\n")
#define ASCII _setmode(_fileno(stdout), _O_TEXT)
#define UNI _setmode(_fileno(stdout), _O_U8TEXT)
#define WAIT Sleep(1300)
//**********************************************************************************
// colors
//**********************************************************************************
#define R "\033[0;31m"
#define B "\033[0;34m"
#define Y "\033[0;33m"
#define G "\033[0;32m"
#define C "\033[0;36m"
#define W "\033[0;37m"
#define P "\033[0;35m"
// **********************************************************************************

// **********************************************************************************
char trash[300];
// **********************************************************************************

void draw_line(int world_length)
{
	int length = world_length * 2;
	for (int i = 0; i < length; i++)
	{
		wprintf(L"- ");
	}
	wprintf(L"\n");
}

void Game_Name()
{
	cout << R << "Mine" << W << " " << G << "Sweeper\n"
		 << W;
}

void To_Lower(char* str)
{
	int i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) ^= 32;
			i++;
		}
		else
		{
			i++;
		}
	}
}

void min_planter(char*** p_world)
{
	p_world[0][10][0] = BOMB;
	p_world[0][14][0] = BOMB;
	p_world[0][15][0] = BOMB;
	p_world[0][16][0] = BOMB;
	p_world[0][18][0] = BOMB;
	p_world[0][21][0] = BOMB;
	p_world[0][27][0] = BOMB;
	/////////////////////////////////////////
	p_world[1][14][0] = BOMB;
	p_world[1][16][0] = BOMB;
	p_world[1][23][0] = BOMB;
	p_world[1][26][0] = BOMB;
	/////////////////////////////////////////
	p_world[2][2][0] = BOMB;
	p_world[2][5][0] = BOMB;
	p_world[2][15][0] = BOMB;
	p_world[2][16][0] = BOMB;
	p_world[2][18][0] = BOMB;
	p_world[2][22][0] = BOMB;
	/////////////////////////////////////////
	p_world[3][3][0] = BOMB;
	p_world[3][5][0] = BOMB;
	p_world[3][16][0] = BOMB;
	p_world[3][22][0] = BOMB;
	p_world[3][24][0] = BOMB;
	p_world[3][27][0] = BOMB;
	/////////////////////////////////////////
	p_world[4][17][0] = BOMB;
	p_world[4][19][0] = BOMB;
	p_world[4][28][0] = BOMB;
	/////////////////////////////////////////
	p_world[5][14][0] = BOMB;
	p_world[5][16][0] = BOMB;
	p_world[5][18][0] = BOMB;
	p_world[5][20][0] = BOMB;
	p_world[5][24][0] = BOMB;
	/////////////////////////////////////////
	p_world[6][1][0] = BOMB;
	p_world[6][3][0] = BOMB;
	p_world[6][5][0] = BOMB;
	p_world[6][13][0] = BOMB;
	p_world[6][18][0] = BOMB;
	p_world[6][25][0] = BOMB;
	/////////////////////////////////////////
	p_world[7][2][0] = BOMB;
	p_world[7][12][0] = BOMB;
	p_world[7][13][0] = BOMB;
	p_world[7][15][0] = BOMB;
	p_world[7][23][0] = BOMB;
	/////////////////////////////////////////
	p_world[8][6][0] = BOMB;
	p_world[8][13][0] = BOMB;
	p_world[8][19][0] = BOMB;
	p_world[8][25][0] = BOMB;
	/////////////////////////////////////////
	p_world[9][0][0] = BOMB;
	p_world[9][9][0] = BOMB;
	p_world[9][12][0] = BOMB;
	p_world[9][15][0] = BOMB;
	p_world[9][16][0] = BOMB;
	p_world[9][17][0] = BOMB;
	p_world[9][19][0] = BOMB;
	p_world[9][21][0] = BOMB;
	/////////////////////////////////////////
	p_world[10][0][0] = BOMB;
	p_world[10][2][0] = BOMB;
	p_world[10][4][0] = BOMB;
	p_world[10][14][0] = BOMB;
	p_world[10][15][0] = BOMB;
	p_world[10][16][0] = BOMB;
	p_world[10][22][0] = BOMB;
	/////////////////////////////////////////
	p_world[11][14][0] = BOMB;
	p_world[11][16][0] = BOMB;
	p_world[11][18][0] = BOMB;
	p_world[11][22][0] = BOMB;
	/////////////////////////////////////////
	p_world[12][4][0] = BOMB;
	p_world[12][5][0] = BOMB;
	p_world[12][10][0] = BOMB;
	p_world[12][13][0] = BOMB;
	p_world[12][14][0] = BOMB;
	p_world[12][15][0] = BOMB;
	p_world[12][16][0] = BOMB;
	/////////////////////////////////////////
	p_world[13][1][0] = BOMB;
	p_world[13][4][0] = BOMB;
	p_world[13][21][0] = BOMB;
	p_world[13][24][0] = BOMB;
	/////////////////////////////////////////
	p_world[14][2][0] = BOMB;
	p_world[14][3][0] = BOMB;
	p_world[14][7][0] = BOMB;
	p_world[14][13][0] = BOMB;
	p_world[14][16][0] = BOMB;
	p_world[14][19][0] = BOMB;
	p_world[14][24][0] = BOMB;
	p_world[14][26][0] = BOMB;
	p_world[14][27][0] = BOMB;
	p_world[14][29][0] = BOMB;
	/////////////////////////////////////////
	p_world[15][5][0] = BOMB;
	p_world[15][6][0] = BOMB;
	p_world[15][7][0] = BOMB;
	p_world[15][8][0] = BOMB;
	p_world[15][13][0] = BOMB;
	p_world[15][21][0] = BOMB;
	p_world[15][24][0] = BOMB;
	p_world[15][25][0] = BOMB;
	p_world[15][26][0] = BOMB;
	p_world[15][27][0] = BOMB;
}

int surrround_checker(char*** p_world, int i, int j, int world_size_j, int world_size_i)
{
	if (p_world[i][j][0] == BOMB)
	{
		return -1;
	}
	int bomb_around = 0;
	world_size_j--;
	world_size_i--;

	for (int x = -1; x < 2; x++)
	{
		if ((i + x) < 0 || (i + x) > world_size_j)
		{
			continue;
		}
		for (int y = -1; y < 2; y++)
		{
			if ((j + y) < 0 || (j + y) > world_size_i)
			{
				continue;
			}
			if (p_world[i + x][j + y][0] == BOMB)
			{
				bomb_around++;
			}
		}
	}

	return bomb_around;
}

void starting_layer_world(char*** p_world)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			p_world[i][j][1] = UNKNOWN;
		}
	}
}

void flag_print()
{
	cout << P;
	UNI;
	wprintf(L"\x2660");
	ASCII;
	cout << W;
}

void show_layer_world(char*** p_world, int world_size_j, int world_size_i)
{
	cout << "- ";
	draw_line(world_size_i);
	for (int i = 0; i < world_size_j; i++)
	{
		cout << "| ";
		for (int j = 0; j < (world_size_i * 2); j++)
		{
			if (j % 2 == 1)
			{
				cout << " | ";
			}
			else
			{
				if (p_world[i][j / 2][1] == FLAG)
				{
					cout << " ";
					flag_print();
				}
				else if (p_world[i][j / 2][1] == UNKNOWN)
				{
					cout << C << p_world[i][j / 2][1] << W;
				}
				else
				{
					cout << Y << p_world[i][j / 2][1] << W;
				}
			}
		}
		ENTER;
		cout << "- ";
		draw_line(world_size_i);
	}
}

void bomb_print()
{
	cout << R;
	UNI;
	wprintf(L"\x01A0");
	ASCII;
	cout << W;
}

void show_main_world(char*** p_world, int world_size_j, int world_size_i)
{
	cout << "- ";
	draw_line(world_size_i);
	for (int i = 0; i < world_size_j; i++)
	{
		cout << "|";
		for (int j = 0; j < (world_size_i * 2); j++)
		{
			if (j % 2 == 1)
			{
				cout << " |";
			}
			else
			{
				if (p_world[i][j / 2][0] == FLAG)
				{
					cout << " ";
					flag_print();
				}
				else if (p_world[i][j / 2][0] == BOMB)
				{
					cout << " ";
					bomb_print();
				}
				else
				{
					cout << Y << p_world[i][j / 2][0] << W;
				}
			}
		}
		ENTER;
		cout << "- ";
		draw_line(world_size_i);
	}
}

void right_click(char*** p_world, int i, int j, int* flag_count, int* bomb_count)
{
	if (p_world[i][j][1] == FLAG) // removing flag // the selected spot has already been flaged so the flag should be removed
	{
		if (p_world[i][j][0] == BOMB) // if the selected spot is bomb and you want to remove flag so: bomb++
		{
			*bomb_count = *bomb_count + 1;
		}
		p_world[i][j][1] = UNKNOWN;

		*flag_count = *flag_count + 1;
		return;
	}
	// using flag
	else if (p_world[i][j][1] != UNKNOWN)
	{
		cout << C;
		cout << "can\'t flag this spot (it's already been determined)";
		WAIT;
		return;
	}
	else
	{
		if (p_world[i][j][0] == BOMB)
		{
			*bomb_count = *bomb_count - 1;
		}

		p_world[i][j][1] = FLAG;
		*flag_count = *flag_count - 1;
		return;
	}
}

int left_click(char*** p_world, int i, int j, int world_size_j, int world_size_i)
{
	// if you clicked bomb : -1
	// if  *      *   safe : 0
	// if  *      *   flag : 1
	if (p_world[i][j][1] == FLAG)
	{
		return 1;
	}

	if (p_world[i][j][0] == BOMB) // you clicked bomb so ...
	{

		return -1;
	}

	int spot_value = surrround_checker(p_world, i, j, world_size_j, world_size_i);

	p_world[i][j][1] = spot_value + '0';
	return 0;
}

void left_click_rec(char*** p_world, int i, int j, int world_size_j, int world_size_i, int op_count)
{
	if (p_world[i][j][0] != '0' || op_count == 9)
	{
		return;
	}

	for (int x = -1; x < 2; x++)
	{
		int selected_row = i + x;
		if (!(selected_row >= 0 && selected_row < world_size_j))
		{
			continue;
		}
		for (int y = -1; y < 2; y++)
		{
			int selected_column = j + y;
			if (!(selected_column >= 0 && selected_column < world_size_i))
			{
				continue;
			}
			if (p_world[selected_row][selected_column][0] == '0' && (selected_column != j || selected_row != i))
			{
				// left_click(p_world, selected_row, selected_column);
				p_world[selected_row][selected_column][1] = '0';
				left_click_rec(p_world, selected_row, selected_column, world_size_j, world_size_i, op_count + 1);
			}
		}
	}
}

void create_full_main_world(char*** p_world)
{
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (p_world[i][j][0] != BOMB)
			{
				int s = surrround_checker(p_world, i, j, 16, 30);
				if (s != -1)
				{
					p_world[i][j][0] = s + '0';
				}
			}
		}
	}
}

void show_flag_min(int* p_flag_count, int* p_min_count)
{
	flag_print();
	cout << " : " << *p_flag_count;
	ENTER;
	bomb_print();
	cout << " : " << *p_min_count;
	ENTER;
}

int main()
{
	Game_Name();
menu:
	cout << R;
	UNI;
	wprintf(L" \x2665");
	ASCII;
	ENTER;
	cout << W
		 << "Menus:\n"
		 << C
		 << "1.Play!\n"
		 << "2.Rules\n"
		 << "3.Exit\n"
		 << W
		 << "\n(enter either the number or the exact command put in ):";
	char command[40];
	gets(command);
	To_Lower(command);

	if (!strcmp(command, "1") || !strcmp(command, "play")) // start the game
	{
		CLEAR;
		int world_size_i = 30;
		int world_size_j = 16;
		char*** world = (char***)malloc(world_size_j * sizeof(char**)); // creating main world
		char*** cworld = (char***)malloc(world_size_j * sizeof(char**)); // creating matrix of main world
		for (int i = 0; i < world_size_j; i++)
		{
			world[i] = (char**)malloc(world_size_i * sizeof(char*));
			cworld[i] = (char**)malloc(world_size_i * sizeof(char*));
			for (int j = 0; j < world_size_i; j++)
			{
				world[i][j] = (char*)malloc(2 * sizeof(char));
				cworld[i][j] = (char*)malloc(100 * sizeof(char));
			}
		}
		int flag_min_re_count[100];
		int move_count = 0;
		int is_trigged = 0;
		int min_count = 97;
		int* p_min_count = &min_count;
		int flag_count = min_count;
		int* p_flag_count = &flag_count;

		min_planter(world);
		create_full_main_world(world); // full main world -> assign each spot(index) its value at the begginig
		starting_layer_world(world); // the first page you will see ( a table filled with "?" )
		while (!is_trigged && min_count > 0) // if is_trigged -> you lose if min_count = 0 -> you win
		{
			flag_min_re_count[move_count] = 0;
			for (int j = 0; j < 30; j++)
			{
				for (int i = 0; i < 16; i++)
				{
					cworld[i][j][move_count] = world[i][j][1];
				}
			}
			Game_Name();
			show_flag_min(p_flag_count, p_min_count);
			show_layer_world(world, world_size_j, world_size_i);
			cout << "Please enter your move :";
			char click;
			int spot = 1;
			cin >> click;
			if (click != 'z' && click != 'Z')
				cin >> spot;

			if (spot > 480 || spot < 1)
			{
				gets(trash);
				INVALID;
				WAIT;
				CLEAR;
				continue;
			}
			if (click == 'R' || click == 'r')
			{
				right_click(world, ((spot - 1) / world_size_i), (spot - 1) % world_size_i, p_flag_count, p_min_count);
				move_count++;
			}
			else if (click == 'L' || click == 'l')
			{
				if (move_count == 0 || move_count == 1)
				{
					spot -= 93;
					for (int i = 1; i <= 49; i++)
					{
						if (spot >= 1 && spot <= 480)
						{
							int check = left_click(world, ((spot - 1) / world_size_i), (spot - 1) % world_size_i, world_size_j, world_size_i);
							left_click_rec(world, ((spot - 1) / world_size_i), (spot - 1) % world_size_i, world_size_j, world_size_i, 0);
							if (check == -1)
							{
								world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][1] = world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][0];
								flag_count--;
								min_count--;
								flag_min_re_count[move_count]++;
							}
							else if (check == 1)
							{
								ENTER;
								cout << "you can't open this spot becuase it's already been flaged";
								WAIT;
								CLEAR;
								continue;
							}
							else
							{
								world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][1] = world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][0];
							}
						}
						if (i % 7 == 0)
						{
							spot += 23;
						}
						spot++;
					}
					move_count++;
				}
				else
				{
					int check = left_click(world, ((spot - 1) / world_size_i), (spot - 1) % world_size_i, world_size_j, world_size_i);
					left_click_rec(world, ((spot - 1) / world_size_i), (spot - 1) % world_size_i, world_size_j, world_size_i, 0);
					if (check == -1)
					{
						is_trigged = 1;
						move_count++;
					}
					else if (check == 1)
					{
						ENTER;
						cout << "you can't open this spot becuase it's already been flaged";
						WAIT;
						CLEAR;
						continue;
					}
					else
					{
						world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][1] = world[((spot - 1) / world_size_i)][(spot - 1) % world_size_i][0];
						move_count++;
					}
				}
			}
			else if (click == 'Z' || click == 'z')
			{
				if (move_count > 0)
				{
					move_count--;
					for (int j = 0; j < 30; j++)
					{
						for (int i = 0; i < 16; i++)
						{
							world[i][j][1] = cworld[i][j][move_count];
						}
					}
					for (int i = 0; i < flag_min_re_count[move_count]; i++)
					{
						flag_count++;
						min_count++;
					}
				}
			}
			else
			{
				INVALID;
				WAIT;
				CLEAR;
			}
			CLEAR;
		}
		// the end of a set of game ///////////////////////////////////////////
		show_flag_min(p_flag_count, p_min_count);
		show_layer_world(world, world_size_j, world_size_i);
		if (is_trigged)
		{
			cout << R << "You Lose";
			ENTER;
			cout << C << "Moves:" << move_count;
			ENTER;
			for (int i = 0; i < 7; i++)
				bomb_print();
			ENTER;
		}
		else
		{
			cout << G;
			cout << "you Win";
			ENTER;
			cout << C << "Moves:" << move_count;
			ENTER;
			for (int i = 0; i < 7; i++)
				flag_print();
			ENTER;
		}
	p_again_1:
		Game_Name();
		show_main_world(world, world_size_j, world_size_i);
		ENTER;
		cout << "do you wnat to play again ? (y/n) : ";
		getchar();
		char play_again = getchar();
		if (play_again == 'y')
		{
			gets(trash);
			CLEAR;
			goto menu;
		}
		else if (play_again == 'n')
		{
			return 0;
		}
		else
		{
			INVALID;
			WAIT;
			goto p_again_1;
		}
	}
	else if (!strcmp(command, "2") || !strcmp(command, "rules")) // show the rules of the game
	{
		ENTER;
		ENTER;
		cout << Y;
		cout << "how to play:\n"
			 << "for selecting a spot you should follow the below construction:\n"
			 << "first enter 'R' or 'L' or 'Z' then enter number of spot you want to choose\n"
			 << "entering 'R' will flag the spot {flag will be shown as :" << P << FLAG << Y << "}\n"
			 << "entering 'L' will reveal the spot\n"
			 << "entering 'Z' will reverse last command\n";
		cout << G;
		cout << "Good Luck!\n";
		cout << W;
		cout << STARSPACE;
		system("pause");
		CLEAR;
		goto menu;
	}
	else if (!strcmp(command, "3") || !strcmp(command, "exit")) // end program
	{
		return 0;
	}
	else
	{
		INVALID;
		WAIT;
		CLEAR;
		goto menu;
	}
	STOP;
}