echo "MetalLB Uninstall"

SRC_DIR=$(pwd)
METALLB_DIR=${SRC_DIR}/metallb
NGINX_DIR=${SRC_DIR}/nginx
FTPS_DIR=${SRC_DIR}/ftps

SERVICE_LIST="nginx mysql phpmyadmin wordpress ftps influxdb grafana"

for SERVICE in ${SERVICE_LIST}
do
	kubectl delete -f $SRC_DIR/$SERVICE/yaml
done

for SERVICE in $SERVICE_LIST
do
	echo "DOCKERFILE OF $SERVICE DELETE"
	docker rmi -f yekim_$SERVICE:1.0
	sleep 1.5
done

kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml
kubectl delete -f $METALLB_DIR/metallb_cm.yaml

$(MAKE) -C $NGINX_DIR clean
$(MAKE) -C $FTPS_DIR clean

echo ${SRC_DIR}
rm ${SRC_DIR}/log.txt
