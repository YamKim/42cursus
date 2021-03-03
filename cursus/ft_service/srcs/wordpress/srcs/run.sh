#!/bin/sh

sleep 2
sh /tmp/set_wpdb.sh

sleep 2
/usr/sbin/telegraf/telegraf &
php-fpm7 & nginx -g "daemon off;"
