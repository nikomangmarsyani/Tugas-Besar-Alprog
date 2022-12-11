#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char array_nama_menu[78][50] = {
    // menu coffee
    "Ristretto", "Americano", "Blackcoffee", "Cappuccino", "Espresso", "Flat White", "Mochaccino", "Vanilla Latte", "Affogato", "Brewed Coffee", "Macchiato", "Cafe au Lait", "Coffee Latte", "Piccolo Latte", "Caramel Latte", "Hazelnut Latte",
    // menu_frappe
    "Coffee Frappe", "Vanilla Frappe", "Classic Mocha Frappe", "Chocolate Frappe", "Caramel Macchiato Frappe", "Cookie and Cream Frappe", "Matcha Frappe", "Thai Milk Tea Frappe",
    // menu_non_coffee
    "Jasmine Tea", "Lemon Tea", "Lychee Tea", "Thai Milk Tea", "Pineapple Passionfruit Lemonade", "Peach Mango Lemonade", "Coconut Strawberry Lemonade",
    // menu_smoothie
    "Banana Mango Smoothie", "Banana Spinach", "Banana Strawberry Smoothie", "Banana Guava Smoothie", "Mango Watermelon Smoothie", "Guava Strawberry Smoothie", "Guava Mango Smoothie", "Mango Strawberry Smoothie", "Mango Blackberry Smoothie", "Mixed Berry Smoothie",
    // menu_dessert
    "Macaroon", "Choux", "Danish", "Cinnamon Roll", "Croissant", "Shortcrust", "Apple Pie", "Chocolate Waffle", "Lava Cake", "Creme Brulee", "Cheesecake", "Tiramisu",
    // menu_paket
    // menu Coffee dan Dessert
    "Cofferoon (Coffee Latte dan Macaroon)", "Macchisant (Macchiato dan Croissant)", "Melchoux (Caramel Latte dan Choux)", "Capfle (Cappuccino dan Chocolate Waffle)", "Merila (Americano dan Lava Cake)", "Piccolocrust (Piccolo Latte dan Shortcrust)", "Vanillapie (Vanilla Latte dan Apple Pie)", "Brecremebru (Brewed Coffee dan Creme Brulee)", "Resocheese (Espresso dan Cheesecake)", "Rismisu (Ristretto dan Tiramisu)",
    // menu Frappe dan Dessert
    "Caroon (Caramel Macchiato Frappe dan Macaroon)", "Classicish (Classic Mocha Frappe dan Danish)", "Matcharoll (Matcha Frappe dan Cinnamon Roll)", "Vanillava (Vanilla Frappe dan Lava Cake)", "Creamcheese (Cookie and Cream Frappe dan Cheesecake)",
    // menu Non Coffee dan Dessert
    "Lycheechoux (Lychee Tea dan Choux)", "Jasminecrust (Jasmine Tea dan Shortcrust)", "Thaifle (Thai Milk Tea dan Chocolate Waffle)", "Lemonbru (Lemon Tea dan Creme Brulee)", "Peachpie (Peach Mango Lemonade dan Apple Pie)",
    // menu Smoothie  dan Dessert
    "Bamassant (Banana Mango Smoothie dan Croissant)", "Mixedcrust (Mixed Berry Smoothie dan Shortcrust)", "Gualava (Guava Mango Smoothie dan Lava Cake)", "Banberrylee (Banana Strawberry Smoothie dan Creme Brulee)", "Blackmisu (Mango Blackberry Smoothie dan Tiramisu)"
};

int array_harga_menu[78] = {
    // menu coffee
    23000, 25000, 25000, 25000, 25000, 25000, 25000, 25000, 27000, 27000, 28000, 30000, 30000, 30000, 32000, 32000,
    // menu_frappe
    25000, 25000, 26000, 27000, 28000, 28000, 28000, 28000,
    // menu_non_coffee
    12000, 15000, 15000, 15000, 22000, 25000, 25000,
    // menu_smoothie
    20000, 20000, 22000, 22000, 22000, 23000, 23000, 23000, 25000, 26000,
    // menu_dessert
    10000, 12000, 12000, 17000, 17000, 20000, 25000, 25000, 25000, 27000, 30000, 30000,
    // menu_paket
    // menu Coffee dan Dessert
    35000, 40000, 40000, 45000, 45000, 45000, 45000, 50000, 50000, 50000,
    // menu Frappe dan Dessert
    33000, 33000, 40000, 45000, 53000,
    // menu Non Coffee dan Dessert
    22000, 27000, 35000, 37000, 45000,
    // menu Smoothie  dan Dessert
    32000, 41000, 43000, 44000, 50000
};

float besar_diskon[3] = {
    0.15,   // diskon jika belanja > 500000
    0.1,    // diskon jika belanja > 400000
    0.05    // diskon jika belanja > 250000
};

