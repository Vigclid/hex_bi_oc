//CODED BY DOAN XUAN SON 📌 FPT UNIVERSITY.
//The Input should be a string of expression with no spaces Example : 313h+345q=?h
//Note: p(octal) , h(hexadecimal) , b(binary)
#include <bits/stdc++.h>
using namespace std;
//some arrays
int a[256];
char hexa_only[5];
//We make the arrays are more helpful.
int the_array(){
    char c;
    int i = 0;
    for (char c = '0'; c <= '9' ; c++){
        a[c] = i;
        i++;
    }
    for (char c = 'A', i = 10 ; c <= 'F' ; c++){
        a[c] = i;
        hexa_only[i] = c;
        i++;
    }
}
//convert___.
int octal_decimal(string x){
    int n = 0,y;
    for (int j = 0; j < x.length(); j++){
        y = a[x[j]];
        n = n+y*pow(8,x.length()-(j+1));
    }
    return n;
}
int binary_decimal(string x){
    int n = 0,y;
    for (int j = 0; j < x.length(); j++){
        y = a[x[j]];
        n = n+y*pow(2,x.length()-(j+1));
    }
    return n;
}
int hexadecimal_decimal(string x){
    int n = 0,y;
    for (int j = 0; j < x.length(); j++){
        y = a[x[j]];
        n = n+y*pow(16,x.length()-(j+1));
    }
    return n;
}
//Octal,Binary,Hexadecimal have the same way to convert do Decimal that's why it's no different.
string decimal_hexdecimal(int x){
    string st = "";
    while (x){
        if (x%16 >= 10) {
            st = st + hexa_only[x%16];
            x = x/16;
        } else { st = st + std::to_string(x%16) ; x=x/16;}
    }
    reverse(st.begin(), st.end());
    return st;
}
string decimal_binary(int x){
    string st = "";
    while (x){
        st = st + std::to_string(x%2);
        x = x/2;
    }
    reverse(st.begin(), st.end());
    return st;
}
string decimal_octal(int x){
    string st = "";
    while (x){
        st = st + std::to_string(x%8);
        x = x/8;
    }
    reverse(st.begin(), st.end());
    return st;
}
//We made three converts about Decimal ---> Octal, Hexadecimal, Binary.
//We've done the convert here.
int main(){
    int i= 0,d1=0,d2=0;
    the_array(); //call this function, make sure the our arrays have their own value. 

    string s_first,s_second,s_expression;
    char op,v1,v2;    

    cin >> s_expression;

// We need the find the two values of this expression.
    for(; i < s_expression.length() ; i++){
        if (s_expression[i] >= 'a' & s_expression[i] <= 'z') {
            v1 = s_expression[i];
            op = s_expression[i+1];
            break;
        }
        s_first += s_expression[i];
    }
    i= i + 2;
    for(; i < s_expression.length(); i++){
        if (s_expression[i] >= 'a' & s_expression[i] <= 'z') {
            v2 = s_expression[i];
            break;
        }
        s_second += s_expression[i];
    }
//Covert it to the decimal form.
//first value.
    if (v1 == 'h') d1 = hexadecimal_decimal(s_first);
        else if (v1 == 'q') d1 = octal_decimal(s_first);
            else d1 = binary_decimal(s_first);
//value two.
    if (v2 == 'h') d2 = hexadecimal_decimal(s_second);
        else if (v2 == 'q') d2 = octal_decimal(s_second);
            else d2 = binary_decimal(s_second);
cout << s_first << v1 <<" " << op << " "<< s_second << v2;
if (op >= '+'&op <= '+') d1 = d1+d2;
    else
        if (op >= '-'&op <= '-') d1 = d1-d2;
            else d1 = d1*d2;
char k;
for (; i < s_expression.length()-1 ;i++){
    k = s_expression[i+1];
    if (s_expression[i] = '?') {
        if (k>='h'&k<='h') {
            cout << " = " <<decimal_hexdecimal(d1) << 'h';
        }
        if (k>='q'&k<='q') {
            cout <<" = " << decimal_octal(d1)      << 'q';
        }   
        if (k>='b'&k<='b') {
            cout << " = " << decimal_binary(d1)     << 'b';
        }
    }
}

}