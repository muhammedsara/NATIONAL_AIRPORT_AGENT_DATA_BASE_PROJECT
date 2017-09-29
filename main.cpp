#include <iostream>
#include <string>
#include <windows.h>
#include <mysql.h>
#include <string>
#include <sstream>
using namespace std;

 MYSQL* baglanti;
    MYSQL_ROW satir;
    MYSQL_RES *sonuc;
    int qstate;

int x=0;


void  direk_sat(string TCKN,string y_isim,string y_soyisim,string adres,string sehir,string eposta,string sefer_bn, string sefer_bin, string tarih, string ukn, int id){
int x=1;



string sefer_id;

qstate = mysql_query(baglanti,"select * from seferler");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                if(ukn==satir[0] && sefer_bn==satir[1] && sefer_bin==satir[2] && tarih==satir[3]){

                    sefer_id=satir[5];
                }

            }
        }
        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }

 //cout<<"\n  iddd===>>>>>>>>>> : "<<sefer_id <<endl;
string direk_bilet="insert into yolcular(TCKN,y_isim,y_soyisim,adres,sehir,eposta,sefer_bn,sefer_bin,tarih,ukn,sefer_id) values('"+TCKN+"','"+y_isim+"','"+y_soyisim+"','"+adres+"','"+sehir+"','"+eposta+"','"+sefer_bn+"','"+sefer_bin+"','"+tarih+"','"+ukn+"','"+sefer_id+"')";


        const char* q = direk_bilet.c_str();

     //   cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);



        qstate = mysql_query(baglanti,"select * from yolcular");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);

        }
        else
        {
            cout<<"  Sorgu hatasi : "<<mysql_error(baglanti)<<endl;
        }

}

