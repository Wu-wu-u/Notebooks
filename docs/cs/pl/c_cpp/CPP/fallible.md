# 易错点

1. `char *`作为容器的键值

```cpp
std::map<char *, int> m;
const int MAX_SIZE = 100;
int main() {
    char str[MAX_SIZE];
    for (int i = 0; i < 10; i++) {
        std::cin >> str;
        m[str] = i;
    }
    std::cout << m.size() << std::endl;
}
```

- `std::map<char *, int> m;` 使用了 `char*` 作为键。这会导致所有输入的字符串都指向同一个内存地址，即 `str` 数组的起始地址。因此，每次输入新的字符串时，都会覆盖之前的内容，导致 `map` 中只有一个键值对。