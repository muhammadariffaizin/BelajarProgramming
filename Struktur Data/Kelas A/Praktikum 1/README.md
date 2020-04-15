# Soal Praktikum 1 Kelas A
## Daftar isi
- [Aya Mau Parkir - AMP](#aya-mau-parkir)
- [Bermain Bersama Wowong - BBW](#bermain-bersama-wowong)
- [Birds of Prey - BOP](#birds-of-prey)
- [Ula the King of Duelist - UTKOD](#ula-the-king-of-duelist)

## Aya Mau Parkir
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 32 MB |

Aya adalah seorang cenayang yang ke mana-mana bawa mobil. Dia juga seorang mahasiswa TC yang sedang ikut seleksi staff Schematics 2020. Dia sangat ingin masuk divisi Sponsorship karena senang mencari uang untuk Schematics NLC, Schematics NPC, Schematics NST, dan Schematics REEVA serta membuat semua orang bahagia. Aya sudah berhasil melewati seleksi pertama. Sekarang dia mau wawancara di Plasa Prof. Supeno. 

Kapasitas parkiran TC adalah **N** dan ada **M** mobil yang parkir pada hari itu. Karena dia cenayang, dia bisa tahu jam berapa mobil-mobil tersebut masuk dan keluar dari parkiran TC. Aya kemudian mengira-ngira apakah dia bisa mendapat parkiran sebelum atau saat waktu wawancaranya.

#### Input Format 
Baris pertama adalah **N** dan **M** (kapasitas parkiran TC dan jumlah mobil yang parkir di hari itu) 

**M**-baris selanjutnya adalah **M**<sub>i</sub> dan **M**<sub>o</sub> (jam mobil masuk dan keluar parkiran) 

Baris terakhir adalah **H** (jam wawancara Aya, di jam tersebut Aya harus sudah parkir)

#### Output Format 
Jika Aya tidak bisa mendapat parkiran, cetak "Semangat wawancaranya!" 

Selain itu, cetak "Coba reschedule!"

#### Constraints

## Bermain Bersama Wowong
| Time Limit | Memory Limit |
|---|---|
| 0.01 seconds | 8 MB |

> TIDAK BOLEH PAKAI STL YA !! 
Hari ini Wowong tidak ada jadwal apel, sehingga dia merasa sangattttt gabut. Akhirnya dia mengambil kardus yang berisi tumpukan angka. 

Dia bermain hitung tumpukan, dimana dia akan mengecek sebuah angka itu berada di tumpukan keberapa. 

#### Input Format 
Baris pertama : banyaknya testcase 

Baris kedua : banyaknya tumpukan angka 

Baris ketiga : tumpukan angka 

Baris keempat : angka yang mau di cek 

#### Output Format 
Kalau ketemu : Posisi angka 

Kalau gak ketemu : -1 

#### Constraints

## Birds of Prey
| Time Limit | Memory Limit |
|---|---|
| 1 seconds | 80 MB |

Sejak peristiwa Suicide Squad, Harley Quinn telah meninggalkan Joker. Harley memutuskan untuk berkelana dunia mencari pencerahan. Namun ketika Harley tiba di kota yang bernama City of Keputih (CoK), ia mendengar kabar bahwa penguasa kejahatan brutal bernama Black Mask, memburu semua bayi yang ada di kota. Harley Quinn kemudian sepakat untuk bersatu dengan warga Keputih untuk mencari Black Mask. Menurut data sensus penduduk, kota Keputih memiliki jumlah N orang bayi dengan umur yang berbeda beda. Setiap harinya, Black Mask akan membuat surat yang isinya hanya berupa list umur dari M bayi dan meletakkan surat tersebut di depan kantor walikota Keputih. Dia juga menuliskan bahwa dia hanya akan menculik bayi yang paling tua dari M bayi tersebut. 

Contoh : \
N = 4, \
M = 2 \
1 2 3 4 

Hari pertama penculikan \
**1 2** 3 4 

Black Mask akan menculik seorang bayi berumur 2 tahun. 

Setelah menculik bayi tersebut, Black Mask akan menempatkan bayi tersebut di suatu tumpukan (anggap mereka akan tinggal di tumpukan itu :p) yang ada di markas rahasianya. Black Mask menyadari bahwa dia bisa tidak menculik setiap hari karena akan membuat markas rahasianya diketahui, sehingga Black Mask akan memilih hari hari tertentu untuk menculik. Setelah menculik seorang bayi, ia akan mengirim bayi tersebut ke bosnya yang bernama Joker, namun Black Mask hanya akan mengirim bayi yang berada di tumpukan paling atas. Selain mengirim ke Joker, Black Mask juga biasa memamerkan bayi yang paling tua di channel TV nya, yaitu Black Mask Envy TV (BME TV). 

Black Mask memiliki asisten bernama Roman Simionis yang melayani Black Mask mulai dari kecil. Karena Black Mask tidak peduli dengan bayi yang ia masukkan ke tumpukan, Maka Roman diminta untuk melakukan tugas tersebut. 

#### Input Format 
Sebuah baris berisi bilangan **N** dan **M**. **N** menyatakan banyaknya bayi yang ada City of Keputih dan **M** menyatakan jumlah bayi yang akan diculik setiap harinya. 

**N** baris berikutnya berisi umur dari bayi-bayi yang akan diculik. 

Baris selanjutnya berisi bilangan **D** dan **A**. **D** adalah hari keberapa dan **A** merupakan jumlah aksi yang dilakukan Black Mask. 

**A** baris selanjutnya berisi bilangan K yang merupakan jenis aksi apa yang akan dilakukan Black Mask. 

**1** artinya Black Mask akan mengirim bayi ke Joker. 

**2** artinya Black Mask akan memamerkan bayi di BME TV. 

Inputan berhenti ketika **D** dan **A** bernilai **-1**. 

#### Output Format 
**A** baris untuk setiap **D** dan **A**. 

Apabila **K** merupakan **1** keluarkan "Segera Dikirim" apabila Bobby sukses mengirim bayi. Apabila tidak ada bayi di tumpukan cetak "Mau direfill, gan". 

Apabila **K** merupakan **2** keluarkan bilangan yang menyatakan umur tertinggi yang dimiliki Black Mask dalam tumpukannya. Apabila tidak ada bayi di tumpukan cetak "Mau direfill, gan". 

#### Constraints

## Ula the King of Duelist
| Time Limit | Memory Limit |
|---|---|
| 0.5 seconds | 16 MB |

Aritmofinka adalah sebuah planet dimana terdapat semua permainan kartu. Sudah menjadi ketetapan di dunia Aritmofinka bahwa semua permasalahan harus dieselesaikan melalui permainan kartu jadi duel kartu sudah menjadi jalan ninja setiap penduduk di Planet itu. Penduduk planet Aritmofinka memiliki kemampuan di bawah manusia di Planet Bumi namun ada beberapa orang terpilih yang diberi anugrah kemampuan unik yang kemudian disebut TCHolder. Ula adalah seorang TCHolder dari sebuah kota bernama Duelist City. Suatu ketika, seorang bandit tersohor bernama Esi, ingin menguasai Duelist City. Dia pun menantang seluruh penduduk Duelist City untuk melawanya dalam permainan kartu yang sudah dia susun. Sebagai 
TCHolder Ula tidak bisa membiarkan Esi berbuat semena-mena oleh karena itu dia pun menerima tantangan tersebut.  

System permainan Kartu yang disusun oleh Esi adalah sebagai berikut : 

* Permainan dilakukan sebanyak n ronde. 
* Ketika Esi mengatakan "push" dan diikuti sebuah bilangan x maka dia akan menaruh kartu dengan nilai x pada tumpukan yang ada 
* Ketika Esi mengatakan "pop" maka dia akan mengambil kembali kartu yang paling atas dari tumpukan tersebut 
* Ketika Esi mengatakan "top" maka Ula harus menebak nilai kartu yang paling atas 
* Ketika Esi mengatakan "max" maka Ula harus menebak nilai terbesar yang ada pada tumpukan kartu tersebut 
* Ketika Esi mengatakan "min" maka Ula harus menebak nilai terkecil yang ada pada tumpukan kartu tersebut 
* Untuk perintah pop,top,max,min dijamin tumpukan kartu tidak kosong. 

Jika Ula berhasil melakukan semua perintah yang diberikan oleh Esi maka Ula akan menjadi pemenangnya. Namun Ula tidak pandai mengingat. Maka dari itu dia menggunakan kemampuan uniknya yang memungkinkan dia berkomunikasi dengan penduduk planet bumi. Kalian sebagai partner yang dipilih Ula di planet Bumi, gunakan Data Struktur stack membantu Ula.  

#### Input Format 
Input line pertama berupa angka n merupakan banyak ronde yang harus dimainkan oleh Ula dan Esi. Kemudian n line berikutnya di ikuti oleh perintah perintah Esi sesuai dekripsi. 

#### Output Format 
Untuk Setiap testcase keluarkan output sesuai deskripsi. 

#### Constraints
