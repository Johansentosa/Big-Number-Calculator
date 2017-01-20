#include "BigNumber.cpp"
#include <windows.h>

int main()
{
    string a,b,c,d;
    string jumlah, kurang, kali, bagi, mod;

    LARGE_INTEGER start, end, freq;

    cout<<"masukan angka pertama : ";
    cin>>a;
    cout<<"masukan angka kedua : ";
    cin>>b;
    cout<<endl;
    c = a;
    d = b;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    if (c[0] == '-' && d[0] == '-'){

        jumlah = '-' + plus2(a,b);
        kurang = substract2(b,a);
        kali = multiply2(a,b);
        bagi = divide2(a,b);

    }
    else if (c[0] == '-'){


        jumlah = substract2(b,a);
        kurang = '-' + plus2(a,b);
        kali = '-' + multiply2(a,b);
        bagi = '-' + divide2(a,b);

    }
    else if (d[0] == '-'){


        jumlah = substract2(a,b);
        kurang = plus2(a,b);
        kali = '-' + multiply2(a,b);
        bagi = '-' + divide2(a,b);
    }
    else{
        jumlah = plus2(a,b);
        kurang = substract2(a,b);
        kali = multiply2(a,b);
        bagi = divide2(a,b);
    }

    mod = mod2(a,b);
    QueryPerformanceCounter(&end);
    cout<<"hasil penjumlahan : " << jumlah <<endl;
    cout<<"assignment penjumlahan : " << cplus << endl << endl;
    cout<<"hasil pengurangan : " << kurang << endl;
    cout<<"assignment pengurangan : " << csubs<<endl<<endl;
    cout<<"hasil perkalian : " << kali << endl;
    cout<<"assignment perkalian :" << cmltply<<endl<<endl;

    cout<<"hasil pembagian : " << bagi<<endl;
    cout<<"hasil mod : "<<mod<<endl;

    cout<<"Total waktu adalah "<< (end.QuadPart - start.QuadPart) * 1000000 / freq.QuadPart << " mikrosecond" << endl;

    return 0;
}