struct pegawai{
	char nama_pegawai[50];
	int pin_pegawai;
};

struct pegawai pegawai01 = {
	"Marsyani", 1234
};

struct pegawai pegawai02 = {
	"Mirah", 4321
};

struct pegawai pegawai_yang_bertugas;

struct pelanggan{
	char nama_pelanggan[50];
	int pin_pelanggan;
};

struct pelanggan pelanggan_baru;
struct pelanggan pelanggan_login;

time_t waktuserver;

void main();
void opening();
void waktu_pemesanan();
void waktu_pembayaran();
void close();
void login_pegawai();
void menu_pegawai();
void data_transaksi();
void menu_pelanggan();
void registrasi_pelanggan();
void login_pelanggan();
void menu_cafe();
void menu_minuman();
void menu_coffee();
void menu_frappe();
void menu_non_coffee();
void menu_smoothie();
void menu_dessert();
void menu_paket();
void opsi_program();
void pemesanan();
void cetak_nama();
void header_cetak_bukti_pemesanan();
void isi_cetak_bukti_pemesanan(int pesanan, int banyak_pesanan, int sub_total, int i);
void closing_cetak_bukti_pemesanan(int total_biaya, int diskon, int total_bayar);
void ulang();
void selesai();

void opening(){
    printf("\n\t==============================================================");
    printf("\n\t||                                                          ||");
    printf("\n\t||            TUGAS BESAR ALGORITMA PEMROGRAMAN             ||");
    printf("\n\t||                   PROGRAM COFFEE SHOP                    ||");
    printf("\n\t||                                                          ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||                  | BERANDA COFFEE SHOP |                 ||");
    printf("\n\t||==========================================================||");
    printf("\n\t||             Program disusun dan dibuat oleh :            ||");
    printf("\n\t||                                                          ||");
    printf("\n\t|| 1. Ni Putu Mirah Kartika Cahyani        (2205551048)     ||");
    printf("\n\t|| 2. Ni Komang Marsyani                   (2205551052)     ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||               Jurusan Teknologi Informasi                ||");
    printf("\n\t||                      Fakultas Teknik                     ||");
    printf("\n\t||                    Universitas Udayana                   ||");
    printf("\n\t||                           2022                           ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t||             Tekan ENTER untuk melanjutkan                ||");
    printf("\n\t==============================================================");
    close();
}

void main(){
    opening();
    login_pegawai();
}

void waktu_pemesanan(){
	time(&waktuserver);
	struct tm* waktu = localtime(&waktuserver);
	printf ("\n\tWaktu Server : %s", asctime (waktu));
}

void waktu_pembayaran(){
	time(&waktuserver);
	struct tm* waktu = localtime(&waktuserver);
	FILE *hasil;
	hasil = fopen("DataPesanan.txt", "a");
	fprintf (hasil, "\n\tWaktu Pemesanan : %s", asctime (waktu));
	fclose(hasil);
}

void close(){
    fflush(stdin);
    printf("\n\tBerikutnya...");
    printf("\n\tTekan Enter untuk Melanjutkan...");
    getchar();
    system("clear");
}

void login_pegawai(){
	int pin;
	printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                      MENU PEGAWAI                        ||");
	printf("\n\t||              SILAKAN LOGIN TERLEBIH DAHULU               ||");
	printf("\n\t==============================================================");
	printf("\n\tMasukkan Pin Pegawai : ");
	while(scanf("%d", &pin)==0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan Kode Pegawai : ");
        while((getchar())!='\n');
    }
	fflush(stdin);
	if(pin == pegawai01.pin_pegawai){
		printf("\n\tNama Pegawai          : %s", pegawai01.nama_pegawai);
		printf("\n\t==============================================================");
        printf("\n\t||                     BERHASIL LOGIN                       ||");
        printf("\n\t==============================================================");
        strcpy(pegawai_yang_bertugas.nama_pegawai, pegawai01.nama_pegawai);
        close();
        menu_pegawai();
	}else if(pin == pegawai02.pin_pegawai){
		printf("\n\tNama Pegawai          : %s ", pegawai02.nama_pegawai);
		printf("\n\t==============================================================");
        printf("\n\t||                     BERHASIL LOGIN                       ||");
        printf("\n\t==============================================================");
        strcpy(pegawai_yang_bertugas.nama_pegawai, pegawai02.nama_pegawai);
        close();
        menu_pegawai();
	}else{
		printf("\n\t==============================================================");
        printf("\n\t||        LOGIN GAGAL | MASUKKAN KODE DENGAN BENAR          ||");
        printf("\n\t==============================================================");
		close();
		login_pegawai();
	}
}