int main()
{


    //ba?lanty kysmy----------------
       baglanti = mysql_init(0);
    if(baglanti)
        //cout<<" ---  Baglanti basarili, baglanti => "<< baglanti <<endl;
         cout<<" ---  Baglanti Basarili --- "<<endl;
    else
        cout<<"Baglanti basarisiz. problem : "<<mysql_error(baglanti);

    baglanti = mysql_real_connect(baglanti,"localhost","root","1234","uhacente",0,NULL,0);

    //------------------------------------------------------
     // count<<"Tablo eklemek için 1 giriniz;"<<endl;

    // cout<<"Tablolara veri eklemek icin 1 giriniz => "

     while(GetAsyncKeyState(VK_ESCAPE)==0){
            gel:

        int girilen=0;
        cout<<"\n\n  Tablolara veri eklemek icin 1 giriniz \n"<<endl;
        cout<<"  Sorgular icin 2 giriniz  \n"<<endl;
        cout<<"  Cikmak icin  0 basiniz...\n"<<endl;
        cout<<"\tGirdi ==> ";cin>>girilen;
         system ("cls");

         if(girilen==0)
         {
             system("taskkill/IM cb_console_runner.exe");
         }


        if(girilen==1){

                cout<<"  \n  Yolcular tablosuna ekleme yapmak icin 1 \n"<<endl;
        cout<<"  Seferler tablosuna ekleme yapmak icin 2  \n"<<endl;
        cout<<"  Ucaklar tablosuna ekleme yapmak icin 3   \n"<<endl;
        cout<<"  Onceki menuye donmek icin 4 giriniz ... =>\n \n";
        cout<<"\tGirdi ==> ";cin>>girilen;
         system ("cls");

        switch(girilen){

            case 1:{


                    if(baglanti)
    {
        cout<<" --- Baglanilan Veritabani : uhacente - Tablo: yolcular ---"<<endl;


        string TCKN,y_isim,y_soyisim,adres,sehir,eposta,sefer_bn,sefer_bin,tarih,ukn;



        cout<<"\n \n  TCKN giriniz            => "; cin>>TCKN;
        cout<<"\n  y_isim giriniz          =>  "; cin>>y_isim;
        cout<<"\n  y_soyisim ismi giriniz  =>  "; cin>>y_soyisim;
        cout<<"\n  adres giriniz           =>  ";cin.ignore(); getline(cin,adres);
        cout<<"\n  sehir giriniz           =>  "; cin>>sehir;
        cout<<"\n  eposta giriniz          =>  "; cin>>eposta;
        cout<<"\n  sefer_bn giriniz        =>  "; cin>>sefer_bn;
        cout<<"\n  sefer_bin giriniz       =>  "; cin>>sefer_bin;
        cout<<"\n  tarih giriniz           =>  "; cin>>tarih;
        cout<<"\n  ukn giriniz             =>  "; cin>>ukn;


        string sefer_id;

qstate = mysql_query(baglanti,"select * from seferler");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                if(ukn==satir[0] && sefer_bn==satir[1] && sefer_bin==satir[2] && tarih==satir[3]){

                    sefer_id=satir[5];
                }

            }
        }



        string yolcu_ekleme_sorgusu="insert into yolcular(TCKN,y_isim,y_soyisim,adres,sehir,eposta,sefer_bn,sefer_bin,tarih,ukn,sefer_id) values('"+TCKN+"','"+y_isim+"','"+y_soyisim+"','"+adres+"','"+sehir+"','"+eposta+"','"+sefer_bn+"','"+sefer_bin+"','"+tarih+"','"+ukn+"','"+sefer_id+"')";


        const char* q = yolcu_ekleme_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<" --- Sorgu Basariyla Gerceklesti --- "<<endl;
        else
            cout<<" Sorgu problemi: "<<mysql_error(baglanti)<<endl;

        qstate = mysql_query(baglanti,"select * from yolcular");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  TCKN  : "<<satir[0]<< " "
                     <<"  y_isim : "<<satir[1]<< " "
                    <<"  y_soyisim : "<<satir[2]<< " "
                    <<"  adres : "<<satir[3]<< " "
                     <<"  sehir : "<<satir[4]<< " "
                    <<"  eposta : "<<satir[5]<< " "
                    <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                       <<"  ukn : "<<satir[9]<< " "
                     <<"  sefer_id : "<<satir[10]<<endl;
            }
        }
        else
        {
            cout<<"  Sorgu hatasi : "<<mysql_error(baglanti)<<endl;
        }
    }
    else
    {
        cout<<"  Baglanti hatasi : "<<mysql_error(baglanti)<<endl;
    }
    break;

            }
            case 2:{
        islembir:
int ms=0;
                if(baglanti)
                {
         cout<<" --- Baglanilan Veritabani : uhacente - Tablo: seferler ---"<<endl;

        string ukn,sefer_bn,sefer_bin,tarih,saat;



        cout<<"\n\n  Ucak kuyruk nosunu giriniz        => "; cin>>ukn;
        cout<<"\n  Sefer baslangic noktasini giriniz =>  "; cin>>sefer_bn;
        cout<<"\n  Sefer bitis noktasini giriniz     =>  "; cin>>sefer_bin;
        cout<<"\n  Tarihi giriniz                    =>  ";cin>>tarih;
        cout<<"\n  Saati giriniz                     =>  "; cin>>saat;

   qstate = mysql_query(baglanti,"select * from ucaklar");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                if(ukn==satir[0]){
                    ms=1;
                }

            }
        }

            if(ms==0)
                  cout<<"\n  Uygun ucak bulunamadi..."<<endl;
                  else{



        string sefer_ekleme_sorgusu="insert into seferler(ukn,sefer_bn,sefer_bin,tarih,saat) values('"+ukn+"','"+sefer_bn+"','"+sefer_bin+"','"+tarih+"','"+saat+"')";


        const char* q = sefer_ekleme_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"  Sorgu Basariyla Gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;

        qstate = mysql_query(baglanti,"select * from seferler");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  ukn  : "<<satir[0]<< " "
                    <<"  sefer_bn : "<<satir[1]<< " "
                    <<"  sefer_bin : "<<satir[2]<< " "
                     <<"  tarih : "<<satir[3]<< " "
                    <<"  saat  : "<<satir[4]<< " " <<endl;
            }
        }
        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
         }
    }
    else
    {
        cout<<"  Baglanti hatasi: "<<mysql_error(baglanti)<<endl;
    }
    break;
            }

            case 3:{


                if(baglanti)
    {
        cout<<" --- Baglanilan Veritabani : uhacente - Tablo: ucaklar ---"<<endl;



        string ukn,model,kapasite;



        cout<<"\n\n  Ucak kuyruk nosunu giriniz => "; cin>>ukn;
        cout<<"\n  Modelini giriniz           =>  "; cin>>model;
        cout<<"\n  Kapasitesini giriniz       =>  "; cin>>kapasite;




        string ucaklar_ekleme_sorgusu="insert into ucaklar(ukn,model,kapasite) values('"+ukn+"','"+model+"','"+kapasite+"')";


        const char* q = ucaklar_ekleme_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;

        qstate = mysql_query(baglanti,"select * from ucaklar");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  ukn  : "<<satir[0]<< " "
                    <<"  model  : "<<satir[1]<< " "
                    <<"  kapasite : "<<satir[2]<< " "<<endl;
            }
        }
        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
    }
    else
    {
        cout<<"  Baglanti hatasi: "<<mysql_error(baglanti)<<endl;
    }


            break;
            }

            default:{
            cout<<"\n  Yanlis girdiniz, tekrar deneyiniz....\n \n ";
            break;
            }

        }



        }



       else if(girilen==2){
      cout<<"\n  1. Islem (Yeni sefer tanimlama (sefer tablosu))  "<<endl;
        cout<<"\n  2. Islem (Bilet satma)  "<<endl;
        cout<<"\n  3. Islem (Yolcu sorgulama)  "<<endl;
        cout<<"\n  4. Islem (Ucus iptali)"<<endl;
        cout<<"\n  5. Islem (Bilet iptali)  "<<endl;
        cout<<"\n  6. Islem (Sefer sorgulama)  "<<endl;
        cout<<"\n  7. Islem (Doluluk orani en fazla olan ucuslar listelenecektir) "<<endl;
        cout<<"\n  8. Onceki Menu "<<endl;
        cout<<"\n  0. Cikis "<<endl;

        cout<<"\n\t Girdi ==> "; cin>>girilen;

        system("cls");



        switch(girilen){

            case 1:{
            goto islembir;

            break;}
            case 2:{
int ms=0;

            int uc=1;
            string ucak1[100];
            string bas1[100];
            string bit1[100];
            string tar1[100];

            string ucak2[100];
            string bas2[100];
            string bit2[100];
            string tar2[100];

            string ucak3[100];
            string bas3[100];
            string bit3[100];
            string tar3[100];

                int tut=0;
           int b_sayisi=0;
       string sefer_bn,sefer_bin,tarih;

              cout<<"\n  Sefer Baslangic Noktasi numarasini giriniz =>  "; cin>>sefer_bn;
                cout<<"  Sefer Bitis Noktasi numarasini giriniz     =>  "; cin>>sefer_bin;
                cout<<"  Tarihi giriniz                             =>  "; cin>>tarih;
                cout<<"  Bilet Sayisini giriniz                     =>  "; cin>>b_sayisi;


                qstate = mysql_query(baglanti,"select * from seferler");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                if(sefer_bn==satir[1] && sefer_bin==satir[2] && tarih==satir[3]){

                   ms=1;
                }

            }
        }
      if(ms==0){
            cout<<"\n  Bu kriterlere uygun ucus bulunmamaktadir... "<<endl;
        }
else{

          string yolcu_sorgusu="select * from seferler where sefer_bin='"+sefer_bin+"' and sefer_bn='"+sefer_bn+"' and tarih='"+tarih+"'";
         string yolcu_sorgusu2="select * from seferler s1, seferler s2 where s1.sefer_bn='"+sefer_bn+"' and s1.tarih='"+tarih+"' and s1.sefer_bin=s2.sefer_bn and s2.sefer_bin='"+sefer_bin+"'  and ((s1.tarih=s2.tarih and s1.saat<s2.saat) or (s1.tarih<s2.tarih));";
         string yolcu_sorgusu3="select * from seferler s1, seferler s2, seferler s3 where s1.sefer_bn='"+sefer_bn+"' and s1.tarih='"+tarih+"' and s1.sefer_bin=s2.sefer_bn and s2.sefer_bin=s3.sefer_bn and s3.sefer_bin='"+sefer_bin+"' and ((s1.tarih=s2.tarih and s1.saat<s2.saat) or  (s2.tarih=s3.tarih and s2.saat<s3.saat) or (s1.tarih<s2.tarih) or (s2.tarih<s3.tarih));";
            const char* q = yolcu_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;

    cout<<"\n\t\t--- Direk Ucuslar ---"<<endl;
       if(!qstate)
        {


            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
   cout<<"\n  "<<uc <<". ukn  : "<<satir[0]<< " "
                    <<"  sefer_bn : "<<satir[1]<< " "
                    <<"  sefer_bin : "<<satir[2]<< " "
                    <<"  tarih : "<<satir[3]<< " "
                    <<"  saat  : "<<satir[4]<< " " <<endl;

                   ucak1[uc]=satir[0];
                   bas1[uc]=satir[1];
                   bit1[uc]=satir[2];
                   tar1[uc]=satir[3];
                tut++;


                    uc++;


            }

        }
        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
            tut=0;
            const char* a = yolcu_sorgusu2.c_str();
        qstate = mysql_query(baglanti,a);

    cout<<"\n\t\t--- Bir Aktarmali Ucuslar ---"<<endl;
     string tutbin1;
      if(!qstate)
        {

            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
              cout<<"\n  "<<uc <<". ukn  : "<<satir[0]<< " "
                    <<"  sefer_bn : "<<satir[1]<< " "
                    <<"  sefer_bin : "<<satir[2]<< " "
                    <<"  tarih : "<<satir[3]<< " "
                    <<"  saat  : "<<satir[4]<< "  ---"
                    <<"  ukn  : "<<satir[6]<< " "
                    <<"  sefer_bn : "<<satir[7]<< " "
                    <<"  sefer_bin : "<<satir[8]<< " "
                    <<"  tarih : "<<satir[9]<< " "
                    <<"  saat  : "<<satir[10]<< " " <<endl;


                   ucak1[uc]=satir[0];
                   bas1[uc]=satir[1];
                   bit1[uc]=satir[2];
                   tar1[uc]=satir[3];

                   ucak2[uc]=satir[6];
                   bas2[uc]=satir[7];
                   bit2[uc]=satir[8];
                   tar2[uc]=satir[9];
tut++;

                    uc++;


            }

        }
        else
        {
            cout<<"  Sorgu hatasi : "<<mysql_error(baglanti)<<endl;
        }
         const char* b = yolcu_sorgusu3.c_str();
        qstate = mysql_query(baglanti,b);
