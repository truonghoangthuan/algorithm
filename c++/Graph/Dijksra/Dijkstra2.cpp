#include<iostream>

#include<conio.h>

using namespace std;

#define MAX 50

#define TRUE 1

#define FALSE  0

#define VOCUNG 10000000

int n, s, t;

char chon;

int truoc[MAX];//m?ng dánh d?u du?ng di.

int d[MAX];//m?ng dánh d?u kho?ng cách.

int Matrix[MAX][MAX];//ma tr?n tr?ng s?

int chuaxet[MAX];//m?ng dánh d?u d?nh dã du?c gán nhãn.


void Init(void){
	freopen("cau01.inp","r", stdin);
	
	cin >> n;
	cout<<"So do thi: "<< n <<endl;
	cin >> s >> t;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Matrix[i][j];
			if (Matrix[i][j] == 0) Matrix[i][j] = VOCUNG;
		}
	}
}


void Result(void){

 cout<<"Duong di ngan nhat tu "<<(char)(s+'A'-1)<<" den "<<(char)(t + 'A' -1)<< " la"<<endl;

 cout<<(char)(t + 'A' - 1)<<"<=";//in d?nh cu?i du?i d?ng char.

 int i = truoc[t];

 while (i != s){

  cout<<(char)(i +'A' -1)<<"<=";//in ra k?t qu? du?i d?ng char.

  i = truoc[i];

 }

 cout<<(char)(s+'A' -1);//in d?nh d?u du?i d?ng char.

 cout<<endl<<"Do dai duong di la : "<< d[t];

}

void Dijkstra(void){

 int u, minp;

 //kh?i t?o nhãn t?m th?i cho các d?nh.

 for (int v = 1; v <= n; v++){

  d[v] = Matrix[s][v];

  truoc[v] = s;

  chuaxet[v] = FALSE;

 }

 truoc[s] = 0;

 d[s] = 0;

 chuaxet[s] = TRUE;

 //buoc l?p

 while (!chuaxet[t]) {

  minp = VOCUNG;

  //tìm d?nh u sao cho d[u] là nh? nh?t

  for (int v = 1; v <= n; v++){

   if ((!chuaxet[v]) && (minp > d[v])){

    u = v;

    minp = d[v];

   }

  }

  chuaxet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat

  if (!chuaxet[t]){

   //gán nhãn l?i cho các d?nh.

   for (int v = 1; v <= n; v++){

    if ((!chuaxet[v]) && (d[u] + Matrix[u][v] < d[v])){

     d[v] = d[u] + Matrix[u][v];

     truoc[v] = u;

    }

   }

  }

 }

}

int main(void){

 Init();

 Dijkstra();

 Result();

 getch();

}