void menu_pegawai(){
    int menu;
    fflush(stdin);
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                        MENU PEGAWAI                      ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| Pilihan Menu Pegawai                                     ||");
    printf("\n\t||  [1] Beralih ke Tampilan Pelanggan                       ||");
    printf("\n\t||  [2] Lihat Data Pelanggan                                ||");
    printf("\n\t||  [3] Lihat Transaksi Toko                                ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan Pilihan Anda : ");
	while(scanf("%d", &menu)==0 || menu < 1 || menu > 3){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan Pilihan Anda : ");
        while((getchar())!='\n');
    }
	close();
    if (menu==1){
        menu_pelanggan();
    }else if(menu==2){
        data_pelanggan();
    }else if(menu==3){
        data_transaksi();
    }
}

void data_pelanggan(){
    FILE *regis = fopen("DataPelanggan.txt", "r");
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                      DATA PELANGGAN                      ||");
    printf("\n\t==============================================================");

    while (!feof(regis)){
        struct pelanggan pelanggan01;

        //membaca data member dalam file DataPelanggan.txt
        fscanf(regis, "%[^#]#%d\n", &pelanggan01.nama_pelanggan, &pelanggan01.pin_pelanggan);
        fflush(stdin);
        printf("\n\tNama Pelanggan         : %s", pelanggan01.nama_pelanggan);
        printf("\n\tKode Pelanggan         : %d", pelanggan01.pin_pelanggan);
        printf("\n\t--------------------------------------------------------------");
    int c;
        while((c=getchar())!='\n' && c!=EOF);
    }
    //menutup file DataPelanggan.txt
    fclose(regis);
    close();
    menu_pegawai();
}

void data_transaksi(){
    char buff[255];
    FILE *fptr;
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                      DATA TRANSAKSI                      ||");
    printf("\n\t==============================================================\n");
    if ((fptr = fopen("DataPesanan.txt","r")) == NULL){
        printf("\n\tError: File tidak ada!");
    }

    while(fgets(buff, sizeof(buff), fptr)){
        printf("%s", buff);
    }

    fclose(fptr);
    close();
    menu_pegawai();
}

void menu_pelanggan(){
    int menu;
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                       MENU PELANGGAN                     ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| Pilihan Menu Pelanggan                                   ||");
    printf("\n\t||  [1] Registrasi Pelanggan                                ||");
    printf("\n\t||  [2] Login Pelanggan                                     ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan Pilihan Anda : ");
	while(scanf("%d", &menu)==0 || menu < 1 || menu > 2){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tInputkan pilihan Anda: ");
        while((getchar())!='\n');
    }
	close();
    if (menu==1){
        registrasi_pelanggan();
    }else if(menu==2){
        login_pelanggan();
    }
}

void registrasi_pelanggan(){
    int i;
    struct pelanggan pelanggan01;
	FILE *regis = fopen("DataPelanggan.txt", "a+");

	printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                   REGISTRASI PELANGGAN                   ||");
    printf("\n\t==============================================================");
	printf("\n\tMasukkan Kode Pelanggan : ");
	while(scanf("%d", &pelanggan_baru.pin_pelanggan)==0 || pelanggan_baru.pin_pelanggan < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan Kode Pelanggan : ");
        while((getchar())!='\n');
    }
	fflush(stdin);

	//Perulangan untuk mengecek data member dalam file DataPelanggan.txt
	while (!feof(regis)){
		//membaca data member dalam file DataPelanggan.txt
		fscanf(regis, "%[^#]#%d\n", &pelanggan01.nama_pelanggan, &pelanggan01.pin_pelanggan);
		fflush(stdin);

		//kondisi untuk mengecek apakah kode yang diinputkan sudah terdaftar atau belum, jika sudah terdaftar maka sistem akan meminta user untuk mengulang memasukan kode
		if (pelanggan01.pin_pelanggan == pelanggan_baru.pin_pelanggan){
            printf("\n\t==============================================================");
            printf("\n\t||            Kode Sudah Digunakan. Coba Lainnya            ||");
            printf("\n\t==============================================================");
            fclose(regis);
			close();
			registrasi_pelanggan();
			break;
		}
	}
    fflush(stdin);
    printf("\n\tMasukkan Nama     : ");
    scanf("%[^\n]", pelanggan_baru.nama_pelanggan);
    fprintf(regis, "%s#%d\n", pelanggan_baru.nama_pelanggan, pelanggan_baru.pin_pelanggan);
    fclose(regis);

    printf("\n\tPelanggan %s telah didaftarkan\n", pelanggan_baru.nama_pelanggan);
    printf("\n\t==============================================================");
    printf("\n\t||            Pelanggan Baru Berhasil Terdaftar             ||");
    printf("\n\t==============================================================");
    close();
    menu_pelanggan();
}

