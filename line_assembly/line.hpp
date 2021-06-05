#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED
#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <cstdlib>

using namespace std;

int min(int x, int y, vector<int> &line,int flag,int n);

class AsmLine
{
public:
    vector<int> a1,a2,t1,t2,f1,f2,L1,L2;
    vector<int>::iterator it;
    int n,e1,e2,x1,x2;
    AsmLine(char file[]);

    void OptimizeTime(int k);
    void PrintResult();
    void TestResult();
    int GetTime(vector<int> &path,int k);
};

#endif // LINE_HPP_INCLUDED
