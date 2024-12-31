#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Fungsi untuk mengecek apakah file ada
void checkFile() {
    fstream file("users.txt", ios::app);
    file.close();
}

// Fungsi untuk registrasi mahasiswa
void registerUser() {
    cout << "\n=== Registrasi Mahasiswa ===" << endl;
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    checkFile();

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string registeredUsername, registeredPassword;
        getline(ss, registeredUsername, ',');
        getline(ss, registeredPassword, ',');

        if (username == registeredUsername) {
            cout << "Username sudah terdaftar! Coba lagi.\n" << endl;
            file.close();
            return;
        }
    }
    file.close();

    ofstream outfile("users.txt", ios::app);
    outfile << username << "," << password << endl;
    outfile.close();

    cout << "Registrasi berhasil! Silakan login.\n" << endl;
}

// Fungsi untuk login mahasiswa
bool loginUser() {
    cout << "\n=== Login Mahasiswa ===" << endl;
    string username, password;

    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: ";
    cin >> password;

    checkFile();

    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string registeredUsername, registeredPassword;
        getline(ss, registeredUsername, ',');
        getline(ss, registeredPassword, ',');

        if (username == registeredUsername && password == registeredPassword) {
            cout << "Login berhasil! Selamat datang, " << username << ".\n" << endl;
            file.close();
            return true;
        }
    }
    file.close();

    cout << "Login gagal! Username atau password salah.\n" << endl;
    return false;
}

// Fungsi utama
int main() {
    int choice;

    do {
        cout << "=== Sistem Login dan Registrasi UNESA ===" << endl;
        cout << "1. Registrasi Mahasiswa" << endl;
        cout << "2. Login Mahasiswa" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu (1/2/3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan sistem ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n" << endl;
        }
    } while (choice != 3);

    return 0;
}