#include <iostream>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	double skal[4][5];
	double org[3][4] =  {  
                          {0, 1, 2, 3} ,   
                          {4, 5, 6, 7} ,   
                          {8, 9, 10, 11}   
                         };
                         
     for ( int i = 0; i < 4; i++ )
      for ( int j = 0; j < 5; j++ )
      {
         skal[i][j] = org[(int)floor(i/1.5)][(int)floor(j/(4/3))];
      }          
	 
	 
	 
	                     
    for ( int i = 0; i < 3; i++ ){
	
      for ( int j = 0; j < 4; j++ )
      {
     
         cout << org[i][j]<<" ";
      } cout<<endl; }    
	  
	      for ( int i = 0; i < 4; i++ ){
      for ( int j = 0; j < 5; j++ )
      {
         
         cout << skal[i][j]<<" ";
      }  cout<<endl; }  
	
	return 0;
}
