echo "MetalLB Uninstall"

SRC_DIR=$(pwd)
METALLB_DIR=${SRC_DIR}/metallb
NGINX_DIR=${SRC_DIR}/nginx

SERVICE_LIST="nginx"

for SERVICE in ${SERVICE_LIST}
do
	kubectl delete -f $SRC_DIR/$SERVICE/$SERVICE.yaml
done

kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml

kubectl delete secret nginx-secret
kubectl delete configmap nginx-config
#kubectl delete secret ftps-secrets
#kubectl delete configmap telegraf-config

cd ${NGINX_DIR}; make clean
#cd ${FTPS_DIR}; make clean

echo ${SRC_DIR}
rm ${SRC_DIR}/log.txt
