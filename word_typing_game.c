#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h> 
#define ROW 24 // I thought defining row and columns as a macro would be nicer.
#define COL 63

char word[11] = ""; // Initializing the word attached to the bomb.
char filename1[50] = "";
char filename_asked[50] = "";
int a = 8; // a is a variable which indicates the column number of the airscrew of the plane, i used it in a for loop in move_plane() function.
int b = -1; // b is a variable which indicates the column number-1 of the tail of the plane, i used it in a for loop in move_plane() function.
int d = 2; // d is a variable which indicates the row number of the tail of the bomb, i used it in a for loop in move_bomb() function.
int e = 5; // e is a variable which indicates the row number of the head of the bomb, i used it in a for loop in move_bomb() function.
int z = 0; // z is a variable which indicates the elements of the char array word (word[z])
int y = 14; // y is a variable which indicates the column numbers of the elements inside word
int counter = 0; // counter is a variable which counts the movements of plane (increases by 1 after each loop)
int correct = 0; // correct is a counter which counts the correct typings of letters for current word
int mistype = 0; // mistype is a counter which counts the incorrect typings of letters for current word
int score = 0; // score is a variable which holds current score (score += old_score)
int old_score = 0; // old_score is a variable which holds old score (correct-mistype)
int t = 800; // t is a variable which indicates sleep time inside the while loop. It decreases by 50 every 5 word so game gets faster
int len_counter = 3; // len_counter is a counter which counts the current word length. It increases by 1 every 5 word
int bomb_counter = 0; // bomb_counter is a variable for activating the bomb when plane flies through a spesific column
int word_counter = 0; // word_counter is a counter which counts the correct words typed. 
int a_s1 = 0;
int b_s1 = 0;
int d_s1 = 0;
int e_s1 = 0;
int z_s1 = 0;
int y_s1 = 0;
int counter_s1 = 0;
int correct_s1 = 0; //these ..._s1 variables are for saving the game but it doesn't work sadly ;-;
int mistype_s1 = 0;
int score_s1 = 0;
int old_score_s1 = 0;
int t_s1 = 0;
int len_counter_s1 = 0;;
int bomb_counter_s1 = 0;
int word_counter_s1 = 0;

void print_city(); //pre-declaring my functions
void move_plane();
void move_bomb();
void scoreboard();
void game_over();
void main_menu();
void new_game();
void reset();
void new_word();
void main_menu_2();
void save1();
void play1();

char city[ROW][COL] = {
						"(|__.-. |                                            Score:   ", //the general outlook of the game
						"== ===_]+                                                     ",
						"        |                                                     ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						" _____        _____    _________________ ________    _________",
						"|o o o|_______|    |__|               | | # # # |____|o o o o|",
						"|o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|",
						"|o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|",
						"|o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|",
						"|_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___|" };

char city_copy[ROW][COL] = {
						"(|__.-. |                                            Score:   ", //the general outlook of the game
						"== ===_]+                                                     ",
						"        |                                                     ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						" _____        _____    _________________ ________    _________",
						"|o o o|_______|    |__|               | | # # # |____|o o o o|",
						"|o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|",
						"|o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|",
						"|o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|",
						"|_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___|" };

char city_s1[ROW][COL] = {
						"(|__.-. |                                            Score:   ", //i make changes with the original array so i need a copyfor initializing
						"== ===_]+                                                     ",
						"        |                                                     ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						"                                                              ",
						" _____        _____    _________________ ________    _________",
						"|o o o|_______|    |__|               | | # # # |____|o o o o|",
						"|o o o|* * *|: ::|. . |               |o| # # # |. . |o o o o|",
						"|o o o|* * *|::  |. . | []  []  []  []|o| # # # |. . |o o o o|",
						"|o o o|**** |:  :| . .| []  []  []    |o| # # # |. . |o o o o|",
						"|_[]__|__[]_|_||_|__< |____________;;_|_|___[]__|_.|_|__[]___|" };

char gameover[ROW][COL] = {
						"**************************************************************",//game over menu
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                        GAME OVER                           *",
						"*                                                            *",
						"*                  PRESS 'Y' FOR NEW GAME                    *",
						"*                  PRESS 'N' FOR MAIN MENU                   *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"*                                                            *",
						"**************************************************************" };
int main() {
	system("cls");
	main_menu();
	return 0;
}

