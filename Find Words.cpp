#include <iostream>
#include <cstring>
using namespace std;

//make data be a capital
void kapital (char* str) 
{
    for (int i = 0; str[i] != '\0'; i++) 
	{
        str[i] = toupper(str[i]);
    }
}


bool cek_kata(const char* word) 
{
    char data_matriks[24][24] = {
        "AAFLKHPFSSUFICICLESGNNH",
        "SFVREOMRWLRTTSXOQQNAOAO",
        "QEIAIFXAEIRFVFYSXIMINJI",
        "WSTRLGOCAPBIAFIWIWTUACM",
        "FEYAEAISTPCRLUJKOAKCERS",
        "RVDAKPNDEEHDEMSNCKKFOAH",
        "MRNEDSLCRRIWNRSAAFITMMI",
        "YAAECIEAHYMOTAVHRSSTISB",
        "RJSEWELCCENNIETOHWSGLSE",
        "ATANYYMOIEESNESIOIRELTR",
        "UTENEWEBHMYBETNNRAIEBEN",
        "RCLKUTEAEQJLSGSHTGDSKOA",
        "BHOICATNRRSDDECEHOOLGIT",
        "ENSLUARIRSETALOCOHCTOHE",
        "FZFUDQJYMADOYIWYGLOVESU",
        "TEKALFWONSNAEBMIEJTZNTG",
        "ESWPOSJXEUTUYOZUWAKEZHM",
        "KZUHBPEZEERFLMSNOWBALLH",
        "NSNOWBOARDYTVWYCLEVOHSA",
        "ACOCRQLGZIYCHODRAZZILBI",
        "LBVKKWANZAAQINWOLPWONSL",
        "BFREEZINGRAINSLILGTMELT",
        "HQPYLWHFMNFFUFPSWXNUMMV"
    };


int kataLen = strlen(word);

//mengecek secara vertikal
  for (int i = 0; i <= 24; i++) 
	{
        for (int j = 0; j < 24; j++) 
		{
            bool found = true;
            for (int k = 0; k < kataLen; k++) 
			{
                if (data_matriks[i + k][j] != word[k]) 
				{
                    found = false;
                    break;
                }
            }
            if (found) 
			{
                return true;
            }
        }
    }

 // menegcek secara horizontal
  for (int i = 0; i < 24; i++) 
	{ 
       for (int j = 0; j <= 24 - kataLen; j++) 
	   { 
          bool found = true;
          for (int k = 0; k < kataLen; k++) 
		  { 
               if (data_matriks[i][j + k] != word[k]) 
			   {
                found = false;
                break; 
           }
        }
        if (found) 
		{
            return true; 
           }
       }
    }
return false;
}

// Mengecek Secara Diagonal (kiri atas)
for (int i = 0; i < 24; i++) {
	for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < kataLen; k++) {
                if (data_matriks[i - k][j - k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }

// Mengecek Secara Diagonal (kanan atas)
for (int i = 0; i < 24; i++) {
        for (int j = 0; j <= 24; j++) {
            bool found = true;
            for (int k = 0; k < kataLen; k++) {
                if (data_matriks[i - k][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }
    
// Mengecek Secara Diagonal (kiri bawah)
for (int i = 0; i <= 24; i++) {
        for (int j = 0; j < 24; j++) {
            bool found = true;
            for (int k = 0; k < kataLen; k++) {
                if (data_matriks[i + k][j - k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }
    
// Check diagonally (down-right)
for (int i = 0; i <= 24; i++) {
        for (int j = 0; j <= 24; j++) {
            bool found = true;
            for (int k = 0; k < kataLen; k++) {
                if (data_matriks[i + k][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return true;
            }
        }
    }
    return false;
}

int main();
{
    int banyak_kata;


    cin >> banyak_kata;
    cin.ignore(); 

    char kata[banyak_kata][25]; 

    for (int i = 0; i < banyak_kata; i++) 
	{
        cin.getline(kata[i], 25);
        kapital(kata[i]); 
      
    }

    for (int i = 0; i < banyak_kata; i++) 
	{
        if (cek_kata(kata[i])) {
        	
            cout << "Ada" << endl;
        } else 
		{
            cout << "Tidak Ada" << endl;
        }
        
    }


 return 0;
}
