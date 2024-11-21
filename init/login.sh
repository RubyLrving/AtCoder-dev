#!/usr/bin/expect -f

set ACC_USERNAME $env(ATCODER_USERNAME)
set ACC_PASSWORD $env(ATCODER_PASSWORD)

# 'acc login'コマンドを実行し、認証情報を渡す
# \nの改行コードは環境によって変わります。\rの場合もあります。
spawn acc login
expect "username:"
send "$ACC_USERNAME\n"
expect "password:"
send "$ACC_PASSWORD\n"
expect eof

# oj login https://beta.atcoder.jp/
spawn oj login https://beta.atcoder.jp/
expect "username:"
send "$ACC_USERNAME\n"
expect "password:"
send "$ACC_PASSWORD\n"
expect eof