void new_game() {
	new_word(); //a new word is created 
	while (true) { //while loop so it iterates
		char ch = 0;
		system("cls");
		print_city();
		system("cls");
		while (ch != 27) { //while ch is not "esc", when we press esc it must exit the loop
			while (_kbhit()) { //when a keyboard button is hit _kbhit() returns a non-zero value
				ch = _getch();
				if (ch == word[z]) { //if our typed letter matches with the first element of word go into this
					word[z] = ' '; //make word's first element '_'
					city[e - 1][y] = ' '; //we can see the letters next to the bomb are disappearing one by one
					correct++; //we made a correct typing so increment it by 1
					y++; 
					z++;
				}
				else if (ch != word[z]) { //if our typed letter don't match with the first element of word go into this
					mistype++; //we made a incorrect typing so increment it by 1
				}
				if (word[len_counter - 1] == ' ') { //if the (last element-1)th element of word is '_' it means we typed all letters correctly
					word_counter++; //we correctly typed all the letters so increment it by 1
					new_word(); //create a new word for next iteration
					if (word_counter % 5 == 0 && word_counter < 41) { //make it every 5 words
						t -= 50; //make waiting time 50 less so game gets faster
						len_counter++;
						new_word(); //create a new word for next iteration
					}
					else if (word_counter > 40) { //if we reach 40 words, it means the game will ask us 10 letter words from now on
						new_word(); //create a new word for next iteration
					}
					
					old_score = correct - mistype; //calculation of old_score
					score += old_score; //new score is added to the old_score
					scoreboard(); //show score after doing the calculations
					reset(); //reset
					break;
				}
			}

			if (counter < 20) { 
				move_plane(); //move the plane
				counter++;
			}
			if (counter > 5) {
				if (bomb_counter == 0) { //creates the bomb for first time, then don't go into this if statement
					city[3][12] = '<';
					city[3][13] = '|';
					city[3][14] = '>';
					city[4][13] = '|';
					city[5][13] = '*';
					city[4][14] = word[0];
					city[4][15] = word[1];
					city[4][16] = word[2];
					city[4][17] = word[3];
					city[4][18] = word[4];
					city[4][19] = word[5];
					city[4][20] = word[6];
					city[4][21] = word[7];
					city[4][22] = word[8];
					city[4][23] = word[9];
					bomb_counter++;
				}
				move_bomb(); //move the bomb one tile below
				if (city[19][13] == '*') { //if the head of the bomb reaches the roof of the city the game ends
					game_over(); //go to game over menu
					break;
				}
			}
			print_city();
			Sleep(t); //wait for certain amount of time
			system("cls");
		}
		main_menu_2(); //if "esc" is pressed go to that menu
	}
	system("cls");
	main_menu();
}

void print_city() { //prints the city
	for (int r = 0; r < ROW; r++)
	{
		printf("%s\n", city[r]);
	}
}

void move_plane() { //moves the plane by two tile to the right
	for (int c = a; c > b; c--) {
		for (int r = 0; r < 3; r++) {
			city[r][c + 2] = city[r][c];
			city[r][c] = ' ';
		}
	}
	a += 2;
	b += 2;
}

void move_bomb() { //moves the bomb by one tile to the ground
	for (int r = e; r > d; r--) {
		for (int c = 12; c < 24; c++) {
			city[r + 1][c] = city[r][c];
			city[r][c] = ' ';
		}
	}
	d += 1;
	e += 1;
}

void scoreboard() {
	if (score >= 100) { //score calculations when score is bigger than 100
		city[0][61] = (score % 10) + '0';
		city[0][60] = ((score / 10)) % 10 + '0';
		city[0][59] = (score / 100) + '0';
	}
	else if (score < 100) { //score calculations when score is less than 100
		city[0][61] = (score % 10) + '0';
		city[0][60] = (score / 10) + '0';
		city[0][59] = '0';
	}
}

void game_over() {
	system("cls"); //clears screen
	for (int r = 0; r < ROW; r++)
	{
		printf("%s\n", gameover[r]); //prints the gameover char array 
	}
	char choice = _getch(); //choice is requested from user
	while (choice != 'n' && choice != 'y') {
		printf("You entered invalid value.\n"); //keeps asking the choice until player presses 'y' or 'n'
		choice = _getch();
	}
	if (choice == 'y') {
		reset(); //resets all global variables to their initial values.
		score = 0;
		old_score = 0;
		scoreboard(); //score is shown at the top right corner with initialized to 0
		word_counter = 0;
		len_counter = 3;
		new_game(); //starts a new game
	}
	else if (choice == 'n') {
		main_menu(); //go back to menu
	}
}

void main_menu() //the menu seen when the code is started
{
	system("cls"); //clears screen
	char int_choice = 0;
	printf("MAIN MENU : \n\n");
	printf("1. New Game\n");
	printf("2. Load a Saved Game\n");
	printf("3. Exit\n");

	int_choice = _getch(); //choice is requested from user
	printf("%c", int_choice);

	switch (int_choice)
	{
	case 49:
		system("cls"); //clears screen
		reset(); //resets all global variables to their initial values.
		score = 0;
		old_score = 0;
		len_counter = 3;
		word_counter = 0;
		new_game(); //starts a new game
		break;
	case 50:
		break;
	case 51:
		exit(0);
	default:printf("Wrong choice. Enter Again\n\n");
		break;
	}
}