tut=0;
    cout<<"\n\t\t--- Iki Aktrarmali Ucuslar ---"<<endl;

      if(!qstate)
        {

            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
                cout<<"\n  "<<uc <<". ukn  : "<<satir[0]<< " "
                    <<"  sefer_bn : "<<satir[1]<< " "
                    <<"  sefer_bin : "<<satir[2]<< " "
                    <<"  tarih : "<<satir[3]<< " "
                    <<"  saat  : "<<satir[4]<< "  ---"
                    <<"  ukn  : "<<satir[6]<< " "
                    <<"  sefer_bn : "<<satir[7]<< " "
                    <<"  sefer_bin : "<<satir[8]<< " "
                    <<"  tarih : "<<satir[9]<< " "
                    <<"  saat  : "<<satir[10]<< " "
                    <<"  ukn  : "<<satir[12]<< " "
                    <<"  sefer_bn : "<<satir[13]<< " "
                    <<"  sefer_bin : "<<satir[14]<< " "
                    <<"  tarih : "<<satir[15]<< " "
                    <<"  saat  : "<<satir[16]<< " " <<endl;

                   ucak1[uc]=satir[0];
                   bas1[uc]=satir[1];
                   bit1[uc]=satir[2];
                   tar1[uc]=satir[3];

                   ucak2[uc]=satir[6];
                   bas2[uc]=satir[7];
                   bit2[uc]=satir[8];
                   tar2[uc]=satir[9];

                   ucak3[uc]=satir[12];
                   bas3[uc]=satir[13];
                   bit3[uc]=satir[14];
                   tar3[uc]=satir[15];
                   uc++;
                   tut++;

            }

        }
        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
        int id=0;






        cout<<"\n  Secmek Istediginiz Ucusun ID sini giriniz  =>  "; cin>>id;

        int k1=0,k2=0,k3=0;
        int k1_t=0, k2_t=0,k3_t=0;
        int k1_bos=0,k2_bos=0,k3_bos=0;
        int yolcusay1=0,yolcusay2=0,yolcusay3=0;
        qstate = mysql_query(baglanti,"select * from ucaklar");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
                if(satir[0]==ucak1[id]){

                    k1=atoi(satir[2]);
                    k1_t=1;
                }
                if(satir[0]==ucak2[id]){
                    k2=atoi(satir[2]);
                    k2_t=1;
                }
                if(satir[0]==ucak3[id]){
                    k3=atoi(satir[2]);
                    k3_t=1;
                }

            }
        }

        qstate = mysql_query(baglanti,"select * from yolcular");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                   if(satir[6]==bas1[id] && satir[7]==bit1[id] && satir[8]==tar1[id] && satir[9]==ucak1[id]){
                    yolcusay1++;

                }
                if(satir[6]==bas2[id] && satir[7]==bit2[id] && satir[8]==tar2[id] && satir[9]==ucak2[id]){
                    yolcusay2++;
                }
                if(satir[6]==bas3[id] && satir[7]==bit3[id] && satir[8]==tar3[id] && satir[9]==ucak3[id]){
                    yolcusay3++;
                }

            }

        }

                k1_bos=k1-yolcusay1;
                k2_bos=k2-yolcusay2;
                k3_bos=k3-yolcusay3;

 //cout<<"\n ucak kapasiteler 1 2 3 => "<<k1<<k2<<k3;
 //cout<<"\n bas"<< bas2[id] ; cout<<"\n bit"<< bit2[id] ; cout<<"\n tar"<< tar2[id] ; cout<<"\n ukn"<< ucak2[id] ;
 // cout<<"\ntabloda olan kapasiteler 1 2 3 => "<<yolcusay1<<yolcusay2<<yolcusay3;
    cout<<"\n  Bos Olan Alanlar 1 :  "<<k1_bos << "  "<<" 2 : "<<k2_bos<< "  " <<" 3 :" <<k3_bos<< endl;

        for(int i=0; i<b_sayisi; i++){





                 string TCKN,y_isim,y_soyisim,adres,sehir,eposta,sefer_bn,sefer_bin,tarih,ukn;


                int kontrol;
                if(k1_t==1 && k1_bos==0){
                 cout<<"\n  Ucak doldu islem yapilamiyor... ";
                goto ucakdolu;
             }
             if(k2_t==1 && k2_bos==0){
                 cout<<"\n  Ucak doldu islem yapilamiyor... ";
                goto ucakdolu;
             }
             if(k3_t==1 && k3_bos==0){
                 cout<<"\n  Ucak doldu islem yapilamiyor... ";
                goto ucakdolu;
             }


             cout<<"\n  TCKN numarasini giriniz => "; cin>>TCKN;


             k1_bos--;
             k2_bos--;
             k3_bos--;

//cout<<"\n kalan bos yer  1 "<<k1_bos;cout<<"  2 "<<k2_bos;cout<<" 3 "<<k3_bos;
             kontrol=0;
            // if((uc-tut)
            qstate = mysql_query(baglanti,"select * from yolcular");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
                if(satir[0]==TCKN){


                     y_isim=satir[1];
                     y_soyisim=satir[2];
                     adres= satir[3];
                    sehir=satir[4];
                    eposta=satir[5];
                    kontrol=1;
                }

            //    if(satir[6]==bas1[id] && satir[7]==bit[])

            }



            }



            if(kontrol==1){
                      cout<<"\n   Bilgileriniz Tablomuzda Mevcuttur.\n";
                 direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas1[id],bit1[id],tar1[id],ucak1[id],id);
                 direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas2[id],bit2[id],tar2[id],ucak2[id],id);
                 direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas3[id],bit3[id],tar3[id],ucak3[id],id);


            }

            if(kontrol==0){

        cout<<"\n  y_isim giriniz          =>  "; cin>>y_isim;
        cout<<"\n  y_soyisim ismi giriniz  =>  "; cin>>y_soyisim;
        cout<<"\n  adres giriniz           =>  ";cin.ignore(); getline(cin,adres);
        cout<<"\n  sehir giriniz           =>  "; cin>>sehir;
        cout<<"\n  eposta giriniz          =>  "; cin>>eposta;

            if(k1_t==1 && k2_t==0 && k3_t==0){
                direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas1[id],bit1[id],tar1[id],ucak1[id],id);
            }
            if(k1_t==1 && k2_t==1 && k3_t==0){
                 direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas1[id],bit1[id],tar1[id],ucak1[id],id);
                direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas2[id],bit2[id],tar2[id],ucak2[id],id);
            }
            if(k1_t==1 && k2_t==1 && k3_t==1){
                  direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas1[id],bit1[id],tar1[id],ucak1[id],id);
                direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas2[id],bit2[id],tar2[id],ucak2[id],id);
                direk_sat(TCKN,y_isim,y_soyisim,adres,sehir,eposta,bas3[id],bit3[id],tar3[id],ucak3[id],id);
            }



        }

        }


        ucakdolu:
         git:
           /* string k1_s,k2_s,k3_s;
            stringstream convert1;
            stringstream convert2;
            stringstream convert3;
            convert1 << k1;
            k1_s = convert1.str();
            convert2 << k2;
            k2_s = convert2.str();
            convert3 << k3;
            k3_s = convert3.str();


            string update1= "update ucaklar set kapasite='"+k1_s+"'  where ukn='"+ucak1[id]+"' ";
            const char* x = update1.c_str();
            qstate = mysql_query(baglanti,x);

            string update2= "update ucaklar set kapasite='"+k2_s+"'  where ukn='"+ucak2[id]+"' ";
            const char* y = update2.c_str();
            qstate = mysql_query(baglanti,y);

            string update3= "update ucaklar set kapasite='"+k3_s+"'  where ukn='"+ucak3[id]+"' ";
            const char* z = update3.c_str();
            qstate = mysql_query(baglanti,z);

           cout<<"\n kapasiteler string 1 "<<k1_s;cout<<"  2 "<<k2_s;cout<<" 3 "<<k3_s;

*/
int f=0;
cout<<"\n\n  Tabloyu Gormek Icin 1 Giriniz  =>  "; cin>>f;
if(f==1){qstate = mysql_query(baglanti,"select * from yolcular");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  TCKN  : "<<satir[0]<< " "
                     <<"  y_isim : "<<satir[1]<< " "
                     <<"  y_soyisim : "<<satir[2]<< " "
                     <<"  adres : "<<satir[3]<< " "
                     <<"  sehir : "<<satir[4]<< " "
                     <<"  eposta : "<<satir[5]<< " "
                     <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                     <<"  ukn : "<<satir[9]<<endl;
            }
        }
        else
        {
          //  cout<<"  Sorgu hatasi : "<<mysql_error(baglanti)<<endl;
        }}



          }  break;}
            case 3:{
                int ms=0;
                string TCKN;
                 cout<<"\n  TCKN numarasini giriniz => "; cin>>TCKN;



                  qstate = mysql_query(baglanti,"select * from yolcular");

                 if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               if(TCKN==satir[0])ms=1;

            }
        }



                if(ms==0){cout<<"\n  Boyle bir kisi bulunamadi.."<<endl;}
