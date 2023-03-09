#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

char inusername[50], inpassword[50], username[50], password[50], key;
char pilihUlang;

typedef struct {
    const char* nama;
    int stok;
    float harga;

}Item;

typedef struct {
    Item item[10];
    float totalHarga;

}Pembeli;

Pembeli pembeli;

Item itemList[5];
int menutambahan = 0;
int totalMenu = sizeof(itemList) / sizeof(Item);
int count = 0;



void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void menu();
void login();
void daftar();



void panah(int rp, int ap) {
    if (rp == ap) {
        printf("==>");
    }
    else {
        printf("   ");
    }
}

//Gwen Theresia Grandis A (672022250)
void tampilBarang(Item* item) {
    printf("==========daftar barang==========\n");
    
    for (int i = 0; i < (totalMenu+menutambahan); i++) {

        printf("Nama  : %s\n", (item+i)->nama);
        printf("stok  : %d\n", (item+i)->stok);
        printf("Harga : %.3f\n\n", (item+i)->harga);
    }
    printf("\nPress any key to go back\n");
    _getch();

}


//Florentino Lama Tokan (672022245)
void TambahBarang(Item* item) {
    muatUlang:
    printf("=========Tambah Barang===========\n");

    for (int i = 0; i < (totalMenu + menutambahan); i++) {

        printf("Nama  : %s\n", (item + i)->nama);
        printf("stok  : %d\n", (item + i)->stok);
        printf("Harga : %.3f\n\n", (item + i)->harga);
    }
    
   
    char* inputNama = malloc(sizeof(char) * 32);
    int stok;
    float harga;
    

    printf("Masukkan Nama Barang : ");
    scanf(" %[^\n]s", inputNama);

    printf("masukkan Stok : ");
    scanf("%d", &stok);
    

    printf("masukkan harga : ");
    scanf("%f", &harga);


    int it;
    for (it = 0; it < totalMenu; it++) {
        int sama = strcmp(inputNama, item[it].nama);
        if (sama == 0) {
            item[it].stok += stok;
            item[it].harga = harga;
            break;
        }

    }
    
    
    if (it == totalMenu) {
        item[totalMenu + menutambahan].nama=inputNama;
        item[totalMenu + menutambahan].stok = stok;
        item[totalMenu + menutambahan].harga = harga;
        menutambahan++;
        printf("berhasil Menambahkan %s pada menu\n", inputNama);
    }
    
    tanyaUlang:
    
    printf("apakah mau menambahkan lagi?[y/n]");
    scanf(" %c", &pilihUlang);
    if (pilihUlang == 'Y' || pilihUlang == 'y') {
        system("cls");
        goto muatUlang;
    }
    else if (pilihUlang == 'N' || pilihUlang == 'n') {
        system("cls");
        menu();

    }
    else {
        goto tanyaUlang;
    }

    
    printf("\nPress any key to go back\n");
    _getch();

}

//Cheful Mandiri Djanning (672022256)
void Kalkulasi(Item *item) {
    char* inputNama = NULL;


    muatUlang:
    for (int i = 0; i < (totalMenu + menutambahan); i++) {

        printf("Nama  : %s\n", (item + i)->nama);
        printf("stok  : %d\n", (item + i)->stok);
        printf("Harga : %.3f\n\n", (item + i)->harga);
    }

    inputNama = malloc(sizeof(char) * 24);
    printf("Masukkan Nama Barang : ");
    scanf("%s", inputNama);

    

    int it;
    for (it = 0; it < (totalMenu+menutambahan); it++) {
        int sama = strcmp(inputNama, item[it].nama);
        if (sama == 0) {
            
            int stok;
            tanyaStok:
            printf("masukkan Stok : ");
            scanf("%d", &stok);
            if (item[it].stok >= stok) {
                item[it].stok -= stok;
                pembeli.item[count].nama = inputNama;
                pembeli.item[count].stok = stok;
                pembeli.item[count].harga = item[it].harga;

                count++;
                printf("Sukses masukkan kedalam keranjang\n");
                system("pause");

                tanyaUlang1:
                printf("mau menambahkan barang lagi?[y/n] : ");
                scanf(" %c", &pilihUlang);
                if (pilihUlang == 'Y' || pilihUlang == 'y') {
                    system("cls");
                    goto muatUlang;
                }
                else if (pilihUlang == 'N' || pilihUlang == 'n') {
                    system("cls");
                    return;

                }
                else {
                    goto tanyaUlang1;
                }
            }
            else if (item[it].stok == 0) {
                printf("Stok Habis\n");
                tanyaUlang:
                printf("mau pilih Barang lain?[y/n] : ");
                scanf(" %c", &pilihUlang);

                if (pilihUlang == 'Y' || pilihUlang == 'y') {
                    system("cls");
                    goto muatUlang;
                }
                else if (pilihUlang == 'N' || pilihUlang == 'n') {
                    system("cls");
                    return;

                }
                else {
                    goto tanyaUlang;
                }

            }
            else if(item[it].stok < stok) {
                printf("stok kurang!!!\n");
                printf("sisa stok dari item %s : %d", inputNama, item[it].stok);
                system("pause");
                goto tanyaStok;
            }
            break;
        }if (it == (totalMenu+menutambahan)-1 && (sama != 0)) {
            printf("barang tidak ditemukan");
            system("pause");
            system("cls");
            goto muatUlang;
            
        }
     
    }

   
    printf("\nPress any key to go back\n");
    _getch();
}


