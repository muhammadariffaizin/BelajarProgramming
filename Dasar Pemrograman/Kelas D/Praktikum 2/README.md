# Soal Praktikum 2 Kelas D
## Daftar Isi
- [Boboiboy Bangkrut](#boboiboy-bangkrut)
- [Gaboleh Sama](#gaboleh-sama)
- [Kampina Kombinasi](#kampina-kombinasi)
- [Sultan Arif](#sultan-arif)

## Boboiboy Bangkrut
| Time Limit | Memory Limit |
|---|:---|
| 0.001 seconds	| 8 MB |

Kokoa Tok Aba sudah aman dari Adudu karena sudah bisa diorder lewat grab. Sekarang, setelah menghabiskan waktunya sibuk melawan alien berkepala kotak, Boboiboy berada pada kondisi dimana dia tidak memiliki pendidikan dan skill penting yang bisa dipakai untuk mencari kerja. Akhirnya, setelah putus asa mencari pekerjaan, Boboiboy memilih untuk menggunakan kekuatan gempanya untuk menjadi kontraktor. 

Karena kelaparan tidak bisa makan karena nggak punya kerja, Boboiboy hanya bisa melakukan kekuatan gempanya sebanyak N kali dalam sehari. Selain jumlahnya terbatas, Boboiboy juga terbatas dalam pengendaliannya. Ketika kekuatannya berjalan, dia hanya bisa menaikkan tanah setinggi C, dari tanah meter ke A, sampai tanah meter ke B. Bayangkan tanah merupakan garis dalam bidang dua dimensi dimana sebagian garis dari A sampai B ini bisa bertambah tinggi tergantung oleh C. 

Sebagai kontraktor, klien akan menanyakan apakah Boboiboy bisa membuat tanah setinggi X sepanjang Y pada hari itu. 

Jangan lupa set isi array jadi 0. 

#### Input Format 
Baris pertama merupakan T, menentukan banyaknya testcase. pada setiap T,

Baris pertama berisikan N, X, dan Y.

Pada setiap N, akan diberikan A, B dan C. 

#### Output Format 
"Akhirnya makan" ketika permintaan klien terpenuhi 

"Sial kelaparan" ketika tidak. (semua output tanpa tanda ") 

#### Sample Input
```c
2 
3 5 3 
1 5 2 
2 9 3 
1 5 0 
3 5 3 
1 5 2 
2 9 3 
1 5 1 
```

#### Sample Output
```c
Akhirnya makan 
Sial kelaparan
```

#### Explanation 

##### Testcase 1 
awalnya tanah berbentuk seperti ini 
```c
0_ _ _ _ _ _ _ _ _ ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 -1   
lalu menjadi seperti ini 
5      _ _ _ 
4 
3    _       _ _ _ 
2  _ 
1       
0_                 ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 -1 
```
karena ada tanah setinggi 5 dan sepanjang 3, Boboiboy bisa makan 

##### Testcase 2 
awalnya tanah berbentuk seperti ini 
```c
0_ _ _ _ _ _ _ _ _ ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 - 1   
lalu menjadi seperti ini 
6      _ _ _
5        
4    _ 
3            _ _ _ 
2  
1       
0_                 ... _ 
 0 1 2 3 4 5 6 7 9 ... 10^5 - 1 
```
karena tidak ada tanah setinggi 5 dan sepanjang 3, Boboiboy kelaparan 

#### Constraints 
1 ≤ T ≤ 20 \
1 ≤ N ≤ 100 \
0<=A<B<10^5 - 1 \
0<=X,Y,C<=10^3

## Gaboleh Sama 
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Samel adalah seseorang hypebeast. Karena sudah bosan membeli, akhirnya ia mencoba berjualan. 
Ketika ingin membuka toko, Samel tidak ingin ada huruf yang berulang pada merk 
dagangannya. Jadi bantulah Samel agar tidak ada huruf yang sama pada merk dagangnya. 

#### Input Format 
Baris pertama berisi angka T dimana T adalah banyaknya inputan yang akan dimasukkan di baris 
berikutnya. Baris berikutnya berisi inputan string sebanyak N karakter.

#### Output Format 
String dari inputan dimana karakternya tidak ada yang lebih dari satu kali.

#### Sample Input 
```c
abcda 
volcom 
reebok 
```

#### Sample Output 
```c
abcd 
volcm 
rebok 
```

#### Explanation 
Output hanya mengambil karakter sebanyak satu kali. Jika karakter tersebut sudah ada, maka tidak 
akan diambil. Contoh pada test case pertama yang mana huruf a sudah ada di awal jadi hasil 
outputnya hanya abcd. 

#### Constraints 
1 ≤ T ≤ 20 \
1 ≤ N ≤ 100 

## Kampina Kombinasi 
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Pada minggu ini, Manager Kampina yang lalai ini ingin berterima kasih kepada kalian yang telah membantu perhitungan jarak pada minggu yang lalu. 

Dari kelalaiannya minggu lalu, Sebelum mengeksekusi rencana promosi, Manager Kampina ini belajar untuk selalu merencanakan sesuatu dengan detail. 

Setelah berhasil menghitung jarak dan memprediksi bahan bakar yang dibutuhkan untuk tiap-tiap pesawat, Manager Kampina mulai mendattar pesawat Jet yang siap untuk diberangkatkan, serta tempat - tempat mana saja yang akan dilewati Oleh pesawat tersebut, Manager Kampina meminta bantuan lagi kepada kalian para Programmer untuk melakukan perhitungan detail kali ini. 

Dimisalkan banyaknya pesawat Jet yang siap berangkat berjumlah **p pesawat**, dan banyak tempat yang menjadi target promosi pesawat jet adalah **t target promosi**, maka Manager Kampina ingin mengetahui berapa banyak **k kombinasi** pesawat dan target promosi sebagai pencegahan apabila rencana awalnya gagal Untuk membuat rencana lebih efisien, sudah dapat dipastikan bahwa setiap tempat yang menjadi target promosi hanya dilewati oleh 1 pesawat saja, sehingga apabila jumlah pesawat lebih besar dari jumlah target promosi, pesawat jet yang tidak berangkat dianggurkan untuk menghemat bahan bakar. 

#### Input Format 
Terdapat 1 baris input yang terdiri dari 2 integer (p, t) 

```c
p t
```

#### Output Format 
print banyak k kombinasi pesawat yang berangkat dengan target promosi 

```c
k
```

#### Sample Input 
```c
3 3 
4 2 
```

#### Sample Output 
```c
6 
12 
```

#### Explanation 
##### Input Pertama 
Terdapat **3 pesawat** Jet yang siap berangkat dan **3 target promosi** 

misal tiap pesawat Jet diberi label : A B C 

dan tiap target promosi diberi label : 2 3 

dengan format : Z(X) -> yang berarti pesawat Jet Z melakukan promosi pada target promosi dengan label X 

Kombinasi - 1: A(1) B(2) C(3)

Kombinasi - 2: A(1) C(2) B(3)

Kombinasi - 3: B(1) A(2) C(3)

Kombinasi - 4: B(1) C(2) A(3)

Kombinasi - 5: C(1) A(2) B(3)

Kombinasi - 6: C(1) B(2) A(3)

didapatkan banyak kombinasi pesawat yang berangkat dengan target promosi sebesar **6 kombinasi** 

##### Input Kedua 
Terdapat **4 pesawat** Jet yang siap berangkat dan **2 target promosi** 

misal tiap pesawat Jet diberi label : A B C D 

dan tiap target promosi diberi label : 1 2 

dengan format : Z(X) -> yang berarti pesawat Jet Z melakukan promosi pada target promosi dengan label X 

Kombinasi - 1: A(1) B(2)

Kombinasi - 2: A(1) C(2)

Kombinasi - 3: A(1) D(2)

Kombinasi - 4: B(1) A(2)

Kombinasi - 5: B(1) C(2)

Kombinasi - 6: B(1) D(2)

Kombinasi - 7: C(1) A(2)

Kombinasi - 8: C(1) B(2)

Kombinasi - 9: C(1) D(2)

Kombinasi - 10: D(1) A(2)

Kombinasi - 11: D(1) B(2)

Kombinasi - 12: D(1) C(2)

didapatkan banyak kombinasi pesawat yang berangkat dengan target promosi sebesar **12 kombinasi** 

#### Constraints
0 ≤ t ≤ p ≤ 100 \
len(k) < 200

## Sultan Arif 
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 64 MB |

Arif merupakan salah satu sultan yang berkuliah di TC. Kekayaan Arif tidak terbatas, bahkan ia mampu membeli club sepakbola Manchester United apabila ia ingin Karena kekayaannya yang sangat banyak Arif menjadi sangat bosan. Pada suatu hari Arif mengunjungi sebuah komplek perumahan di Surabaya. Namun Arif terkejut karena perumahan tersebut tampak sepi, lesu, dan seperti tidak ada kehidupan. Arif pun berinisiatif bertanya kepada ketua RT komplek tersebut untuk mengetahui permasalahan yang terjadi pada komplek tersebut. 

Setelah berdiskusi panjang dengan ketua RT Arif pun mengetahui masalah utama yang terjadi pada komplek tersebut yaitu Uang. Arif yang merasa prihatin dengan kondisi komplek tersebut berinisiatif memberikan pinjaman uang kepada semua penghuni komplek tersebut dan bekerja sama dengan ketua RT setempat. 

Proses hutang mulai berlangsung, Komplek tersebut terdiri dari N rumah dimana masing - masing rumah memiliki hutang awal sebesar Hi (1 ≤ i ≤ N). Setiap harinya Ketua RT akan membawakan 3 bilangan yaitu L, R, X yang berarti rumah pada nomor L sampai R meminjam uang sebanyak X kepada Arif. Selanjutnya ketua RT akan memberikan uang sebesar X untuk diberikan kepada masing - masing rumah dari nomor L hingga nomor R. 

Q hari berlalu, ketua RT selalu memberikan 3 bilangan setiap harinya, Komplek yang dulunya lesu telah menjadi pusat perbelajaan terkenal di Surabaya. Penduduk komplek yang merasa berterima kasih kepada Arif ingin mengembalikan uang yang telah mereka pinjam. Namun terdapat satu permasalahan, Arif, Ketua RT, dan Masyarakat setempat tidak mencatat total hutang masing - masing rumah. Data yang dimiliki hanyalah daftar 3 bilangan L R X sebanyak Q hari yang disimpan oleh istri ketua RT.

Masyarakat komplek yang merasa kebingungan pun meminta tolong bantuan anda untuk menghitung total hutang masing - masing rumah setelah Q hari. Anda sebagai jagoan informatika pun tertantang untuk menyelesaikan permasalahan Arif dan Komplek Lesu. 

P.S Arif sebenarnya tidak peduli dengan hutangnya, namun masyarakat komplek bersikeras akan 
membayar hutangnya. 

#### Input Format 
Sebuah baris berisi nilai N. 

Baris berikutnya berisi N bilangan Hi (1 ≤ i ≤ N) yang merupakan nilai hutang awal masing masing rumah komplek. 

Baris berikutnya berisi sebuah bilangan Q yang menyatakan banyaknya hari. 

Q baris berikutnya berisi 3 buah bilangan masing masing 
```c
L R X 
```

#### Output Format 
Sebuah baris berisi N bilangan yang menyatakan total hutang yang dimiliki masing - masing rumah pada komplek. 

#### Sample Input 
```c
2 
1 10
1 
1 1 10 
```
#### Sample Output 
```c
11 10 
```

#### Constraints 
1 ≤ N, Q ≤ 100000 \
1 ≤ L, R ≤ N \
0 ≤ X ≤ 1000000 \
0 ≤ H ≤ 10000000000 
