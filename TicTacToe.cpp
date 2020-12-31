#include <iostream>
#include <vector>

void TicTacToeRender(char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
	std::cout << "\n";
	std::cout << "| " << a << " | " << b << " | " << c << " |\n";
	std::cout << "| " << d << " | " << e << " | " << f << " |\n";
	std::cout << "| " << g << " | " << h << " | " << i << " |\n";
}

bool TicTacToeCheck(char a, char b, char c, char d, char e, char f, char g, char h, char i)
{
	if (a == 'X' && b == 'X' && c == 'X' || \
		d == 'X' && e == 'X' && f == 'X' || \
		g == 'X' && h == 'X' && i == 'X') return true;

	if (a == 'X' && d == 'X' && g == 'X' || \
		b == 'X' && e == 'X' && h == 'X' || \
		c == 'X' && f == 'X' && i == 'X') return true;

	if (a == 'X' && e == 'X' && i == 'X' || \
		c == 'X' && e == 'X' && g == 'X') return true;

	if (a == 'O' && b == 'O' && c == 'O' || \
		d == 'O' && e == 'O' && f == 'O' || \
		g == 'O' && h == 'O' && i == 'O') return true;

	if (a == 'O' && d == 'O' && g == 'O' || \
		b == 'O' && e == 'O' && h == 'O' || \
		c == 'O' && f == 'O' && i == 'O') return true;

	if (a == 'O' && e == 'O' && i == 'O' || \
		c == 'O' && e == 'O' && g == 'O') return true;

	else return false;
}

void TicTacToe()
{
	int filled = 0, num = 0;
	bool pnext = false, won = false;
	std::vector<char> xo = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

	while (filled < 9 && !won)
	{
		TicTacToeRender(xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6], xo[7], xo[8]);

		pnext = false;
		while (!pnext)
		{
			std::cout << "X turn: ";
			std::cin >> num;
			if (xo[num - 1] == ' ') {
				xo[num - 1] = 'X';
				filled++;
				pnext = true;
			}
			else std::cout << "Already filled !!\n";
		}

		TicTacToeRender(xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6], xo[7], xo[8]);
		won = TicTacToeCheck(xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6], xo[7], xo[8]);
		if (won) {
			for (int i = 0; i < xo.size(); i++) {
				if (xo[i] == 'O') xo[i] = ' ';
			}
			break;
		}

		pnext = false;
		while (!pnext)
		{
			std::cout << "O turn: ";
			std::cin >> num;
			if (xo[num - 1] == ' ') {
				xo[num - 1] = 'O';
				filled++;
				pnext = true;
			}
			else std::cout << "Already filled !!\n";
			won = TicTacToeCheck(xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6], xo[7], xo[8]);
			if (won) {
				for (int i = 0; i < xo.size(); i++) {
					if (xo[i] == 'X') xo[i] = ' ';
				}
				break;
			}
		}
	}

	std::cout << "\n\n";
	TicTacToeRender(xo[0], xo[1], xo[2], xo[3], xo[4], xo[5], xo[6], xo[7], xo[8]);
	std::cout << "Game Over.\n\n";
}


int main()
{
	std::cout << "Template:\n";
	std::cout << "| #1 | #2 | #3 |\n";
	std::cout << "| #4 | #5 | #6 |\n";
	std::cout << "| #7 | #8 | #9 |\n";
	TicTacToe();
	system("pause");
}
