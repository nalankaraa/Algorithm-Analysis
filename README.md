# 🚀 Algoritma Analizi ve Karmaşıklık Projesi (C++)

---

## 🎯 Proje Amaçları

* Temel algoritmaları C++ ile sıfırdan implement etmek  
* Farklı zaman karmaşıklıklarını pratikte karşılaştırmak  
* Teorik analiz ile gerçek çalışma süresi arasındaki farkları gözlemlemek
* Ölçüm sonuçlarını CSV formatında dışa aktarmak
* Modüler ve genişletilebilir bir proje yapısı oluşturmak 

---

## 📋 İçindekiler

*  Uygulanan Algoritmalar  
* Performans Ölçümü (Benchmark)  
* Proje Klasör Yapısı  
* Derleme ve Çalıştırma  
* Çıktı Formatı  
* Gereksinimler 

---


### ✨ Uygulanan Algoritmalar
### 1️⃣ Maksimum Alt Dizi Toplamı (Maximum Subsequence Sum)

Aynı problemi çözen dört farklı algoritma kullanılarak zaman karmaşıklıkları karşılaştırılmıştır:

* Brute Force — **O(n³)**
* İyileştirilmiş Brute Force — **O(n²)**
* Böl ve Yönet (Divide & Conquer) — **O(n log n)**
* Kadane Algoritması — **O(n)**

> **Tüm algoritmalar aynı veri seti üzerinde çalıştırılmıştır.



### 2️⃣ Sıralama Algoritmaları

Farklı karmaşıklık sınıflarından sıralama algoritmaları uygulanmıştır:

**O(n²) Algoritmalar**
- Selection Sort  
- Bubble Sort  
- Insertion Sort  

**O(n log n) Algoritmalar**
- Merge Sort  

> **Her algoritmanın çalışma süresi ayrı ayrı ölçülmüştür.



### 3️⃣ Arama Algoritmaları

- İleri Doğrusal Arama — **O(n)**
- Geri Doğrusal Arama — **O(n)**
- İkili Arama (Recursive Binary Search) — **O(log n)**



### 4️⃣ Özyinelemeli (Recursive) Algoritmalar

- Fibonacci  
- 1’den N’e Toplam  
- Dizi Toplamı  
- Üs Alma  
- Super Digit  
- Hanoi Kuleleri Problemi  

> **Amaç, özyineleme mantığını ve çağrı yapısını incelemektir.



### 5️⃣ Heap Veri Yapısı (Min Heap)

Tam fonksiyonel bir **Binary Min Heap** yapısı elde edilmiştir:

- Eleman ekleme  
- Minimum elemanı bulma  
- Minimum elemanı silme  
- Heap oluşturma  
- Anahtar artırma / azaltma  
- Heap birleştirme  



### 6️⃣ Açgözlü (Greedy) Algoritmalar

- Aktivite Seçimi Problemi  
- İş Zamanlama (Job Scheduling)  

> **Amaç, greedy yaklaşımın optimizasyon problemlerindeki etkisini gözlemlemektir.



### 7️⃣ Dinamik Programlama

- Fibonacci (Bottom-Up)  
- Minimum Maliyetli Yol  
- 0/1 Knapsack Problemi  

> **Dinamik programlama tabloları kullanılarak tekrar eden hesaplamalar azaltılmıştır.

---
## ⚙️ Derleme ve Çalıştırma

**Derleme:**
```powershell
g++ src/*.cpp -I include -o main; .\main
```
**Çalıştırma:**
```powershell
.\project
```
---

## 📂 Project Structure

```text
AlgorithmAnalysis/
│
├── include/            # Header dosyaları (.h)
│   ├── sorting.h
│   ├── searching.h
│   ├── heap.h
│   ├── recursive.h
│   ├── greedy.h
│   └── dynamic.h
│
├── src/                # Kaynak kodlar (.cpp)
│   ├── main.cpp        # Ana program ve benchmark
│   ├── sorting.cpp
│   ├── searching.cpp
│   ├── heap.cpp
│   ├── recursive.cpp
│   ├── greedy.cpp
│   └── dynamic.cpp
│
├── results/            # Program çıktıları
│   └── analysis_results.csv
│
├── README.md
└── project.exe

