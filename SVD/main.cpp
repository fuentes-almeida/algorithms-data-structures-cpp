#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

template<typename tipo>
tipo* requestvectormemory(tipo *vector, int n)
{
    vector=new tipo[n];
    return vector;
}

template<typename tipo>
tipo** requestmatrixmemory(tipo **matrix,int n, int m)
{
    matrix=new tipo*[n];
    for (int i=0;i<n;i++)
        matrix[i]=new tipo[m];

    return matrix;
}

double *SolveDiagMatrix(double **MatrixDiag,int n,double *x,double *b)
{
    int i;
    for(i=0;i<n;i++){
        x[i]=b[i]/MatrixDiag[i][i];}

return x;

}

double* SolveTriInfMatrix(double **MatrixInf,int n,double *x,double *b)
{
    int i,j;
    double sum=0;

    x[0]=b[0]/MatrixInf[0][0];
    for(j=1;j<n;j++){
             sum=0;
        for(i=0;i<=j-1;i++){
            sum=sum + MatrixInf[j][i]*x[i];}
        x[j]=(b[j]-sum)/MatrixInf[j][j];
    }
    return x;
}

double* SolveTriSupMatrix(double **MatrixSup,int n,double *x,double *b)
{
    int i,j;
    double sum=0;

    x[n-1]=b[n-1];
    for(j=n-2;j>=0;j--){
                sum=0;
        for(i=j+1;i<n;i++){
            sum=sum + MatrixSup[j][i]*x[i];
        }
        x[j]=b[j]-sum;
    }
    return x;
}

double **FactorizeCrouthMatrix(double **MatrixA,int n)
{
 int i,j,k;
 double sum;

    for (i=0;i<n;i++){
    sum=0;
    for(k=0;k<i;k++)
        sum=sum+MatrixA[i][k]*MatrixA[k][i];
    MatrixA[i][i]=MatrixA[i][i]-sum;

    for(j=i+1;j<n;j++){
            sum=0;
        for(k=0;k<i;k++)
            sum=sum+MatrixA[j][k]*MatrixA[k][i];
    MatrixA[j][i]=MatrixA[j][i]-sum;}

    for(j=i+1;j<n;j++){
            sum=0;
        for (k=0;k<i;k++)
            sum=sum+MatrixA[i][k]*MatrixA[k][j];
    MatrixA[i][j]=(MatrixA[i][j]-sum)/MatrixA[i][i];}
    }

    return MatrixA;
}

double *SolveCrouthSystem(double **CrouthMatrix, double *b, double *x, int n)
{
    double *y;
    y=requestvectormemory(y,n);
    y=SolveTriInfMatrix(CrouthMatrix,n,y,b);
    x=SolveTriSupMatrix(CrouthMatrix,n,x,y);
    delete y;
    return x;
}

double **FactorizeCholeskyMatrix(double **MatrixA,int n)
{
    int i,j,k;
    double sum=0;

    for (i=0;i<n;i++){
    sum=0;
    for(k=0;k<i;k++)
        sum=sum+MatrixA[i][k]*MatrixA[i][k]*MatrixA[k][k];
    MatrixA[i][i]=MatrixA[i][i]-sum;
    for(j=i+1;j<n;j++){
            sum=0;

        for(k=0;k<i;k++)
            sum=sum+MatrixA[i][k]*MatrixA[j][k]*MatrixA[k][k];
    MatrixA[j][i]=(MatrixA[j][i]-sum)/MatrixA[i][i];
    MatrixA[i][j]=MatrixA[j][i];
    }}

return MatrixA;
}

double* SolveCholeskySupMatrix(double **MatrixSup,int n,double *x,double *b)
{
    int i,j;
    double sum=0;

    x[n-1]=b[n-1];
    for(j=n-2;j>=0;j--){
                sum=0;
        for(i=j+1;i<n;i++){
            sum=sum + MatrixSup[j][i]*x[i];
        }
        x[j]=b[j]-sum;
    }

    return x;
}

