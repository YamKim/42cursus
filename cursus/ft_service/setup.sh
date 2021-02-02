#!/bin/bash

FTSVC_DIR=$(pwd)
SRC_DIR=${FTSVC_DIR}/srcs
METALLB_DIR=${SRC_DIR}/metallb
NGINX_DIR=${SRC_DIR}/nginx

SERVICE_LIST="nginx"

# install MetalLB
echo "MetalLB Installation"
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/metallb.yaml
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

cd ${METALLB_DIR}
# modify MetalLB configuration
MINIKUBE_IP=$(minikube ip)
sed "s/MINIKUBE_IP/${MINIKUBE_IP}/g" template.yaml > metallb.yaml
kubectl apply -f metallb.yaml

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
done

for SERVICE in $SERVICE_LIST
do
	SERVICE_DIR=${SRC_DIR}/${SERVICE}
	#sed "s/MINIKUBE_IP/${MINIKUBE_IP}/g" ${SERVICE_DIR}/template.yaml > ${SERVICE_DIR}/${SERVICE}.yaml
	kubectl apply -f ${SERVICE_DIR}/${SERVICE}.yaml
done
