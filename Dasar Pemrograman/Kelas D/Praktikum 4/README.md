# Soal Praktikum 4 Kelas D
## Daftar Isi
- [Battle of Dasprog - BOD](#battle-of-dasprog)
- [Kampina Berterima Kasih - KBK](#kampina-berterima-kasih)
- [Toko Anime Wibu - TAW](#toko-anime-wibu)
- [Tukang Selip - TS](#tukang-selip)

## Battle of Dasprog 
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Pada suatu kerajaan dasprog, munculah seekor monster yang kejam. la membunuh semua yang berada didepannya. Sang raja pun menunjuk N ksatria untuk melawan sang monster. Nama para ksatria pun disamarkan agar mereka tidak riya jika membunuh para monster. Masing-masing ksatria mempunyai serangan yang berbeda-beda- Anehnya, kamu yang menentukan berapa banyak darah monster tersebut dan seberapa kuat si monster. Kama kamu tau darah monster berapa dan seberapa kuat dia maka dalam pertarungan ini kamu diminta menjadi wasit antara monster dan para ksatria. Seluruh ksatria mempunyai darah sebesar 100 point. 

#### Input Format 
Baris pertama berisi N yakni banyaknya ksatria. Baris berikutnya sebanyak N berisi nama sepanjang W dan X damage tiap ksatria Baris terakhir merupakan Y darah dan Z damage sang monster. 

#### Output Format 
Tentukan apakah monster mati, jika ia maka siapa saja ksatria yang gugur dalam pertempuran. Jika tidak, maka monster gagal dibunuh. 

#### Sample Input 
```c
4 
ana 10 
bona 20 
cun 30 
dena 40 
450 20 

4 
ana 10 
bona 20 
cun 30 
dena 40 
400 25 

4 
ana 10 
bona 20 
cun 30 
550 20 
```

#### Sample Output 
```c
Monster mati dibunuh cun 
Orang yang mati : 
1. ana 
2. bona 
3. cun 

Monster mati dibunuh dena 
Orang yang mati : 
1. ana 
2. bona 
3. cun 
4. dena 

Monster gagal dibunuh 
```

#### Explanation 
Pertarungan dilakukan secara bergantian dimulai dari a menyerang monster lalu monster menyerang a Begitu seterusnya hingga ada yang kalah. Ada kemungkinan jika ksatria dan monster sama sama kalah. Jika ini terjadi maka kemenangan diberikan kepada para ksatria. Jika tidak ada yang terbunuh maka biarkan kosong 

#### Constraints 
1 ≤ N ≤ 100 \
1 ≤ X ≤ 2^32-1 \
1 ≤ Y ≤ 2^32-1 \
1 ≤ Z ≤ 2^32-1 \
1 ≤ W ≤ 20 

## Kampina Berterima Kasih
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Perusahaan Kampina ingin menyampaikan pesan rahasia kepada kalian sebagai tanda terima kasih, sebagai programmer, kalian diharapkan dapat mencari tahu isi dan **mencetak pesan** yang tersembunyi di dalam text berikut: 

```c
QmFnaSBrYWxpYW4geWFuZyBzdWRhaCBiZXJqdWFuZyB1bnR1ayBtZW1iYW50dSBwZXJ1c2FoYWFuIEthbXBpbmEgdW50dWsgbWVueWVsZXNhaWthbiBwZXJtYXNhbGFoYW4tcGVybWFzYWxhaGFuIHlhbmcgYWRhLCBtYWthIGRhcmkgaXR1IHBlcnVzYWhhYW4gS2FtcGluYSBtZW55YXRha2FuIHVuZHVyIGRpcmkgZGFuIGJlcnRlcmltYSBrYXNpaCBrZXBhZGEga2FsaWFuIHByb2dyYW1tZXIgSW5mb3JtYXRpa2EgMjAxOSBzZWJhZ2FpIG1pdHJhIGRhcmkgS2FtcGluYS4gU2Vtb2dhIGtlZGVwYW5ueWEga2FsaWFuIHN1a3NlcyBkYW4gZGFwYXQgbWVuZ2dhcGFpIG1pbXBpIGthbGlhbiBtYXNpbmctbWFzaW5nLCBTYXlvdW5hcmEu
```

Sebelumnya Perusahaan Kampina memberi tahu kalian bahwa text yang tertulis di atas merupakan hasil **Encode dari Base64** dan kalian diperbolehkan untuk membuka tools yang terdapat pada link berikut **https://codebeautify.org (https://codebeautify.org)** yang akan membantu kalian **men-Decode** dan memecahkan pesan rahasia di atas. 

Cetaklah pesan tersebut! 

#### Input 
[No Input] 

#### Output 
[Decode dari text di atas] 

## Toko Anime Wibu
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 8 MB |

Wibu memiliki suatu toko dvd anime, bantu Wibu untuk mengorganisir dvd yang dimilikinya! 

#### Input Format 
T berupa banyak DVD 

ada sebanyak T 

X yaitu ID dari DVD itu 

Y yaitu Harga dari DVD itu 

Z yaitu Banyak dics didalam DVD itu 

C yaitu ID DVD yang dicari 

#### Output Format 
ID : [ID DVD] 

Harga : [Harga DVD itul 

Banyak disc : [Banyak Disc DVD itul 

Jika tidak ada DVD dengan id itu, output "Tidak ada dvd dengan id itu" tanpa tanda kutip 

#### Sample Input 
```c
2 
3 
5000 
1
6 
10000
3 
3
```

#### Sample Output 
```c
ID : 3 
Harga : 5000 
Banyak disc : 1 
```

#### Constraints 
0 ≤ T ≤ 100 \
0 ≤ X ≤ 100 \
5000 ≤ Y ≤ 100000 \
0 ≤ X ≤ 10 \
0 ≤ C ≤ 100 

## Tukang Selip
| Time Limit | Memory Limit |
|---|---|
| 0.5 seconds | 64 MB |

Sebuah perusahaan memiliki data tentang anggotanya. Data anggota hanya terdiri dari ID dan NAMA. Perusahaan tersebut memiliki cara unik untuk memasukkan data. Karena suatu dan lain hal, perusahaan menggunakan skema selip menyelip dalam memasukkan data anggota baru. Namun karena selama ini mereka melakukannya manual dalam buku, mereka merasa kesusahan dalam mengaplikasikannya (harus banyak tipex) Karena itu anda sebagai programmer bantulah perusahaan tersebut untuk membuat programnya 

Format menyelipkan data adalah sebagai berikut: 

ID1 ID2 NAMA-ID2 

Artinya menyelipkan data dengan ID2 setelah data ID1 

#### Input Format 
Sebuah baris berisi bilangan N. 

N baris selanjutnya merupakan data awal secara terurut 

Selanjutnya sebuah baris berisi bilangan Q menyatakan jumlah data yang ditambah. 

Q baris selanjutnya berisi masukan dengan format sebagai berikut. 

ID1 ID2 NAMA-ID2. 

#### Output Format 
N + Q Nama sesuai urutan akhir. 

#### Sample Input 
```c
3 
1 arif 
2 ikta 
3 ade 
2 
1 4 pakmunif 
4 5 wow 
```

#### Sample Output 
```c
arif pakmunif wow ikta ade 
```

#### Explanation 
Data awal: 

```c
arif ikta ade 
```

Selip pertama 
```c
arif pakmunif ikta ade 
```

Selip kedua 
```c
arif pakmunif wow ikta ade. 
```

#### Constraints 
1 ≤ N, Q ≤ 10000 \
1 ≤ PanjangString ≤ 10 \
1 ≤ Xi ≤ 100000 \
ID dijamin unik.
