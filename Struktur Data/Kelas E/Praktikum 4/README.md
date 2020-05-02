# Soal Praktikum 4 Kelas E
## Daftar Isi
- [Baney Language](#baney-language)
- [Concert Ticket](#concert-ticket)
- [Dua Indeks](#dua-indeks)
- [Fight Against Disease](#fight-against-disease)

## Baney Language
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Baney ingin membuat sebuah bahasa baru. Pada BaneyLanguage terdapat rules untuk setiap kata yang dapat dibuat. Pada mulanya Baney akan memiliki kata dengan length 1 yang terdiri dari sebuah huruf alphabet 'a' hingga 'z'. Kemudian untuk kata dengan length 2 dan seterusnya akan didefinisikan bahwa kata tersebut merupakan BaneyLanguage jika dan hanya jika untuk setiap karakternya memenuhi rule yang telah ditetapkan. Rule tersebut adalah untuk setiap huruf C<sub>i</sub> yang ada, maka huruf C<sub>j</sub> merupakan huruf selanjutnya yang valid membentuk BaneyLanguage. Dengan rule yang telah didefinisikan tersebut, Baney penasaran, berapakah kata dengan length n yang dapat dibuat untuk tiap huruf terakhir.

#### Input Format
Baris pertama berisi bilangan bulat M yang menyatakan banyak rules yang ada.

Untuk M baris selanjutnya berisikan dua buah karakter C<sub>i</sub> dan C<sub>j</sub> yang menandakan bahwa untuk tiap huruf C<sub>i</sub>, maka huruf C<sub>j</sub> merupakan huruf selanjutnya yang valid. Baris selanjutnya berisi q yang menunjukkan banyaknya kueri. Untuk tiap kueri q, terdiri dari sebuah bilangan n yang menunjukkan panjang kata yang akan dibentuk.

#### Constraints
* 1 ≤ q ≤ 100
* 1 ≤ n ≤ 10<sup>9</sup>

#### Output Format
Untuk tiap kueri, keluarkan banyaknya kata dengan panjang n untuk tiap huruf terakhir 'a' hingga 'z'. Karena output bisa saja besar maka hasinya di MOD 10^9+7

#### Sample Input 0
```c
4
x y
x z
y z
z x
2
2
3
```

#### Sample Output 0
```c
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 1 2
```
#### Explanation 0
Pada contoh tersebut huruf dengan panjang 2 yang dapat terbentuk adalah zx, xy, yz, dan xz

## Concert Ticket
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Suatu organisasi sedang mengadakan undian berhadiah. Sudah pasti Lily akan ikut karena jika ia memenangkan undian ini, maka ia akan mendapat tiket konser dari penyanyi favoritnya. Tetapi tentu saja kemungkinan untuk memenangkan undian ini tidaklah besar. Untung saja Lily punya banyak koneksi sehingga ia memiliki "orang dalam" di organisasi tersebut.

Cara kerja undian adalah sebagai berikut 
- Untuk menginputkan nomor, tiap orang hanya perlu mengechat angka yang dipilihnya ke kontak dari organisasi (kebetulan kenalan Lily)
- Nomor yang boleh diinputkan ada dalam range 1 - 1.000.000
- Dari semua nomor tersebut, organisasi akan memilih orang yang menginputkan nomor terkecil ke-Y

Oleh karena itu, Lily akan mengechat kenalannya dalam organisasi untuk tahu nomor terkecil ke-Y sekarang nomor berapa. Sehingga ia dapat menginputkan nomor yang akan membuatnya menang undian ketika sudah dekat dengan waktu terakhir undian ditutup.

Bantulah kenalan Lily untuk membuat program yang akan menampilkan bilangan terkecil ke-Y jika Lily mengechat dia.

#### Input Format
Baris pertama berupa testcase

Baris kedua berupa X dan Y, dimana X adalah banyak chat dan Y adalah index ke-Y terkecil dari bilangan-bilangan sejumlah X yang diinputkan

Baris selanjutnya berupa Zi sebanyak X (Z1, Z2, ..., Zx)

Zi dapat berupa isi chat dalam range 1 - 1.000.000 (tandanya orang lain chat nomor yang dipilih mereka) atau dapat berupa isi chat angka 0 (tandanya Lily sedang mengechat kenalannya dan ingin tahu nomor terkecil ke-Y sekarang)

#### Constraints
Testcase, X, Y, Zi = Integer

#### Output Format
Jika Zi = 0 maka keluarkan bilangan terkecil ke-Y

Jika Zi = 0 tetapi bilangan yang diinputkan belum sebanyak Y atau lebih, maka outputkan -1

#### Sample Input 0
```c
2
2 1
79
0
6 2
1988
0
3571
0
103
0
```

#### Sample Output 0
```c
79
-1
3571
1988
```

## Dua Indeks
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Diberikan array, cari i dan j, yaitu indeks pada array yang apabila isi dari array dengan indeks tersebut dijumlah bernilai k. Dengan catatan:
* i < j.
* i harus seminimal mungkin.

#### Input Format
Baris pertama berisi bilangan bulat N, banyaknya element pada array

Baris kedua berisi N buah bilangan bulat, element-element pada array (berurutan)

Baris ketiga berisi bilangan bulat T, banyaknya testcase

T baris berikutnya berisi bilangan bulat K, nilai yang dicari

#### Constraints
* 0 ≤ N ≤ 1000000
* 0 < T ≤ 10000
* 0 < k ≤ 2^31-1

#### Output Format
Untuk setiap testcase keluarkan i dan j (berurutan), dengan contoh format seperti pada sampel.

#### Sample Input 0
```c
5
1 2 3 4 5
4
7
8
9
10
```

#### Sample Output 0
```c
Case 1: 2 5
Case 2: 3 5
Case 3: 4 5
Case 4: 10 not found
```

## Fight Against Disease
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Because you've been home for too long, you want to get out of your village. But you have just realized that in your surroundings there are already many diseases that have various levels of danger.

Your village is in the form of a 2D field consisting of equally large plots, such as a chessboard. In each plot there will be 1 disease or you. To pass a plot, you must defeat the disease, each of which has its own strength (time to be defeated). You are considered safe if you can get out through one side of the village.

#### Input Format
The first row N W H. N represents many types of diseases in your village. W and H represent the width and height of your village.

The next N lines contain one capital letter which symbolizes the initial of the disease (except 'Y') followed by M which is the time needed to defeat it (in minutes).

The next H line contains W capital letters which are not separated by spaces. There is only 1 'Y' in the field and the rest are other letters of the initial disease.

#### Constraints
* 1 ≤ N ≤ 25
* 1 ≤ W ≤ 500
* 1 ≤ H ≤ 500
* 1 ≤ M ≤ 100

#### Output Format
One line integer is the minimum time you need to get out of the village.

#### Sample Input 0
```c
3 8 8
X 56
O 96
H 25
XOOHXHOO
HOOXOOOX
OXXHOHOX
OHXHHOHX
XHHOYOOH
OHXHHHHO
HOOOXOOX
HHOOXXHH
```

#### Sample Output 0
```c
137
```