//Angelina Sekar Ayu (672022240)
void menuTotal() {
    printf("Total Keseluruhan\n");
    if (count < 1) {
        printf("Keranjang Kosong!\n");
        printf("\nPress any key to go back\n");
        _getch();
        return;
    }
  
    for (int i = 0; i < count; i++) {
        printf("%s , %d, %.3f\n", pembeli.item[i].nama, pembeli.item[i].stok, pembeli.item[i].harga);
        printf("total harga : %.3f\n", pembeli.item[i].stok * pembeli.item[i].harga);
        pembeli.totalHarga += pembeli.item[i].stok * pembeli.item[i].harga;
        
    
    }
    printf("grand total %.3f\n\n", pembeli.totalHarga);

    printf("\nPress any key to go back\n");
    _getch();
}


void animasi()
{
    int x; double y;
    int key;
    char Pembuat[] = "\t\t\t   Pembuat :";
    char NIM1[] = "\t\t\t   Angelina Sekar Ayu (672022240)";
    char NIM2[] = "\t\t\t   Florentino Lama Tokan (672022245)";
    char NIM3[] = "\t\t\t   Cheful Mandiri Djanning (672022256)";
    char NIM4[] = "\t\t\t   Rheyna Atalya S (672022168)";
    char NIM5[] = "\t\t\t   Gwen Theresia Grandis A (672022250)";

    printf("\n\n\n");
    for (x = 0; Pembuat[x] != NULL; x++)
    {
        printf(" %c", Pembuat[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    for (x = 0; NIM1[x] != NULL; x++)
    {
        printf(" %c", NIM1[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    for (x = 0; NIM2[x] != NULL; x++)
    {
        printf(" %c", NIM2[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    for (x = 0; NIM3[x] != NULL; x++)
    {
        printf(" %c", NIM3[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    for (x = 0; NIM4[x] != NULL; x++)
    {
        printf(" %c", NIM4[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    for (x = 0; NIM5[x] != NULL; x++)
    {
        printf(" %c", NIM5[x]);
        for (y = 0; y <= 9999999; y++)
        {
        }

    }
    printf("\n");
    _getch();


}



int main() {
    system("cls");
    system("COLOR F8");
    gotoxy(2, 2);
    printf("================");
    gotoxy(2, 3);
    printf("     WELCOME    ");
    gotoxy(2, 4);
    printf("================");
    gotoxy(2, 10);
    printf("================");
    int posisi = 1;
    int tekan = 0;

    itemList[0].nama = "ayam";
    itemList[0].stok = 10;
    itemList[0].harga = 55.000;

    itemList[1].nama = "ikan";
    itemList[1].stok = 1;
    itemList[1].harga = 15.000;

    itemList[2].nama = "minyak_goreng_1Liter";
    itemList[2].stok = 12;
    itemList[2].harga = 40.000;

    itemList[3].nama = "Telur_ayam_1Lusin";
    itemList[3].stok = 10;
    itemList[3].harga = 50.000;

    itemList[4].nama = "beras_5kg";
    itemList[4].stok = 20;
    itemList[4].harga = 67.000;

    

    while (tekan != 13) {
        gotoxy(2, 5);
        panah(1, posisi); printf(" 1. Register");
        gotoxy(2, 6);
        panah(2, posisi); printf(" 2. Login");
        gotoxy(2, 7);
        panah(3, posisi); printf(" 3. EXIT");
        tekan = _getch();
        if (tekan == 80 && posisi != 3) {
            posisi++;
        }
        else if (tekan == 72 && posisi != 1) {
            posisi--;
        }
        else {
            posisi = posisi;
        }
    }int x = posisi;

    switch (x) {
    case 1:
        system("cls");
        system("COLOR F8");

        daftar();

        system("pause");
        main();
        break;

    case 2:
        system("cls");
        system("COLOR F8");

        login();

        system("pause");
        main();
        break;

    case 3:
        system("cls");
        system("COLOR F8");

        animasi();

        system("pause");
        exit(0);
    }
}

//Rheyna Atalya S (672022168)
void daftar()
{
    printf("MENU DAFTAR\n");
    printf("masukkan username = ");
    scanf(" %[^\n]s", &inusername);
    printf("masukkan password = ");
    scanf(" %[^\n]s", &inpassword);
    strcpy(username, inusername);
    strcpy(password, inpassword);
    printf("\nANDA TELAH REGIS\n\n");
    system("pause");
    system("cls");
    main();

}

//Rheyna Atalya S (672022168)
void login()
{
    while (1)
    {
        int i = 0;
        system("cls");
    labelLogin:
        if (inusername[0] == '\0' || inpassword[0] == '\0') {
            printf("anda Belum Register\n");
            return;
        }
        printf("masukkan username : ");
        scanf(" %[^\n]s", &username);


        printf("masukkan password : ");
        while ((key = _getch()) != 13)
        {
            if (i < 0)
                i = 0;
            if (key == 8)
            {
                if (i == 0)
                    continue;
                else
                {
                    printf("\b \b");
                    i--;
                    continue;
                }
            }
            if (i == 8)
            {
                continue;
            }
            printf("*");
            password[i] = key;
            i++;
        }
        password[i] = '\0';
        if (strcmp(inusername, username) == 0 && strcmp(inpassword, password) == 0) {
            printf("\nLOGIN SUKSES\n");
            system("pause");
            system("cls");
            menu();
        }
        else if (strcmp(inusername, username) != 0 && strcmp(inpassword, password) != 0) {
            printf("\nPASSWORD ATAU USERNAME ANDA SALAH\n");
            system("pause");
            system("cls");
            login();
        }
        else  {
            printf("\nregis!!\n");
            system("pause");
            system("cls");
            login();
        }
        
        system("cls");
        main();

    }
}

void menu() {
    system("cls");
    system("COLOR F8");
    gotoxy(2, 2);
    printf("================");
    gotoxy(2, 3);
    printf("WELCOME TO ALFAWIDIW");
    gotoxy(2, 4);
    printf("================");
    gotoxy(2, 10);
    printf("================");
    int posisi = 1;
    int tekan = 0;

    

    while (tekan != 13) {
        gotoxy(2, 5);
        panah(1, posisi); printf(" 1. List Barang");
        gotoxy(2, 6);
        panah(2, posisi); printf(" 2. Tambah Barang");
        gotoxy(2, 7);
        panah(3, posisi); printf(" 3. Kalkulasi Barang");
        gotoxy(2, 8);
        panah(4, posisi); printf(" 4. total dan tampil barang");
        gotoxy(2, 9);
        panah(5, posisi); printf(" 5. Exit");
        tekan = _getch();
        if (tekan == 80 && posisi != 6) {
            posisi++;
        }
        else if (tekan == 72 && posisi != 1) {
            posisi--;
        }
        else {
            posisi = posisi;
        }
    }int x = posisi;

    switch (x) {
    case 1:
        system("cls");
        system("COLOR F8");

        tampilBarang(itemList);

       
        menu();
        break;

    case 2:
        system("cls");
        system("COLOR F8");

        TambahBarang(itemList);

       
        menu();
        break;

    case 3:
        system("cls");
        system("COLOR F8");
        
        Kalkulasi(itemList);

        menu();
        break;

    case 4:
        system("cls");
        system("COLOR F8");

        menuTotal();

        menu();
        break;

    case 5:
        system("cls");
        system("COLOR F8");

        main();

        system("pause");
        break;
    }
}
