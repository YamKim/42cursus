#!/bin/sh

mysql_install_db --user=root
/usr/bin/mysqld --user=root --bootstrap < /tmp/init_db.sql

#telegraf 백그라운드 실행 & mysql 서버 데몬 실행
/usr/sbin/telegraf/telegraf &
/usr/bin/mysqld_safe --user=root
