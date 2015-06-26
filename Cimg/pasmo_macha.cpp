#include <iostream>
#include "CImg.h"


using namespace cimg_library; 
int main(int argc, char** argv) {
	
 CImg<unsigned char> obraz(800,400,1);
   int g=0;
   
   
   for(unsigned int i=0; i < 800; i+=50){

    for(unsigned int k=i; k<i+50; k++){

       for(unsigned int j=0; j<obraz.height(); j++){
	  
           obraz(k,j) = g;
       }
	} 
	  g+=17;
   }
   
  // obraz.display();
CImgDisplay im_display(obraz,"Gradient",3);
while (!im_display.is_closed())
{}
	return 0;
}
