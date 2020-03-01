# Soal Praktikum 1
## Daftar Isi
- [Antre Belanja - AB](#antre-belanja)
- [Cari Terkecil - CT](#cari-terkecil)
- [Easy - EZ](#easy)
- [Koyer - KOYER](#koyer)

## Antre Belanja
| Time Limit | Memory Limit |
|---|:---|
| 1,5 seconds	| 16 MB |

Hari ini Bang Jali mencoba bekerja sambilan di suatu toko perbelanjaan terkemuka. Namun disana, semua pembelinya memiliki perilaku unik. Mereka sangat tidak efisien dalam membeli barang, karena dalam sekali antrian, mereka hanya akan membeli satu jenis barang dalam jumlah X dengan harga Y.

Selagi melayani pembeli, Bang Jali iseng-iseng ingin coba kepo tentang transaksi pembelinya. Dia ingin mencari tahu berapa rata-rata penjualan dari semua pembeli sejumlah P (0 < P < 10000) yang mengantri. Selain itu, dia juga kepingin tahu berapa jumlah barang dan jumlah harga per barang dari A pembeli awal (0 < A < P).

Bantu Bang Jali melakukan keisengannya!

#### Input Format
Baris pertama diberikan T sebagai testcase. Untuk setiap testcase ada 4 kemungkinan input :

```c
1 X Y
```
untuk memasukkan pembeli ke antrian, X (1 <= X <= 100000) merepresentasikan harga per barang, Y (1 <= X <= 1000) merepresentasikan barang yang diinputkan.
```c
2
```
menyatakan Bang Jali sudah selesai memproses pembeli terdepan, dan mengeluarkan pembeli terdepan dari antrian. Bila tidak ada pembeli, cetak "Yah habis :(" (tanpa tanda kutip).
```c
3
```
menghitung rata-rata dari total transaksi (harga per barang * barang dibeli) per jumlah pembeli.
```c
4 A
```
menghitung masing-masing harga per barang dan barang terbeli dari pembeli terdepan (dimulai dari 1) hingga pembeli ke A (1 <= A <= P).
#### Output Format
- Setiap input 3, cetak rata-rata dengan 4 tempat desimal dengan format "Rata-rata : R" dengan R adalah rata-rata. Dijamin di antrian pasti ada setidaknya 1 orang saat dihitung. (Hint : "%.4f")
- Setiap input 4, cetak dengan format "Harga Total : H, Jumlah Total : B", dengan H adalah harga per barang dan B adalah jumlah barang terbeli.

#### Sample Input
```c
8
1 200 3
1 300 4
1 400 6
1 500 6
4 2
3
2
3
```
#### Sample Output
```c
Harga Total : 500, Jumlah Total : 7
Rata-rata : 1800.0000
Rata-rata : 2200.0000
```
#### Explanation
Untuk testcase ke 5, cetak jumlah harga dari pembeli ke 1 sampai ke 2, jadi harga total = 200 + 300 = 500, jumlah total = 3 + 4 = 7.

Untuk testcase ke 6 dan 8, dihitung rata-rata dari nilai transaksi antrian.

#### Constraints
1 ≤ T ≤ 50
1 ≤ X ≤ 100000, 1 ≤ Y ≤ 1000
0 < P < 10000
1 <= A <= P
Semua input dipastikan bilangan bulat positif, kecuali nilai R

## Cari Terkecil
| Time Limit | Memory Limit |
|---|:---|
| 0,01 seconds	| 10 MB |

Cari nilai terkecil dalam setiap interval t bilangan.

#### Input Format
- baris pertama berisi integer n sebagai jumlah angka dalam baris
- baris berikutnya berisi integer t sebagai panjang interval
- baris berikutnya berisi n integer sebagai baris 

#### Output Format
outputkan setiap angka terkecil dalam interval dengan dipisahkan enter

#### Sample Input
```c
5
3
1 2 3 4 5
```
#### Sample Output
```c
1
2
3
```
#### Explanation
- interval 1 : 1 2 3 hasil : 1

- interval 2 : 2 3 4 hasil : 2

- interval 3 : 3 4 5 hasil : 3

tips : deque ,awas TLE

#### Constraints
1 ≤ n ≤ 1000000
1 ≤ t  ≤ 10000
t < n
1 ≤ k < 1000000

## Easy
| Time Limit | Memory Limit |
|---|:---|
| 1 seconds	| 50 MB |

Baris pertama terdapat N dan Q. N merupakan banyak stack dan Q adalah jumlah query.

Q baris berikutnya :

- `1 X V`  : Push `V` ke stack urutan ke-`X`
- `2 X`    : Pop stack urutan ke-`X`
- `3 L R`  : Print data terbesar kedua setelah penggabungangan stack [`L`, `R`]

Jika tidak ditemukan data outputkan “Tidak Ada!”

#### Sample Input
```c
3 10
1 1 2
1 1 4
3 1 2
1 3 3
1 2 6
2 1
3 1 3
2 2
2 1
3 1 2
```
#### Sample Output
```c
2
3
Tidak Ada!
```
#### Constraints
1 ≤ N ≤ 100
1 ≤ Q ≤ 10000
1 ≤ V ≤ 1000000
1 ≤ X ≤ N
1 ≤ L, R ≤ N

## Koyer
| Time Limit | Memory Limit |
|---|:---|
| 1 seconds	| 8 MB |

Ranoraa dan Okom sedang bermain suatu permainan yang bernama Jimmyjembz. Permainan ini merupakan permainan yang menyusun batu setinggi mungkin. Namun, jika ada batu yang lebih besar dari batu sebelumnya, maka batu sebelumnya akan hancur.

Bantulah Rranoraa dan Okom untuk memenangkan pertandingan tersebut

#### Input Format
T sebagai testcase, N sebagai banyak batu, B sebagai berat batu

#### Output Format
Menampilkan berat batu yang tersisa

#### Sample Input
```c
1
5
3 7 2 5 1
```
#### Sample Output
```c
7 5 1
```
#### Explanation
udah ya geperlu dijelasin lagi

#### Constraints
1 ≤ T ≤ 20
1 ≤ N ≤ 100
1 ≤ B ≤ 1000000
