# README.md

ここで管理しているプログラムは[`Qiita`](https://qiita.com/)で投稿した[C言語で書いたプログラムをgoogletestでテストできるようにした](https://qiita.com/kaitokimuraofficial/items/b879ad6ee190f3f80afb) に対応するものです。

## Getting Started (まずは使ってみよう！)
サンプルのテストコードをおいています。まずは試してみましょう。

`Docker`を立ち上げた状態で、`Makefile`の
```makefile
test:
				docker build . -t clang_unit_test
				docker rmi clang_unit_test 
```

のコマンドを実行します。

```
make test
```
を実行してみましょう。

`Dockerfile`に書かれた内容がビルドされると思います。


特にエラーが起こらず、ビルドが終了すると思います。
このような時は全てのテストにパスしたことを表します。



`Dockerfile`内の
```Dockerfile
RUN cd build && ctest --output-on-failure
```
の部分が`CMake`でビルドして、テストを時効している部分なのです。

**テストコードにエラーがあったり、失敗するテストが含まれているとエラーが発生します。**

**失敗したテストについてのログが表示されるので、参考にしながらテストコードかソースコードを修正してください。**


## 使い方

では、具体的な使い方について説明します。


### 1. まず`src`にテストしたいC言語のプログラムを追加してください。


### 2. `src`に追加したプログラムのテストコードを`tests`に追加します。

このとき、

```cpp
extern "C" {
// テストしたいプログラムのソースをincludeしてください。

// こちらはnode_test.ccと同じように
// ../src/node.hをincludeしています。
// #include "../src/node.h"
}

#include <gtest/gtest.h>
#include <string>

TEST(NodeTest, onlyHead) {
    // C言語の文法で、テストしたいシナリオやassertionを
    // googletestを使いながら記載してください。


    // EXPECT_EQはgoogletestのライブラリ特有のassertionです。
    // EXPECT_EQ(1 + 2, 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```


こちらをテンプレートとして参考にしながらテストコードを作成してみてください。


### 3. `CMakeLists.txt`を編集する

`CMakeLists.txt`の

```txt
# == TEMPLATE == 
#
# add_executable(
#   xxx_test
#   xxx_test.cc
#   ../src/xxx.c
# )
# target_link_libraries(
#   xxx_test
#   GTest::gtest_main
# )
#
# include(GoogleTest)
# gtest_discover_tests(xxx_test)
```

をコピーして、変更し、
```txt
include(GoogleTest)
gtest_discover_tests(node_test)
```

の上部に追加していけばいいです。

`xxx`のところを各自が追加したファイル名に変更してください。

**追加したテストコード(`xxx_test.cc`)だけでなく、ソースファイルの`.../src/xxx.c`も`add_executable`に追加することに気をつけましょう。**


## 最後に

何かありましたら、ご指摘・ご連絡していただけると幸いです。
よろしくお願いします。
