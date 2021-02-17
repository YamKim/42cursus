#!/bin/bash

FTSVC_DIR=$(pwd)
SRC_DIR=${FTSVC_DIR}/srcs
METALLB_DIR=${SRC_DIR}/metallb
NGINX_DIR=${SRC_DIR}/nginx

SERVICE_LIST="nginx phpmyadmin"

# install MetalLB
export LOG_PATH=${SRC_DIR}/log.txt
touch ${LOG_PATH}
echo "MetalLB Installation"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml >> $LOG_PATH
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml >> $LOG_PATH
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)" >> $LOG_PATH

# modify MetalLB configuration
MINIKUBE_IP=$(minikube ip)
cd ${METALLB_DIR}
sed -i '.bak' "s/MINIKUBE_IP/${MINIKUBE_IP}/g" metallb.yaml
kubectl apply -f metallb.yaml >> $LOG_PATH

# enable docker deamon
eval $(minikube -p minikube docker-env)

# make keys for openssl
cd ${NGINX_DIR}; make keys;
#cd ${FTPS_DIR}; make keys;
echo "nginx ssl success"

kubectl create secret tls nginx-secret \
	--key ${NGINX_DIR}/ssl/nginx.key \
	--cert ${NGINX_DIR}/ssl/nginx.crt

kubectl create configmap nginx-config \
	--from-file=${NGINX_DIR}/srcs/nginx.conf

for SERVICE in $SERVICE_LIST
do
	echo "DOCKERFILE OF $SERVICE BUILD"
	docker build -t yekim_$SERVICE:1.0 ${SRC_DIR}/$SERVICE
	sleep 1.5
done

for SERVICE in $SERVICE_LIST
do
	SERVICE_DIR=${SRC_DIR}/${SERVICE}
	#sed "s/MINIKUBE_IP/${MINIKUBE_IP}/g" ${SERVICE_DIR}/template.yaml > ${SERVICE_DIR}/${SERVICE}.yaml
	kubectl apply -f ${SERVICE_DIR}/${SERVICE}.yaml
done
:<<'END'
END