void login_pelanggan(){
	int i;
	int pin;
	struct pelanggan pelanggan01;
	FILE *regis = fopen("DataPelanggan.txt", "a+");

	printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                      LOGIN PELANGGAN                     ||");
    printf("\n\t==============================================================");
	printf("\n\tMasukkan Kode Pelanggan : ");
	while(scanf("%d", &pin)==0 || pin < 0){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tMasukkan Kode Pelanggan : ");
        while((getchar())!='\n');
    }

	// Perulangan untuk mengecek data member dalam file data.txt
	while (!feof(regis)){
		//membaca data member dalam file data.txt
		fscanf(regis, "%[^#]#%d\n", &pelanggan01.nama_pelanggan, &pelanggan01.pin_pelanggan);
		fflush(stdin);

		//kondisi untuk mengecek apakah pin yang diinputkan terdaftar pada sistem atau tidak
		if (pelanggan01.pin_pelanggan == pin){
			// jika pin member ditemukan maka sistem akan menampilkan data yang sesuai dengan pin yang diinputkan
			printf("\n\tNama Pelanggan         : %s", pelanggan01.nama_pelanggan);
			printf("\n\tKode Pelanggan         : %d", pelanggan01.pin_pelanggan);
			printf("\n\t==============================================================");
			strcpy(pelanggan_login.nama_pelanggan, pelanggan01.nama_pelanggan);
			fclose(regis); //menutup file DataPelanggan.txt
			close();
			menu_cafe();
			break;
		}
	}
	fclose(regis); //menutup file DataPelanggan.txt
    //Jika pin member yang dimasukkan tidak ditemukan pada akun, sistem akan mengulang kembali ke fungsi menu_pelanggan()
    printf("\n\t==============================================================");
    printf("\n\t||                Pelanggan Belum Terdaftar                 ||");
    printf("\n\t||           Silahkan registrasi terlebih dahulu            ||");
    printf("\n\t==============================================================");
    close();
    menu_pelanggan();
}

void menu_cafe(){
    int menu;
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||           SILAHKAN PILIH MENU YANG AKAN DIBUKA           ||");
	printf("\n\t||==========================================================||");
    printf("\n\t|| [1] Minuman                                              ||");
    printf("\n\t|| [2] Dessert                                              ||");
    printf("\n\t|| [3] Paket                                                ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan angka untuk memilih: ");
  	while (scanf("%d", &menu)==0 || menu < 1 || menu > 3){
		printf("\t--------------------------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar.");
        printf("\n\t--------------------------------------------------------------");
		printf("\n\tMasukkan angka untuk memilih: ");
		while((getchar())!='\n');
	}
	close();
  	if(menu==1){
		menu_minuman();
    }else if(menu==2){
        menu_dessert();
    }else if(menu==3){
		menu_paket();
	}
}

void menu_minuman(){
    int minuman;
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||            SILAKAN PILIH MENU YANG AKAN DIBUKA           ||");
	printf("\n\t||==========================================================||");
    printf("\n\t|| [1] Coffee                                               ||");
    printf("\n\t|| [2] Frappe                                               ||");
    printf("\n\t|| [3] Non Coffee                                           ||");
    printf("\n\t|| [4] Smoothie                                             ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| [0] Kembali ke menu utama                                ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan angka untuk memilih: ");
  	while (scanf("%d", &minuman)==0 || minuman < 0 || minuman > 4){
		printf("\t--------------------------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar.");
        printf("\n\t--------------------------------------------------------------");
		printf("\n\tMasukkan angka untuk memilih: ");
		while((getchar())!='\n');
	}
	close();
  	if(minuman==1){
		menu_coffee();
    }else if(minuman==2){
        menu_frappe();
    }else if(minuman==3){
        menu_non_coffee();
    }else if(minuman==4){
		menu_smoothie();
	}else if(minuman==0){
        menu_cafe();
    }
}

void menu_coffee(){
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                         COFFEE MENU                      ||");
	printf("\n\t||==========================================================||");
    printf("\n\t||     [Kode Menu] Nama Menu      ||          Harga         ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| [1] Ristretto                  ||        Rp 23000        ||");
    printf("\n\t|| [2] Americano                  ||        Rp 25000        ||");
    printf("\n\t|| [3] Blackcoffee                ||        Rp 25000        ||");
    printf("\n\t|| [4] Cappuccino                 ||        Rp 25000        ||");
    printf("\n\t|| [5] Espresso                   ||        Rp 25000        ||");
    printf("\n\t|| [6] Flat White                 ||        Rp 25000        ||");
    printf("\n\t|| [7] Mochaccino                 ||        Rp 25000        ||");
    printf("\n\t|| [8] Vanilla Latte              ||        Rp 25000        ||");
    printf("\n\t|| [9] Affogato                   ||        Rp 27000        ||");
    printf("\n\t|| [10] Brewed Coffee             ||        Rp 27000        ||");
    printf("\n\t|| [11] Macchiato                 ||        Rp 28000        ||");
    printf("\n\t|| [12] Cafe au Lait              ||        Rp 30000        ||");
    printf("\n\t|| [13] Coffee Latte              ||        Rp 30000        ||");
    printf("\n\t|| [14] Piccolo Latte             ||        Rp 30000        ||");
    printf("\n\t|| [15] Caramel Latte             ||        Rp 32000        ||");
    printf("\n\t|| [16] Hazelnut Latte            ||        Rp 32000        ||");
    printf("\n\t==============================================================");
    opsi_program();
}