else{



          string yolcu_sorgusu="select * from yolcular where TCKN='"+TCKN+"'";

            const char* q = yolcu_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"\n  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;




       if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  TCKN  : "<<satir[0]<< " "
                     <<"  y_isim : "<<satir[1]<< " "
                    <<"  y_soyisim : "<<satir[2]<< " "
                    <<"  adres : "<<satir[3]<< " "
                     <<"  sehir : "<<satir[4]<< " "
                    <<"  eposta : "<<satir[5]<< " "
                    <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                     <<"  ukn : "<<satir[9]<<endl;
            }
        }
        else
        {
            cout<<"\n  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
}
            break;}
            case 4:{

                     string sefer_bn,sefer_bin,saat,ukn,tarih;
               cout<<"\n\n  Ucak kuyruk nosunu giriniz        => "; cin>>ukn;
        cout<<"\n  Sefer baslangic noktasini giriniz =>  "; cin>>sefer_bn;
        cout<<"\n  Sefer bitis noktasini giriniz     =>  "; cin>>sefer_bin;
        cout<<"\n  Tarihi giriniz                    =>  ";cin>>tarih;
        cout<<"\n  Saati giriniz                     =>  "; cin>>saat;

        string sefer_id;
int var=0;
qstate = mysql_query(baglanti,"select * from seferler");

        if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {

                if(ukn==satir[0] && sefer_bn==satir[1] && sefer_bin==satir[2] && tarih==satir[3] && saat==satir[4]){

                    sefer_id=satir[5];
                    var=1;
                }

            }
        }


        if(var==0){cout<<"\n  Boyle bir sefer bulunamadi..."<<endl;}
             else{

                string yolcu_sorgusu="delete from seferler where sefer_id='"+sefer_id+"' ";

            const char* q = yolcu_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"\n  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;

             }



       /*if(!qstate)
        {

            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
                cout<<"ukn: "<<satir[0]<< " "
                    <<"sefer_bn: "<<satir[1]<< " "
                    <<"sefer_bin: "<<satir[2]<<" "
                     <<"tarih: "<<satir[3]<< " "
                    <<"saat: "<<satir[4]<<" " <<endl;
            }

        }
        else
        {
            cout<<"Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
*/


            break;}
            case 5:{
                int ms=0;

                string TCKN, tarih, ukn;
                 cout<<"\n  TCKN numarasini giriniz        => "; cin>>TCKN;
                 cout<<"\n  Tarihi giriniz                 => "; cin>>tarih;
                 cout<<"\n  Ucak kuyruk numarasini giriniz => "; cin>>ukn;

                 qstate = mysql_query(baglanti,"select * from yolcular");

                 if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               if(TCKN==satir[0] && tarih==satir[8] && ukn==satir[9])ms=1;

            }
        }



                if(ms==0){cout<<"\n  Boyle bir kisi bulunamadi.."<<endl;}
