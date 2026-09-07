#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short RoundNumber;
	enGameChoice Player1Choice, ComputerChoice;
	enWinner RoundWinner;
	string RoundWinnerName;
};

struct stGameResult
{
	short GameRounds = 0, Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	enWinner Winner;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	//function to generate random Number in Range. 
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

string  HorizentalLine(short LenghtOfLine)
{
	string Line = "";
	for (short i = 1; i <= LenghtOfLine; i++)
	{
		Line = Line + '_';
	}
	return Line;
}

string  Tabs(short NumberOfTabs)
{
	string Tab = "";
	for (short i = 1; i <= NumberOfTabs; i++)
	{
		Tab = Tab + "\t";
	}
	return Tab;
}

short ReadHowManyRounds()
{
	short GameRounds = 1;
	do
	{
		cout << "How many rounds you want to play ? ";
		cin >> GameRounds;

	} while (GameRounds < 1 || GameRounds>10);
	return GameRounds;
}

void ResetScreen()
{
	system("cls");
	system("color 0f");
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 0;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?  ";
		cin >> Choice;
		cout << "\n";
	} while (Choice < 1 || Choice>3);
	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F"); // turn screen color green.
		break;
	case enWinner::Computer:
		cout << "\a";
		system("color 4F"); // turn screen color red.
		break;
	case enWinner::Draw:
		system("color 6F"); // turn screen color yellow.
	}
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		SetWinnerScreenColor(enWinner::Draw);
		return enWinner::Draw;
	};
	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
		{
			SetWinnerScreenColor(enWinner::Computer);
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			SetWinnerScreenColor(enWinner::Computer);
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			SetWinnerScreenColor(enWinner::Computer);
			return enWinner::Computer;
		}
	}
	SetWinnerScreenColor(enWinner::Player1);
	return enWinner::Player1;
}

string ChoiceName(enGameChoice Choice)
{
	string arrChoiceName[3] = { "Stone","Paper","Scissor" };
	return arrChoiceName[Choice - 1];
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1","Computer","No Winner" };
	return arrWinnerName[Winner - 1];
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
	cout << HorizentalLine(13) << "Round [" << RoundInfo.RoundNumber << "]" << HorizentalLine(13);
	cout << "\n\n";
	cout << "Player1 Choice  :" << ChoiceName(RoundInfo.Player1Choice);
	cout << "\n";
	cout << "Computer Choice :" << ChoiceName(RoundInfo.ComputerChoice);
	cout << "\n";
	cout << "Round Winner    :" << "[" << RoundInfo.RoundWinnerName << "]";
	cout << "\n\n";
	cout << HorizentalLine(35);
	cout << "\n\n";
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (Player1WinTimes < ComputerWinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

stGameResult FillGameResult(short Player1WinTimes, short ComputerWinTimes, short DrawTimes, short HowManyRounds)
{
	stGameResult GameResult;
	GameResult.ComputerWinTimes = ComputerWinTimes;
	GameResult.DrawTimes = DrawTimes;
	GameResult.GameRounds = HowManyRounds;
	GameResult.Player1WinTimes = Player1WinTimes;
	GameResult.Winner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameResult.WinnerName = WinnerName(GameResult.Winner);
	return GameResult;
}

stGameResult PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins: \n";
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.RoundWinner = WhoWonTheRound(RoundInfo);
		RoundInfo.RoundWinnerName = WinnerName(RoundInfo.RoundWinner);
		if (RoundInfo.RoundWinner == enWinner::Player1)
			Player1WinTimes++;
		else if (RoundInfo.RoundWinner == enWinner::Computer)
			ComputerWinTimes++;
		else
			DrawTimes++;
		PrintRoundResult(RoundInfo);
	}
	return FillGameResult(Player1WinTimes, ComputerWinTimes, DrawTimes, HowManyRounds);
}

void showGameOverScreen()
{
	cout << "\n";
	cout << Tabs(3) << HorizentalLine(40);
	cout << "\n\n";
	cout << Tabs(4) << "+++ G a m e O v e r +++\n";
	cout << Tabs(3) << HorizentalLine(40);
	cout << "\n\n";
}

void ShowFinalGameResults(stGameResult GameResult)
{
	cout << Tabs(3) << HorizentalLine(11) << "[ Game Results ]" << HorizentalLine(13) << "\n\n";
	cout << Tabs(3) << "Game Rounds         :" << GameResult.GameRounds << "\n";
	cout << Tabs(3) << "Player1 Win times   :" << GameResult.Player1WinTimes << "\n";
	cout << Tabs(3) << "Computer win times  :" << GameResult.ComputerWinTimes << "\n";
	cout << Tabs(3) << "Draw times          :" << GameResult.DrawTimes << "\n";
	cout << Tabs(3) << "Final Winner        :" << GameResult.WinnerName << "\n\n";
	cout << Tabs(3) << HorizentalLine(40);
}

void StartGame()
{
	char PlayAgain = 'Y';
	stGameResult GameResult;
	do
	{
		ResetScreen();
		GameResult = PlayGame(ReadHowManyRounds());
		showGameOverScreen();
		ShowFinalGameResults(GameResult);
		cout << "\n\n";
		cout << Tabs(3) << "Do you want to Play again Y / N ? ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}