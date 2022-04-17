#!/bin/bash

# usage: bash atcoder.sh https://atcoder.jp/contests/abc245/tasks/abc245_d 1
#
# $1: 問題を識別するURLを指定する
# $2: 0ならば出力例を出力し、1ならば入力例を出力する

case $2 in
  0) ;;
  1) ;;
  *) exit 0 ;;
esac

readonly URL="$1"
readonly TEXT=`curl $URL --show-error | \
  sed -n '/<pre/,/<\/pre/p' | \
  sed 's/<\/h3>/<\/h3> \
/' | \
  sed 's/<pre>//' | \
  sed 's///' | \
  sed 's/<\/pre>//' | \
  sed 's/<var>.*<\/var>//'`

FLAG=$2
for STR in ${TEXT[@]}; do
  if [[ `echo $STR | grep "入力例"` ]]; then
    FLAG=!$FLAG
    continue
  fi

  if [[ `echo $STR | grep "出力例"` ]]; then
    FLAG=!$FLAG
    continue
  fi

  if [[ `echo $STR | grep "</h3>"` ]]; then
    continue
  fi

  if [[ $FLAG -eq 0 ]]; then
    echo $STR
  fi
done
