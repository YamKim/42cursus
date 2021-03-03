#!/bin/sh

SERVICE_LIST="mysql phpmyadmin wordpress ftps"

FTSVC_DIR=$(pwd)
SRC_DIR=${FTSVC_DIR}/srcs

cd ${NGINX_DIR}; make keys;

for SERVICE in $SERVICE_LIST
do
	echo "DOCKERFILE OF $SERVICE BUILD"
	docker build -t yekim_$SERVICE:1.0 ${SRC_DIR}/$SERVICE/
	sleep 1
done

docker run -d --name mysql -p 3306:3306 yekim_mysql:1.0
docker run -d --name phpmyadmin -p 5000:5000 yekim_phpmyadmin:1.0
docker run -d --name wordpress -p 5050:5050 yekim_wordpress:1.0
docker run -d --name ftps -p 20:20 -p 21:21 -p 21100-21104:21100-21104 yekim_ftps:1.0 sh
