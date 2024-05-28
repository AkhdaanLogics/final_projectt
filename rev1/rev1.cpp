#include<iostream>
#define max 10
using namespace std;
long harga, hargaTotal;
int pil, i, lama;
string pilChar;

struct dataAkun
{
    string username;
    string password;
    int pin;
}dataAkun[max];

struct dataPenyewa
{
    string nama;
    string alamat;
    string noTelp;
    int lama;
    dataPenyewa* next;
};

void halamanUtama();
void adminCariDataPenyewa();
void dataUserAdmin();

void cariUsername() {
    string namaCari;
    bool found = false;
    cout << "Masukkan username yang dicari: ";
    cin >> namaCari;
    for (int i = 0; i < max; i++) {
        if (dataAkun[i].username == namaCari) {
            cout << "Username : " << dataAkun[i].username << endl;
            cout << "Password : " << dataAkun[i].password << endl;
            cout << "Pin : " << dataAkun[i].pin << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Username tidak ditemukan." << endl;
    }
    dataUserAdmin();
}

void totalHarga(int durasi) {
    hargaTotal = harga * durasi;
    cout << "Total harga : " << hargaTotal << endl;
    cout << "======================" << endl;
    halamanUtama();
}

void dataUserAdmin() {
    do
    {
        cout << "==== Halaman Admin ====\n";
        cout << "==== DATA AKUN ====\n";
        cout << "[1] Cari username\n";
        cout << "[2] Keluar\n";
        cout << "Masukkan Pilihan [1-2] : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            cariUsername();
            break;
        case 2:
            halamanUtama();
		default:
			cout << "Salah input\n";
			break;
        }
    } while (pil < 2);
}


/////// PER LINGLIST AN
struct linkedList {
    dataPenyewa* head;
    dataPenyewa* tail;
    int size;
} list;

void initLinkedList() {
    list.head = NULL;
    list.tail = NULL;
    list.size = 0;
}

bool kosongLinkedList() {
    return list.size == 0;
}

void tampilDataLinkedList() {
    if (!kosongLinkedList()) {
        dataPenyewa* current = list.head;
        while (current != NULL) {
            cout << "Nama     :" << current->nama << endl;
            cout << "ALamat   :" << current->alamat << endl;
            cout << "No Telp  :" << current->noTelp << endl;
            cout << "Lama     :" << current->lama << endl;
            cout << endl;
            current = current->next;
        }
    }
    else {
        cout << "Data Kosong" << endl;
    }
}

void enqueueBelakang() {
    dataPenyewa* newdata = new dataPenyewa();
    cout << "Masukan nama       : ";
    cin >> newdata->nama;
    cout << "Masukan alamat      : ";
    cin >> newdata->alamat;
    cout << "Masukan no telp      : ";
    cin >> newdata->noTelp;
    cout << "Masukan lama     : ";
    cin >> newdata->lama;
    newdata->next = nullptr;
    if (list.tail != nullptr) {
        list.tail->next = newdata;
    }
    list.tail = newdata;
    if (list.head == NULL) {
        list.head = newdata;
    }
    list.size++;
    totalHarga(newdata->lama);
}

void dequeueDepan() {
    if (!kosongLinkedList()) {
        dataPenyewa* temp = list.head;
        cout << "Data penyewa dibawah ini membatalkan sewa" << endl;
        cout << "Nama       :" << temp->nama << endl;
        cout << "Alamat     :" << temp->alamat << endl;
        cout << "No telp    :" << temp->noTelp << endl;
        cout << "Lama       :" << temp->lama << endl;
        list.head = list.head->next;
        delete temp;
        list.size--;
        if (list.size == 0) {
            list.tail = nullptr;
        }
    }
    else {
        cout << "Antrian Kosong" << endl;
    }
}

void dequeueTengah(int posisi) {
    if (posisi <= 0 || posisi > list.size) {
        cout << "Posisi tidak valid" << endl;
        return;
    }
    if (posisi == 1) {
        dequeueDepan();
        return;
    }
    dataPenyewa* current = list.head;
    for (int i = 1; i < posisi - 1; i++) {
        current = current->next;
    }
    dataPenyewa* temp = current->next;
    current->next = temp->next;
    if (temp->next == nullptr) {
        list.tail = current;
    }
    cout << "Data penyewa dibawah ini membatalkan sewa" << endl;
    cout << "Nama       :" << temp->nama << endl;
    cout << "Alamat     :" << temp->alamat << endl;
    cout << "No telp    :" << temp->noTelp << endl;
    cout << "Lama       :" << temp->lama << endl;
    delete temp;
    list.size--;
}

void dequeueBelakang() {
    if (list.size <= 1) {
        dequeueDepan();
        return;
    }
    dataPenyewa* current = list.head;
    while (current->next != list.tail) {
        current = current->next;
    }
    cout << "Data penyewa dibawah ini membatalkan sewa" << endl;
    cout << "Nama       :" << list.tail->nama << endl;
    cout << "Alamat     :" << list.tail->alamat << endl;
    cout << "No telp    :" << list.tail->noTelp << endl;
    cout << "Lama       :" << list.tail->lama << endl;
    delete list.tail;
    list.tail = current;
    list.tail->next = NULL;
    list.size--;
}

/////// SAMPAI DISINI PER LINGLIST AN NYA
void urutanLamaSewa() {
    dataPenyewa* temp;
    for (int i = 1; i < list.size; i++) {
        temp = list.head;
        for (int j = 0; j < list.size - i; j++) {
            if (temp->lama > temp->next->lama) {
                string namaTemp = temp->nama;
                string alamatTemp = temp->alamat;
                string noTelpTemp = temp->noTelp;
                int lamaTemp = temp->lama;

                temp->nama = temp->next->nama;
                temp->alamat = temp->next->alamat;
                temp->noTelp = temp->next->noTelp;
                temp->lama = temp->next->lama;

                temp->next->nama = namaTemp;
                temp->next->alamat = alamatTemp;
                temp->next->noTelp = noTelpTemp;
                temp->next->lama = lamaTemp;
            }
            temp = temp->next;
        }
    }
    cout << "Daftar setelah diurutkan berdasarkan lama sewa:" << endl;
    tampilDataLinkedList();
}


void dataPenyewaAdmin() {
    do
    {
        cout << "==== Halaman Admin ====\n";
        cout << "==== DATA PENYEWA ====\n";
        cout << "[1] Gulfstream G650\n";
        cout << "[2] Bombardier Global 7500\n";
        cout << "[3] Keluar\n";
        cout << "Masukkan Pilihan [1-3] : ";
        cin >> pil;
        switch (pil)
        {
            case 1:
                do
                {
                    cout << "==== Data Penyewa ====\n";
                    cout << "==== Gulfstream G650 ====\n";
                    cout << "[1] Cari nama penyewa\n";
                    cout << "[2] Tampilkan semua data penyewa\n";
                    cout << "[3] Kick penyewa\n";
                    cout << "[4] Urutkan berdasakan lama\n";
                    cout << "[5] Exit\n";
                    cout << "Masukkan Pilihan [1-4] : ";
                    cin >> pil;
                    switch (pil)
                    {
                        case 1:
                            adminCariDataPenyewa();
                            break;
                        case 2:
                            tampilDataLinkedList();
                            break;
                        case 3:
                            tampilDataLinkedList();
                            cout << "Masukkan posisi penyewa yang ingin di-kick: ";
                            int pos;
                            cin >> pos;
                            dequeueTengah(pos);
                            break;
                        case 4:
                            urutanLamaSewa();
                            break;
                        case 5:
                            halamanUtama();
                        default:
                            cout << "Salah input\n";
                            break;
                    }
                }
                while (pil < 4);

            case 2:
                cout << "==== Data Penyewa ====\n";
                cout << "==== Bombardier Global 7500 ====\n";

                break;
            case 3:
                halamanUtama();
                break;
		    default:
			    cout << "Salah input\n";
			    break;
        }
    } 
    while (pil < 3);
}

void halamanAdmin() {
    do
    {
        cout << "==== Halaman Admin ====\n";
        cout << "[1] Lihat Data Penyewa\n";
        cout << "[2] Lihat Data Akun\n";
        cout << "[3] Keluar\n";
        cout << "Masukkan Pilihan [1-3] : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            dataPenyewaAdmin();
            break;
        case 2:
            cout << "==== Data Akun ====\n";
            for (int i = 0; i < max; i++) {
                cout << "Username: " << dataAkun[i].username << endl;
                cout << "Password: " << dataAkun[i].password << endl;
                cout << "PIN: " << dataAkun[i].pin << endl;
            }
            break;
        case 3:
            halamanUtama();
            break;
		default:
			cout << "Salah input\n";
			break;
        }
    } while (pil < 3);
}

