#!/bin/sh

openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-subj /C=KR/ST=Seoul/L=Seoul/O=42/OU=Lee/CN=nginxsvc \
	-keyout /etc/ssl/nginx.key -out /etc/ssl/nginx.crt

adduser -D yekim
echo "yekim:5933" | chpasswd

ssh-keygen -t rsa -f /etc/ssh/ssh_host_rsa_key -N ""

/usr/sbin/telegraf/telegraf &

/usr/sbin/sshd
/usr/sbin/nginx -g "daemon off;"
