#include<iostream>
#include<ctime>
using namespace std;

int totalDays(string dob, string today) {
    int arr[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i=1; i<=12; i++) {
        arr[i]+=arr[i-1];
    }
    int d1=(dob[0]-'0')*10 + (dob[1]-'0');
    int d2=(today[0]-'0')*10 + (today[1]-'0');

    int m1=(dob[3]-'0')*10 + (dob[4]-'0');
    int m2=(today[3]-'0')*10 + (today[4]-'0');

    int y1=(stoi)(dob.substr(6));
    int y2=(stoi)(today.substr(6));

    if (y1>y2) {
        cout<<"Please enter the dates correctly"<<endl;
        return -1;
    }

    int days=0;

    if (y2>y1+1) {
        days = days + (y2-y1-1)*365;
        int lp1=y1/4;
        int lp2=(y2-1)/4;
        days+=(lp2-lp1);
    }

    if (y1!=y2) {
        days+=arr[m2-1];
        days+=d2;
        if (m2>2 && y2%4==0) {
            days++;
        }

        days+=arr[12]-arr[m1];
        days += (arr[m1]-arr[m1-1]-d1);
        if (m1<=2 && y1%4==0) {
            days++;
        } 
    }
    else {
        if (m1<m2-1) {
            days+=(arr[m2-1]-arr[m1]);
        }
        if (m1==m2) {
            days+=d2-d1;
        }
        else {
            days+=d2;
            days+=(arr[m1]-arr[m1-1]-d1);
            if (m1<=2 && m2>=2) {
                days++;
            }
        }
    }

    return days;
}

int main(){
    cout<<totalDays("22-11-2004", "18-11-2022");
    // we at meow inc. ensures that the user gets flexibility 
    // left argument is for your dob
    // right argument for till date you wish to calculate
    return 0;
}