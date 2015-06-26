#include <iostream>
#include "CImg.h"


using namespace cimg_library; 
int main(int argc, char** argv) {
CImg<float> image("bb.pgm"), visu(500, 400, 1, 3, 0);



CImg<float> korekcja = image.get_equalize(256);
(image,korekcja).display();


CImgDisplay display(image, "histogram", 1);
const CImg<float> img = image.histogram(256);
const CImg<float> img1 = korekcja.histogram(256);
img.display_graph(0, 3);
img1.display_graph(0, 3);



while (!display.is_closed())
{
}



	return 0;
}
