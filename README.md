# Push Swap 🔢

[🇺🇸 English](#english) | [🇹🇷 Türkçe](#türkçe)

---

# English

## 📋 Table of Contents

- [📖 About the Project](#📖-about-the-project)
- [🎯 Project Goals](#🎯-project-goals)
- [🚀 Installation](#🚀-installation)
- [💻 Usage](#💻-usage)
- [⚙️ Algorithms](#⚙️-algorithms)
- [📊 Operations](#📊-operations)
- [🧪 Testing](#🧪-testing)
- [📈 Performance](#📈-performance)
- [🛠️ Technical Details](#🛠️-technical-details)
- [👨‍💻 Developer](#👨‍💻-developer)

---

## 📖 About the Project

**Push Swap** is a crucial project in the 42 School curriculum. This project aims to sort a sequence of numbers using two stacks with the minimum number of moves possible. The project provides deep knowledge in data structures, algorithm analysis, and optimization.

### ✨ Features

- 🔄 **Two Stack System**: Efficient sorting using Stack A and Stack B
- 🧮 **Multiple Algorithms**: Optimized algorithms for different sizes
- ⚡ **High Performance**: Maximum efficiency with minimum move count
- 🔍 **Error Handling**: Input validation and error management
- 📏 **Flexible Size**: Supports from 2 to thousands of elements

---

## 🎯 Project Goals

1. **Algorithm Development**: Understanding and implementing efficient sorting algorithms
2. **Data Structure Management**: Effective use of stack data structure
3. **Optimization**: Sorting with minimum number of moves
4. **Error Management**: Handling all edge cases
5. **Code Quality**: Writing clean, readable, and maintainable code

---

## 🚀 Installation

### Requirements

- GCC compiler
- Make build system
- Unix/Linux environment (macOS, Linux)

### Installation Steps

```bash
# Clone the repository
git clone https://github.com/CilginSinek/push_swap.git

# Navigate to project directory
cd push_swap

# Compile the project
make

# Clean up (optional)
make clean  # Removes only .o files
make fclean # Removes all compiled files
```

---

## 💻 Usage

### Basic Usage

```bash
# Simple example
./push_swap 3 2 1

# Large numbers
./push_swap 42 21 84 63 105

# Pass as string
./push_swap "3 2 1 4 5"

# Mixed format
./push_swap "3 2" 1 "4 5"
```

### Example Outputs

```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
```

### Error Cases

```bash
# Duplicate numbers
./push_swap 1 2 2 3
# Output: Error

# Invalid characters
./push_swap abc 123
# Output: Error

# Outside INT limits
./push_swap 2147483648
# Output: Error
```

---

## ⚙️ Algorithms

### 1. 🔢 Simple Sorting for 2-3 Elements

**2 elements:**
- Only `sa` (swap a) operation is used

**3 elements:**
- Special cases for all permutations
- Maximum 2 moves

### 2. 🎯 Optimized Sorting for 4-5 Elements

**Strategy:**
1. Move smallest elements to Stack B
2. Sort 3 elements in Stack A
3. Retrieve from Stack B

```c
void sort_five(t_list **head_a, t_list **head_b)
{
    while (ft_lstsize(*head_a) > 3)
        push_min_to_b(head_a, head_b);
    sort_three(head_a);
    while (*head_b)
        put(head_b, head_a, 'a');
}
```

### 3. 🌟 Radix Sort for Large Arrays

**Radix Sort Algorithm:**
- Uses binary representation
- Bit-by-bit sorting
- O(n * log(n)) complexity

```c
static void radix_sort(t_list **head_a, t_list **head_b)
{
    int max_bits = get_max_bits(ft_lstsize(*head_a) - 1);
    
    for (int i = 0; i < max_bits; i++)
    {
        // For each bit position
        for (int j = 0; j < size_a; j++)
        {
            if (((num >> i) & 1) == 0)
                put(head_a, head_b, 'b');  // Send to B if 0
            else
                rotater(head_a, 'a');      // Rotate if 1
        }
        // Retrieve all elements back
        while (*head_b)
            put(head_b, head_a, 'a');
    }
}
```

---

## 📊 Operations

Available operations in Push Swap:

| Operation | Description | Example |
|-----------|-------------|---------|
| `sa` | Swap first two elements of Stack A | `[2,1,3]` → `[1,2,3]` |
| `sb` | Swap first two elements of Stack B | - |
| `ss` | Do `sa` and `sb` simultaneously | - |
| `pa` | Push top of Stack B to Stack A | - |
| `pb` | Push top of Stack A to Stack B | - |
| `ra` | Rotate Stack A up | `[1,2,3]` → `[2,3,1]` |
| `rb` | Rotate Stack B up | - |
| `rr` | Do `ra` and `rb` simultaneously | - |
| `rra` | Rotate Stack A down | `[1,2,3]` → `[3,1,2]` |
| `rrb` | Rotate Stack B down | - |
| `rrr` | Do `rra` and `rrb` simultaneously | - |

---

## 🧪 Testing

### Simple Tests

```bash
# 3-element test
./push_swap 3 2 1

# 5-element test
./push_swap 5 4 3 2 1

# Random test
./push_swap 42 21 84 63 105 31
```

### Using Checker (if available)

```bash
# Validate sorting operations
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK or KO
```

### Performance Test

```bash
# 100-element random test
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# 500-element test
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

## 📈 Performance

### Move Count Targets

| Element Count | Maximum Moves | Average |
|---------------|---------------|---------|
| 3 | 3 | 1-2 |
| 5 | 12 | 8-10 |
| 100 | 700 | 500-600 |
| 500 | 5500 | 4000-5000 |

### Algorithm Complexity

- **Time Complexity**: O(n * log(n))
- **Space Complexity**: O(n)
- **Best Case**: O(n) - already sorted
- **Worst Case**: O(n * log(n))

---

## 🛠️ Technical Details

### File Structure

```
push_swap/
├── push_swap.c      # Main program
├── push_swap.h      # Header file
├── sortlittle.c     # Algorithm for small arrays
├── sortbig.c        # Algorithm for large arrays (Radix Sort)
├── list_utils.c     # List operations
├── list_utils1.c    # Additional list operations
├── utils.c          # Helper functions
├── utils1.c         # Additional helper functions
├── split.c          # String parsing
├── Makefile         # Build system
└── Libft/           # 42 standard library
```

### Data Structure

```c
typedef struct s_list
{
    void            *content;    // Numeric value
    size_t          index;       // Normalized index
    struct s_list   *next;       // Next node
}   t_list;
```

### Features

- **Index Normalization**: Numbers are normalized from 0 to n-1
- **Memory Management**: All memory operations are safe
- **Error Handling**: Comprehensive error control
- **Modular Design**: Functional programming approach

---

## 👨‍💻 Developer

**👤 İsmail Duman (iduman)**
- 🏫 **42 Istanbul Student**
- 🌐 **GitHub**: [@CilginSinek](https://github.com/CilginSinek)
- 📧 **Email**: iduman@student.42istanbul.com.tr
- 📅 **Development Date**: July-August 2025

---

### 📄 License

This project was developed as a 42 School project. It is suitable for educational purposes.

---

### 🤝 Contributing

Since this is a 42 school project, it's not open for direct contributions, but I welcome your feedback!

---

### ⭐ Give a Star if You Like It!

If you found this project useful, please support it by giving a ⭐!

---

**📚 Check out my [GitHub profile](https://github.com/CilginSinek) for more 42 projects!**

---

# Türkçe

## 📋 İçindekiler

- [📖 Proje Hakkında](#📖-proje-hakkında-1)
- [🎯 Proje Hedefleri](#🎯-proje-hedefleri-1)
- [🚀 Kurulum](#🚀-kurulum-1)
- [💻 Kullanım](#💻-kullanım-1)
- [⚙️ Algoritmalar](#⚙️-algoritmalar-1)
- [📊 İşlemler](#📊-işlemler-1)
- [🧪 Test Etme](#🧪-test-etme-1)
- [📈 Performans](#📈-performans-1)
- [🛠️ Teknik Detaylar](#🛠️-teknik-detaylar-1)
- [👨‍💻 Geliştirici](#👨‍💻-geliştirici-1)

---

## 📖 Proje Hakkında

**Push Swap**, 42 School müfredatının önemli bir projesidir. Bu proje, iki yığın (stack) kullanarak bir sayı dizisini mümkün olan en az hareketle sıralamayı amaçlar. Proje, veri yapıları, algoritma analizi ve optimizasyon konularında derinlemesine bilgi kazandırır.

### ✨ Özellikler

- 🔄 **İki Yığın Sistemi**: Stack A ve Stack B kullanarak etkili sıralama
- 🧮 **Çoklu Algoritma**: Farklı boyutlar için optimize edilmiş algoritmalar
- ⚡ **Yüksek Performans**: Minimum hareket sayısı ile maksimum verimlilik
- 🔍 **Hata Kontrolü**: Giriş validasyonu ve hata yönetimi
- 📏 **Esnek Boyut**: 2'den binlerce elemana kadar destekler

---

## 🎯 Proje Hedefleri

1. **Algoritma Geliştirme**: Etkili sıralama algoritmalarını anlamak ve uygulamak
2. **Veri Yapı Yönetimi**: Yığın (stack) veri yapısını etkin kullanmak
3. **Optimizasyon**: En az hareket sayısı ile sıralama yapmak
4. **Hata Yönetimi**: Tüm edge case'leri ele almak
5. **Kod Kalitesi**: Temiz, okunabilir ve maintainable kod yazmak

---

## 🚀 Kurulum

### Gereksinimler

- GCC derleyicisi
- Make build sistemi
- Unix/Linux ortamı (macOS, Linux)

### Kurulum Adımları

```bash
# Repoyu klonlayın
git clone https://github.com/CilginSinek/push_swap.git

# Proje dizinine gidin
cd push_swap

# Projeyi derleyin
make

# Temizlik (opsiyonel)
make clean  # Sadece .o dosyalarını siler
make fclean # Tüm derlenmiş dosyaları siler
```

---

## 💻 Kullanım

### Temel Kullanım

```bash
# Basit örnek
./push_swap 3 2 1

# Büyük sayılar
./push_swap 42 21 84 63 105

# String olarak geçme
./push_swap "3 2 1 4 5"

# Karışık format
./push_swap "3 2" 1 "4 5"
```

### Örnek Çıktılar

```bash
$ ./push_swap 3 2 1
sa
rra

$ ./push_swap 5 4 3 2 1
pb
pb
sa
pa
pa
```

### Hata Durumları

```bash
# Duplicate sayılar
./push_swap 1 2 2 3
# Output: Error

# Geçersiz karakterler
./push_swap abc 123
# Output: Error

# INT sınırları dışında
./push_swap 2147483648
# Output: Error
```

---

## ⚙️ Algoritmalar

### 1. 🔢 2-3 Eleman İçin Basit Sıralama

**2 eleman:**
- Sadece `sa` (swap a) işlemi kullanılır

**3 eleman:**
- Tüm permütasyonlar için özel durumlar
- Maksimum 2 hareket

### 2. 🎯 4-5 Eleman İçin Optimized Sıralama

**Strateji:**
1. En küçük elemanları Stack B'ye taşı
2. Stack A'daki 3 elemanı sırala
3. Stack B'den geri al

```c
void sort_five(t_list **head_a, t_list **head_b)
{
    while (ft_lstsize(*head_a) > 3)
        push_min_to_b(head_a, head_b);
    sort_three(head_a);
    while (*head_b)
        put(head_b, head_a, 'a');
}
```

### 3. 🌟 Büyük Diziler İçin Radix Sort

**Radix Sort Algoritması:**
- Binary representation kullanır
- Bit-by-bit sıralama
- O(n * log(n)) kompleksitesi

```c
static void radix_sort(t_list **head_a, t_list **head_b)
{
    int max_bits = get_max_bits(ft_lstsize(*head_a) - 1);
    
    for (int i = 0; i < max_bits; i++)
    {
        // Her bit pozisyonu için
        for (int j = 0; j < size_a; j++)
        {
            if (((num >> i) & 1) == 0)
                put(head_a, head_b, 'b');  // 0 ise B'ye gönder
            else
                rotater(head_a, 'a');      // 1 ise döndür
        }
        // Tüm elemanları geri al
        while (*head_b)
            put(head_b, head_a, 'a');
    }
}
```

---

## 📊 İşlemler

Push Swap'ta kullanılabilecek işlemler:

| İşlem | Açıklama | Örnek |
|--------|----------|-------|
| `sa` | Stack A'nın ilk iki elemanını değiştir | `[2,1,3]` → `[1,2,3]` |
| `sb` | Stack B'nin ilk iki elemanını değiştir | - |
| `ss` | `sa` ve `sb`'yi aynı anda yap | - |
| `pa` | Stack B'nin tepesini Stack A'ya taşı | - |
| `pb` | Stack A'nın tepesini Stack B'ye taşı | - |
| `ra` | Stack A'yı yukarı döndür | `[1,2,3]` → `[2,3,1]` |
| `rb` | Stack B'yi yukarı döndür | - |
| `rr` | `ra` ve `rb`'yi aynı anda yap | - |
| `rra` | Stack A'yı aşağı döndür | `[1,2,3]` → `[3,1,2]` |
| `rrb` | Stack B'yi aşağı döndür | - |
| `rrr` | `rra` ve `rrb`'yi aynı anda yap | - |

---

## 🧪 Test Etme

### Basit Test

```bash
# 3 elemanlı test
./push_swap 3 2 1

# 5 elemanlı test
./push_swap 5 4 3 2 1

# Random test
./push_swap 42 21 84 63 105 31
```

### Checker Kullanımı (Eğer mevcutsa)

```bash
# Sıralama işlemlerini doğrula
./push_swap 3 2 1 | ./checker 3 2 1
# Output: OK veya KO
```

### Performance Test

```bash
# 100 elemanlı random test
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# 500 elemanlı test
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

## 📈 Performans

### Hareket Sayısı Hedefleri

| Eleman Sayısı | Maksimum Hareket | Ortalama |
|---------------|------------------|----------|
| 3 | 3 | 1-2 |
| 5 | 12 | 8-10 |
| 100 | 700 | 500-600 |
| 500 | 5500 | 4000-5000 |

### Algoritma Karmaşıklığı

- **Zaman Karmaşıklığı**: O(n * log(n))
- **Alan Karmaşıklığı**: O(n)
- **En İyi Durum**: O(n) - zaten sıralı
- **En Kötü Durum**: O(n * log(n))

---

## 🛠️ Teknik Detaylar

### Dosya Yapısı

```
push_swap/
├── push_swap.c      # Ana program
├── push_swap.h      # Header dosyası
├── sortlittle.c     # Küçük diziler için algoritma
├── sortbig.c        # Büyük diziler için algoritma (Radix Sort)
├── list_utils.c     # Liste işlemleri
├── list_utils1.c    # Ek liste işlemleri
├── utils.c          # Yardımcı fonksiyonlar
├── utils1.c         # Ek yardımcı fonksiyonlar
├── split.c          # String parsing
├── Makefile         # Build sistemi
└── Libft/           # 42 standart kütüphanesi
```

### Veri Yapısı

```c
typedef struct s_list
{
    void            *content;    // Sayısal değer
    size_t          index;       // Normalize edilmiş index
    struct s_list   *next;       // Sonraki node
}   t_list;
```

### Özellikler

- **Index Normalization**: Sayılar 0'dan n-1'e normalize edilir
- **Memory Management**: Tüm bellek işlemleri güvenli
- **Error Handling**: Comprehensive hata kontrolü
- **Modular Design**: Fonksiyonel programlama yaklaşımı

---

## 👨‍💻 Geliştirici

**👤 İsmail Duman (iduman)**
- 🏫 **42 İstanbul Öğrencisi**
- 🌐 **GitHub**: [@CilginSinek](https://github.com/CilginSinek)
- 📧 **Email**: iduman@student.42istanbul.com.tr
- 📅 **Geliştirme Tarihi**: Temmuz-Ağustos 2025

---

### 📄 Lisans

Bu proje 42 School projesi olarak geliştirilmiştir. Eğitim amaçlı kullanım için uygundur.

---

### 🤝 Katkıda Bulunma

Bu bir 42 okul projesi olduğu için direkt katkıya açık değildir, ancak geri bildirimlerinizi memnuniyetle karşılarım!

---

### ⭐ Beğendiyseniz Yıldız Verin!

Bu projeyi faydalı bulduysanız, lütfen bir ⭐ vererek destekleyin!

---

**📚 Daha fazla 42 projesi için [GitHub profilime](https://github.com/CilginSinek) göz atın!**