else{



           string biletiptal_sorgusu="Delete from yolcular where TCKN='"+TCKN+"' and tarih='"+tarih+"' and ukn='"+ukn+"'";

            const char* q = biletiptal_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"\n  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;



            int f=0;
cout<<"\n\n  Tabloyu Gormek Icin 1 Giriniz  =>  "; cin>>f;

if(f==1){

      qstate = mysql_query(baglanti,"select * from yolcular ");

             if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  TCKN  : "<<satir[0]<< " "
                     <<"  y_isim : "<<satir[1]<< " "
                    <<"  y_soyisim : "<<satir[2]<< " "
                    <<"  adres : "<<satir[3]<< " "
                     <<"  sehir : "<<satir[4]<< " "
                    <<"  eposta : "<<satir[5]<< " "
                    <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                     <<"  ukn : "<<satir[9]<<endl;
            }
        }

        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
}}
            break;}
            case 6:{
                int ms=0;
                string tarih, ukn;

               cout<<"\n  Tarihi giriniz                 => "; cin>>tarih;
                 cout<<"\n  Ucak kuyruk numarasini giriniz => "; cin>>ukn;


                qstate = mysql_query(baglanti,"select * from seferler");

                 if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               if(tarih==satir[3] &&  ukn==satir[0])ms=1;

            }
        }



                if(ms==0){cout<<"\n  Boyle bir sefer bulunamadi.."<<endl;}
