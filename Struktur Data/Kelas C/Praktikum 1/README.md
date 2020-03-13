# Soal Praktikum 1 Kelas C
## Daftar Isi
- [Genap Ganjil - GG](#genap-ganjil)
- [Nanti Kita Menyebrang Sungai Hari Ini - NKMSHI](#nanti-kita-menyebrang-sungai-hari-ini)
- [Nanti Kita Pikirkan Deskripsinya Kapan Kapan - NKPDKK](#nanti-kita-pikirkan-deskripsinya-kapan-kapan)
- [Nanti Kita Syukuran Hari Ini - NKSHI](#nanti-kita-syukuran-hari-ini)

## Genap Ganjil
| Time Limit | Memory Limit |
|---|:---|
| 1 seconds	| 8 MB |
Urutkan nomor-nomor yang diinputkan. Outputkan nomor-nomor genap yang diurutkan secara ascending diikuti oleh nomor-nomor ganjil yang diurutkan secara descending. 

#### Input Format 
Baris pertama adalah N. N baris berikutnya adalah nomor yang akan diurutkan. 

#### Output Format 
Setiap nomor yang telah diurutkan berdasarkan kriteria tersebut dioutputkan per baris. 

#### Sample Input
```c
10 
4 
32 
34 
543 
3456 
654 
567 
87 
6789 
98 
```

#### Sample Output
```c
4 
32 
34 
98 
654 
3456 
6789 
567 
543 
87 
```

#### Constraints 
1 ≤ N ≤ 1000

## Nanti Kita Menyebrang Sungai Hari Ini
| Time Limit | Memory Limit |
|---|:---|
| 1 seconds	| 64 MB |

Terdapat sebuah sungai yang memisahkan dua ~~pasang kekasih~~ buah daratan. Satu-satunya cara untuk sampai dari daratan satu ke daratan yang lainnya adalah dengan menggunakan sebuah kapal. 

Sebuah kapal dapat menampung N orang penumpang dalam sekali jalan(tidak termasuk pengemudinya). Untuk sekali menyeberang,dibutuhkan waktu selama T menit. Kapal akan terus menyeberang selama ada setidaknya SATU penumpang di salah satu daratan. Setiap kali sampai di satu daratan, kapal akan mengangkut N orang penumpang, lalu kembali berlayar. Jika terdapat lebih dari N penumpang yang telah menunggu,maka kapal akan memprioritaskan orang yang datang lebih cepat. 

Jika tidak ada orang yang menunggu di salah satu daratan, kapal akan menunggu sampai ada yang datang, lalu pergi ke daratan dimana orang itu ada, lalu kembali mengantarkannya. 

Untuk setiap M orang yang akan menyeberang, tentukan pada menit keberapa orang tersebut sampai ke tujuannya. 

#### Format Masukan

Baris pertama berisi sebuah bilangan Q yang menyatakan banyaknya testcase. 

Untuk setiap testcase, baris pertama akan berisi 3 buah bilangan N,T dan M seperti yang dijelaskan pada deskripsi 

M baris setelahnya berisi sebuah bilangan K dan sebuah string “kiri” atau “kanan” yang menyatakan waktu orang tersebut datang ke antrian serta posisi daratan tempat ia mengantri. 

Asumsikan kapal awalnya berada di daratan sebelah kiri 

#### Format Keluaran 

Untuk setiap testcase, keluarkan M buah bilangan yang masing-masing merupakan waktu orang ke-i sampai ke tujuannya. 

Keluarkan sebuah baris kosong diantara tiap testcase kecuali testcase terakhir. 

#### Batasan 
1 <= N,M,T <= 100000 

#### Contoh Masukan
```c
2 
2 10 10 
0 kiri 
10 kiri 
20 kiri 
30 kiri 
40 kiri 
50 kiri 
60 kiri 
70 kiri 
80 kiri 
90 kiri 
2 10 3 
10 kanan 
25 kiri 
40 kiri 
```

#### Format Keluaran
```c
10 
30 
30 
50 
50 
70 
70 
90 
90 
110 

30 
40 
60 
```

## Nanti Kita Pikirkan Deskripsinya Kapan Kapan - NKPDKK
| Time Limit | Memory Limit |
|---|:---|
| 1 seconds	| 64 MB |

Diberikan sebuah array A berisi N buah bilangan. Tentukan total value dari setiap subarray sepanjang K dari array A. 

Subarray dari array A adalah kumpulan bilangan yang memiliki indeks yang terurut. Dalam kata lain sebuah subarray berukuran K dapat dinotasikan sebagai A[i], A[i + 1], A[i + 2], .. A[i + k – 1] untuk suatu nilai i 

_Value_ dari sebuah subarray adalah nilai maksimal yang ada pada subarray tersebut 

#### Format Masukan 

Baris pertama berisi sebuah bilangan N dan K seperti yang sudah dijelaskan 

Baris berikutnya berisi N buah bilangan yang merupakan elemen dari array A 

#### Format Keluaran 

Sebuah baris berisi sebuah bilangan seperti yang dijelaskan di deskripsi

#### Batasan 
1 <= N,K,A[i] <= 1000000 

#### Contoh Masukan 
```c
6 4 
1 2 3 4 5 6 
```
#### Contoh Keluaran 
```c
15
```

## Nanti Kita Syukuran Hari Ini
| Time Limit | Memory Limit |
|---|:---|
| 3 seconds	| 64 MB | 

Rumah Phan hari ini kedatangan banyak tamu karena ia sedang menggelar syukuran karena ia diterima menjadi admin lab Kimia. Ia pun mengundang semua admin lab lain untuk datang ke rumahnya dan ia meminta setiap lab untuk mengirimkan nama dari admin-adminnya yang akan datang sebelum acara dimulai. 

Ini ternyata justru menjadi masalah karena seperti orang-orang Indonesia pada umumnya, setiap lab justru terlambat mengirimkan daftar nama adminnya dan malah mengirimkannya ditengah-tengah acara. 

Dan ini menjadi masalah untuk Phan karena ia tidak tau bagaimana cara agar dia dapat menyimpan dan mengakses data-data tersebut dengan efisien karena dia belum lancer ngoding ☹ 

Anda yang terkenal sebagai programmer hebat pun dimintai tolong oleh Phan untuk menyelesaikan masalahnya ini. Sebagai bayaran, Phan akan memberi tahu salah satu asdos mu untuk memberikan kamu nilai 100 untuk salah satu soal pada praktikummu.

#### Format Masukan 
Baris pertama berisi sebuah bilagan Q yang melambangkan query. 

Q baris berikutnya berisi salah satu dari 2 buah query yang berbentuk 
1. 1 K S1 S2 S3 ... Sk yang berarti terdapat sebuah lab yang baru mengirimkan data adminnya yang berjumlah K orang beserta nama-namanya. 
2. 2 A B yang berarti Phan ingin tau nama admin pada urutan ke-B yang dikirim oleh lab ke-A. 

#### Format Keluaran 
Untuk setiap query tipe 2, keluarkan nama admin seperti yang diminta atau keluarkan -1 apabila tidak ada. 

#### Batasan 
* 1 <= Q <= 10^5
* 1 <= |Si| <= 10 
* Jumlah K untuk seluruh Query tidak lebih dari 10
* Pasti ada setidaknya 1 buah query tipe 2 

#### Contoh Masukan 
```c
8
1 3 Pan Mus Hainnes 
1 2 Dila Ardi 
2 1 3 
2 3 1 
1 2 Json Leeta 
1 4 Pisi Elsi Esti Eva 
2 3 2 
2 5 3 
```

#### Contoh Keluaran 
```c
Hainnes 
-1 
Leeta 
-1 
```