double* SolveCholeskyInfMatrix(double **MatrixInf,int n,double *x,double *b)
{
    int i,j;
    double sum=0;

    x[0]=b[0];
    for(j=1;j<n;j++){
             sum=0;
        for(i=0;i<=j-1;i++){
            sum=sum + MatrixInf[j][i]*x[i];}
        x[j]=b[j]-sum;
    }
    return x;
}

double *SolveCholeskySystem(double **A,double *b,double *x,int n)
{
    x=SolveCholeskyInfMatrix(A,n,x,b);
    x=SolveDiagMatrix(A,n,x,x);
    x=SolveCholeskySupMatrix(A,n,x,x);
    return x;
}

double VectorXVector(double esca,double *A,double *B,int n)
{
    esca=0;
    for (int i=0;i<n;i++)
        esca+=A[i]*B[i];
    return esca;
}

double *MatrixXVector(double **matrix, double *vector, double *product, int n)
{
    for (int i=0;i<n;i++){
            double suma=0;
        for(int j=0;j<n;j++){
            suma+=matrix[i][j]*vector[j];
        }
        product[i]=suma;
    }
    return product;

}

double **MatrizXMatriz(double**A, int A_rows, int A_cols, double**B, int B_rows, int B_cols)
{

    double**C;
    C=requestmatrixmemory(C,A_rows,B_cols);

    for (int i = 0; i < A_rows; ++i)
    {
        for (int j = 0; j < B_cols; ++j)
        {
            double sum = 0;
            for (int k = 0; k < A_cols; ++k)
            {
                sum+=A[i][k]*B[k][j];
            }
            C[i][j] = sum;
            }
            }
    return C;
}

double *Normalize(double *vector, int n)
{
    double product=0;
    product=VectorXVector(product,vector,vector,n);
    if (product<0)
        printf("Error, operation cannot be computed");

    product=sqrt(product);
        for (int i=0;i<n;i++)
            vector[i]=vector[i]/product;
    return vector;
}

void FindMaxAbsValue(double**A,int n,int *max_row, int *max_col,double *valor)
{
    *valor=0.0;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
            if (fabs(A[i][j])>=*valor)
                {
                    *valor=fabs(A[i][j]);
                    *max_row=i; *max_col=j;
                }
}

double **PerformJacobiRotation (double **A,double**Phi,int n,double tolerance, int ite_max)
{
    double valor=1e6;
    int i,j,count=0;
    for (int k=0;k<n;k++)
        for (int p=0;p<n;p++)
        Phi[k][p]=0;
    for (int k=0;k<n;k++)
        Phi[k][k]=1;

    while (valor>tolerance&&count<ite_max)
        {
        count++;
        FindMaxAbsValue(A,n,&i,&j,&valor);
        double theta =0.5*atan2 (2*A[i][j],A[i][i]-A[j][j]);
        for (int k=0;k<n;k++)
            {
            double temp1=A[k][i]*cos(theta)+A[k][j]*sin(theta);
            double temp2=A[k][j]*cos(theta)-A[k][i]*sin(theta);
            A[k][i]=temp1;
            A[k][j]=temp2;
            temp1=Phi[k][i]*cos(theta)+Phi[k][j]*sin(theta);
            temp2=Phi[k][j]*cos(theta)-Phi[k][i]*sin(theta);
            Phi[k][i]=temp1;
            Phi[k][j]=temp2;
            }

        for (int k=0;k<n;k++)
            {
            double temp1=A[i][k]*cos(theta)+A[j][k]*sin(theta);
            double temp2=A[j][k]*cos(theta)-A[i][k]*sin(theta);
            A[i][k]=temp1;
            A[j][k]=temp2;
            }
        }
    return Phi;
}

