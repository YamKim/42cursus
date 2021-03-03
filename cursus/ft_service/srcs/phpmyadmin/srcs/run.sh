#!/bin/sh

/usr/sbin/telegraf/telegraf &
php-fpm7 & nginx -g "daemon off;"
