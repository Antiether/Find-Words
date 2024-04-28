#include <iostream>
#include <cstring>
using namespace std;





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
