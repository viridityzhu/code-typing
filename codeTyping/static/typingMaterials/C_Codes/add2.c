#include <iostream> 
#include <stdio.h> 
#include <string> 
#include <sstream> 
#include <string.h> 
// using namespace std; 
// stringstream ss; 
int tointbinary(int num) 
{ 
int counter = 1; 
int ans = 0; 
	while(num!=0) 
	{ 
		ans+=num%2*counter; 
		counter = counter*10; 
		num = num/2; 
	} 
	return ans; 
} 
double todoublebinary(double k) 
{ 
	double ans = 0; 
	double counter = 1.0; 
	while (k!=0) 
	{ 
		//printf("%f\n",k); 
		k = k*2; 
		counter = counter *0.1; 
	if (k>=1) 
	{ 
		k = k-1; 
		ans = ans + counter; 
	} 
	} 
	return ans; 
} 
int tonegintbinary(int z) 
{ 
	z = 0-z; 
	int ans = 11111111 - tointbinary(z); 
	char imptans[10]; 
	sprintf(imptans,"%d",ans); 
	//cout<<"here is "<<imptans<<endl; 
	for (int i=strlen(imptans)-1;i>=0;i--) 
	{ 
		if (imptans[i] == '1') { imptans[i] = '0'; } 
		else if (imptans[i] == '0') { imptans[i] = '1'; break; } 
	} 
	//cout<<"here is "<<imptans<<endl; 
	ss.clear(); 
	ss<<imptans; 
	ss>>ans; 
	return ans; 
} 
double tonegdoublebinary(double z) 
{ 
	double imptz = todoublebinary(0-z); 
	char imptans[10]; 
	sprintf(imptans,"%f",imptz); 
	//cout<<"imptz; "<<imptz<<endl; 
	for (int i=0;i<strlen(imptans);i++) 
	{ 
		if (imptans[i] == '1') 
		{ 
			imptans[i] = '0'; 
		} else if (imptans[i] == '0') { imptans[i] = '1'; } } 
		//cout<<"impt "<<imptans<<endl; 
		//cout<<"here is "<<imptans<<endl; 
		for (int i=strlen(imptans)-1;i>=0;i--) 
		{ 
			if (imptans[i] == '1') { imptans[i] = '0'; } 
			else if (imptans[i] == '0') { imptans[i] = '1'; break; } 
		} //cout<<"here is "<<imptans<<endl; 
		ss.clear(); 
		ss<<imptans; 
		double ans; 
		ss>>ans; 
		return ans; 
	} 
void Reverse(char *s,int n)
{ 
	for(int i=0,j=n-1;i<j;i++,j--)
	{ char c=s[i]; s[i]=s[j]; s[j]=c; } 
} 
int intjinzhizhunahuan(int a) 
{ 
	int counter = 1; int ans = 0; 
	while(a!=0) 
	{ 
		ans = ans + (a%10)*counter; 
		a = a/10; counter = counter*2; 
	} 
	return ans; 
} 
double doublejinzhizhuanhuan(double a) 
{ 
	double counter = 0.5; double ans = 0; 
	while(a-(int)(a)!=0 and a<100000) 
	{ 
		//cout<<a<<endl; 
		a = a*10; 
		ans = ans + ((int)(a)%10)*counter; 
		counter = counter*0.5; 
	} 
	return ans; 
} 
int counterpro(int a,int b) 
{ 
	int mid; 
	if (a<b) { mid = a; a = b; b = mid; } 
	//cout<<"a "<<a<<" b "<<b<<endl; 
	char impta[10]; 
	sprintf(impta,"%d",a); 
	char imptb[10]; 
	sprintf(imptb,"%d",b); 
	int lena = strlen(impta); 
	int lenb = strlen(imptb); 
	//printf("lena %d and lenb %d\n",lena,lenb); 
	int addpos = 0; char strans[10]; int z = 0; 
	for (;z<lenb;z++) 
	{ 
		int imptcheck = (int)(impta[lena-1-z]-'0') + (int)(imptb[lenb-1-z]-'0') + addpos; 
		if (imptcheck == 2) { addpos = 1; strans[z] = '0'; } 
		else if (imptcheck == 1) { addpos = 0; strans[z] = '1'; } 
		else if (imptcheck == 0) { addpos = 0; strans[z] = '0'; } 
	} 
	for (;z<lena;z++) 
	{ 
		int imptcheck = (int)(impta[lena-1-z]-'0') + addpos; 
		if ( imptcheck == 2) { addpos = 1; strans[z] = '0'; } 
		else if (imptcheck == 1) { addpos = 0; strans[z] = '1'; } 
		else if (imptcheck == 0) { addpos = 0; strans[z] = '0'; } 
	} 
	if (addpos==1 && lena<8) 
	{ 
		strans[z] = '1'; 
		strans[z+1] = 0; 
	} 
	else { strans[z] = 0; } 
	Reverse(strans,strlen(strans)); 
	//cout<<strans<<endl; 
	for (int l = 0;l<strlen(strans);l++) 
	{ 
		if (strans[l]!='0' && strans[l]!='1') 
			strans[l] = '1'; 
	} 
	ss.clear(); 
	ss<<strans; 
	int ans; 
	ss>>ans; 
	return ans;

} 
int main() 
{ 
	double a,b; 
	scanf("%lf+%lf",&a,&b); 
	int imptintcountera,imptintcounterb; 
	double imptdoublecountera,imptdoublecounterb; 
	double doubleans; int intans; 
	if ((a-(int)(a))!=0) 
		{ 
			if (a>0) 
			{ 
				imptdoublecountera = todoublebinary(a); 
			} 
			else { imptdoublecountera = tonegdoublebinary(a); } 
			if (b>0) { imptdoublecounterb = todoublebinary(b); } 
			else { imptdoublecounterb = tonegdoublebinary(b); } 
			cout<<imptdoublecountera<<endl<<imptdoublecounterb<<endl; 
			imptdoublecountera = imptdoublecountera*10000; 
			imptdoublecounterb = imptdoublecounterb*10000; 
			doubleans = (double)(counterpro(imptdoublecountera,imptdoublecounterb))/10000.0; 
			//cout<<doubleans<<setw(6)<<setfill('0')<<endl; 
			printf("%.4f\n",doubleans); 
			if (doublejinzhizhuanhuan(doubleans)<=0.5) 
				cout<<doublejinzhizhuanhuan(doubleans)<<endl; 
			else cout<<1-doublejinzhizhuanhuan(doubleans)<<endl; } 
			else 
			{ 
				if (a>0) { imptintcountera = tointbinary(a); } 
				else { imptintcountera = tonegintbinary(a); } 
				if (b>0) { imptintcounterb = tointbinary(b); } 
				else { imptintcounterb = tonegintbinary(b); } 
				cout<<imptintcountera<<endl<<imptintcounterb<<endl; 
				intans = counterpro(imptintcountera,imptintcounterb); 
				//cout<<doubleans<<setw(6)<<setfill('0')<<endl; 
				printf("%d\n",intans); 
				if (intjinzhizhunahuan(intans)>100) 
					cout<<intjinzhizhunahuan(intans)-255<<endl; 
				else cout<<intjinzhizhunahuan(intans); 
			} 
			cout<<doublejinzhizhuanhuan(1.1111)<<endl; 
			//cout<<intjinzhizhunahuan(1101)<<endl; 
			//cout<<counterpro(11001,11011100)<<endl; 
		}