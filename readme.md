# Vector konteineris

## 1 užduotis

```c++
void reserve(size_type new_cap) {
    if (capacity_ < new_cap) {
        value_type *tmp = new value_type[new_cap];
        for (auto i = 0; i < size_; i++) {
            tmp[i] = elem_[i];
        }
        delete[] elem_;
        elem_ = tmp;
        capacity_ = new_cap;
        tmp = nullptr;
    }
}
```

Funkcija pakeičia konteinerio talpą jeigu pateiktas argumentas `new_cap` yra didesnis nei esama konteinerio talpa. Jei argumentas tenkina sąlygą, konteinerio elementai perkopijuojami į naujai išskirtą atminties vietą, o sena atminties vieta atlaisvinama.

```c++
void shrink_to_fit() {
    if (size_ < capacity_) {
        value_type *tmp = new value_type[size_];
        for (auto i = 0 ; i < size_; i++) {
            tmp[i] = elem_[i];
        }
        delete[] elem_;
        elem_ = tmp;
        tmp = nullptr;
        capacity_ = size_;
    }
}
```

Funkcija sumažina konteinerio talpą iki tiek, kad nebūtų lasivos vietos konteineryje. Mažinimas vyksta perkopojuojant konteinerio elementus į naujai išskirtą atminties vietą; perkovijavus sena atmintis atlaisvinama ir konteinerio rodyklė nukreipiama į naujai išskirtą atminties vietą.

```c++
void push_back(const_reference value ) {
    if (capacity_ == 0) {
        elem_ = new value_type[1];
        elem_[0] = value;
        capacity_ = 1;
        size_ = 1;
    } else {
        if (!(size_ < capacity_)) {
            reserve(capacity_ * 2);
        }
        elem_[size_++] = value;
    }
}
```

Funkcija įterpia nurodytą elementą į konteinerio galą. Prieš įterpimą patikrinama ar konteinerio talpa nelygi nuliui ir ar konteinerio dydis mažesnis už talpą. Skirtingais atvėjais vykdomas skirtingas elemento įterpimas arba papildomas konteinerio dydžio pakeitimas.

```c++
void pop_back() {
    if (size_ > 0) {
        elem_[--size_].~value_type();
    }
}
```

Funkcija ištrina paskutinį konteinerio elementą iškviesdama jo destruktorių. Konteinerio talpa nepakinta. Dydis keičiasi.

```c++
reference operator[](size_type i)	{
    if (i < 0 || capacity() <= i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem_[i];
}
```

Operatorius leidžia pasiekti bet kokį konteinerio elementą ir gražina "referenc'ą" į jį.

## 2 užduotis

push_back()

| Konteineris        | Talpa     | Vidutinis laikas |
| ------------------ | --------- | ---------------- |
| `std::vector<int>` | 1000000   | 0.015626s        |
| `Vector<int>`      | 1000000   | 0.015611s        |
| `std::vector<int>` | 10000000  | 0.187927s        |
| `Vector<int>`      | 10000000  | 0.171654s        |
| `std::vector<int>` | 100000000 | 1.71695s         |
| `Vector<int>`      | 100000000 | 1.74192s         |

## 3 užduotis

capacity() == size()

| Konteineris        | Talpa     | capacity() == size() |
| ------------------ | --------- | -------------------- |
| `std::vector<int>` | 100000000 | 28 kartai            |
| `Vector<int>`      | 100000000 | 28 kartai            |

## 4 užduotis

[Nuoroda į releasą](https://github.com/d1j/OBJ-3uzd/releases/tag/v3.0)

## Papildoma užduotis
