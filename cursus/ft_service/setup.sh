#!/bin/sh

SRCS_DIR=$PWD/srcs/
MINIKUBE_IP=$(minikube ip)

# MODIFIY CONFIG FILES FROM TEMPLATE
METALLB_DIR=$SRCS_DIR/metallb
sed "s/MINIKUBE_IP/$MINIKUBE_IP/" $METALLB_DIR/metallb_cm.yaml.template > $METALLB_DIR/metallb_cm.yaml
NGINX_SRCS_DIR=$SRCS_DIR/nginx/srcs
sed "s/MINIKUBE_IP/$MINIKUBE_IP/" $NGINX_SRCS_DIR/default.conf.template > $NGINX_SRCS_DIR/default.conf
FTPS_SRCS_DIR=$SRCS_DIR/ftps/srcs
sed "s/MINIKUBE_IP/$MINIKUBE_IP/" $FTPS_SRCS_DIR/vsftpd.conf.template > $FTPS_SRCS_DIR/vsftpd.conf
WORDPRESS_SRCS_DIR=$SRCS_DIR/wordpress/srcs
sed "s/MINIKUBE_IP/$MINIKUBE_IP/" $WORDPRESS_SRCS_DIR/wp-config.php.template > $WORDPRESS_SRCS_DIR/wp-config.php

SERVICE_LIST="nginx mysql phpmyadmin wordpress ftps influxdb grafana"

# install MetalLB
export LOG_PATH=$SRCS_DIR/log.txt
touch $LOG_PATH

echo "INSTALL MetalLB..."
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml >> $LOG_PATH
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml >> $LOG_PATH
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> $LOG_PATH

kubectl apply -f $METALLB_DIR/metallb_cm.yaml >> $LOG_PATH

# enable docker deamon
eval $(minikube -p minikube docker-env)

# show dashboard on background
minikube dashboard &

# build docker files for docker images
for SERVICE in $SERVICE_LIST
do
	echo "BUILD DOCKERFILE FOR $SERVICE"
	docker build -t yekim_$SERVICE:1.0 ${SRCS_DIR}/$SERVICE >> $LOG_PATH
	sleep 1.5
done

# create application service
for SERVICE in $SERVICE_LIST
do
	echo "CREATE $SERVICE SERVICE"
	SERVICE_DIR=${SRCS_DIR}/${SERVICE}
	kubectl create -f ${SERVICE_DIR}/yaml >> $LOG_PATH
done
