# Laboratory work II

Данная лабораторная работа посвящена изучению систем контроля версий на примере Git.

репозиторий:https://github.com/Shohiii/lab02

Условие лабораторной работы: https://github.com/tp-labs/lab02

## Part I

### 1. Создать пустой репозиторий на сервисе GitHub

Создан публичный репозиторий `lab02`.

### 2. Выполнить инструкцию по созданию первого коммита

Первый коммит репозитория:

```text
cf46a7d Initial commit
```

### 3. Создать файл `hello_world.cpp` и реализовать Hello World с плохим стилем

Файл был создан с использованием `using namespace std;`.

Исходный код на данном этапе:

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world" << endl;
    return 0;
}
```

### 4. Добавить файл в локальный репозиторий

Команда:

```bash
git add hello_world.cpp
```

### 5. Закоммитить изменения

Коммит:

```text
e09c381 Add hello world program (bad style)
```

### 6. Изменить программу так, чтобы она запрашивала имя пользователя

Программа была изменена следующим образом:

```cpp
#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << endl;
    return 0;
}
```

### 7. Закоммитить новую версию программы

Коммит:

```text
f4896f7 Add user input and greeting
```

Так как `hello_world.cpp` уже является отслеживаемым файлом, изменения можно добавить и закоммитить отдельными командами:

```bash
git add hello_world.cpp
git commit -m "Add user input and greeting"

### 8. Отправить изменения в удалённый репозиторий

Команда:

```bash
git push origin main
```

После этого коммиты появились в удалённом репозитории GitHub.

### 9. Проверить историю коммитов

История:

```text
f4896f7 Add user input and greeting
e09c381 Add hello world program (bad style)
cf46a7d Initial commit
```

---

## Part II

### 1. Создать локальную ветку `patch1`

Команда:

```bash
git checkout -b patch1
```

### 2. Исправить код и удалить `using namespace std`

Код был изменён так, чтобы использовать пространство имён `std` явно:

```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

### 3. Выполнить commit и push ветки `patch1`

Коммит:

```text
9f8830f Fix code style, remove using namespace std
```

Ветка была отправлена в удалённый репозиторий:

```bash
git push origin patch1
```

### 4. Проверить наличие ветки `patch1` в удалённом репозитории

После push ветка `patch1` стала доступна на GitHub.

### 5. Создать pull request `patch1 -> main`

На GitHub был создан Pull Request №1 из ветки `patch1` в ветку `main`.

### 6. Добавить комментарии в исходный код

В ветке `patch1` в программу были добавлены комментарии:

```cpp
// Программа для демонстрации персонализированного "Hello World"
// Исправлено: удалено 'using namespace std' для большей ясности кода
```

### 7. Выполнить commit и push

Коммит:

```text
4c583ec Add comments in patch1
```

Изменения были отправлены:

```bash
git push origin patch1
```

### 8. Проверить обновление Pull Request

После push новый коммит появился в ранее созданном Pull Request №1.

### 9. Выполнить слияние Pull Request и удалить удалённую ветку `patch1`

Pull Request №1 был слит в `main`.

В истории появился merge-коммит:

```text
9b32553 Merge pull request #1 from Shohiii/patch1
```

Удалённая ветка `patch1` была удалена.

### 10. Обновить локальную ветку `main`

После слияния выполняется переход в основную ветку и получение изменений:

```bash
git checkout main
git pull origin main
```

### 11. Просмотреть историю ветки `main`

Команда:

```bash
git log --oneline
```

Фрагмент истории:

```text
9b32553 Merge pull request #1 from Shohiii/patch1
4c583ec Add comments in patch1
9f8830f Fix code style, remove using namespace std
f4896f7 Add user input and greeting
e09c381 Add hello world program (bad style)
cf46a7d Initial commit
```

### 12. Удалить локальную ветку `patch1`

Команда:

```bash
git branch -d patch1
```

---

## Part III

### 1. Создать локальную ветку `patch2`

Команда:

```bash
git checkout -b patch2
```

### 2. Изменить стиль кода с помощью `clang-format`

Использована команда:

```bash
clang-format -i -style=Mozilla hello_world.cpp
```

После форматирования функция `main` стала выглядеть следующим образом:

```cpp
int main()
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}
```

### 3. Выполнить commit, push и создать Pull Request `patch2 -> main`

После форматирования был создан коммит.

После последующего `rebase` его итоговый хеш:

```text
25a2996 Apply clang-format Mozilla style
```

Ветка была отправлена на GitHub, после чего был создан Pull Request №2 из `patch2` в `main`.

### 4. Изменить комментарии в основной ветке

В ветке `main` комментарии были изменены с русского языка на английский:

```cpp
// Program to demonstrate a personalized "Hello World"
// Fixed: removed 'using namespace std' for better code clarity
```

Коммит:

```text
b548edb refactoring comments in main
```

Изменения были отправлены в ветку `main`.

### 5. Проверить появление конфликта

Так как в `main` и `patch2` были изменены одни и те же участки файла `hello_world.cpp`, в Pull Request №2 появился конфликт.

### 6. Выполнить rebase и исправить конфликт

Локально были получены актуальные изменения основной ветки, после чего был выполнен rebase ветки `patch2` на `main`.

Использовалась команда:

```bash
git rebase origin/main
```

Во время конфликта файл `hello_world.cpp` был исправлен вручную.

После разрешения конфликта:

```bash
git add hello_world.cpp
git rebase --continue
```

Результат:

```text
[detached HEAD 25a2996] Apply clang-format Mozilla style
Successfully rebased and updated refs/heads/patch2.
```

### 7. Выполнить force push ветки `patch2`

После `rebase` история ветки изменилась, поэтому потребовалась принудительная отправка:

```bash
git push origin patch2 --force
```

### 8. Проверить исчезновение конфликтов

После force push Pull Request №2 был обновлён, конфликт исчез.

### 9. Выполнить merge Pull Request `patch2 -> main`

Pull Request №2 был слит в основную ветку.

В истории появился merge-коммит:

```text
86ac85b Merge pull request #2 from Shohiii/patch2
```

Итоговая история репозитория:

```text
02912b9 Create REPORT.md
86ac85b Merge pull request #2 from Shohiii/patch2
25a2996 Apply clang-format Mozilla style
b548edb refactoring comments in main
9b32553 Merge pull request #1 from Shohiii/patch1
4c583ec Add comments in patch1
9f8830f Fix code style, remove using namespace std
f4896f7 Add user input and greeting
e09c381 Add hello world program (bad style)
cf46a7d Initial commit
```
