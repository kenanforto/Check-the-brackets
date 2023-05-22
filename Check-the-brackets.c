#include <stdio.h>
int provjeri_zagrade(char *s)
{
	int sz=2,vz=2,mz=2;
	char *srednja=s;
	char *velika=s;
	char *mala=s;
	while(*s!='\0')
	{
		if(*s=='}')
		{
			if(vz==2)//SLUCAJ KADA JE VELIKA ZAGRADA ZATVORENA A NIJE OTVORENA
			return 0;
			else if(vz==1)//SLUCAJ KADA JE VELIKA ZAGRADA OTVORENA
			{
				if(sz==1 && (srednja-velika)>0)//UKOLIKO SE SREDNJA ZAGRADA NALAZI UNUTAR VELIKE A NIJE ZATVORENA PRIJE NEGO STO SE ZATVORILA VELIKA
				{
				sz=2;
				}
				else if(mz== 1 && (mala-velika)>0) //UKOLIKO SE MALA ZAGRADA NALAZI UNUTAR VELIKE A NIJE ZATVORENA PRIJE NEGO STO JE VELIKA ZAGRADA ZATVORENA
				{
				mz=2;
				}
				vz=2;
			}
		}
		else if(*s==']')
		{
			if(sz==2)//SLUCAJ KADA JE SREDNAJ ZAGRADA ZATVORENA A NIJE OTVORENA
			return 0;
			else if(sz==1)//SLUCAJ KADA JE SREDNJA ZAGRADA BILA OTVORENA
			{

				if(mz==1 && (mala-srednja)>0)
				mz=2;
				if(vz==1 && (velika-srednja)>0)
				return 0;
				else
				sz=2;
			}
		}
		else if(*s==')')
		{
			if(mz==2)
			return 0;
			else if(mz==1)
			{
				if(vz==1 && (velika-mala)>0)
				return 0;
				else if(sz==1 && (srednja-mala)>0)
				return 0;
				else
				mz=2;
			}
		}

		if(*s=='[')
		{
			if(mz==1)//AKO JE PRIJE BILA OTVORENA MALA A NIJE SMJELA BITI
			return 0;
			srednja=s;
			sz=1;
		}
		else if(*s=='{')
		{
			if(sz==1)//AKO JE BILA OTVORENA SREDNJA ZAGRADA
			return 0;
			if(mz==1)//AKO JE BILA OTVORENA MALA ZAGRADA
			return 0;
			velika=s;
			vz=1;
		}
		else if(*s=='(')
		{
			mala=s;//POKAZIVAC NA MJESTO OTVORENE MALE ZAGRADE
			mz=1;//1-OZNACAVA OTVORENU ZAGRADU , 2-OZNACAVA ZAGRADU KOJA NIJE BILA OTVORENA
		}
		s++;
	}
	if(sz==1 || vz==1 || mz==1)
	return 0;
	else
	return 1;
}

int main() {
	char string[1000]="Primjer {[( zadatka sa za]gradama)]}";
	char string1[1000]="primjer { s} [ s{ fff}  s]";
	char string2[1000]="pocetak (u velik(oj za)gradi...) asdf";
	printf("%d ",provjeri_zagrade(string));
	printf("%d ",provjeri_zagrade(string1));
	printf("%d",provjeri_zagrade(string2));
	return 0;
}
