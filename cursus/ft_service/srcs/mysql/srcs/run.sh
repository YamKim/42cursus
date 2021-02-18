#!/bin/sh

/usr/bin/mysql_install_db --user=mysql --datadir=/var/lib/mysql
sleep 2
/usr/bin/mysqld_safe --datadir="/var/lib/mysql" &
sleep 2
mysql -u root < /tmp/init_db.sql

while true
do	/bin/sh
done
