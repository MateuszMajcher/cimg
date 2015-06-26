#include <iostream>
using namespace std;
int main() {
	
 
	int obraz[8][8] = { { 100, 100, 100, 100, 100, 100, 100, 100 },
	                    { 100, 100, 50, 100, 100, 100, 100, 100 },
						{ 100, 100, 100, 100, 100, 100, 100, 100 },
						{ 100, 100, 100, 100, 100, 100, 100, 100 },
						{ 200, 200, 200, 200, 50, 100, 100, 100 },
						{ 100, 200, 200, 50, 100, 100, 100, 100 },
						{ 100, 100, 100, 100, 100, 100, 100, 100 },
						{ 100, 100, 100, 100, 100, 100, 100, 100 }};
	int nowy[7][7];

	int maska[3][3] = { {1,1,1},
	                    {1,1,1},
						{1,1,1} };
	int temp = 0;

	for (int i = 1; i < 8; i++){
		for (int j = 1; j < 8; j++){
			cout << obraz[i][j] << " ";
		}
		cout << endl;
	}


	/*oblicznie nowej wartosci */
	for (int i = 1; i < 7; i++){
		for (int j = 1; j < 7; j++){
			
                nowy[i][j] =  obraz[i - 1][j - 1] * maska[0][0] + obraz[i - 1][j] * maska[0][1] + obraz[i - 1][j + 1] * maska[0][2] +
				obraz[i][j - 1] * maska[1][0] + obraz[i][j] * maska[1][1] + obraz[i][j + 1] * maska[1][2] +
				obraz[i + 1][j - 1] * maska[2][0] + obraz[i + 1][j] * maska[2][1] + obraz[i + 1][j + 1] * maska[2][2];
			     
		}
		cout << endl;
	}

	/*wyswietleie po nalozeniu maski*/
	for (int i = 1; i < 7; i++){
		for (int j = 1; j < 7; j++){
			cout << nowy[i][j] << " ";
          }
		cout << endl;
	}
	return 0;
}
