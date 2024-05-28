#include <iostream>
#define max 10
using namespace std;

int i = 0;
int j;
int pilRute, pil, pilMaskapai;
long hargaTiket = 250000;
long totalHarga;
int jml;
bool bisnis;

struct dataAkun
{
    string username;
    string password;
    int pin;
}akun[max];

struct dataPenumpang
{
	string nama;
	string alamat;
	string noTelp;
	string tanggal;
}data;

void cetakTiket()
{
	dataPenumpang data[max];
	if (bisnis == true)
    {
        totalHarga = (hargaTiket + 250000) * jml;
        cout << "==== Tiket Pesawat ====\n";
		cout << "Total Harga Tiket: " << totalHarga << endl;
	}

    else
    {
		totalHarga = hargaTiket * jml;
		cout << "==== Tiket Pesawat ====\n";
		cout << "Total Harga Tiket: " << totalHarga << endl;
    }
	for (int i = 0; i < jml; i++)
    {
		cout << "==== Penumpang ke-" << i + 1 << " ====\n";
		cout << "Nama: " << data[i].nama << endl;
		cout << "Alamat: " << data[i].alamat << endl;
		cout << "No. Telp: " << data[i].noTelp << endl;
		cout << "Tanggal Keberangkatan: " << data[i].tanggal << endl;
        cout << "Nomor kursi penumpang ke - " << i + 1;
	}
}


void inputPenumpang()
{
	
	dataPenumpang data[max];
	cout << "==== Input Data Penumpang ====\n";
	cout << "Masukkan Jumlah Penumpang: ";
	cin >> jml;
	for (int i = 0; i < jml; i++)
	{
		cout << "==== Penumpang ke-" << i + 1 << " ====\n";
		cout << "Masukkan Nama Penumpang: ";
		cin >> data[i].nama;
		cout << "Masukkan Alamat Penumpang: ";
		cin >> data[i].alamat;
		cout << "Masukkan No. Telp Penumpang: ";
		cin >> data[i].noTelp;
		cout << "Masukkan Tanggal Keberangkatan: ";
		cin >> data[i].tanggal;
	}
	cout << "==== Data Penumpang ====\n";
	for (int i = 0; i < jml; i++)
	{
		cout << "==== Penumpang ke-" << i + 1 << " ====\n";
		cout << data[i].nama << endl;
		cout << data[i].alamat << endl;
		cout << data[i].noTelp << endl;
		cout << data[i].tanggal << endl;
	}
	cout << "Apakah data penumpang sudah benar? [y/n] : ";
    char pilChar;
    cin >> pilChar;
	if (pilChar == 'y')
	{
		cout << "Data penumpang berhasil disimpan\n";
		cetakTiket();
	}
    else
    {
        cout << "Data mana yang ingin anda ubah?\n";
        cout << "Masukkan Nomor Penumpang: ";
        cin >> pil;
        cout << "Masukkan Nama Penumpang: ";
        cin >> data[pil - 1].nama;
        cout << "Masukkan Alamat Penumpang: ";
        cin >> data[pil - 1].alamat;
        cout << "Masukkan No. Telp Penumpang: ";
        cin >> data[pil - 1].noTelp;
        cout << "Masukkan Tanggal Keberangkatan: ";
        cin >> data[pil - 1].tanggal;
		cout << "==== Data Penumpang ====\n";
		for (int i = 0; i < jml; i++)
        {
			cout << "==== Penumpang ke-" << i + 1 << " ====\n";
			cout << data[i].nama << endl;
			cout << data[i].alamat << endl;
			cout << data[i].noTelp << endl;
			cout << data[i].tanggal << endl;
		}
		cetakTiket();
    }
}


void pilihKelas()
{
    int pilKelas;
    do
    {
        cout << "==== Pilih Kelas Penerbangan ====\n";
        cout << "[1] Ekonomi\n";
        cout << "[2] Bisnis\n";
        cout << "[*] Masukkan Pilihan [1-2] : ";
        cin >> pilKelas;
        switch (pilKelas)
        {
        case 1:
            cout << "Anda memilih kelas Ekonomi\n";
			bisnis = false;
			inputPenumpang();
            break;
        case 2:
            cout << "Anda memilih kelas Bisnis\n";
			bisnis = true;
			inputPenumpang();
            break;
        default:
            cout << "Pilihan tidak tersedia\n";
            break;
        }
    } while (pilKelas != 1 && pilKelas != 2);
}

