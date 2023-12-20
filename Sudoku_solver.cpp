// Mateusz Pawlowski 2023. Program that solves Sudoku.
#include <iostream>
#include <time.h>
#include <list>
#include <stdlib.h>

/*
int table[9][9] = { {5,3,0,0,7,0,0,0,0},
						{6,0,0,1,9,5,0,0,0},
						{0,9,8,0,0,0,0,6,0},
						{8,0,0,0,6,0,0,0,3},
						{4,0,0,8,0,3,0,0,1},
						{7,0,0,0,2,0,0,0,6},
						{0,6,0,0,0,0,2,8,0},
						{0,0,0,4,1,9,0,0,5},
						{0,0,0,0,8,0,0,7,9}
};

int tableorg[9][9] = { {5,3,0,0,7,0,0,0,0},
						{6,0,0,1,9,5,0,0,0},
						{0,9,8,0,0,0,0,6,0},
						{8,0,0,0,6,0,0,0,3},
						{4,0,0,8,0,3,0,0,1},
						{7,0,0,0,2,0,0,0,6},
						{0,6,0,0,0,0,2,8,0},
						{0,0,0,4,1,9,0,0,5},
						{0,0,0,0,8,0,0,7,9}
};
*/

/*
int table[9][9] = {		{4,5,0,0,0,0,0,0,0},
						{0,0,2,0,7,0,6,3,0},
						{0,0,0,0,0,0,0,2,8},
						{0,0,0,9,5,0,0,0,0},
						{0,8,6,0,0,0,2,0,0},
						{0,2,0,6,0,0,7,5,0},
						{0,0,0,0,0,0,4,7,6},
						{0,7,0,0,4,5,0,0,0},
						{0,0,8,0,0,9,0,0,0}
};

int tableorg[9][9] = { {4,5,0,0,0,0,0,0,0},
						{0,0,2,0,7,0,6,3,0},
						{0,0,0,0,0,0,0,2,8},
						{0,0,0,9,5,0,0,0,0},
						{0,8,6,0,0,0,2,0,0},
						{0,2,0,6,0,0,7,5,0},
						{0,0,0,0,0,0,4,7,6},
						{0,7,0,0,4,5,0,0,0},
						{0,0,8,0,0,9,0,0,0}
};
*/

int table[9][9] = {		{2,0,9,0,0,0,6,0,0},
						{0,4,0,8,7,0,0,1,2},
						{8,0,0,0,1,9,0,4,0},
						{0,3,0,7,0,0,8,0,1},
						{0,6,5,0,0,8,0,3,0},
						{1,0,0,0,3,0,0,0,7},
						{0,0,0,6,5,0,7,0,9},
						{6,0,4,0,0,0,0,2,0},
						{0,8,0,3,0,1,4,5,0}
};

int tableorg[9][9] = { {2,0,9,0,0,0,6,0,0},
						{0,4,0,8,7,0,0,1,2},
						{8,0,0,0,1,9,0,4,0},
						{0,3,0,7,0,0,8,0,1},
						{0,6,5,0,0,8,0,3,0},
						{1,0,0,0,3,0,0,0,7},
						{0,0,0,6,5,0,7,0,9},
						{6,0,4,0,0,0,0,2,0},
						{0,8,0,3,0,1,4,5,0}
};

int x, y;
int r;

int l = 0;

int draw_board()
{
	int x, y;
	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			printf("%d ", table[y][x]);
		}
		printf("\n");
	}
	return 0;
}



bool sprawdz_wiersz()
{
	for (int a = 0; a < 9; a++)
	{
		if (table[y][a] == r) { return true; }
	}
	return false;
}

bool sprawdz_kolumne()
{
	for (int a = 0; a < 9; a++)
	{
		if (table[a][x] == r) { return true; }
	}
	return false;
}

bool k1()
{
	if (table[0][0] == r) { return true; }
	if (table[0][1] == r) { return true; }
	if (table[0][2] == r) { return true; }

	if (table[1][0] == r) { return true; }
	if (table[1][1] == r) { return true; }
	if (table[1][2] == r) { return true; }

	if (table[2][0] == r) { return true; }
	if (table[2][1] == r) { return true; }
	if (table[2][2] == r) { return true; }
	return false;
}

bool k2()
{
	if (table[0][3] == r) { return true; }
	if (table[0][4] == r) { return true; }
	if (table[0][5] == r) { return true; }

	if (table[1][3] == r) { return true; }
	if (table[1][4] == r) { return true; }
	if (table[1][5] == r) { return true; }

	if (table[2][3] == r) { return true; }
	if (table[2][4] == r) { return true; }
	if (table[2][5] == r) { return true; }
	return false;
}