void menu_frappe(){
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                         FRAPPE MENU                      ||");
	printf("\n\t||==========================================================||");
    printf("\n\t||     [Kode Menu] Nama Menu      ||          Harga         ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| [17] Coffee Frappe             ||        Rp 25000        ||");
    printf("\n\t|| [18] Vanilla Frappe            ||        Rp 25000        ||");
    printf("\n\t|| [19] Classic Mocha Frappe      ||        Rp 26000        ||");
    printf("\n\t|| [20] Chocolate Frappe          ||        Rp 27000        ||");
    printf("\n\t|| [21] Caramel Macchiato Frappe  ||        Rp 28000        ||");
    printf("\n\t|| [22] Cookie and Cream Frappe   ||        Rp 28000        ||");
    printf("\n\t|| [23] Matcha Frappe             ||        Rp 28000        ||");
    printf("\n\t|| [24] Thai Milk Tea Frappe      ||        Rp 28000        ||");
    printf("\n\t==============================================================");
    opsi_program();
}

void menu_non_coffee(){
    printf("\n\t======================================================================");
    printf("\n\t||             C U P  O'  J A N E  C O F F E E  S H O P             ||");
	printf("\n\t||``````````````````````````````````````````````````````````````````||");
	printf("\n\t||                         NON COFFEE MENU                          ||");
    printf("\n\t||==================================================================||");
    printf("\n\t||         [Kode Menu] Nama Menu          ||          Harga         ||");
    printf("\n\t||==================================================================||");
    printf("\n\t|| [25] Jasmine Tea                       ||        Rp 12000        ||");
    printf("\n\t|| [26] Lemon Tea                         ||        Rp 15000        ||");
    printf("\n\t|| [27] Lychee Tea                        ||        Rp 15000        ||");
    printf("\n\t|| [28] Thai Milk Tea                     ||        Rp 15000        ||");
    printf("\n\t|| [29] Pineapple Passionfruit Lemonade   ||        Rp 22000        ||");
    printf("\n\t|| [30] Peach Mango Lemonade              ||        Rp 25000        ||");
    printf("\n\t|| [31] Coconut Strawberry Lemonade       ||        Rp 25000        ||");
    printf("\n\t======================================================================");
    opsi_program();
}

void menu_smoothie(){
    printf("\n\t======================================================================");
    printf("\n\t||             C U P  O'  J A N E  C O F F E E  S H O P             ||");
	printf("\n\t||``````````````````````````````````````````````````````````````````||");
	printf("\n\t||                           SMOOTHIE MENU                          ||");
    printf("\n\t||==================================================================||");
    printf("\n\t||         [Kode Menu] Nama Menu          ||          Harga         ||");
    printf("\n\t||==================================================================||");
    printf("\n\t|| [32] Banana Mango Smoothie             ||        Rp 20000        ||");
    printf("\n\t|| [33] Banana Spinach                    ||        Rp 20000        ||");
    printf("\n\t|| [34] Banana Strawberry Smoothie        ||        Rp 22000        ||");
    printf("\n\t|| [35] Banana Guava Smoothie             ||        Rp 22000        ||");
    printf("\n\t|| [36] Mango Watermelon Smoothie         ||        Rp 22000        ||");
    printf("\n\t|| [37] Guava Strawberry Smoothie         ||        Rp 23000        ||");
    printf("\n\t|| [38] Guava Mango Smoothie              ||        Rp 23000        ||");
    printf("\n\t|| [39] Mango Strawberry Smoothie         ||        Rp 23000        ||");
    printf("\n\t|| [40] Mango Blackberry Smoothie         ||        Rp 25000        ||");
    printf("\n\t|| [41] Mixed Berry Smoothie              ||        Rp 26000        ||");
    printf("\n\t======================================================================");
    opsi_program();
}

