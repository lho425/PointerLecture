#C言語ポインタ講習

- 概念
- 文法
- 関数の引数のポインタ渡しと値渡し
- ポインタの演算
- 配列とポインタ・文字列
- 関数ポインタ

##概念
変数はメモリ上に確保される

メモリの位置は数値で表します

その数値を(メモリ)アドレス、番地、と呼んだりする

C言語では、変数のメモリ上の位置を得ることができる

また、C言語では、アドレスをポインタ型の変数に格納出来る  

##文法

    int i = 1;
    &i;          //変数iのアドレス

    int *i_ptr;  //intポインタ型の変数の宣言
    		 //int* i_ptr;と書いてもよい

    i_ptr = &i;  //intポインタ型の変数i_ptrに変数iのアドレスを代入

    *i_ptr = 10; //intポインタi_ptrの指すメモリ領域（この場合は変数iと同じ領域）に10を代入

    int *i_ptr2 = &i;  //宣言と代入を一度にやる場合

###確認してみよう
メモリ内容が確認できるデバッガを使うと、より理解が深まるでしょう

    #include <stdio.h>

    void main(){
        char c = 1;
        char *c_ptr = &c;

        printf("cのアドレス: %p\n",&c);
        printf("c_ptrの値: %p\n",c_ptr);
    }

デバッガを使ってメモリ内容を見る場合、
型をchar以外にした場合、変数の大きさや、エンディアンを考慮する必要があります。
(普通にプログラミングする場合はエンディアンは無視して良い)

    #include <stdio.h>

    void main(){
        int i = 1;
        int *i_ptr = &i;

        printf("iのアドレス: %p\n",&i);
        printf("i_ptrの値: %p\n",i_ptr);
    }


##関数の引数のポインタ渡しと値渡し

なぜポインタを使うのか？
デカイデータを扱う時にデータそのものをコピーしたくない時とかに使う

    struct Data {
        int id;
        char nakami[100];
    };

    void syokika(struct Data *data_ptr){
        /* いろいろ */
    }

    void main(){
        struct Data d;
        syokika(&d);
        
    }

#その他モロモロ
ポインタの解説がいい感じに書いてある http://www.cc.kyoto-su.ac.jp/~yamada/programming/pointer.html

配列や文字列とポインタの関係がわかる http://www2.netf.org/pointer3.html

読むべし
