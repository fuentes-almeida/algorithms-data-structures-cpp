#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <setjmp.h>
#include <unistd.h>
#include "function.h"

void writelog(char *msg)
{
    FILE *log;
    log=fopen(name,"a");
    fputs(msg,log);
    fputc(' ',log);
    fclose(log);
}

void manejador(int senial)
{
    printf("Recibi la senial %d\n",senial);
    writelog(__DATE__);writelog(__TIME__);
    char *msg;
    if (senial==SIGFPE)
        {
        msg=" Floating point exception\n";
        writelog(msg);
        abort();
        }
    if (senial==SIGINT)
        {
        msg=" Interruption\n";
        writelog(msg);
        abort();
        }
    if (senial==SIGTERM)
        {
        msg=" Program terminated\n";
        writelog(msg);
        abort();
        }
    if (senial==SIGSEGV)
        {
        msg=" Segmentation fault\n";
        writelog(msg);
        abort();
        }
}

void fija_Seniales()
{
    signal(SIGINT,manejador);
    signal(SIGTERM,manejador);
    signal(SIGFPE,manejador);
    signal(SIGSEGV,manejador);
}

void generarError1(double *x,int error)
{
    if(error==0)
        {
        x[999999999]=8;
        }
    else
    for (int i=0;i<n;i++){
    if (error==1)
        {
        x[i]=sqrt(x[i]);raise(SIGINT);
        }
    else if (error==2)
        {
        x[i]=-1/x[i];
        }}
}

void generarError2(double *x,int error)
{
    int val=0;
    if(error==0)
        {
        x[999999999]=8;
        }
    else if (error==1)
        {
        jmp_buf env_buffer;
        val=setjmp(env_buffer);
        for (int i=0;i<n;i++){
        if (val!=0) x[i]=val;
        if (x[i]<0) longjmp(env_buffer,x[i]+1.0);
        x[i]=sqrt(x[i]);
        }
        }
    else
        {
        jmp_buf env_buffer;
        val=setjmp(env_buffer);
        for (int i=0;i<n;i++){
        if (val!=0) x[i]=val;
        if (x[i]<0) longjmp(env_buffer,x[i]+1.0);
        x[i]=-1/x[i];
        }
        }
}
