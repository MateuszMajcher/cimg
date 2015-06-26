#include <iostream>
#define kanaly 3
#define kolumny 6
#define wiersze 5
using namespace std;
int main(int argc, char** argv) {
	int ***obraz = new int**[kanaly];
	for (int i = 0;i< kanaly;i++)
	   obraz[i] = new int*[kolumny];
	   
	for(int i = 0;i<kanaly;i++)
	   for(int j = 0;j<kolumny;j++)
	   obraz[i][j] = new int[wiersze];
	
	
	
	//int obraz[kanaly][wiersze][kolumny];
	int alg[] ={0,100,1000};
	int count;
	
	for(int i=0;i<kanaly;i++){
		count =0;
		     
		    /*wypelnianie liczbami*/
			for(int w=0;w<wiersze;w++){
		            for(int k=0;k<kolumny;k++){
		            	obraz[i][w][k] = count++ + alg[i];
		            	
		            }
		        }	}
		        
		    /*wyswietlanie*/
		    for (int i=0;i<kanaly;i++){
			cout<<"kanal - "<<i<<endl;
			  for(int w=0;w<wiersze;w++){
		            for(int k=0;k<kolumny;k++){
		            	cout<<obraz[i][w][k]<<" ";
		            	
		            }
		            cout<<endl;
		        }
				
			}
			
			int temp=0;
			
			 for (int i=0;i<kanaly;i++){
			cout<<"kanal - "<<i<<endl;
			  for(int w=0;w<wiersze;w++){
		            for(int k=0;k<(kolumny/2);k++){
		           	     temp = obraz[i][w][k];
		           	     obraz[i][w][k] = obraz[i][w][kolumny - k - 1];
		           	     
		           	     obraz[i][w][kolumny - k -1] = temp;
		           	     cout<<obraz[i][w][k]<<" ";
		            	
		            }
		            cout<<endl;
		        }}
		        
		        /*wyswietlanie tablicy*/
			 for (int i=0;i<kanaly;i++){
			cout<<"odbity kanal - "<<i<<endl;
			  for(int w=0;w<wiersze;w++){
		            for(int k=0;k<kolumny;k++){
		           	     
		           	     cout<<obraz[i][w][k]<<" ";
		            	
		            }
		            cout<<endl;
		        }}
			
		        

	return 0;
}
