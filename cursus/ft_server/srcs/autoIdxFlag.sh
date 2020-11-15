#! /bin/bash
NGINX_DEFAULT=/etc/nginx/sites-available/default
if [ ${AUTOINDEXFLAG} -eq 0 ] ; then
	awk '{sub(/autoindex on/, "autoindex off"); print}' $NGINX_DEFAULT > default.tmp
	echo "AUTOINDEX OFF"
else
	awk '{sub(/autoindex off/, "autoindex on"); print}' $NGINX_DEFAULT > default.tmp
	echo "AUTOINDEX ON"
fi
mv default.tmp $NGINX_DEFAULT
