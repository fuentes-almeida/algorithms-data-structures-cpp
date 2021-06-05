int *RequestVectorIntMem(int);
float *RequestVectorFloatMem(int);
char *RequestVectorCharMem(int);
unsigned char*RequestVectorUnsignedCharMem(int);
double *RequestVectorDoubleMem(int);
int **RequestMatrixIntMem(int,int);
float **RequestMatrixFloatMem(int,int);
char **RequestMatrixCharMem(int,int);
unsigned char**RequestMatrixUnsignedCharMem(int,int);
double **RequestMatrixDoubleMem(int,int);

int *RequestVectorIntMem(int data_size){
    int *pointer;
    pointer=(int*)malloc(data_size*sizeof(int));
    return pointer;}

float *RequestVectorFloatMem(int data_size){
    float *pointer;
    pointer=(float*)malloc(data_size*sizeof(float));
    return pointer;}

char *RequestVectorCharMem(int data_size){
    char *pointer;
    pointer=(char*)malloc(data_size*sizeof(char));
    return pointer;}

unsigned char*RequestVectorUnsignedCharMem(int data_size){
    unsigned char*pointer;
    pointer=(unsigned char*)malloc(data_size*sizeof(unsigned char));
    return pointer;}

double *RequestVectorDoubleMem(int data_size){
    double *pointer;
    pointer=(double*)malloc(data_size*sizeof(double));
    return pointer;}

int **RequestMatrixIntMem(int data_size1, int data_size2){
    int i;
    int **pointer;
    pointer=(int **)malloc(data_size1*sizeof(int*));
    for (i=0;i<data_size1;i++)
        pointer[i]=(int*)malloc(data_size2*sizeof(int));
    return pointer;}

float **RequestMatrixFloatMem(int data_size1, int data_size2){
    int i;
    float **pointer;
    pointer=(float **)malloc(data_size1*sizeof(float*));
    for (i=0;i<data_size1;i++)
        pointer[i]=(float*)malloc(data_size2*sizeof(float));
    return pointer;    }

char **RequestMatrixCharMem(int data_size1, int data_size2){
    int i;
    char **pointer;
    pointer=(char **)malloc(data_size1*sizeof(char*));
    for (i=0;i<data_size1;i++)
        pointer[i]=(char*)malloc(data_size2*sizeof(char));
    return pointer;}

unsigned char**RequestMatrixUnsignedCharMem(int data_size1, int data_size2){
    int i;
    unsigned char **pointer;
    pointer=(unsigned char **)malloc(data_size1*sizeof(unsigned char*));
    for (i=0;i<data_size1;i++)
        pointer[i]=(unsigned char*)malloc(data_size2*sizeof(unsigned char));
    return pointer;}

double **RequestMatrixDoubleMem(int data_size1, int data_size2){
    int i;
    double **pointer;
    pointer=(double **)malloc(data_size1*sizeof(double*));
    for (i=0;i<data_size1;i++)
        pointer[i]=(double*)malloc(data_size2*sizeof(double));
    return pointer;}