bool k3()
{
	if (table[0][6] == r) { return true; }
	if (table[0][7] == r) { return true; }
	if (table[0][8] == r) { return true; }

	if (table[1][6] == r) { return true; }
	if (table[1][7] == r) { return true; }
	if (table[1][8] == r) { return true; }

	if (table[2][6] == r) { return true; }
	if (table[2][7] == r) { return true; }
	if (table[2][8] == r) { return true; }
	return false;
}

bool k4()
{
	if (table[3][0] == r) { return true; }
	if (table[3][1] == r) { return true; }
	if (table[3][2] == r) { return true; }

	if (table[4][0] == r) { return true; }
	if (table[4][1] == r) { return true; }
	if (table[4][2] == r) { return true; }

	if (table[5][0] == r) { return true; }
	if (table[5][1] == r) { return true; }
	if (table[5][2] == r) { return true; }
	return false;
}

bool k5()
{
	if (table[3][3] == r) { return true; }
	if (table[3][4] == r) { return true; }
	if (table[3][5] == r) { return true; }

	if (table[4][3] == r) { return true; }
	if (table[4][4] == r) { return true; }
	if (table[4][5] == r) { return true; }

	if (table[5][3] == r) { return true; }
	if (table[5][4] == r) { return true; }
	if (table[5][5] == r) { return true; }
	return false;
}

bool k6()
{
	if (table[3][6] == r) { return true; }
	if (table[3][7] == r) { return true; }
	if (table[3][8] == r) { return true; }

	if (table[4][6] == r) { return true; }
	if (table[4][7] == r) { return true; }
	if (table[4][8] == r) { return true; }

	if (table[5][6] == r) { return true; }
	if (table[5][7] == r) { return true; }
	if (table[5][8] == r) { return true; }
	return false;
}

bool k7()
{
	if (table[6][0] == r) { return true; }
	if (table[6][1] == r) { return true; }
	if (table[6][2] == r) { return true; }

	if (table[7][0] == r) { return true; }
	if (table[7][1] == r) { return true; }
	if (table[7][2] == r) { return true; }

	if (table[8][0] == r) { return true; }
	if (table[8][1] == r) { return true; }
	if (table[8][2] == r) { return true; }
	return false;
}

bool k8()
{
	if (table[6][3] == r) { return true; }
	if (table[6][4] == r) { return true; }
	if (table[6][5] == r) { return true; }

	if (table[7][3] == r) { return true; }
	if (table[7][4] == r) { return true; }
	if (table[7][5] == r) { return true; }

	if (table[8][3] == r) { return true; }
	if (table[8][4] == r) { return true; }
	if (table[8][5] == r) { return true; }
	return false;
}

bool k9()
{
	if (table[6][6] == r) { return true; }
	if (table[6][7] == r) { return true; }
	if (table[6][8] == r) { return true; }

	if (table[7][6] == r) { return true; }
	if (table[7][7] == r) { return true; }
	if (table[7][8] == r) { return true; }

	if (table[8][6] == r) { return true; }
	if (table[8][7] == r) { return true; }
	if (table[8][8] == r) { return true; }
	return false;
}

bool sprawdz_kwadrat()
{
	bool sprawdz = false;

	if (x >= 0 && x < 3 && y >= 0 && y < 3) { sprawdz = k1(); }
	if (x >= 3 && x < 6 && y >= 0 && y < 3) { sprawdz = k2(); }
	if (x >= 6 && x < 9 && y >= 0 && y < 3) { sprawdz = k3(); }

	if (x >= 0 && x < 3 && y >= 3 && y < 6) { sprawdz = k4(); }
	if (x >= 3 && x < 6 && y >= 3 && y < 6) { sprawdz = k5(); }
	if (x >= 6 && x < 9 && y >= 3 && y < 6) { sprawdz = k6(); }

	if (x >= 0 && x < 3 && y >= 6 && y < 9) { sprawdz = k7(); }
	if (x >= 3 && x < 6 && y >= 6 && y < 9) { sprawdz = k8(); }
	if (x >= 6 && x < 9 && y >= 6 && y < 9) { sprawdz = k9(); }

	return sprawdz;
}

int zeruj()
{

	printf("zeruj");

	for (y = 0; y < 9; y++)
	{
		for (x = 0; x < 9; x++)
		{
			//table[y][x] = 0;
			table[y][x] = tableorg[y][x];
			//if (x == 8) { table[y][x] = 123; }
		}
	}



	x = 0; y = 0;
	return false;
}

