#include<CImg.h>
#include<iostream>

using namespace std;
using namespace cimg_library;
int main() {
	
	
CImg<unsigned char> OriginalImage("obraz.bmp");

	
	CImg<unsigned char> obraz(800, 708, 1);
	obraz.fill(255);
	cimg_for_borderXY(obraz, x, y, 30) obraz(x, y) = 0;
	cimg_for_insideXY(obraz, x, y, 60) obraz(x, y) =200;
	obraz.draw_image(90, 90, OriginalImage);
	obraz.draw_image(410, 90, OriginalImage.mirror('x'));
	obraz.draw_image(90, 364, OriginalImage);
	obraz.draw_image(410, 364, OriginalImage.mirror('x'));
	
	CImgDisplay pokaz(obraz, "obraz", 3);
	while (!pokaz.is_closed()){}
	
	return 0;
}
