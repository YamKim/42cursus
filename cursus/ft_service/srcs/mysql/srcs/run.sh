#!/bin/sh

#sed -i "s/PMA_USER/$PMA_USER/g;s/PMA_PASSWD/$PMA_PASSWD/g" db_init.sql
#sed -i "s/WP_USER/$WP_USER/g;s/WP_PASSWD/$WP_PASSWD/g" db_init.sql
sed -i "s/skip-networking//g" /etc/my.cnf.d/mariadb-server.cnf

nohup /tmp/run_mysql.sh > /dev/null 2>&1 &

/usr/bin/mysql_install_db --user=mysql --datadir="/var/lib/mysql"
/usr/bin/mysqld_safe --satadir="/var/lib/mysql"
