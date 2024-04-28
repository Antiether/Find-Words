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
