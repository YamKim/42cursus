#!/bin/sh

sleep 2
sh /tmp/set_wpdb.sh

sleep 2
php-fpm7 & nginx -g "daemon off;"
