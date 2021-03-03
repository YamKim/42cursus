#!/bin/sh

SRC_DIR=$PWD/srcs/
METALLB_DIR=$SRC_DIR/metallb

SERVICE_LIST="nginx mysql phpmyadmin wordpress ftps influxdb grafana"

# install MetalLB
export LOG_PATH=$SRC_DIR/log.txt
touch $LOG_PATH

echo "INSTALL MetalLB..."
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml >> $LOG_PATH
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml >> $LOG_PATH
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> $LOG_PATH

kubectl apply -f $METALLB_DIR/metallb_cm.yaml >> $LOG_PATH

# enable docker deamon
eval $(minikube -p minikube docker-env)

# make keys for openssl
$MAKE -C $SRC_DIR/nginx/ keys >> $LOG_PATH
$MAKE -C $SRC_DIR/ftps/ keys >> $LOG_PATH

# show dashboard on background
minikube dashboard &

# build docker files for docker images
for SERVICE in $SERVICE_LIST
do
	echo "BUILD DOCKERFILE FOR $SERVICE"
	docker build -t yekim_$SERVICE:1.0 ${SRC_DIR}/$SERVICE >> $LOG_PATH
	sleep 1.5
done

# create application service
for SERVICE in $SERVICE_LIST
do
	echo "CREATE $SERVICE SERVICE"
	SERVICE_DIR=${SRC_DIR}/${SERVICE}
	kubectl create -f ${SERVICE_DIR}/yaml >> $LOG_PATH
done