else{



        string sefer_sorgusu= "select * from yolcular where tarih='"+tarih+"' and ukn='"+ukn+"' ";

            const char* q = sefer_sorgusu.c_str();

        cout<<"\n  Sorgu : "<<q<<endl;
        qstate = mysql_query(baglanti,q);

        if(!qstate)
            cout<<"\n  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;

             if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
                cout<<"\n  TCKN  : "<<satir[0]<< " "
                     <<"  y_isim : "<<satir[1]<< " "
                    <<"  y_soyisim : "<<satir[2]<< " "
                    <<"  adres : "<<satir[3]<< " "
                     <<"  sehir : "<<satir[4]<< " "
                    <<"  eposta : "<<satir[5]<< " "
                    <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                     <<"  ukn : "<<satir[9]<<endl;
            }
        }

        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }
}
            break;}
            case 7:{




         qstate = mysql_query(baglanti,"select *, count(*) AS say from yolcular group by ukn, tarih order by say desc ");

        if(!qstate)
            cout<<"\n  Sorgu Basariyla gerceklesti..."<<endl;
        else
            cout<<"  Sorgu problemi: "<<mysql_error(baglanti)<<endl;


       if(!qstate)
        {
            sonuc = mysql_store_result(baglanti);
            while(satir=mysql_fetch_row(sonuc))
            {
               cout<<"\n  Doluluk  : "<<satir[11]<< " -->"

                     <<"  sefer_bn : "<<satir[6]<< " "
                     <<"  sefer_bin : "<<satir[7]<< " "
                     <<"  tarih : "<<satir[8]<< " "
                     <<"  ukn : "<<satir[9]<<endl;
            }
        }

        else
        {
            cout<<"  Sorgu hatasi: "<<mysql_error(baglanti)<<endl;
        }

            break;}
            case 8:{
 goto gel;

            break;}
              case 0:{
system("taskkill/IM cb_console_runner.exe");

            break;}
            default:{
            cout<<"\n  Yanlis girdiniz, tekrar deneyiniz...\n \n ";
            }



        }




       }
       else
        cout<<"\n  Yanlis girdiniz, tekrar deneyiniz....\n \n ";




}

    mysql_close(baglanti);

    return 0;
}
