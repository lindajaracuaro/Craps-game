// Craps game from the chapter 5.10 of Deitel series
// 5.10 Craps game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

enum Status { WIN, LOSE, CONTINUE };	// Enum-specifier: What posibilities are? for Status

int roll(void);

int main()
{
	enum Status gameStatus;	//Creating the Label 

	int mypoint;
	int score;
	
	srand(time(NULL));	//Two different initializations with the same seed will generate the same succession of results in subsequent calls to rand.

	score = roll();

	switch (score)
	{
	case 7:
	case 11:
		gameStatus = WIN;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOSE;
		break;
	default:
		gameStatus = CONTINUE;
		mypoint = score;
		std::cout << "Your point is : \t" << mypoint << std::endl;
	}

	while (gameStatus == CONTINUE)
	{
		score = roll();	//Tira again

		if (score == mypoint)
			gameStatus = WIN;
	}

	if (gameStatus == WIN)
	{
		std::cout << "You win" << std::endl;
	}
	else
	{
		std::cout << "You lose" << std::endl;
	}

	return 0;
}

int roll(void)
{

	//	srand(time(NULL));	Si lo colocas aquí el resultado se repetirá

	int d1 = 1 + rand() % 6 ;
	int d2 = 1 + rand() % 6 ;

	int TempScore = d1 + d2;

	std::cout << "Your score is \t" << d1 << " + " << d2 << " = " << TempScore << std::endl;
	
	return TempScore;
}
