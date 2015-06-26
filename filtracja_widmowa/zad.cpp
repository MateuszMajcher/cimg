#include <iostream>
#include "CImg.h"


using namespace cimg_library; 
int main(int argc, char** argv) {
CImg<unsigned char> obraz1 = CImg<unsigned char>("filtracja.pgm").resize(256, 256);

// Obliczenie FFT (dwie macierze, bo FFT jest zespolona)
CImgList<> widmoFFT = obraz1.get_FFT();

// Wyœrodkowanie widma Fouriera
widmoFFT[0].
shift(obraz1.width() / 2, obraz1.height() / 2, 0, 0, 2);
widmoFFT[1].
shift(obraz1.width() / 2, obraz1.height() / 2, 0, 0, 2);

// Widmo amplitudowe (tylko dla prezentacji w oknie)
CImg<unsigned char> widmoAmpl =
((widmoFFT[0].get_pow(2) + widmoFFT[1].get_pow(2)).
sqrt() + 1.0f).log().normalize(0, 255);


// Utworzenie maski filtrowanie fouriera
CImg<unsigned char>
maska(obraz1.width(), obraz1.height(), 1, 1, 1);
unsigned char one[] = {1 }, zero[] = { 0 }, white[] = { 255 };
int rmin = 25, rmax = 40;
maska.fill(0).
draw_circle(widmoAmpl.width() / 2, widmoAmpl.height() / 2, rmax, one).
draw_circle(widmoAmpl.width() / 2, widmoAmpl.height() / 2, rmin, zero);


//je¿eli obraz ma byæ przefiltrowany dolnoprzepustowo, nale¿y usun¹æ z 
//F-obrazu wszystkie punkty znajduj¹ce siê w zadanej odleg³oœci od œrodka widma.
//W rezultacie po odtworzeniu obrazu odwrotn¹ transformacj¹ Fouriera,
//otrzymuje siê obraz rozmyty. Usuwanym punktom przypisywana jest wartoœæ 0

//maska dla filtrowania dolnoprzepustowej
rmin = 25, rmax = 256;
CImg<unsigned char>maska_dolna(obraz1.width(), obraz1.height(), 1, 1, 1);
maska_dolna.fill(0).
draw_circle(obraz1.width() / 2, widmoAmpl.height() / 2, rmax, zero).draw_circle(widmoAmpl.width() / 2, widmoAmpl.height() / 2, rmin, one);

CImg<unsigned char>maska_gorna(obraz1.width(), obraz1.height(), 1, 1, 1);
maska_gorna.fill(0).
draw_circle(widmoAmpl.width() / 2, widmoAmpl.height() / 2, rmax, one).draw_circle(widmoAmpl.width() / 2, widmoAmpl.height() / 2, rmin, zero);

// Nowe widmo amplitudowe (tylko dla prezentacji w oknie)
CImg<unsigned char> noweWidmoAmpl(widmoAmpl);
noweWidmoAmpl.mul(maska);


CImg<unsigned char> noweWidmoAmplDolne(widmoAmpl);
noweWidmoAmplDolne.mul(maska_dolna);


CImg<unsigned char> noweWidmoAmplGorne(widmoAmpl);
noweWidmoAmplGorne.mul(maska_gorna);


// Filtracja  fouriera
CImgList<> noweWidmoFFT(widmoFFT);
noweWidmoFFT[0].mul(maska).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);
noweWidmoFFT[1].mul(maska).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);

CImg<unsigned char> filtrowany(obraz1);
filtrowany = noweWidmoFFT.FFT(true)[0].normalize(0, 255);
CImgList<unsigned char> okno(obraz1,
	widmoAmpl,
	maska.normalize(0, 255),
	noweWidmoAmpl,
	filtrowany);

CImgDisplay disp(okno, "Filtracja Fouriera");


//filtracja dolnoprzepustowa


CImgList<> noweWidmoFFT_dolno(widmoFFT);
noweWidmoFFT_dolno[0].mul(maska_dolna).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);
noweWidmoFFT_dolno[1].mul(maska_dolna).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);

CImg<unsigned char> filtrowany_dolno(obraz1);
filtrowany_dolno = noweWidmoFFT_dolno.FFT(true)[0].normalize(0, 255);
CImgList<unsigned char> okno_dolno(obraz1,
	widmoAmpl,
	maska_dolna.normalize(0, 255),
	noweWidmoAmplDolne,
	filtrowany_dolno);

CImgDisplay disp_dolno(okno_dolno, "Filtracja dolno");



//filtracja gornoprzepustowa


CImgList<> noweWidmoFFT_gorna(widmoFFT);
noweWidmoFFT_gorna[0].mul(maska_gorna).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);
noweWidmoFFT_gorna[1].mul(maska_gorna).
shift(-obraz1.width() / 2, -obraz1.height() / 2, 0, 0, 2);

CImg<unsigned char> filtrowany_gorna(obraz1);
filtrowany_gorna = noweWidmoFFT_gorna.FFT(true)[0].normalize(0, 255);
CImgList<unsigned char> okno_gorna(obraz1,
	widmoAmpl,
	maska_dolna.normalize(0, 255),
	noweWidmoAmplGorne,
	filtrowany_gorna);

CImgDisplay disp_gorna(okno_gorna, "Filtracja gorno");
	getchar();

	return 0;
}
