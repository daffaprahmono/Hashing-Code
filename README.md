# *Hashing* menggunakan SHA_256
Projek ini bertujuan untuk *generate hash code* dari data "flow:2.6L/min", lalu menyimpannya dalam file .txt sebagai simulasi pengiriman data. Lalu data akan diverifikasi dengan membandingkan data yang dikirim dan &hash code& nya.

## Tutorial Penggunaan
Pastikan semua file berada dalam folder yang sama

#### List File:
* pengirim.cpp
* penerima.cpp
* sha256.cpp
* sha256.h

#### Langkah Penggunaan
Pertama, *compile* kedua file pengirim.cpp dan penerima.cpp untuk menghasilkan file *executable*
```
g++ .\pengirim.cpp .\sha256.cpp -o pengirim
g++ .\penerima.cpp .\sha256.cpp -o penerima
```
Setelah kedua file tersebut selesai di*compile* maka akan terbentuk dua file *executable* yang bernama **pengirim.exe** dan **penerima.exe**.

Lalu jalankan file **pengirim.exe** terlebih dahulu menggunakan *command*:
```
./pengirim
```
Setelah file **pengirim.exe** selesai dijalankan, maka akan muncul file **data_kirim.txt** sebagai data beserta hasil *hashing*nya.

Lalu baru jalankan file **penerima.exe** dengan *command*:
```
./penerima
```
File **penerima.exe** akan membaca nilai dair file **data_kirim.txt** dan memvalidasi data menggunakan *hash code* yang telah di*generate* sebelumnya.

#### Output
Berikut merupakan contoh *output* yang akan dihasilkan.

**1. pengirim.exe**
```
[Client] Data dan hash berhasil dikirim (disimpan ke file).
```
Data disimpan pada file **data_kirim.txt** yang berisi:
```
Flow:2.6L/min|1745935899
3074288cf1cb058b48927a22ffff4df04ec2b72e55c94d40a1a64ab752a79624
```

**2. penerima.exe**

Terdapat dua skenario saat file **penerima.exe** dijalankan:

Pertama, saat data yang dikirim dan diterima sesuai (tidak ada *error*).
```
[Server] Data diterima: Flow:2.6L/min|1745933022
[Server] Hash diterima: 6c25f9b772103f16a16ee5bfa25991b61cbb02574fc974fce6dbcfb39da9a9fa
[Server] Hash dihitung: 6c25f9b772103f16a16ee5bfa25991b61cbb02574fc974fce6dbcfb39da9a9fa
[Server] Data valid, tidak terjadi perubahan.
```

Kedua, saat data yang dikirim dan diterima tidak sesuai (ada *error* atau perubahan)
```
[Server] Data diterima: Flow:28.6L/min|1745933824
[Server] Hash diterima: eb4515da38bb32d83b8b1ffb64e26f17739b885608e5f4bf1791cd94f03110fb
[Server] Hash dihitung: 6b3497b39c18fc82593edeada5f0316f200fd16e640c44d41ed115ede534c3b5
[Server] Data rusak atau telah dimodifikasi!
```
