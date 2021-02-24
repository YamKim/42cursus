#!/bin/sh

SRC_DIR=$(pwd)
METALLB_DIR=${SRC_DIR}/metallb
NGINX_DIR=${SRC_DIR}/nginx

SERVICE_LIST="mysql phpmyadmin wordpress ftps"

for SERVICE in ${SERVICE_LIST}
do
	docker rm -f $SERVICE
	sleep 1
	docker rmi -f yekim_$SERVICE:1.0
	sleep 1
done


#cd ${NGINX_DIR}; make clean
#cd ${FTPS_DIR}; make clean
