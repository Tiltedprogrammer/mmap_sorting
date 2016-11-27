
#include "comparator.h" 
int comparator(char *first, char *second )
{
    int i = 0;
    int f,s;
    while((first[i] !='\n') && (second[i]!='\n'))
	{
		//CAPITAL letters first
	    f = first[i];
	    s = second[i];
		//if ((f <91) && (s >=96))  <-------CAPITAL and common letters united  
			//{
		//		f+=32;
		//	}
        //if ((f >= 96)&&(s < 91))
		//	{
		//		s+=32;
		//	}
		if (f > s)  return 1;
		else if(f < s) return -1;
			i++;
    }

	if (first[i]=='\0')return -1;
	return 1;
}
