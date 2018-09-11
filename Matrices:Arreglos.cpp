#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct matriz //Matriz definida como estructura
{
  int matriz[6][6];

};

void Diagonal(int Matriz[6][6]) //imprime solo los elementos de la diagonal de una matriz
{
int i,j, contador=0;
for(i=0;i<6;i++)
 {
   for(j=0;j<6;j++)
   {
      if(i==j)
    cout << i << j << ": " << Matriz[i][j]<<endl;
    contador++;
   }
 }
 cout << "Big O: " << contador << endl;
}

void Simetricos (int Matriz [3][3]) //Funcion que dice si una matriz es simetrica o no
{
int i,j,x=0,contador=0;;
for(i=0;i<3;i++)
 {
   for(j=0;j<3;j++)
   {
      if(Matriz[i][j]==Matriz[j][i])
      x=1;
      contador++;
    }
  }

  if (x==1)
  cout << "La Matriz es simetrica\n";
  else
  cout << "La Matriz no es simetrica\n";
  cout << "Big O: " << contador << endl;
}

template<typename Type, std::size_t M, std::size_t N>
void Imprimir (Type (&Matriz)[M][N]) //imprime una matriz de 3x3
{
  for (size_t i = 0; i < M; i++)
  {
    for (size_t j = 0; j < N; j++)

    cout << Matriz[i][j] << " ";
    cout << "\n";
  }
}

void Imprimir2 (int Matriz[3][3]) //imprime una matriz de 3x3
{
  int i,j;
  for (i = 0; i < 3; i++)
  {
    for (j = 0; j < 3; j++)

    cout << Matriz[i][j] << " ";
    cout << "\n";
  }
}

void Suma (int A[6][6], int B[6][6]) //Funcion suma de dos matrices
{
int i,j,suma[6][6];

for(i = 0; i < 6; i++)
{
  for(j = 0; j < 6; j++)
  {
    suma[i][j] = A[i][j] + B[i][j];
    //cout << i << j << ": " << suma[i][j]<<endl;
   }
 }
 for (i = 0; i < 6; i++)
 {
   for (j = 0; j <6; j++)

   cout << suma[i][j] << " ";
   cout << "\n";
 }
}

void Multi6 (int A[6][6], int B[6][6]) //funcion multiplicacion de dos matrices
{
int i,j,k, multi[6][6],contador=0;

for(int i=0;i<6;i++){
  for(int j=0;j<6;j++){
          multi[i][j]=0;
          for(int k=0;k<6;k++){
  multi[i][j]= multi[i][j]+ A[i][k] * B[k][j];
  contador++;
  }
  }
}
cout << "Big O: " << contador << endl;

for(int i=0;i<6;i++)
{
for(int j=0;j<6;j++)
cout<<multi[i][j]<<" ";
cout << "\n";
}
}

void Multi3 (int A[3][3], int B[3][3]) //funcion multiplicacion de dos matrices
{
int i,j,k, multi[3][3],contador=0;

for(int i=0;i<3;i++){
  for(int j=0;j<3;j++){
          multi[i][j]=0;
          for(int k=0;k<3;k++){
  multi[i][j]= multi[i][j]+ A[i][k] * B[k][j];
  contador++;
  }
  }
  }
  cout << "Big O: " << contador << endl;

for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)

cout<<multi[i][j]<<" ";
cout << "\n";
}
}

void Transpuesta (int Matriz[6][6]) //Transpuesta de una Matriz
{
  int i,j,trans[6][6];
  for(i=0;i<6;i++)
   {
     for(j=0;j<6;j++)
     {
       trans[i][j]=Matriz[j][i];
     }
    }

for(int i=0;i<6;i++)
{
for(int j=0;j<6;j++)

cout<<trans[i][j]<<" ";
cout << "\n";
}
}

void MultiCuad (int A[3][3], int B[3][3])
{
  int i,j,k, multi[3][3],multi2[3][3],contador1=0, contador=0;

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
            multi[i][j]=0;
            for(int k=0;k<3;k++){
    multi[i][j]= multi[i][j]+ A[i][k] * B[k][j];
    contador1++;
    }
    }
    }
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
              multi2[i][j]=0;
              for(int k=0;k<3;k++){
      multi2[i][j]= multi2[i][j]+ multi[i][k] * A[k][j];
      contador++;
      }
      }
      }

    cout << "Big O: " << contador + contador1 << endl;

  for(int i=0;i<3;i++)
  {
  for(int j=0;j<3;j++)

  cout<<multi2[i][j]<<" ";
  cout << "\n";
  }
}



//-----------------------------------------------------------------------------

int main (void)
{
int S[3][3] = {{0,1,2},{1,0,3},{2,3,0}};
int s[3][3] = {{1,1,5},{1,1,3},{5,3,1}};
int A[6][6] = {{0,1,2,3,4,5},{0,1,2,3,4,5},{0,1,2,3,4,5},{0,1,2,3,4,5},{0,1,2,3,4,5},{0,1,2,3,4,5}};
int B[6][6] = {{5,4,3,2,1,1},{0,1,2,3,4,5},{5,4,3,2,1,1},{5,4,3,2,1,1},{0,1,0,0,0,0},{0,1,2,3,1,1}};

cout << "Los elementos de la diagonal de la matriz son:\n";
Diagonal(A);

cout << "\n";
Simetricos (s);
Imprimir (s);

cout << "\nMatriz A:\n";
Imprimir (A);

cout << "\nMatriz B:\n";
Imprimir (B);

cout << "\nLa Suma de A+B:\n";
Suma (A,B);

cout << "\n[A]*[B]:\n";
Multi6 (A,B);

cout<<"\nLa matriz original es:\n";
Imprimir(A);
cout << "\nSu Transpuesta es:\n";
Transpuesta(A);

cout<<"\nMultiplicando matrices cuadradas NO simetricas:\n";
cout << "\n[A]*[B]:\n";
Multi6 (A,B);
cout << "\n[B]*[A]:\n";
Multi6 (B,A);
cout << "\n[A]*[B]=[B]*[A] NO se cumple para matrices NO simetricas\n";

cout<<"\nMultiplicando matrices simetricas:\n";
cout << "\n[S]*[s]:\n";
Multi3 (S,s);
cout << "\n[s]*[S]:\n";
Multi3 (s,S);
cout<<"\nSe obtiene que AxB=-BxA\n";
cout<<"\nAxB=BxA Solo es verdad cuando A=B\n";

cout<<"\nA^2xA=AxA^A porque A conmuta consigo misma\n";
MultiCuad(S,S);

return 0;
}