void maskapaiPenerbangan()
{
    do
    {
        cout << "==== Pilih Maskapai Penerbangan ====\n";
        cout << "[1] Garuda Indonesia\n";
        cout << "[2] Batik Air\n";
        cout << "Masukkan Pilihan [1 - 2] : ";
        cin >> pilMaskapai;
        if (pilMaskapai == 1)
        {
            cout << "Anda memilih Garuda Indonesia\n";
            pilihKelas();
        }
        else if (pilMaskapai == 2)
        {
            cout << "Anda memilih Batik Air\n";
            pilihKelas();
        }
        else
        {
            cout << "Pilihan tidak tersedia\n";
        }
    } while (pilMaskapai != 1 && pilMaskapai != 2);
}

void rutePenerbangan()
{
    do
    {
        cout << "==== Pilih Rute Penerbangan ====\n";
        cout << "[1] Jogjakarta - Aceh\n";
        cout << "[2] Jogjakarta - Palu\n";
        cout << "[*] Masukkan Pilihan [1-2] : ";
        cin >> pilRute;
        switch (pilRute)
        {
        case 1:
            cout << "Rute Penerbangan Jogjakarta - Aceh\n";
            maskapaiPenerbangan();
            break;
        case 2:
            cout << "Rute Penerbangan Jogjakarta - Palu\n";
            maskapaiPenerbangan();
            break;
        default:
            cout << "Pilihan tidak tersedia\n";
            break;
        }
    } while (pilRute != 1 && pilRute != 2);
}

void halamanAdmin()
{
    do
    {
        cout << "==== Halaman Admin ====\n";
	    cout << "[1] Lihat Data Penumpang\n";
	    cout << "[2] Lihat Data Akun\n";
	    cout << "[3] Keluar\n";
	    cout << "Masukkan Pilihan [1-3] : ";
	    cin >> pil;
	    switch (pil)
	    {
	    case 1:
		    cout << "==== Data Penumpang ====\n";
		    break;
	    case 2:
		    cout << "==== Data Akun ====\n";
		    break;
	    case 3:
		    cout << "==== EXIT ====\n";
		    break;
	    }
    } while (pil < 3);

}

void login()
{
    string usernameBaru, passwordBaru;
    int pinBaru;
    do
    {
        for (j = 0; j < max; j++)
        {
            cout << "Masukkan username: ";
            cin >> usernameBaru;
            cout << "Masukkan password: ";
            cin >> passwordBaru;
            cout << "Masukkan pin: ";
            cin >> pinBaru;
            if (usernameBaru == akun[j].username && passwordBaru == akun[j].password && pinBaru == akun[j].pin)
            {
                cout << "Login berhasil!" << endl;
                rutePenerbangan();
            }
            else if (usernameBaru == "admin" && passwordBaru == "admin" && pinBaru == 123)
            {
				halamanAdmin();
            }
            else
            {
                cout << "Login gagal!" << endl;
            }
        }

    } while (usernameBaru != akun[j].username && passwordBaru != akun[j].password && pinBaru != akun[j].pin || usernameBaru != "admin" && passwordBaru != "admin" && pinBaru != 123);
}

void buatAkun()
{
    for (i; i < max; i++) 
    {
        cout << "Masukkan username: ";
        cin >> akun[i].username;
        cout << "Masukkan password: ";
        cin >> akun[i].password;
        cout << "Masukkan pin: ";
        cin >> akun[i].pin;
        cout << "Akun berhasil dibuat!" << endl;
        cout << "username: " << akun[i].username << endl;
        cout << "Password: " << akun[i].password << endl;
        cout << "Pin: " << akun[i].pin << endl;
        goto x;
    }
x:
    cout << "Selamat anda berhasil membuat akun!" << endl;
    login();
}

int main()
{
    do
    {
        cout << "==== Aplikasi Pemesanan Tiket Pesawat ====\n";
        cout << "[1] Login\n";
        cout << "[2] Buat Akun\n";
        cout << "Masukkan Pilihan [1-2] : ";
        cin >> pil;
        if (pil == 1)
        {
            login();
        }
        else if (pil == 2)
        {
            buatAkun();
        }
        else
        {
            cout << "Pilihan tidak tersedia\n";
        }
    } while (pil != 1 && pil != 2);
}
