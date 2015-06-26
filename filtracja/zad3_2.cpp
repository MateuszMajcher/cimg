#include <iostream>
#include "CImg.h"



using namespace cimg_library; 
int main(int argc, char** argv) {
	
CImg<unsigned char> image("c.pgm");
CImg<unsigned char> nowy(image.width(), image.height(), 1);
nowy = image;
CImg<> Mask = CImg<>(5, 5).fill(1, 4, 7, 4, 1,
                                4, 16, 26, 16,4.
                                7,26,41,26,7,
                                4,16,26,16,4,
                                1,4,7,4,1);
							

image.convolve(Mask);

nowy.display();
image.display();
	getchar();

	return 0;
}