void main_menu_2() //the menu seen when pressing the "esc" key inside the game
{
	system("cls");
	char int_choice = 0;
	printf("MAIN MENU : \n\n");
	printf("1. New Game\n");
	printf("2. Load a Saved Game\n");
	printf("3. Save Current Game\n");
	printf("4. Return to Game\n");
	printf("5. Exit\n");

	int_choice = _getch(); //choice is requested from user
	printf("%c", int_choice);

	switch (int_choice)
	{
	case 49:
		system("cls"); //clears screen
		reset(); //resets all global variables to their initial values.
		score = 0; 
		old_score = 0;
		len_counter = 3;
		word_counter = 0;
		new_game(); //starts the new game
		break;
	case 50:
		system("cls");
		printf("Enter a filename:\n");
		printf("Current filenames:\n");
		printf("1. %s\n", filename1);
		scanf("%s", &filename_asked);
		while (strcmp(filename1, filename_asked) != 0) { //while there is no such file it compares these two strings
			printf("No such file.\n");
			if (strcmp(filename1,filename_asked) == 0) { //if the strings are equal to each other
				play1();
				scoreboard();
				new_game();
			}
		}
		break;
		
	case 51:
		system("cls");
		printf("Enter a filename\n"); 
		scanf("%s", &filename1); //take a filename from user
		save1();
	case 52:
		break;
	case 53:
		exit(0); //exit code
	default:printf("Wrong choice. Enter Again\n\n"); //keeps asking the choice
		break;
	}
}

void reset() { //reseting all the global values and the char array to their initial values
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			city[i][j] = city_copy[i][j];
		}
	}
	scoreboard();
	a = 8;
	b = -1;
	d = 2;
	e = 5;
	z = 0;
	y = 14;
	counter = 0;
	correct = 0;
	mistype = 0;
	t = 800;
	bomb_counter = 0;
}

void new_word() { //creates a new word using codewords.txt
	srand((unsigned)time(NULL)); //seed for random numbers
	char line[255] = ""; //we will use this array to read lines from codewords.txt
	FILE* fpointer; //FILE pointer
	fpointer = fopen("codewords.txt", "r"); //opens the file for read only
	for (int w = 0; w < (len_counter - 2); w++) { //determines which line will be read from file (ex. for 3 letter words 1st line)
		fgets(line, 255, fpointer);
	}
	char* token = strtok(line, ":"); //strtok function for tokenizing the words seperated with colons
	char word1[11]; //we have ten word for each word length so i created these arrays
	char word2[11];
	char word3[11];
	char word4[11];
	char word5[11];
	char word6[11];
	char word7[11];
	char word8[11];
	char word9[11];
	char word10[11];
	strcpy(word1, token); //copying tokens into these arrays created above
	token = strtok(NULL, ":");
	strcpy(word2, token);
	token = strtok(NULL, ":");
	strcpy(word3, token);
	token = strtok(NULL, ":");
	strcpy(word4, token);
	token = strtok(NULL, ":");
	strcpy(word5, token);
	token = strtok(NULL, ":");
	strcpy(word6, token);
	token = strtok(NULL, ":");
	strcpy(word7, token);
	token = strtok(NULL, ":");
	strcpy(word8, token);
	token = strtok(NULL, ":");
	strcpy(word9, token);
	token = strtok(NULL, ":");
	strcpy(word10, token);
	fclose(fpointer); //closes file
	int random = rand() % 10; //creates random number between 0-9
	switch (random) { //switch case determines which word is going to be chosen
	case 0: strcpy(word, word1); break;
	case 1: strcpy(word, word2); break;
	case 2: strcpy(word, word3); break;
	case 3: strcpy(word, word4); break;
	case 4: strcpy(word, word1); break;
	case 5: strcpy(word, word2); break;
	case 6: strcpy(word, word3); break;
	case 7: strcpy(word, word4); break;
	case 8: strcpy(word, word1); break;
	case 9: strcpy(word, word2); break;
	case 10: strcpy(word, word3); break;
	}
}

void save1() { //this function was supposed to be saving the game
	a_s1 = a;
	b_s1 = b;
	d_s1 = d;
	e_s1 = e;
	z_s1 = z;
	y_s1 = y;
	counter_s1 = counter;
	correct_s1 = correct;
	mistype_s1 = mistype;
	score_s1 = score;
	old_score_s1 = old_score;
	t_s1 = t;
	len_counter_s1 = len_counter;
	bomb_counter_s1 = bomb_counter;
	word_counter_s1 = word_counter;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			city_s1[i][j] = city[i][j];
		}
	}
}
void play1() {//this function was supposed to be playing the saved game
	a = a_s1;
	b = b_s1;
	d = d_s1;
	e = e_s1;
	z = z_s1;
	y = y_s1;
	counter = counter_s1;
	correct = correct_s1;
	mistype = mistype_s1;
	score = score_s1;
	old_score = old_score_s1;
	t = t_s1;
	len_counter = len_counter_s1;
	bomb_counter = bomb_counter_s1;
	word_counter = word_counter_s1;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			city[i][j] = city_s1[i][j];
		}
	}
}