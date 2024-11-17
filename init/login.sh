#!/usr/bin/expect -f

# 環境変数からユーザー名とパスワードを取得
set ACC_USERNAME $env(ATCODER_USERNAME)
set ACC_PASSWORD $env(ATCODER_PASSWORD)

# 'acc login'コマンドを実行し、認証情報を渡す
spawn acc login
expect "username:"
send "$ACC_USERNAME\r"
expect "password:"
send "$ACC_PASSWORD\r"
expect eof

# oj login https://beta.atcoder.jp/
spawn oj login https://beta.atcoder.jp/
expect "username:"
send "$ACC_USERNAME\r"
expect "password:"
send "$ACC_PASSWORD\r"
expect eof