bool check_zeros() 
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (table[y][x] == 0) { return true; }
		}
	}
	return false;
}

int main()
{
	srand(time(NULL));
	printf("Mateusz Pawlowski 2023. Program that solves Sudoku.\n");
	

	std::list<int> lA;
	std::list<int> lB;
	std::list<int> lC;
	std::list<int> lD;

	r = rand() % 9 + 1;

	draw_board();

	for (y = 0; y < 9; y++)
	{
		srand(time(NULL));
		
		for (x = 0; x < 9; x++)
		{

			if (table[y][x] == 0)
			{

			lA.clear();
			lB.clear();
			lC.clear();
			lD.clear();
			lD = { 1,2,3,4,5,6,7,8,9 };

			for (int q = 0; q < 9; q++)
			{
				if (table[y][q] != 0)
				{
					//printf("%d", lA[q]);
					//printf("%d", table[y][q]);

					lA.push_back(table[y][q]);

				}
			}
			
			for (int q = 0; q < 9; q++)
			{
				if (table[q][x] != 0)
				{
					//printf("%d", table[q][x]);
					lB.push_back(table[q][x]);
				}
			}
			
			if (x >= 0 && x < 3 && y >= 0 && y < 3)
			{
				if (table[0][0] != 0) { lC.push_back(table[0][0]); }
				if (table[0][1] != 0) { lC.push_back(table[0][1]); }
				if (table[0][2] != 0) { lC.push_back(table[0][2]); }

				if (table[1][0] != 0) { lC.push_back(table[1][0]); }
				if (table[1][1] != 0) { lC.push_back(table[1][1]); }
				if (table[1][2] != 0) { lC.push_back(table[1][2]); }

				if (table[2][0] != 0) { lC.push_back(table[2][0]); }
				if (table[2][1] != 0) { lC.push_back(table[2][1]); }
				if (table[2][2] != 0) { lC.push_back(table[2][2]); }
			}

			if (x >= 3 && x < 6 && y >= 0 && y < 3)
			{
				if (table[0][3] != 0) { lC.push_back(table[0][3]); }
				if (table[0][4] != 0) { lC.push_back(table[0][4]); }
				if (table[0][5] != 0) { lC.push_back(table[0][5]); }

				if (table[1][3] != 0) { lC.push_back(table[1][3]); }
				if (table[1][4] != 0) { lC.push_back(table[1][4]); }
				if (table[1][5] != 0) { lC.push_back(table[1][5]); }

				if (table[2][3] != 0) { lC.push_back(table[2][3]); }
				if (table[2][4] != 0) { lC.push_back(table[2][4]); }
				if (table[2][5] != 0) { lC.push_back(table[2][5]); }
			}

			if (x >= 6 && x < 9 && y >= 0 && y < 3)
			{
				if (table[0][6] != 0) { lC.push_back(table[0][6]); }
				if (table[0][7] != 0) { lC.push_back(table[0][7]); }
				if (table[0][8] != 0) { lC.push_back(table[0][8]); }

				if (table[1][6] != 0) { lC.push_back(table[1][6]); }
				if (table[1][7] != 0) { lC.push_back(table[1][7]); }
				if (table[1][8] != 0) { lC.push_back(table[1][8]); }

				if (table[2][6] != 0) { lC.push_back(table[2][6]); }
				if (table[2][7] != 0) { lC.push_back(table[2][7]); }
				if (table[2][8] != 0) { lC.push_back(table[2][8]); }
			}

			if (x >= 0 && x < 3 && y >= 3 && y < 6)
			{
				if (table[3][0] != 0) { lC.push_back(table[3][0]); }
				if (table[3][1] != 0) { lC.push_back(table[3][1]); }
				if (table[3][2] != 0) { lC.push_back(table[3][2]); }

				if (table[4][0] != 0) { lC.push_back(table[4][0]); }
				if (table[4][1] != 0) { lC.push_back(table[4][1]); }
				if (table[4][2] != 0) { lC.push_back(table[4][2]); }

				if (table[5][0] != 0) { lC.push_back(table[5][0]); }
				if (table[5][1] != 0) { lC.push_back(table[5][1]); }
				if (table[5][2] != 0) { lC.push_back(table[5][2]); }
			}

			if (x >= 3 && x < 6 && y >= 3 && y < 6)
			{
				if (table[3][3] != 0) { lC.push_back(table[3][3]); }
				if (table[3][4] != 0) { lC.push_back(table[3][4]); }
				if (table[3][5] != 0) { lC.push_back(table[3][5]); }

				if (table[4][3] != 0) { lC.push_back(table[4][3]); }
				if (table[4][4] != 0) { lC.push_back(table[4][4]); }
				if (table[4][5] != 0) { lC.push_back(table[4][5]); }

				if (table[5][3] != 0) { lC.push_back(table[5][3]); }
				if (table[5][4] != 0) { lC.push_back(table[5][4]); }
				if (table[5][5] != 0) { lC.push_back(table[5][5]); }
			}

			if (x >= 6 && x < 9 && y >= 3 && y < 6)
			{
				if (table[3][6] != 0) { lC.push_back(table[3][6]); }
				if (table[3][7] != 0) { lC.push_back(table[3][7]); }
				if (table[3][8] != 0) { lC.push_back(table[3][8]); }

				if (table[4][6] != 0) { lC.push_back(table[4][6]); }
				if (table[4][7] != 0) { lC.push_back(table[4][7]); }
				if (table[4][8] != 0) { lC.push_back(table[4][8]); }

				if (table[5][6] != 0) { lC.push_back(table[5][6]); }
				if (table[5][7] != 0) { lC.push_back(table[5][7]); }
				if (table[5][8] != 0) { lC.push_back(table[5][8]); }
			}

			if (x >= 0 && x < 3 && y >= 6 && y < 9)
			{
				if (table[6][0] != 0) { lC.push_back(table[6][0]); }
				if (table[6][1] != 0) { lC.push_back(table[6][1]); }
				if (table[6][2] != 0) { lC.push_back(table[6][2]); }

				if (table[7][0] != 0) { lC.push_back(table[7][0]); }
				if (table[7][1] != 0) { lC.push_back(table[7][1]); }
				if (table[7][2] != 0) { lC.push_back(table[7][2]); }

				if (table[8][0] != 0) { lC.push_back(table[8][0]); }
				if (table[8][1] != 0) { lC.push_back(table[8][1]); }
				if (table[8][2] != 0) { lC.push_back(table[8][2]); }
			}

			if (x >= 3 && x < 6 && y >= 6 && y < 9)
			{
				if (table[6][3] != 0) { lC.push_back(table[6][3]); }
				if (table[6][4] != 0) { lC.push_back(table[6][4]); }
				if (table[6][5] != 0) { lC.push_back(table[6][5]); }

				if (table[7][3] != 0) { lC.push_back(table[7][3]); }
				if (table[7][4] != 0) { lC.push_back(table[7][4]); }
				if (table[7][5] != 0) { lC.push_back(table[7][5]); }

				if (table[8][3] != 0) { lC.push_back(table[8][3]); }
				if (table[8][4] != 0) { lC.push_back(table[8][4]); }
				if (table[8][5] != 0) { lC.push_back(table[8][5]); }
			}

			if (x >= 6 && x < 9 && y >= 6 && y < 9)
			{
				if (table[6][6] != 0) { lC.push_back(table[6][6]); }
				if (table[6][7] != 0) { lC.push_back(table[6][7]); }
				if (table[6][8] != 0) { lC.push_back(table[6][8]); }

				if (table[7][6] != 0) { lC.push_back(table[7][6]); }
				if (table[7][7] != 0) { lC.push_back(table[7][7]); }
				if (table[7][8] != 0) { lC.push_back(table[7][8]); }

				if (table[8][6] != 0) { lC.push_back(table[8][6]); }
				if (table[8][7] != 0) { lC.push_back(table[8][7]); }
				if (table[8][8] != 0) { lC.push_back(table[8][8]); }
			}

			/*
			printf("\n");
					   
			for (int w : lA) { printf("%d", w); }
			printf("\n");


			for (int w : lB) { printf("%d", w); }
			printf("\n");


			for (int w : lC) { printf("%d", w); }
			printf("\n");
			*/


			lA.sort();
			lB.sort();
			lC.sort();

			lA.merge(lB);
			lA.unique();
			lA.merge(lC);
			lA.unique();

			/*
			for (int w : lA) { printf("%d", w); }
			printf("\n");
			*/

			for (int w : lA)
			{
				lD.remove(w);
			}

			
			/*
			printf("x= %d ",x);
			printf("y= %d", y);
			printf("\n");
						

			for (int w : lD) { printf("%d", w); }
			printf("\n");
			*/
						
			for (int w : lD)
			{
				r = w;				
			}

			if (lD.size() == 1)
			{
				table[y][x] = r;
			}
			
				bool t = true;
				
			}

			if (x == 8 && y == 8)
			{
				x = 0; y = 0;
				if (check_zeros() == false) 
				{
					printf("\n");
					draw_board();
					return 0;
				};
			}
		}
	}
	return 0;
}