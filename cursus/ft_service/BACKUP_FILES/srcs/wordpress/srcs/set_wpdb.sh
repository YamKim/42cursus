#! /bin/sh

sleep 2
mysql --host=mysql --user=yekim --password=5933 wordpress < /tmp/wordpress.sql > /dev/null 2>&1

until [ $? != 1 ]
do
	sleep 1
	echo "modfiying contents of wp-db. Retrying..."
	mysql --host=mysql --user=yekim --password=5933 wordpress < /tmp/wordpress.sql > /dev/null 2>&1
done
