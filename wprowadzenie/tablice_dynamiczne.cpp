#include<iostream>

#define kanaly 3
#define kolumny 6
#define wiersze 5

using namespace std;
int main(){

	int * obraz = new int[kanaly*wiersze*kolumny];
	int tab[3] = {0,100,1000};
	int count =0;
      for(int i = 0;i<kanaly;i++){
      	count =0;
		for(int w=0;w<wiersze;w++){
			for(int k = 0;k<kolumny;k++){
			  *(obraz+k+w*kolumny+i*kolumny*wiersze)=count++ + tab[i];
			  
			}
			
		}
	}

	
				
 for(int i = 0;i<kanaly;i++){
   cout<<"kanal - "<<i<<endl;
		for(int w=0;w<wiersze;w++){
			for(int k = 0;k<kolumny;k++){
			 cout<< *(obraz+k+w*kolumny+i*kolumny*wiersze)<<" ";
			  
			}
			cout<<endl;
		}
	}
	
	
	int temp = 0;
 for(int i = 0;i<kanaly;i++){
  
		for(int w=0;w<wiersze;w++){
			for(int k = 0;k<(kolumny/2);k++){
				temp = *(obraz+k+w*kolumny+i*kolumny*wiersze);
				*(obraz+k+w*kolumny+i*kolumny*wiersze)=*(obraz+kolumny - k - 1+w*kolumny+i*kolumny*wiersze);
			    *(obraz+kolumny - k -1 +w*kolumny+i*kolumny*wiersze) = temp;
			    
			  
			}
			
		}
	}	
					
 for(int i = 0;i<kanaly;i++){
   cout<<"kanal - "<<i<<endl;
		for(int w=0;w<wiersze;w++){
			for(int k = 0;k<kolumny;k++){
			 cout<< *(obraz+k+w*kolumny+i*kolumny*wiersze)<<" ";
			  
			}
			cout<<endl;
		}
	}
	 
	return 0;
}