void SubspaceIteration(double **A,int n,int m,double tolerance, int ite_max)
{
    double **Acholesky=requestmatrixmemory(Acholesky,n,n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            Acholesky[i][j]=A[i][j];
    Acholesky=FactorizeCholeskyMatrix(Acholesky,n);
    double **LambdaNM0=requestmatrixmemory(LambdaNM0,n,m);
    double **LambdaNM1=requestmatrixmemory(LambdaNM1,n,m);
    double **B=requestmatrixmemory(B,m,m);
    double **LambdaMNT=requestmatrixmemory(LambdaMNT,m,n);
    double **QMM=requestmatrixmemory(QMM,m,m);
    double *x,*b,*eigens_curr,*eigens_new,distance=1000,ak;
    int count=0;
    x=requestvectormemory(x,n);
    b=requestvectormemory(b,n);
    eigens_curr=requestvectormemory(eigens_curr,m);
    eigens_new=requestvectormemory(eigens_new,m);

    for (int i=0;i<m;i++)
        LambdaNM0[i][i]=1;


    while (distance>tolerance&&count<ite_max){
    count++;
    for (int i=0;i<m;i++)
    {

        for (int j=0;j<n;j++)
        {
            b[j]=LambdaNM0[j][i];
        }


        x=SolveCholeskySystem(Acholesky,b,x,n);

        if (i>0)
        for (int k=0;k<i;++k)
            {
            ak=0;
            for (int j=0;j<n;j++)
                ak+=LambdaNM1[j][k]*x[j];
            for (int j=0;j<n;j++)
                x[j]=x[j]-ak*LambdaNM1[j][k];
            }

        x=Normalize(x,n);

        for (int j=0;j<n;j++)
        {
            LambdaNM1[j][i]=x[j];
        }

    }

    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            LambdaMNT[i][j]=LambdaNM1[j][i];

    B=MatrizXMatriz(MatrizXMatriz(LambdaMNT,m,n,A,n,n),m,n,LambdaNM1,n,m);

    QMM=PerformJacobiRotation(B,QMM,m,tolerance,ite_max);

    LambdaNM0=MatrizXMatriz(LambdaNM1,n,m,QMM,m,m);

    distance=0;
    for (int i=0;i<m;i++)
        {
        eigens_new[i]=B[i][i];
        distance+=pow(eigens_curr[i]-eigens_new[i],2);
        }
    distance=sqrt(distance);

    for (int i=0;i<m;i++)
        eigens_curr[i]=eigens_new[i];
    }

    printf("Eigenvalores:\n");
        for (int i=0;i<m;i++)
            printf("%lf\n",B[i][i]);

    printf("\nEigenVectores por columnas:\n");
        for (int i=0;i<n;i++){
        for (int j=0;j<m;j++)
            printf("%lf  ",LambdaNM0[i][j]);
            printf("\n");}

}

int** LeerImagen(int **Imagen, char *filename)
{
    int n,scale; char format[2];
    ifstream input (filename);
    input>>format>>n>>n>>scale;

    Imagen=new int*[n];
    for (int i=0;i<n;i++)
        Imagen[i]=new int[n];

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            input>>Imagen[i][j];
    return Imagen;
}

int **ObtenerTraspuesta(int** matriz_tras,int **matriz, int n)
{
    matriz_tras=new int*[n];
    for (int i=0;i<n;i++)
        matriz_tras[i]=new int[n];

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            matriz_tras[i][j]=matriz[j][i];

    return matriz_tras;
}

double** MatrizXMatriz1(int**A, int**B, int n)
{
    double**C=requestmatrixmemory(C,n,n);


    for ( int i = 0; i < n; ++i)
        {
        for (int j = 0; j < n; ++j)
            {
            double sum=0;
            for (int k = 0; k < n; ++k)
                {
                sum+=A[i][k]*B[k][j];
                }
                C[i][j]=sum;
            }
        }
    return C;
}

int main()
{
    int n=380;
    char* filename="leon_original.pgm";

    int **Imagen=NULL;

    Imagen=LeerImagen(Imagen,filename);

    int **ImagenTras=NULL;

    ImagenTras=ObtenerTraspuesta(ImagenTras,Imagen,n);
    double** Producto=NULL;

    Producto=MatrizXMatriz1(ImagenTras,Imagen,n);

    /*for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cout<<Producto[i][j]<<" ";*/

    /*ofstream output ("copia.pgm");
    output<<"P2"<<endl<<n<<" "<<n<<endl<<255<<endl;
        for (int i=0;i<n;i++){
        for (int j=0;j<n;j++)
            output<<Imagen[i][j]<<" ";
            output<<"\n";}*/

    SubspaceIteration(Producto,n,n,0.005,1000);
    return 0;
}
