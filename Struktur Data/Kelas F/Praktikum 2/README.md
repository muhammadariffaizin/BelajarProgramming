# Soal Praktikum 2 Kelas F
## Daftar isi
- [Brembo dan Lahan Baru 2 - BLAND2](#brembo-dan-lahan-baru-2)
- [Brembo dan BST Lamp - BSTLAMP](#brembo-danbst-lamp)
- [Luffy Menemukan Pohon Buah Setan - LMBS](#luffy-menemukan-pohon-buah-setan)
- [Mahmood Terjebak di Penjara - MTDP](#mahmood-terjebak-di-penjara)
- [Silsilah Keluarga MudMud - SKM](#silsilah-keluarga-mudmud)

## Brembo dan Lahan Baru 2
| Time Limit | Memory Limit |
|---|:---|
| 0,6 seconds	| 32 MB |

Setelah sukses sebagai petani, kini lahan Brembo telah berkembang pesat. Saat ini, ia memiliki lahan baru tak jauh dari tempat tinggalnya. Lahan baru Brembo berbentuk berbeda dari sebelumnya dengan luas ∞ hektare. Jika diilustrasikan, lahan baru Brembo berbentuk seperti gambar di bawah.

![BLAND2](img/BLAND2.png)

_Satu kotak menggambarkan satu lahan_

Brembo juga bekerja sebagai **Primary Botanist** di **Tece 19 Institute**. Disini, Brembo akan diberikan N daftar kerja dengan gajinya masing-masing (s_i). Ia diharuskan memilih setidaknya satu pekerjaan yang tersedia dari daftar. Jika ia memilih lebih dari satu pekerjaan, maka pekerjaan-pekerjaan tersebut haruslah berurutan dalam daftar. Selain itu, Brembo juga diberikan M kesempatan untuk mengubah gaji pekerjaan i (s_i). Diterapkan juga sistem asuransi dengan cara memotong sebanyak K dari gaji pada masing-masing pekerjaan yang telah dipilih.

Brembo ingin memasang pagar pada lahan barunya menggunakan gaji pertama hasil bekerja di perusahaan tersebut. Sama seperti lahan sebelumnya, ia hanya mau menggunakan jumlah pagar seminimum mungkin. Untuk itulah, Brembo telah membuat sebanyak Q skenario perhitungan. Terdapat dua jenis skenario, meliputi :
1. Menggunakan hak untuk mengubah gaji pada pekerjaan ke-i (s_i), atau
2. Menghitung maksimum lahan yang dapat dipagari jika ia memilih pekerjaan i hingga j (i,j).
Untuk mempermudah perhitungan, ia memutuskan untuk membuat program sederhana untuk mengetahui hasil dari masing-masing skenario.
> Challenge: Kerjakan soal ini tanpa menggunakan alokasi dinamis/heap.
#### Format Input
Baris pertama terdapat bilangan N,M dan K. Masing-masing adalah banyaknya daftar pekerjaan, banyaknya kesempatan untuk mengubah gaji dan biaya asuransi. Pada baris kedua, terdapat bilangan s_1,s_2,s_3,…,s_N yang menyatakan gaji untuk masing-masing pekerjaan (dipisahkan spasi). Baris ketiga adalah Q, jumlah skenario.

Q baris berikutnya adalah deskripsi skenario. Masing-masing formatnya dapat berupa :
* 1 i X, yakni mengubah gaji pekerjaan ke-i (s_i) 1≤i≤N dengan nilai X.
* 2 i j, yakni menghitung berapa maksimum lahan yang bisa dibangun pagar sesuai pada deskripsi (1≤i≤j≤N).
#### Format Output
Pada masing-masing skenario, cetak output berupa string “Kasus #x: ” dimana x adalah skenario ke-x dimulai dari 1 kemudian diikuti dengan  :
* Untuk skenario jenis 1, cetak string “ok” jika berhasil mengubah gaji, sebaliknya cetak “gagal” jika gagal.
* Sedangkan skenario jenis 2, cetak satu bilangan berupa maksimum lahan yang bisa dibangun pagar.

#### Contoh Input
```c
5 1 3
6 7 4 10 12
5
2 1 3
1 1 11
2 1 3
1 4 15
2 2 5
```

#### Contoh Output
```c
Kasus #1: 2
Kasus #2: ok
Kasus #3: 4
Kasus #4: gagal
Kasus #5: 7
```

##### Batasan
* 1<N,Q≤10^6
* 1≤M≤10^5
* 1≤K≤10^4
* 1≤s_i≤10^8
* Skenario 1: 1≤i≤N dan 1≤X≤10^8
* Skenario 2: 1≤i≤j≤N

## Brembo dan BST Lamp
## Luffy Menemukan Pohon Buah Setan
## Mahmood Terjebak di Penjara
## Silsilah Keluarga MudMud
