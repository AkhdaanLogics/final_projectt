#include <iostream>
#define max 10
using namespace std;

struct dataAkun
{
    string nama;
    string password;
    int pin;
}akun[max];



int i = 0;
int j;
int pilRute, pil, pilMaskapai;

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
            break;
        case 2:
            cout << "Anda memilih kelas Bisnis\n";
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

void login()
{
    string namaBaru, passwordBaru;
    int pinBaru;
    do
    {
        for (j = 0; j < max; j++)
        {
            cout << "Masukkan nama: ";
            cin >> namaBaru;
            cout << "Masukkan password: ";
            cin >> passwordBaru;
            cout << "Masukkan pin: ";
            cin >> pinBaru;
            if (namaBaru == akun[j].nama && passwordBaru == akun[j].password && pinBaru == akun[j].pin)
            {
                cout << "Login berhasil!" << endl;
                rutePenerbangan();
            }
            else if (namaBaru == "admin" && passwordBaru == "admin" && pinBaru == 123)
            {
                cout << "Halaman Admin\n";
            }
            else
            {
                cout << "Login gagal!" << endl;
            }
        }

    } while (namaBaru != akun[j].nama && passwordBaru != akun[j].password && pinBaru != akun[j].pin || namaBaru != "admin" && passwordBaru != "admin" && pinBaru != 123);
}

void buatAkun()
{
    for (i; i < max; i++) // Fix: Use [max] instead of 10
    {
        cout << "Masukkan nama: ";
        cin >> akun[i].nama;
        cout << "Masukkan password: ";
        cin >> akun[i].password;
        cout << "Masukkan pin: ";
        cin >> akun[i].pin;
        cout << "Akun berhasil dibuat!" << endl;
        cout << "Nama: " << akun[i].nama << endl;
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
