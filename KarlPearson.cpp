#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int calc_fdn(vector<int>& fd, vector<int>& f, int n) {
    int fdn=0;

    for (int i=0; i<f.size(); i++) {
        fdn+=((pow(fd[i], n))*f[i]);
    }

    return fdn;
}

float findKarlPearsonCoefficient(vector<int>& x, vector<int>& f) {
    int fx=0;
    int N=0;
    vector<int> fd;
    for (int i=0; i<x.size(); i++) {
        fx+=(x[i]*f[i]);
        N+=f[i];
    }
    int a=fx/N;
    for (int i=0; i<x.size(); i++) {
        fd.push_back(x[i]-a);
    }

    int fd1=calc_fdn(fd, f, 1);
    int fd2=calc_fdn(fd, f, 2);
    int fd3=calc_fdn(fd, f, 3);

    float raw1=(float)fd1/N;
    float raw2=(float)fd2/N;
    float raw3=(float)fd3/N;

    float c1=0;
    float c2=raw2-(raw1*raw1);
    float c3=raw3 - ( 3 * raw1 * raw2 ) + 2 * pow(raw1, 3);

    float Ksp=c3/pow(c2, 1.5);
    return Ksp;
}

int main(){
    vector<int> x;
    vector<int> f;
    int N=7;

    for (int i=0; i<N; i++) {
        int a, b;
        cin>>a>>b;
        x.push_back(a);
        f.push_back(b);
    }

    cout<<findKarlPearsonCoefficient(x, f);
    return 0;
}