void menu_dessert(){
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                       DESSERT MENU                       ||");
	printf("\n\t||==========================================================||");
	printf("\n\t||     [Kode Menu] Nama Menu      ||          Harga         ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| [42] Macaroon                  ||        Rp 10000        ||");
    printf("\n\t|| [43] Choux                     ||        Rp 12000        ||");
    printf("\n\t|| [44] Danish                    ||        Rp 12000        ||");
    printf("\n\t|| [45] Cinnamon Roll             ||        Rp 17000        ||");
    printf("\n\t|| [46] Croissant                 ||        Rp 17000        ||");
    printf("\n\t|| [47] Shortcrust                ||        Rp 20000        ||");
    printf("\n\t|| [48] Apple Pie                 ||        Rp 25000        ||");
    printf("\n\t|| [49] Chocolate Waffle          ||        Rp 25000        ||");
    printf("\n\t|| [50] Lava Cake                 ||        Rp 25000        ||");
    printf("\n\t|| [51] Creme Brulee              ||        Rp 27000        ||");
    printf("\n\t|| [52] Cheesecake                ||        Rp 30000        ||");
    printf("\n\t|| [53] Tiramisu                  ||        Rp 30000        ||");
    printf("\n\t==============================================================");
    opsi_program();
}

void menu_paket(){
    printf("\n\t==================================================================================================");
    printf("\n\t||                            C U P  O'  J A N E  C O F F E E  S H O P                          ||");
	printf("\n\t||``````````````````````````````````````````````````````````````````````````````````````````````||");
	printf("\n\t||                                          PAKET MENU                                          ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t||                    [Kode Menu] Nama Menu                           ||          Harga         ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t||                      Coffee dan Dessert                            ||          Harga         ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t|| [54] Cofferoon     (Coffee Latte dan Macaroon)                     ||        Rp 35000        ||");
    printf("\n\t|| [55] Macchisant    (Macchiato dan Croissant)                       ||        Rp 40000        ||");
    printf("\n\t|| [56] Melchoux      (Caramel Latte dan Choux)                       ||        Rp 40000        ||");
    printf("\n\t|| [57] Capfle        (Cappuccino dan Chocolate Waffle)               ||        Rp 45000        ||");
    printf("\n\t|| [58] Merila	      (Americano dan Lava Cake)                       ||        Rp 45000        ||");
    printf("\n\t|| [59] Piccolocrust  (Piccolo Latte dan Shortcrust)                  ||        Rp 45000        ||");
    printf("\n\t|| [60] Vanillapie    (Vanilla Latte dan Apple Pie)                   ||        Rp 45000        ||");
    printf("\n\t|| [61] Brecremebru   (Brewed Coffee dan Creme Brulee)                ||        Rp 50000        ||");
    printf("\n\t|| [62] Resocheese    (Espresso dan Cheesecake)                       ||        Rp 50000        ||");
    printf("\n\t|| [63] Rismisu       (Ristretto dan Tiramisu)                        ||        Rp 50000        ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t||                                   Frappe dan Dessert                                         ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t|| [64] Caroon        (Caramel Macchiato Frappe dan Macaroon)         ||        Rp 33000        ||");
    printf("\n\t|| [65] Classicish    (Classic Mocha Frappe dan Danish)               ||        Rp 33000        ||");
    printf("\n\t|| [66] Matcharoll    (Matcha Frappe dan Cinnamon Roll)               ||        Rp 40000        ||");
    printf("\n\t|| [67] Vanillava     (Vanilla Frappe dan Lava Cake)                  ||        Rp 45000        ||");
    printf("\n\t|| [68] Creamcheese   (Cookie and Cream Frappe dan Cheesecake)        ||        Rp 53000        ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t||                                  Non Coffee dan Dessert                                      ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t|| [69] Lycheechoux   (Lychee Tea dan Choux)                          ||        Rp 22000        ||");
    printf("\n\t|| [70] Jasminecrust  (Jasmine Tea dan Shortcrust)                    ||        Rp 27000        ||");
    printf("\n\t|| [71] Thaifle       (Thai Milk Tea dan Chocolate Waffle)            ||        Rp 35000        ||");
    printf("\n\t|| [72] Lemonbru      (Lemon Tea dan Creme Brulee)                    ||        Rp 37000        ||");
    printf("\n\t|| [73] Peachpie      (Peach Mango Lemonade dan Apple Pie)            ||        Rp 45000        ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t||                                   Smoothie  dan Dessert                                      ||");
    printf("\n\t||==============================================================================================||");
    printf("\n\t|| [74] Bamassant     (Banana Mango Smoothie dan Croissant)           ||        Rp 32000        ||");
    printf("\n\t|| [75] Mixedcrust    (Mixed Berry Smoothie dan Shortcrust)           ||        Rp 41000        ||");
    printf("\n\t|| [76] Gualava       (Guava Mango Smoothie dan Lava Cake)            ||        Rp 43000        ||");
    printf("\n\t|| [77] Banberrylee   (Banana Strawberry Smoothie dan Creme Brulee)   ||        Rp 44000        ||");
    printf("\n\t|| [78] Blackmisu     (Mango Blackberry Smoothie dan Tiramisu)        ||        Rp 50000        ||");
    printf("\n\t==================================================================================================");
    opsi_program();
}

