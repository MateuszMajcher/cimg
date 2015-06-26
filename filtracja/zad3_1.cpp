#include <iostream>
#include "CImg.h"

void sort(int tab[]){
	int temp, i, j;
	for (int i = 0; i < 9; i++){
		temp = tab[i];
		for (j = i - 1; j >= 0 && temp < tab[j]; j--){
			tab[j + 1] = tab[j];
		}
		tab[j + 1] = temp;
	}
}

using namespace cimg_library; 
int main(int argc, char** argv) {
	
int tab[9];

	CImg<unsigned char> image("c.pgm");
	CImg<unsigned char> nowy(image.width(), image.height(), 1);

	
	
	for (int y = 1; y < image.width()- 1; y++){
		for (int x = 1; x< image.height() - 1; x++){

	
			tab[0] = image(y - 1, x - 1);
			tab[1] = image(y, x - 1);
			tab[2] = image(y + 1, x - 1);
			tab[3] = image(y - 1, x);
			tab[4] = image(y, x);
			tab[5] = image(y + 1, x);
			tab[6] = image(y - 1, x + 1);
			tab[7] = image(y, x + 1);
			tab[8] = image(y + 1, x + 1);
			//cout << tab[0] << " " << tab[1] << " " << tab[2] << " " << tab[3] << " "<<tab[4]<< tab[5] << " " << tab[6] << " " << tab[7] << " " << tab[8] << endl;
		
	sort(tab);

			
			nowy(y, x) = tab[4];
			//cout << tab[4] << endl;
		}
	}
	image.display();
	nowy.display();


	getchar();

	return 0;
}