void adminCariDataPenyewa() {
    string namaCari;
    bool found = false;
    cout << "Masukkan nama penumpang yang dicari: ";
    cin >> namaCari;
    if (!kosongLinkedList()) {
        dataPenyewa* current = list.head;
        while (current != NULL) {
            if (current->nama == namaCari) {
                cout << "Nama: " << current->nama << endl;
                cout << "Alamat: " << current->alamat << endl;
                cout << "No. Telp: " << current->noTelp << endl;
                found = true;
            }
            current = current->next;
        }
    }
    if (!found) {
        cout << "Data penumpang tidak ditemukan." << endl;
    }
    halamanAdmin();
}

void halamanPenyewa() {
    do
    {
        cout << "==== Pilihan Private Jet ====\n";
        cout << "[1] Gulfstream G650\n";
        cout << "[2] Bombardier Global 7500\n";
        cout << "[3] Keluar\n";
        cout << "Masukkan Pilihan [1-3] : ";
        cin >> pil;
        switch (pil)
        {
        case 1:
            do
            {
                cout << "==== Gulfstream G650 ====\n";
                cout << "Kabin yang luas dengan interior mewah, kursi yang dapat\ndiatur menjadi tempat tidur, dapur lengkap dengan\nperalatan makan, kamar mandi pribadi dengan shower, sistem hiburan\nterintegrasi dengan layar besar, dan konektivitas\ninternet tinggi.\n";
                cout << "Harga Sewa : 3 juta/jam\n";
                cout << "Apakah anda ingin menyewa pesawat terebut : \n";
                cout << "[1] Yakin banget\n";
                cout << "[2] kembali\n";
                cout << "Masukkan Pilihan [1-2] : ";
                harga = 3000000;
                cin >> pil;
                if (pil == 1) {
                    enqueueBelakang();
                }
                else if (pil == 2) {
                    halamanPenyewa();
                }
            } while (pil < 2);
            cout << "Pilihan tidak tersedia\n";
            break;

        case 2:
            do
            {
                cout << "==== Bombardier Global 7500 ====\n";
                cout << "Kabin yang sangat luas dengan banyak ruang pribadi, kursi\nyang dapat diubah menjadi tempat tidur, dapur lengkap dengan\nperalatan makan, kamar mandi mewah dengan shower, ruang\npertemuan atau ruang kerja yang dilengkapi\ndengan teknologi konferensi, sistem\nhiburan canggih dengan layar besar, dan konektivitas internet super cepat.\n";
                cout << "Harga Sewa : 4 juta/jam\n";
                cout << "Apakah anda ingin menyewa pesawat terebut : \n";
                cout << "[1] Yakin banget\n";
                cout << "[2] kembali\n";
                cout << "Masukkan Pilihan [1-2] : ";
                harga = 4000000;
                cin >> pil;
                if (pil == 1) {
                    enqueueBelakang();
                }
                else if (pil == 2) {
                    halamanPenyewa();
                }
            } while (pil < 2);
            cout << "Pilihan tidak tersedia\n";
            break;

        case 3:
            halamanUtama();
            break;
        }
    } while (pil < 3);
    cout << "Pilihan tidak tersedia\n";
}

void buatAkun() {
    for (i = 0; i < max; i++)
    {
        cout << "Masukkan username: ";
        cin >> dataAkun[i].username;
        cout << "Masukkan password: ";
        cin >> dataAkun[i].password;
        cout << "Masukkan pin: ";
        cin >> dataAkun[i].pin;
        goto X;
    }
X:
    cout << "Akun berhasil dibuat!" << endl;
    halamanUtama();
}

void login() {
    string usernameBaru, passwordBaru;
    int pinBaru;

    cout << "Masukkan username: ";
    cin >> usernameBaru;
    cout << "Masukkan password: ";
    cin >> passwordBaru;
    cout << "Masukkan pin: ";
    cin >> pinBaru;

    for (i = 0; i < max; i++)
    {
        if (usernameBaru == dataAkun[i].username && passwordBaru == dataAkun[i].password && pinBaru == dataAkun[i].pin)
        {
            cout << "Login berhasil!" << endl;
            halamanPenyewa();
        }
        else if (usernameBaru == "admin" && passwordBaru == "admin" && pinBaru == 123)
        {
            cout << "Login Sebagai Admin" << endl;
            halamanAdmin();
        }
    }
    cout << "Login gagal!" << endl;
    halamanUtama();
}

void halamanUtama() {
    do
    {
        cout << "==== Aplikasi Pemesanan PJ ====\n";
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
    } while (pil != 1 && pil != 2);
    cout << "Pilihan tidak tersedia\n";
}

int main() {
    halamanUtama();
}