void opsi_program(){
    int pilihan;
    printf("\n\t==============================================================");
    printf("\n\t|| Pilihan Program :                                        ||");
    printf("\n\t||----------------------------------------------------------||");
    printf("\n\t|| [0] Kembali ke menu utama                                ||");
    printf("\n\t|| [1] Pemesanan                                            ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan angka untuk memilih: ");
  	while (scanf("%d", &pilihan)==0 || pilihan < 0 || pilihan > 1){
		printf("\t--------------------------------------------------------------");
        printf("\n\tKarakter yang Anda inputkan salah!");
        printf("\n\tMohon inputkan angka yang benar...");
        printf("\n\t--------------------------------------------------------------");
		printf("\n\tMasukkan angka untuk memilih: ");
		while((getchar())!='\n');
	}

	switch(pilihan){
    case 0 :
        close();
        menu_cafe();
        break;
    case 1 :
        pemesanan();
        break;
	}
}

void pemesanan(){
    int pesanan[50], banyak_pesanan[50], pilihan, i = 0, sub_total[50], total_biaya = 0, total_bayar = 0, diskon;
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                         PEMESANAN                        ||");
	printf("\n\t==============================================================");
	waktu_pemesanan();
	header_cetak_bukti_pemesanan();
	do{
        fflush(stdin);
        printf("\n\tMasukkan Kode Pesanan: ");
            while (scanf("%d", &pesanan[i])==0 || pesanan[i] < 0 || pesanan[i] > 78){
            printf("\t--------------------------------------------------------------");
            printf("\n\tMohon inputkan angka yang benar.");
            printf("\n\t       [Angka 1 - 78]");
            printf("\n\t--------------------------------------------------------------");
            printf("\n\tMasukkan Kode Pesanan: ");
            while((getchar())!='\n');
        }
        fflush(stdin);
        printf("\n\tMasukkan Banyak Pesanan: ");
        while (scanf("%d", &banyak_pesanan[i])==0 || banyak_pesanan[i] < 0){
            printf("\t--------------------------------------------------------------");
            printf("\n\tKarakter yang Anda inputkan salah!");
            printf("\n\tMohon inputkan angka yang benar.");
            printf("\n\t--------------------------------------------------------------");
            printf("\n\tMasukkan Banyak Pesanan: ");
            while((getchar())!='\n');
        }

        sub_total[i] = array_harga_menu[pesanan[i]-1] * banyak_pesanan[i];
        total_biaya = total_biaya + sub_total[i];

        printf("\n\tPesanan Anda ke-%d : %s", i+1, array_nama_menu[pesanan[i]-1]);
        printf("\n\tHarga Menu        : Rp %d", array_harga_menu[pesanan[i]-1]);
        printf("\n\tBanyak Pesanan    : %d", banyak_pesanan[i]);
        printf("\n\tSub-total         : Rp %d", sub_total[i]);

        isi_cetak_bukti_pemesanan(pesanan[i], banyak_pesanan[i], sub_total[i], i);

        printf("\n\t--------------------------------------------------------------");
        printf("\n\tApakah Anda Ingin Memesan Kembali ?");
        printf("\n\t [1] Pesan Lagi     [2] Lanjutkan Pembayaran");
        printf("\n\tMasukkan Pilihan Anda: ");
        while (scanf("%d", &pilihan)==0 || pilihan < 1 || pilihan > 2){
            printf("\t--------------------------------------------------------------");
            printf("\n\tKarakter yang Anda inputkan salah!");
            printf("\n\tMohon inputkan angka yang benar.");
            printf("\n\t--------------------------------------------------------------");
            printf("\n\tMasukkan Pilihan Anda: ");
            while((getchar())!='\n');
        }
        printf("\t--------------------------------------------------------------");
        i++;
	}while(pilihan==1);

    switch(pilihan){
    case 2 :
        printf("\n\t==============================================================");
        printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
        printf("\n\t||``````````````````````````````````````````````````````````||");
        printf("\n\t||                        PEMBAYARAN                        ||");
        printf("\n\t==============================================================");
        waktu_pemesanan();
        printf("\n\tNama Pelanggan    : %s", pelanggan_login.nama_pelanggan);
        printf("\n\tNama Pegawai      : %s", pegawai_yang_bertugas.nama_pegawai);
        printf("\n\t--------------------------------------------------------------");
        for(int j = 0; j < i; j++){
            printf("\n\tPesanan Anda ke-%d : %s", j+1, array_nama_menu[pesanan[j]-1]);
            printf("\n\tHarga Menu        : Rp %d", array_harga_menu[pesanan[j]-1]);
            printf("\n\tBanyak Pesanan    : %d", banyak_pesanan[j]);
            printf("\n\t--------------------------------------------------------------");
        }
        if(total_biaya > 500000){
            diskon = besar_diskon[0] * total_biaya;
        }else if(total_biaya > 400000){
            diskon = besar_diskon[1] * total_biaya;
        }else if(total_biaya > 250000){
            diskon = besar_diskon[2] * total_biaya;
        }else{
            diskon = 0;
        }
        total_bayar = total_biaya - diskon;
        printf("\n\tTotal Biaya       : Rp %d", total_biaya);
        printf("\n\tPotongan Harga    : Rp %d", diskon);
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tTotal Bayar       : Rp %d", total_bayar);
        printf("\n\t==============================================================");
        printf("\n\t                STRUK PEMBAYARAN TELAH DICETAK                ");
        printf("\n\t==============================================================");
        closing_cetak_bukti_pemesanan(total_biaya, diskon, total_bayar);
        ulang();
        break;
    }
}

