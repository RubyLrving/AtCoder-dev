# AtCoderの開発環境
## 言語
C++20, python3, pypy

## 環境
docker, vscode, ac-library, online-judge-tools, git

## python3 モジュール
numpy  

## 事前準備  
   1. docker desktopのインストール。  
   2. gitのインストール。  
   3. vscodeのインストール。  
   4. vscodeの拡張機能で、「Remote Development」をインストール。  
   5. githubのSSHからこのプロジェクトのcloneを用意します。  
      `git clone git@github.com:RubyLrving/AtCoder-dev.git`  

## プロジェクトをremote Developmentで実行
   1. vscodeでこのプロジェクトを開きます。  
   2. 表示>コマンドパレットから「Open folder in container」を選択します。  
   3. 下記の「自動化手順」 or 「手動手順」 へ  

## コンテスト参加時  
1. カレントディレクトリ移動  
   `$ cd contest`  
   - ディレクトリは `/workspaces/AtCoder-dev/contest` となる想定  
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
   - cppの場合は、`g++ -std=c++20 main.cpp`にて、a.outファイルをビルド後に`oj t -d ./tests/`  
   - スクリプト言語の場合は `oj t -c "pypy3 main.py" -d ./tests/` のようになる  
   - 例: `g++ -std=c++20 main.cpp && oj t -d ./tests/`  
   - 例: `oj t -c "python3 ./main.py" -d ./tests/`  
   - 例: `oj t -c "pypy3 ./main.py" -d ./tests/`  
1. 任意の入力データによるデバッグ実行
   - cppでのinput.txtを使用したデバッグ実行の方法  
      - エディタの左側にある「デバッグと実行」を選択。  
      - 「C++:current File」を選択します。  
      - 画面上にあるメニューから、「実行」>「デバッグ実行」を選択。  
   - python3, pypyでのinput.txtを使用したデバッグ実行の方法  
      - 例: `python3 main.py < input.txt`  
      - 例: `pypy3 main.py < input.txt`  
1. 提出
   `acc s main.cpp`  

## 手動手順
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
      `$ acc templates`  
  

## 自動化手順
   1. 事前にルートのディレクトリに .env ファイルを作成し以下内容を記述(右辺は適宜変更のこと)  
      `ATCODER_USERNAME=your username`  
      `ATCODER_PASSWORD=your password`  
   1. VSCodeでコンテナ環境にリモート接続後、以下のコマンドを実行しスクリプトに実行権限付与  
      `$ chmod +x ./init/*.sh`  
   1. 以下実行  
      `./init/startup.sh`  
   1. コンテナを終了したい時、左下の「><」をクリックし、「リモート接続の終了」を選択してvscodeを閉じます。   

## ライブラリ
atcoder libraryに加えて自作のライブラリも「./atcoder-dev/lib」フォルダに保存してあります。  