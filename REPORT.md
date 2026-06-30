# Laboratory work II

## Part I

### 1. Создать пустой репозиторий на сервисе github.com.
Публичный репозиторий с названием lab02 создан.

### 2. Выполнить инструкцию по созданию первого коммита на странице репозитория.
Инструкция выполнена, первый коммит:
`[main cf46a7d] Initial commit`

### 3. Создать файл hello_world.cpp с плохим стилем.
Команда: `nano hello_world.cpp`
Код создан.

### 4. Добавить файл в локальную копию репозитория.
Команда: `git add hello_world.cpp`
Файл добавлен.

### 5. Закоммитить изменения с осмысленным сообщением.
Вывод команды:
[main e09c381] Add hello world program (bad style)
1 file changed, 9 insertions(+)
create mode 100644 hello_world.cpp

### 6. Изменить исходный код для запроса имени.
Команда: `nano hello_world.cpp`
Код изменен (добавлен ввод через cin).

### 7. Закоммитить новую версию программы.
Вывод команды:
[main f4896f7] Add user input and greeting
1 file changed, 6 insertions(+), 1 deletion(-)

### 8. Запушить изменения в удаленный репозиторий.
Вывод команды:
To https://github.com/Shohiii/lab02.git
cf46a7d..f4896f7  main -> main

### 9. Проверить историю коммитов.
Вывод команды:
f4896f7 (HEAD -> main, origin/main) Add user input and greeting

e09c381 Add hello world program (bad style)

cf46a7d Initial commit

---

## Part II

### 1. Создать локальную ветку patch1.
Команда: `git checkout -b patch1`
Локальная ветка patch1 создана.

### 2. Внести изменения (исправить стиль, удалить using namespace std).
Код изменен через `nano hello_world.cpp`.

### 3. Commit, push локальную ветку.
Вывод:
[patch1 9f8830f] Fix code style, remove using namespace std
1 file changed, 5 insertions(+), 6 deletions(-)
...
To https://github.com/Shohiii/lab02.git

[new branch]      patch1 -> patch1


### 4. Проверить, что ветка patch1 доступна.
Команда: `git branch -a`
Вывод:
main

patch1
remotes/origin/main
remotes/origin/patch1


### 5. Создать pull-request patch1 -> main.
Создан pull-request patch1 -> main на GitHub.

### 6. Добавить комментарии в код.
Код изменен через `nano hello_world.cpp`.

### 7. Commit, push.
Вывод:
[patch1 4c583ec] Add comments in patch1
1 file changed, 3 insertions(+)
To https://github.com/Shohiii/lab02.git
9f8830f..4c583ec  patch1 -> patch1


### 8. Проверить изменения в pull-request.
Изменения внесены — проверено на сайте Github.

### 9. Слить PR и удалить ветку patch1.
Команда: `gh pr merge 1 --merge --delete-branch`
Вывод: Слияние выполнено успешно, ветка patch1 удалена.

### 10. Просмотреть историю в ветке main.
Вывод:
commit 9b32553b7601ca4c642c0697aeea2f0c41838540 (HEAD -> main, origin/main)
Merge: f4896f7 4c583ec
Author: Shohiii as50503as@gmail.com
Date:   Tue Jun 30 23:19:46 2026 +0300
Merge pull request #1 from Shohiii/patch1
Fix code style, remove using namespace std


### 11. Удалить локальную ветку patch1.
Команда: `git branch -d patch1` (выполнено).

---

## Part III

### 1. Создать локальную ветку patch2.
Команда: `git checkout -b patch2`

### 2. Изменить code style (clang-format).
Команда: `clang-format -i -style=Mozilla hello_world.cpp`

### 3. Commit, push, PR patch2 -> main.
Вывод:
[patch2 8318281] Apply clang-format Mozilla style
...
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/Shohiii/lab02/pull/new/patch2


### 4. Изменить комментарии в мастере.
Команда: `git checkout main`, внесение изменений, `push`.

### 5. Проверить наличие конфликтов.
На сайте Github видим, что конфликты появились.

### 6. Исправить конфликты.
Команда: `git rebase origin/main`, `nano hello_world.cpp` (исправлено), `git rebase --continue`.
Вывод:
[detached HEAD 25a2996] Apply clang-format Mozilla style
Successfully rebased and updated refs/heads/patch2.


### 7. Force push в ветку patch2.
Команда: `git push origin patch2 --force`

### 8. Проверить, что конфликты пропали.
Все конфликты пропали.

### 9. Вмержить PR patch2 -> main.
Команда: `gh pr merge` (выполнено).

### 7. Закоммитить новую версию программы.
Вывод команды:
