#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

void isaret_ciz(char,int);
bool gecerli_isim(string);
bool gecerli_numara(string);

class iletisim{
    string isim;
    string numara;

public:
    iletisim():isim(""),numara(""){
    }

    bool goster(){
        if(isim!=""){
            cout<<isim<<"\t"<<numara<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }

    bool goster(string arama_terimi){
        if(arama_terimi==isim){
            cout<<isim<<"\t"<<numara<<endl;
            return 1;
        }
        else{
            return 0;
        }
    }

    bool isim_var(string gecici_isim){
        if(gecici_isim==isim){
            return 1;
        }
        else{
            return 0;
        }
    }

    bool ekle(string yeni_isim,string yeni_numara){
        if(isim==""){
            isim=yeni_isim;
            numara=yeni_numara;
            return 1;
        }
        else{
            return 0;
        }
    }

    bool duzenle(string);

    bool sil(string yeni_isim){
        if(yeni_isim==isim){
            isim="";
            numara="";
            return 1;
        }
        else{
            return 0;
        }
    }
};

bool iletisim::duzenle(string yeni_isim){
    string yeni_numara;

    if(yeni_isim==isim){
        cout<<"Yeni Ismi Giriniz: "<<endl;
        cin>>yeni_isim;
        cout<<"Yeni Numarayi Giriniz: "<<endl;
        cin>>yeni_numara;
        isim=yeni_isim;
        numara=yeni_numara;
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    iletisim kisi[100];
    string gecici_isim, gecici_numara;
    int tercih, i, sayac;
    bool dogru, yanlis;

    cout<<"**TELEFON REHBERI**"<<endl;

    do{
        isaret_ciz('-',20);
        cout<<"0 -> Kisileri Goster"<<endl;
        cout<<"1 -> Kisileri Ekle"<<endl;
        cout<<"2 -> Kisileri Duzenle"<<endl;
        cout<<"3 -> Kisileri Sil"<<endl;
        cout<<"4 -> Kisileri Ara"<<endl;
        cout<<"5 -> Cikis"<<endl;
        isaret_ciz('-',20);
        cout<<"Tercihinizi Giriniz: "<<endl;
        cin>>tercih;

        system("cls");
        isaret_ciz('-',20);
        yanlis=0;
        dogru=0;
        sayac=0;


    switch(tercih){
    case 0:
        cout<<"Kisileri Goster"<<endl;
        isaret_ciz('-',20);

        for(i=0;i<100;i++){
            if(kisi[i].goster()){
                dogru=1;
            }
        }

        if(!dogru){
            cout<<"Kisi Bulunamadi"<<endl;
        }

        break;

    case 1:
        cout<<"Yeni Bir Kisi Ekle, Iptal Etmek Icin $ Basin"<<endl;
        isaret_ciz('-',20);
        sayac=0;

        do{
            dogru=0;
            if(sayac){
                cout<<"Tekrar Deneyin, Iptal Etmek Icin $ Basin"<<endl;
                sayac++;
            }

            cout<<"Isim: "<<endl;
            cin>>gecici_isim;
            if(gecici_isim=="$"){
                yanlis=1;
                break;
            }

            cout<<"Numara: "<<endl;
            cin>>gecici_numara;
            if(gecici_numara=="$"){
                yanlis=1;
                break;
            }

            for(i=0;i<100;i++){
                if(kisi[i].isim_var(gecici_isim)){
                    cout<<"Girdiginiz Isim Zaten Var, Farkli Bir Isim Deneyin"<<endl;
                    dogru=1;
                    break;
                }
            }
        }while(!gecerli_isim(gecici_isim) || dogru || !gecerli_numara(gecici_numara));

        if(yanlis){
            system("cls");
            break;
        }

        for(i=0;i<100;i++){
            if(kisi[i].ekle(gecici_isim,gecici_numara)){
                cout<<"Kisi Basariyla Eklendi"<<endl;
                dogru=1;
                break;
            }
        }

        if(!dogru){
            cout<<"Hafiza Dolu, Once Bazi Kisileri Silin"<<endl;
            break;
        }

    case 2:
        cout<<"Duzenlemek Icin Bir Kisi Adi Girin: (Iptal Etmek Icin $ Basin)"<<endl;
        cin>>gecici_isim;

        if(gecici_isim=="$"){
            system("cls");
            break;
        }

        for(i=0;i<100;i++){
            if(kisi[i].duzenle(gecici_isim)){
                cout<<"Basariyla Duzenlendi"<<endl;
                dogru=1;
                break;
            }
        }

        if(!dogru){
            cout<<"Kisi Adi Bulunamadi"<<endl;
        }

        break;

    case 3:
        do{
            if(sayac){
                cout<<"Tekrar Deneyin"<<endl;
            }

            sayac++;
            cout<<"Silinecek Kisinin Adini Girin: (Iptal Etmek Icin $ Basin)"<<endl;
            cin>>gecici_isim;

            if(gecici_isim=="$"){
                system("cls");
                break;
            }

            for(i=0;i<100;i++){
                if(kisi[i].isim_var(gecici_isim)){
                    dogru=1;
                    cout<<"Silmek Istedigine Emin misin? (1/0)"<<endl;
                    int evet;
                    cin>>evet;
                    if(!evet){
                        system("cls");
                        yanlis=1;
                    }
                    break;
                }
            }

            if(!dogru){
                break;
            }

            if(dogru){
                for(i=0;i<100;i++){
                    if(kisi[i].sil(gecici_isim)){
                        cout<<"Basariyla Silindi"<<endl;
                        break;
                    }
                }
            }
        }while(!dogru);
        break;

    case 4:
        do{
            if(sayac){
                cout<<"Tekrar Deneyin"<<endl;
            }
            sayac++;
            cout<<"Bir Isim Ara: (Iptal Etmek Icin $ Basin"<<endl;
            cin>>gecici_isim;

            if(gecici_isim=="$"){
                system("cls");
                break;
            }

            for(i=0;i<100;i++){
                if(kisi[i].goster(gecici_isim)){
                    dogru=1;
                    break;
                }
            }

            if(!dogru){
                cout<<"Kisi Adi Bulunamadi"<<endl;
            }
        }while(!dogru);

        break;

    case 5:
        return 0;
        break;
        }
    }while(1);

    getch();
    return 0;
}

void isaret_ciz(char isaret,int boyut){
    for(int i=0;i<boyut;i++){
        cout<<isaret;
    }
    cout<<"\n";
}

bool gecerli_isim(string gecici_isim){
    if(gecici_isim.size()>20){
        cout<<"Gecersiz Isim, 20 Karakterden Fazla Girmeyiniz"<<endl;
        return 0;
    }
    else if(gecici_isim==""){
        cout<<"Gecersiz Isim, Bos Olamaz"<<endl;
        return 0;
    }
    else{
        return 1;
    }
}

bool gecerli_numara(string gecici_numara){
    if(gecici_numara.size()>13 || gecici_numara.size()<10){
        cout<<"Gecersiz Numara, 10-13 Basamak Arasinda Giriniz"<<endl;
        return 0;
    }
    else if(gecici_numara==""){
        cout<<"Gecersiz Numara, Bos Olamaz"<<endl;
        return 0;
    }
    else{
        return 1;
    }
}

