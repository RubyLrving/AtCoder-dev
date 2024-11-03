# AtCoderの開発環境
## 言語
C++, python3, pypy

## 環境
docker, vscode, ac-library, online-judge-tools, git

# プロジェクトをremote Developmentで実行

※下記に記載されている「設定方法」を全て実行してください

1. vscodeでこのプロジェクトを開きます。
2. 表示>コマンドパレットから「Open folder in container」を選択します。

## cppの使用方法

- cppの新規のプロジェクトの作成

```
acc new abc378 --template cpp
```

- サンプル入力でテストを行う

指定の問題のディレクトリを開いてコマンドを実行。

```
oj t -c -d ./tests/
```

- 実行>デバッグ実行を行う

このプロジェクトでは実行>デバッグ実行の入力を、「./atcoder-dev/input.txt」のテキストを読み込むようにしています。

入力データを毎回手動で入力しなくてもいいようにしています。

- ライブラリ

atcoder libraryに加えて自作のライブラリも「./atcoder-dev/lib」フォルダに保存してあります。

データ構造やアルゴリズムは、その場で実装できるレベルに理解しておくのが基本です。

データ構造やアルゴリズムにその場で変更を加えないとACできない問題があるからです。

中身を修正できる自作のライブラリは貴重です。

## pyの使用方法

- pyの新規のプロジェクトの作成

```
acc new abc378 --template py
```

- サンプル入力でテストを行う

指定の問題のディレクトリを開いてコマンドを実行。

1. python3
```
oj t -c "python3 ./main.py" -d ./tests/
```

2. pypy

```
oj t -c "pypy3 ./main.py" -d ./tests/
```

# 設定方法
1. docker desktopのインストール。
2. gitのインストール。
3. vscodeのインストール。
4. vscodeの拡張機能で、「Remote Development」をインストール。
5. githubのSSHからこのプロジェクトのcloneを用意します。
6. vscodeでこのプロジェクトを開きます。
7. 表示>コマンドパレットから「Open folder in container」を選択します。
8. temolateの設定のため、隠しフォルダのConfigフォルダへ移動。

```
cd `acc config-dir`
```

9. vscodeで隠しフォルダを開きます。

```
code .
```

10. cpp, pyフォルダを作成します。

```
mkdir cpp
mkdir py
```

11. cppへAtCoder-dev/configのmain.cppとtemplate.jsonをコピーします。
12. pyへAtCoder-dev/configのmain.pyとtemplate.jsonをコピーします。
13. pyフォルダのtemplate.jsonを編集します。

template.jsonにて、main.cppの拡張子をpyに変更します。

```
{
  "task":{
    "program": ["main.py"],
    "submit": "main.py"
  }
}
```

14. 「code .」で開いたvscodeを閉じます。
15. templateを確認します。

```
acc templates
```

16. aclでatcoderへログイン

```
acc login
```

17. ojでatcoderへログイン

```
oj login https://beta.atcoder.jp/
```

18. 手順の終了、vscodeを閉じます。