#include "BigNumber.h"


int cplus=0, csubs=0, cmltply=0; //variabel total operator digunakan


//fungsi untuk melakukan penjumlahan
string plus2(string nums1, string nums2)
{
    string x;
    char result;
    int car = 0;
    int i;

    minusLose(&nums1);
    minusLose(&nums2);
    sammy(&nums1,&nums2);

    for(i = nums1.length()-1; i >= 0; i--)
    {
        result = (char)((int)nums1[i] + (int)nums2[i] + car - 48);
        car = 0;
        //ascii way of adding
        if((int)result > 57)
        {
            result = (char)((int)result - 10);
            car = 1;

        }
        x = result + x;
    }

    if (car != 0)
    {
        x = char(car+'0') + x;
    }

    while(x[0] == '0' && x.length() != 1)
    {
        //cout<<x.length()<<endl;
        x.erase(0,1);
    }

    if (nums1.length() > nums2.length()){
        cplus += nums1.length();
    }
    else{
        cplus += nums2.length();
    }
    return x;
}

//fungsi untuk melakukan pengurangan
string substract2(string nums1, string nums2)
{
    string x,a,b;
    bool min;
    char result;
    int i;
    int car = 0  ;

    minusLose(&nums1);
    minusLose(&nums2);
    sammy(&nums1,&nums2);
    if(isGreaterNum(nums1,nums2)){
        a = nums1;
        b = nums2;
    }
    else
    {
        a = nums2;
        b = nums1;
        min = true;
    }
    for(i = a.length()-1; i >= 0; i--)
    {
        result = (char)((int)a[i] - (int)b[i] - car + 48);
        car = 0;
        if((int)result < 48)
        {
            result = (char)((int)result + 10);
            car = 1;
        }
        x = result + x;
    }
    //cout<<car<<endl;
    while(x[0] == '0' && x.length() != 1)
    {
        //cout<<x.length()<<endl;
        x.erase(0,1);
    }
    if(min)
    {
        x = char(45) + x;
    }

    if (nums1.length() > nums2.length()){
        csubs += nums1.length();
    }
    else{
        csubs += nums2.length();
    }

    return x;
}

//procedure yang berfungsi mengembalikan jumlah karakter nums1 sama dengan jumlah karakter nums2
void sammy(string *nums1, string *nums2)
{
    int panjang;
    if((*nums1).length() > (*nums2).length())
    {
        panjang = (*nums2).length();
        for(int i = 0; i < (*nums1).length() - panjang; i++)
        {
            *nums2 = "0" + *nums2;
        }
    }
    else if ((*nums1).length() < (*nums2).length())
    {
        panjang = (*nums1).length();
        for(int i = 0; i < (*nums2).length() - panjang; i++)
        {
            *nums1 = "0" + *nums1;
        }
    }
}
//fungsi yang mengubah integer to string
string IntToString (int x)
{
    ostringstream temp;
    temp << x;
    return temp.str();
}

//fungsi untuk melakukan perkalian
string multiply2(string nums1, string nums2)
{
    if (nums1.length()==1 && nums2.length()==1){
        cmltply += 1;
    }
    else{
        cmltply += 3;
    }
    string a,b,c,d ;
    char x,y;
    string temp1,temp2,temp3,temp4,temp5,temp6;
    minusLose(&nums1);
    minusLose(&nums2);
    sammy(&nums1,&nums2);
    if(nums1.length() == 1 && nums2.length() == 1)
    {
        x = nums1[0];
        y = nums2[0];
        int num = ((nums1[0]-'0')*(nums2[0]-'0'));
        return (IntToString(num));
    }
    else
    {
        if (nums1.length() % 2 != 0)
        {
            nums1 = "0" + nums1;
        }
        if (nums2.length() % 2 != 0)
        {
            nums2 = "0" + nums2;
        }

        takeHalf(nums1,&a,&b);
        takeHalf(nums2,&c,&d);

        sammy(&a,&c);
        sammy(&b,&d);

        temp1 = multiply2(a,c); // a.c
        temp2 = multiply2(b,d); // b.d
        temp3 = multiply2(plus2(a,b),plus2(c,d)); //(a+b).(c+d)
        temp4 = temp1 + zeroks(nums1,2); // a.c.10^2s
        temp5 = substract2(substract2(temp3,temp1),temp2); //{(a+b).(c+d) - a.c - b.d}
        temp6 = temp5 + zeroks(nums1,1);//{(a+b).(c+d) - a.c - b.d}.10^s
        return plus2(plus2(temp4,temp6),temp2);
    }
}

string divide2(string nums1, string nums2)
{
    minusLose(&nums1);
    minusLose(&nums2);
    string x,b;
    if(nums1.length() < nums2.length())
    {
        x = "0";
    }
    else
    {
        string i = "1";
        string a = "0";
        do
        {
            b = multiply2(nums2,a);
            a = plus2(a,i);
        }while(b != nums1 && (isGreaterNum(nums1,b)));
        if(b != nums1)
        {
            a = substract2(a,"2");
        }
        else
        {
            a = substract2(a,"1");
        }
        x = a + x;
    }
    return x;

}

string mod2(string nums1, string nums2)
{
    minusLose(&nums1);
    minusLose(&nums2);
    string x;
    if(nums1 == "1" && nums2 == "0")
    {
        x = "tidak ada mod";
    }
    else if(nums1 == "0" && nums2 == "1")
    {
        x = "0";
    }
    else
    {
        string hasilDiv = divide2(nums1,nums2);
        x = substract2(nums1,multiply2(hasilDiv,nums2));
    }
    return x;
}

string zeroks(string num, int n)
{
    string x = "";
    string a;
    if (n == 1){
        a = "0";
    }
    else if(n == 2){
        a = "00";
    }
    for(int i = 0; i < num.length()/2 ; i++)
    {
        x = a + x;
    }
    return x;
}

void takeHalf(string nums, string *num1, string *num2)
{
    for(int i = 0; i < nums.length()/2; i++)
    {
       *num1 =  *num1 + nums[i];
    }
    for(int i = nums.length()/2 ; i < nums.length(); i++)
    {
        *num2 = *num2 + nums[i];
    }
}


bool isGreater(string nums1, string nums2)
{
    return (nums1.length() > nums2.length());
}

bool isGreaterNum(string nums1, string nums2)
{
    int i = 0;
    bool great;
    sammy(&nums1,&nums2);
    //pasti sudah jamin bahwa length num 1 dan num 2 sama
    while((int)nums1[i] == (int)nums2[i] && i < nums1.length())
    {
        i++;
    }
    if ((int)nums1[i] >= (int)nums2[i])
    {
        great = true;
    }
    else
    {
        great = false;
    }
    return great;
}

void minusLose(string *num)
{
    if ((*num)[0] == '-')
    {
        (*num).erase(0,1);
    }
}

