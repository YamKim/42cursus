#!/bin/sh

/usr/bin/mysql_install_db --user=root --datadir=/var/lib/mysql
sleep 2
/usr/bin/mysqld_safe --datadir="/var/lib/mysql" &
sleep 2

mysql -u root -e "CREATE DATABASE wordpress;"
mysql -u root -e "CREATE USER 'yekim'@'localhost' IDENTIFIED BY '5933';"
mysql -u root -e "GRANT ALL PRIVILEGES ON *.* TO 'yekim'@'localhost' WITH GRANT OPTION;"
mysql -u root -e "FLUSH PRIVILEGES;"

while true
do	/bin/sh
done
