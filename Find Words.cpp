#include <iostream>
#include <cstring>
using namespace std;

//mengubah data menjadi huruf kapital
void kapital (char* str)                                //deklarasi fungsi kapital 
{
    for (int i = 0; str[i] != '\0'; i++)                //loop akan tetap berjalan selama string tidak null
	{
        str[i] = toupper(str[i]);                       //fungsi "toupper" menjadikan huruf menjadi kapital yang disimpan ke str[i]
    }
}


bool cek_kata(const char* word)                          //fungsi yang menerima input berupa string karakter (dalam bentuk pointer ke karakter pertama dari string) dan mengembalikan nilai boolean (benar atau salah)
{
    char data_matriks[24][24] = {                        //tempat menyimpan data matriks
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

    int kataLen = strlen(word);                              //mendeglarasikan penghitungan jumlah panjang karakter string


    // Mengecek secara vertikal
    for (int i = 0; i <= 24; i++)                            //loop ini melalui seiap baris dari array matriks
	{
        for (int j = 0; j < 24; j++)                         //loop ini melalui setiap kolom dan baris dari array matriks
		{
            bool found = true;                                //fungsi found(ketemu) diatur ke true 
            for (int k = 0; k < kataLen; k++)                 //loop ini melalui setiap pada karakter string
			{
                if (data_matriks[i + k][j] != word[k])        //jika karakter tidak ada di data maka diatur ke false dan loop berhenti
				{
                    found = false;
                    break;
                }
            }
            if (found)                                        //jika masih ketemu maka true setelah diperiksanya semua karakter string dan menunjukan string telah ditemukan
			{
                return true;
            }
        }
    }
    
    // mengecek secara horizontal
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
    

    //mengecek secara diagonal (kiri atas)
    for (int i = 0; i < 24; i++) 
	{
        for (int j = 0; j < 24; j++) 
		{
            bool found = true;
            for (int k = 0; k < kataLen; k++) 
			{
                if (data_matriks[i - k][j - k] != word[k]) 
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

    //mengecek secara diagonal (kanan atas)
    for (int i = 0; i < 24; i++) 
	{
        for (int j = 0; j <= 24; j++) 
		{
            bool found = true;
            for (int k = 0; k < kataLen; k++) 
			{
                if (data_matriks[i - k][j + k] != word[k]) 
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
    
    //mengecek secara diagonal (kiri bawah)
    for (int i = 0; i <= 24; i++) 
	{
        for (int j = 0; j < 24; j++) 
		{
            bool found = true;
            for (int k = 0; k < kataLen; k++) 
			{
                if (data_matriks[i + k][j - k] != word[k]) 
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
    
    //mengecek secara diagonal (kanan bawah)
    for (int i = 0; i <= 24; i++) 
	{
        for (int j = 0; j <= 24; j++) 
		{
            bool found = true;
            for (int k = 0; k < kataLen; k++) 
			{
                if (data_matriks[i + k][j + k] != word[k]) 
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

int main() 
{
    int banyak_kata;                                                  //mendeklarasikan variabel bernama banyak_kata


    cin >> banyak_kata;                                               //input banyak_kata
    cin.ignore();                                                     //fungsi mengabaikan satu atau lebih karakter dari aliran input standar

    char kata[banyak_kata][25];                                       // Deklarasi array 2D untuk menyimpan kata
                                                                      // 'banyak_kata' adalah jumlah kata yang ingin dibaca, dan '25' adalah panjang maksimum setiap kata
// Looping Membaca 'banyak_kata' kata dari input
    for (int i = 0; i < banyak_kata; i++) 
	{
        cin.getline(kata[i], 25);                                      // Membaca satu baris input hingga 25 karakter maksimum
        kapital(kata[i]);                                              // Mengubah kata menjadi huruf kapital 
      
    }
//Looping  Memeriksa apakah kata memenuhi kondisi tertentu dengan 'cek_kata'
    for (int i = 0; i < banyak_kata; i++) 
	{
        if (cek_kata(kata[i])) {                                        // Jika kata memenuhi kondisi
        	
            cout << "Ada" << endl;                                      // Output jika kata tersebut valid
        } else 
		{
            cout << "Tidak Ada" << endl;                                // Output jika kata tersebut tidak valid
        }
        
    }


 return 0;                                                              // Mengembalikan nilai dari main untuk menunjukkan eksekusi sukses
}
