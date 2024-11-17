# AtCoderの開発環境
## 言語
C++, python3, pypy

## 環境
docker, vscode, ac-library, online-judge-tools, git

## プロジェクトをremote Developmentで実行

※下記に記載されている「設定方法」を全て実行してください

1. vscodeでこのプロジェクトを開きます。
2. 表示>コマンドパレットから「Open folder in container」を選択します。

## コンテスト参加時

1. カレントディレクトリ移動  
  `$ cd contest`
  - ディレクトリは /workspaces/atcoder_cpp/contest となる想定
1. 問題の取得
  `$ acc new コンテストID`
  - 例: `$ acc new abc123`
  - 例: `acc new abc378 --template cpp`
  - 例: `acc new abc378 --template py`
1. フォルダ移動  
  `$ cd コンテストID`
  - 例: `$ cd abc123`
1. main.cppを開いてコーディング
1. コンパイルし、a.outを生成する
1. テスト  
  `oj t -d ./tests/`
  - cppの場合は、`g++ -std=c++20 main.cpp`にて、a.outファイルをビルド後に`oj t -c -d ./tests/`
  - スクリプト言語の場合は `oj t -c "pypy3 main.py" -d ./tests/` のようになる
  - 例: `g++ -std=c++20 main.cpp && oj t -c -d ./tests/`
  - 例: `oj t -c "python3 ./main.py" -d ./tests/`
  - 例: `oj t -c "pypy3 ./main.py" -d ./tests/`
1. 提出
  `acc s main.cpp`

- 手動手順
  1. 以下のコマンドを実行し、AtCoderログイン設定  
    `$ acc login`
  1. 以下のコマンド実行し、再びAtCoderアカウント入力  
    `$ oj login https://beta.atcoder.jp/`
  1. 全問インストールする設定にする  
    `$ acc config default-task-choice all`
  1. テンプレート設定用フォルダ確認  
    ``$ ls -l `acc config-dir` ``
  1. テンプレート設定のコピー  
    ``$ cp -r ./config/. `acc config-dir` `` 
  1. テンプレート設定用フォルダ配下にコピーされていること確認  
    ``$ ls -l `acc config-dir` ``
  1. デフォルトテンプレートの設定  
    `$ acc config default-template cpp`
  1. c++20の設定の為、「表示」>「コマンドパレット」から、「C++」を検索
  1. 「c/c++ edit configurations」を選択
  1. 「c++ 標準」の項目にて、「c++20」を選択

- 自動化手順
  1. 事前にルートのディレクトリに .env ファイルを作成し以下内容を記述(右辺は適宜変更のこと)  
    ```
    ATCODER_USERNAME=your username
    ATCODER_PASSWORD=your password
    ```
  1. VSCodeでコンテナ環境にリモート接続後、以下のコマンドを実行しスクリプトに実行権限付与  
    `$ chmod +x ./init/*.sh`
  1. 以下実行  
    `./init/startup.sh`

  1. コンテナを終了したい時、左下の「><」をクリックし、「リモート接続の終了」を選択してvscodeを閉じます。

## 実行>デバッグ実行を行う

このプロジェクトでは実行>デバッグ実行の入力を、「./atcoder-dev/input.txt」のテキストを読み込むようにしています。

入力データを毎回手動で入力しなくてもいいようにしています。

## ライブラリ

atcoder libraryに加えて自作のライブラリも「./atcoder-dev/lib」フォルダに保存してあります。
