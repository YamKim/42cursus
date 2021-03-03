#!/bin/sh

mysql_install_db --user=root
/usr/bin/mysqld --user=root --bootstrap < /tmp/init_db.sql

/usr/sbin/telegraf/telegraf &
/usr/bin/mysqld_safe --user=root