void cetak_nama(){
	FILE *hasil;
	hasil = fopen("DataPesanan.txt", "a");
	fprintf(hasil, "\n\tNama Pelanggan    : %s", pelanggan_login.nama_pelanggan);
	fprintf(hasil, "\n\tNama Pegawai      : %s", pegawai_yang_bertugas.nama_pegawai);
	fprintf(hasil, "\n\t--------------------------------------------------------------");
	fclose(hasil);
}

void header_cetak_bukti_pemesanan(){
    FILE *insert = fopen("DataPesanan.txt", "a");
	fprintf(insert,"\n\t==============================================================");
	fprintf(insert,"\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	fprintf(insert,"\n\t||``````````````````````````````````````````````````````````||");
	fprintf(insert,"\n\t||                      BUKTI PEMESANAN                     ||");
	fprintf(insert,"\n\t==============================================================");
	fclose(insert);
	waktu_pembayaran();
	cetak_nama();
}

void isi_cetak_bukti_pemesanan(int pesanan, int banyak_pesanan, int sub_total, int i){
    FILE *insert = fopen("DataPesanan.txt", "a");
    fprintf(insert,"\n\tPesanan Anda ke-%d : %s", i+1, array_nama_menu[pesanan-1]);
    fprintf(insert,"\n\tHarga Menu        : Rp %d", array_harga_menu[pesanan-1]);
    fprintf(insert,"\n\tBanyak Pesanan    : %d", banyak_pesanan);
    fprintf(insert,"\n\tSub-total         : %d", sub_total);
    fprintf(insert,"\n\t--------------------------------------------------------------");
    fclose(insert);
}

void closing_cetak_bukti_pemesanan(int total_biaya, int diskon, int total_bayar){
    FILE *insert = fopen("DataPesanan.txt", "a");
	fprintf(insert,"\n\tTotal Biaya       : Rp %d", total_biaya);
	fprintf(insert,"\n\tPotongan Harga    : Rp %d", diskon);
	fprintf(insert,"\n\t--------------------------------------------------------------");
	fprintf(insert,"\n\tTotal Bayar       : Rp %d", total_bayar);
	fprintf(insert,"\n\t==============================================================");
	fclose(insert);
}

void ulang(){
    int menu;
    close();
    fflush(stdin);
    printf("\n\t==============================================================");
    printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
    printf("\n\t||``````````````````````````````````````````````````````````||");
    printf("\n\t||                           MENU                           ||");
    printf("\n\t||==========================================================||");
    printf("\n\t|| Apakah Anda Ingin Memesan Kembali ?                      ||");
    printf("\n\t||  [1] Pesan Lagi                                          ||");
    printf("\n\t||  [0] Keluar Program                                      ||");
    printf("\n\t==============================================================");
    printf("\n\tMasukkan Pilihan Anda : ");
	while(scanf("%d", &menu)==0 || menu < 0 || menu > 1){
        printf("\t--------------------------------------------------------------");
        printf("\n\tAngka yang Anda inputkan salah!");
        printf("\n\tMohon inputkan pilihan yang benar...");
        printf("\n\t--------------------------------------------------------------");
        printf("\n\tInputkan pilihan Anda: ");
        while((getchar())!='\n');
    }
	close();
	switch(menu){
case 1 :
        menu_cafe();
        break;
    case 0 :
        selesai();
        break;
    }
}

void selesai(){
    printf("\n\t==============================================================");
	printf("\n\t||         C U P  O'  J A N E  C O F F E E  S H O P         ||");
	printf("\n\t||``````````````````````````````````````````````````````````||");
	printf("\n\t||                TERIMAKASIH TELAH BERKUNJUNG              ||");
	printf("\n\t==============================================================");
	exit(0);
}