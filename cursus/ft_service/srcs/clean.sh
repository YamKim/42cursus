echo "MetalLB Uninstall"

SRC_DIR=$PWD
METALLB_DIR=$SRC_DIR/metallb

SERVICE_LIST="nginx mysql phpmyadmin wordpress ftps influxdb grafana"

for SERVICE in $SERVICE_LIST
do
	echo "DELETE SERVICE OF $SERVICE"
	kubectl delete -f $SRC_DIR/$SERVICE/yaml > /dev/null 2>&1
done

for SERVICE in $SERVICE_LIST
do
	echo "DELETE BUILT DOCKERFILE OF $SERVICE"
	docker rmi -f yekim_$SERVICE:1.0 > /dev/null 2>&1
	sleep 1.5
done

kubectl delete -f https://raw.githubusercontent.com/metallb/metallb/v0.9.3/manifests/namespace.yaml > /dev/null 2>&1
kubectl delete -f $METALLB_DIR/metallb_cm.yaml > /dev/null 2>&1

echo "DELETE LOG FILE"
rm -f $SRC_DIR/log.txt > /dev/null 2>&1
